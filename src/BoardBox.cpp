//
#include "BoardBox.h"
#include "BoardBody.h"
#include <QtGui/QApplication>
#include <QtGui/QPainter>
#include <QtGui/QTransform>
#include <QtOpenGL/QGLWidget>
#include <QtGui/QGraphicsScene>
#include <QtGui/QGraphicsSceneMouseEvent>
#include <QtGui/QLayout>
#include <QtGui/QGraphicsObject>
#include <QtDeclarative/QDeclarativeEngine>
#include <QtDeclarative/QDeclarativeComponent>
#include <QtCore/QMimeData>
#include <QtGui/QDrag>
#include <QtGui/QBitmap>

//
//
//
BoardBox::BoardBox(QGraphicsItem *parent) 
	: QGraphicsItem(parent), m_Space(0), m_World(0), m_StepSize(0.3)
{
	m_World = new dWorld();
	m_Space = new dHashSpace();
	m_JointGroup = new dJointGroup();
	
	m_World->setGravity(0, 0, 0);
	
	dWorldSetCFM(m_World->id(), 1e-5);
	
   m_JointGroup->create();
   
   m_ShowLabels = true; // read from prefs
   m_ShowJoints = true; // read from prefs
   
   setCursor(Qt::OpenHandCursor);
   setAcceptedMouseButtons(Qt::LeftButton);
   this->setAcceptDrops(true);
}

//
//
//
QRectF BoardBox::boundingRect() const
{
	qreal penWidth = 0;

	return QRectF(0 - penWidth / 2, -10,
                       100 + penWidth, 100 + penWidth);
}

//
//
//
BoardBody *BoardBox::addBody(const QString& name, const QString& image, const QPointF& p)
{
	QString bodyName = name;
	unsigned int bodyIndex = 1;
	
	while (bodyExists(bodyName)) {
		bodyName = name + QString("%1").arg(bodyIndex);
		++bodyIndex;
	}
	
   // return false if body already exists
	BoardBody *body = new BoardBody(bodyName, image);

	body->init(m_World, m_Space);
	// set init position - right now deciding on the basis of last mouse click.
	body->setPosition(p.x(), p.y(), 0);

	m_Bodies.push_back(std::pair<QString, BoardBody*>(body->name(), body));
	
	initJoints();
   
   return body;
}

//
//
//
bool BoardBox::bodyExists(const QString& name)
{
	for (size_t index = 0; index < m_Bodies.size(); ++index) {
		std::pair<QString, BoardBody*> body = m_Bodies.at(index);
		
		if (body.first == name) {
			return true;
		}
	}
	
	return false;
}

//
//
//
void BoardBox::initJoints()
{
	for (size_t i = 0; i < m_Bodies.size() - 1; ++i) {
		std::pair<QString, BoardBody*> body1 = m_Bodies[i];

		for (size_t j = i+1; j < m_Bodies.size(); ++j) {
			std::pair<QString, BoardBody*> body2 = m_Bodies[j];

			if (body1.second && body2.second) {
				createJoint(body1.second, body2.second);
			}
		}
   }
#if 0
   // remove unnecessary joints
   if (m_Joints.size() > 0) {
		int diff = m_Joints.size() - m_Bodies.size() - 1;
		// TODO not correct
	   
		for (int j = 0; j < diff; ++j) {
			dBallJoint* ballJoint = m_Joints[m_Joints.size() - 1];
			
			delete ballJoint;
			m_Joints.pop_back();
		}
	}
#endif
}

//
//
//
void BoardBox::createJoint(const QString& bodyName1, const QString& bodyName2)
{
	BoardBody *body1 = NULL;
	BoardBody *body2 = NULL;
	
	for (size_t i = 0; i < m_Bodies.size(); ++i) {
		std::pair<QString, BoardBody*> body = m_Bodies[i];
		
		if (body.first == bodyName1) {
			body1 = body.second;;
		}
		if (body.first == bodyName2) {
			body2 = body.second;
		}
		if (body1 && body2) break;
	}
	
	if (body1 && body2) {
		createJoint(body1, body2);
	}
}

//
//
//
void BoardBox::createJoint(const BoardBody* body1, const BoardBody* body2)
{
	Q_ASSERT(body1);
	Q_ASSERT(body2);
	
	dBallJoint *ballJoint = new dBallJoint;
	
	m_Joints.push_back(ballJoint);
	
	ballJoint->create(m_World->id());
	
	ballJoint->attach(*body1->getBody(), *body2->getBody());
	
	const dReal *pos1 = body1->getBody()->getPosition();
	const dReal *pos2 = body2->getBody()->getPosition();
	
	dReal xAnchor = (*(pos1 + 0) + *(pos2 + 0))/2;
	dReal yAnchor = (*(pos1 + 1) + *(pos2 + 1))/2;
	dReal zAnchor = (*(pos1 + 2) + *(pos2 + 2))/2;
	
	ballJoint->setAnchor(xAnchor, yAnchor, zAnchor);
}

//
//
//
bool BoardBox::disableJoint(const QString& name)
{
	std::vector<std::pair<QString, BoardBody*> >::iterator it = m_Bodies.begin();
	
	while (it != m_Bodies.end()) {
		std::pair<QString, BoardBody*> body = *it;
		
		if (body.first == name) {
			// get joints on this body
			int numJoints = body.second->getBody()->getNumJoints();
			
			for (int i = 0; i < numJoints; ++i) {
				dJointID jointID = body.second->getBody()->getJoint(i);
				
				for(std::vector<dBallJoint*>::iterator  it = m_Joints.begin(); it < m_Joints.end(); ++it) {
					dBallJoint *ballJoint = *it;
					
					if (ballJoint->id() == jointID) {
						ballJoint->disable();
						break;
					}
				}
			}
			break;
		}
		++it;
	}

	return true;
}

//
//
//
bool BoardBox::enableJoint(const QString& name)
{
	std::vector<std::pair<QString, BoardBody*> >::iterator it = m_Bodies.begin();
	
	while (it != m_Bodies.end()) {
		std::pair<QString, BoardBody*> body = *it;
		
		if (body.first == name) {
			// get joints on this body
			int numJoints = body.second->getBody()->getNumJoints();
			
			for (int i = 0; i < numJoints; ++i) {
				dJointID jointID = body.second->getBody()->getJoint(i);
				
				for(std::vector<dBallJoint*>::iterator  it = m_Joints.begin(); it < m_Joints.end(); ++it) {
					dBallJoint *ballJoint = *it;
					
					if (ballJoint->id() == jointID) {
						ballJoint->enable();
						break;
					}
				}
			}
			break;
		}
		++it;
	}

	return true;
}

//
//
//
void BoardBox::setCurrentItem(const QString& item)
{
	for (size_t i = 0; i < m_Bodies.size(); ++i) {
		std::pair<QString, BoardBody*> body = m_Bodies[i];
		
		if (body.first == item) {
			body.second->setCurrentItem(true);
		}
		else {
			body.second->setCurrentItem(false);
		}
	}
}

//
//
//
void BoardBox::setWorldGravity(dReal x, dReal y, dReal z)
{
	m_World->setGravity(x, y, z);
}

//
//
//
void BoardBox::setStepSize(dReal stepSize)
{
	m_StepSize = stepSize;
}

//
//
//
void BoardBox::addForce(const QString& name, dReal x, dReal y, dReal z)
{
	for (size_t i = 0; i < m_Bodies.size(); ++i) {
		std::pair<QString, BoardBody*> body = m_Bodies[i];
		
		if (body.first == name) {
			body.second->addForce(x, y, z);
			break;
		}
	}
}

//
//
//
void BoardBox::setMass(const QString& name, dReal mass)
{
	for (size_t i = 0; i < m_Bodies.size(); ++i) {
		std::pair<QString, BoardBody*> body = m_Bodies[i];
		
		if (body.first == name) {
			body.second->setMass(mass);
			break;
		}
	}
}

//
//
//
void BoardBox::incStepSize()
{
	m_StepSize += 0.02;
}

//
//
//
void BoardBox::decStepSize()
{
	dReal stepSize = m_StepSize;
	
	stepSize -= 0.02;
	
	if (stepSize <= 0) stepSize = 0.1; // 0 is not allowed
	
	m_StepSize = stepSize;
}

//
//
//
bool BoardBox::removeBody(const QString& name)
{
	std::vector<std::pair<QString, BoardBody*> >::iterator it = m_Bodies.begin();
	
	while (it != m_Bodies.end()) {
		std::pair<QString, BoardBody*> body = *it;
		
		if (body.first == name) {
			// destroy this body
			dBodyDestroy(body.second->getBody()->id());
			m_Bodies.erase(it);
			break;
		}
		++it;
	}

	initJoints();
	
	return true;
}

//
//
//
void BoardBox::resetForce(const QString& name)
{
	for (size_t i = 0; i < m_Bodies.size(); ++i) {
		std::pair<QString, BoardBody*> body = m_Bodies[i];
		
		if (body.first == name) {
			body.second->resetForce();
			break;
		}
	}
}

//
//
//
void BoardBox::setPosition(const QString& name, dReal x, dReal y, dReal z)
{
	for (size_t i = 0; i < m_Bodies.size(); ++i) {
		std::pair<QString, BoardBody*> body = m_Bodies[i];
		
		if (body.first == name) {
			body.second->setPosition(x, y, z);
			break;
		}
	}
}

//
//
//
QString BoardBox::inspect(const QString& bodyName, const QString& inspectAttribute)
{
	for (size_t i = 0; i < m_Bodies.size(); ++i) {
		std::pair<QString, BoardBody*> body = m_Bodies[i];
		
		if (body.first == bodyName) {
			return body.second->inspect(inspectAttribute);
			break;
		}
	}
	
	return QString("");
}

//
//
//
void BoardBox::stop()
{
	for (size_t i = 0; i < m_Bodies.size(); ++i) {
		std::pair<QString, BoardBody*> body = m_Bodies[i];
		
		body.second->stop();
	}
}

//
//
//
void BoardBox::start()
{
	for (size_t i = 0; i < m_Bodies.size(); ++i) {
		std::pair<QString, BoardBody*> body = m_Bodies[i];
		
		body.second->start();
	}
}

//
//
//
void BoardBox::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                QWidget *widget)
{
   m_Space->collide(this, &BoardBox::nearCallback);
   m_World->step(m_StepSize);

   // Remove all contact joints
   m_JointGroup->empty();
   QRectF sceneRect;

	for (size_t i = 0; i < m_Bodies.size(); ++i) {
		std::pair<QString, BoardBody*> body = m_Bodies[i];
		
		painter->save();
		
		if (QGraphicsScene *s = scene()) {
			sceneRect = s->sceneRect();
		}
		
		body.second->drawBody(painter, option, sceneRect, m_ShowLabels, m_ShowJoints);
		
		painter->restore();
	}

	update();
}

//
//
//
BoardBox::~BoardBox()
{
	for (size_t i = 0; i < m_Bodies.size(); ++i) {
		std::pair<QString, BoardBody*> body = m_Bodies[i];
		
		delete body.second;
	}
	
	for (size_t i = 0; i < m_Joints.size(); ++i) {
		dBallJoint *ballJoint = m_Joints[i];

		delete ballJoint;
	}

	delete m_World;
	delete m_Space;
	delete m_JointGroup;
}

//
//
//
void BoardBox::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	Qt::MouseButton b = event->button();

#if 0
	if (b == Qt::LeftButton)
		m_World->setGravity (0.0, 0.0,0.0);

	if (b == Qt::RightButton)
		m_World->setGravity (0.0, 0.0,0.5);

	update();
#endif
	setCursor(Qt::OpenHandCursor);
}

//
//
//
void BoardBox::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	setCursor(Qt::ClosedHandCursor);
}

//
//
//
void BoardBox::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	if (QLineF(event->screenPos(), event->buttonDownScreenPos(Qt::LeftButton))
         .length() < QApplication::startDragDistance()) {
         return;
     }

     QDrag *drag = new QDrag(event->widget());
     QMimeData *mime = new QMimeData;
     drag->setMimeData(mime);
     
     QColor color(Qt::red);

     static int n = 0;
     if (n++ > 2 && (qrand() % 3) == 0) {
         QImage image("./images/BBCircle.png");
         
         mime->setImageData(image);

         drag->setPixmap(QPixmap::fromImage(image).scaled(30, 40));
         drag->setHotSpot(QPoint(15, 30));
     }
     else {
         mime->setColorData(QColor(255,0,0));
         mime->setText(QString("#%1%2%3")
                       .arg(color.red(), 2, 16, QLatin1Char('0'))
                       .arg(color.green(), 2, 16, QLatin1Char('0'))
                       .arg(color.blue(), 2, 16, QLatin1Char('0')));

         QPixmap pixmap(34, 34);
         pixmap.fill(Qt::white);

         QPainter painter(&pixmap);
         
         painter.translate(15, 15);
         painter.setRenderHint(QPainter::Antialiasing);
         paint(&painter, 0, 0);
         painter.end();

         pixmap.setMask(pixmap.createHeuristicMask());

         drag->setPixmap(pixmap);
         drag->setHotSpot(QPoint(15, 20));
     }

     drag->exec();
     setCursor(Qt::OpenHandCursor);
}

//
//
//
void BoardBox::nearCallback (void *data, dGeomID o1, dGeomID o2)
{
  // exit without doing anything if the two bodies are connected by a joint
  dBodyID b1 = dGeomGetBody(o1);
  dBodyID b2 = dGeomGetBody(o2);
  
  if (b1 && b2 && dAreConnected (b1,b2)) {
	return;
  }

  BoardBox *boardBox = reinterpret_cast<BoardBox*>(data);

  dContact contact;
  
  contact.surface.mode = 0;
  contact.surface.mu = dInfinity;
  
  if (dCollide (o1, o2, 1, &contact.geom,sizeof(dContactGeom))) {
    dJointID c = dJointCreateContact(boardBox->getWorld()->id(), boardBox->getJointGroup()->id(), &contact);
    
    dJointAttach(c, b1, b2);
  }
}
