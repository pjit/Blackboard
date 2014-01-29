//
#include "BoardBody.h"
#include <QtGui/QPixmap>
#include <QtGui/QApplication>
#include <QtOpenGL/QGLWidget>

//
//
//
BoardBody::BoardBody(const QString& name, const QString& image)
	: m_Name(name), m_Box(NULL), m_Body(NULL), m_Image(image)
{
	m_Pixmap = QPixmap("./images/BBCircle.png");
	
	if (!image.isEmpty()) {
		m_Pixmap = QPixmap(image);
		
		if (m_Pixmap.isNull()) {
			m_Pixmap = QPixmap("./images/BBCircle.png");
		}
	}
	m_BoxSide = 10.0;
	m_Current = false;
}

//
//
//
void BoardBody::init(dWorld *world, dSpace *space)
{
	m_Body = new dBody();

	m_Body->create(world->id());
	
	setMass(1.0);

	m_Box = new dBox;

	m_Box->create(space->id(), m_BoxSide, m_BoxSide, m_BoxSide);
	m_Box->setBody(*m_Body);
	
	stop();
}


//
//
//
void BoardBody::addForce(dReal x, dReal y, dReal z)
{
	m_Body->addForce(x, y, z);
}

//
//
//
void BoardBody::setPosition(dReal x, dReal y, dReal z)
{
	m_Body->setPosition(x - m_BoxSide, y - m_BoxSide, z);
}

//
//
//
void BoardBody::setMass(dReal mass)
{
	if (mass > 0) {
		Q_ASSERT(m_Body);
		dMass m;

		m.setBox(1, m_BoxSide, m_BoxSide, m_BoxSide);
		m.adjust(mass);

		m_Body->setMass(&m);
	}
}

//
//
//
void BoardBody::resetForce()
{
	m_Body->setForce(0, 0, 0);
}

//
//
//
QString BoardBody::inspect(const QString& inspectAttribute)
{
	QString result("");
	dReal xVal = 0.0;
	dReal yVal = 0.0;
	dReal zVal = 0.0;
	
	if (inspectAttribute == "force" || inspectAttribute == "f" ) {
		const dReal *attrValue = m_Body->getForce();
		
		xVal = *(attrValue + 0);
		yVal = *(attrValue + 1);
		zVal = *(attrValue + 2);
		
		result = QString("x: %1 y: %2 z: %3").arg(xVal).arg(yVal).arg(zVal);
	}
	
	if (inspectAttribute == "position" || inspectAttribute == "p") {
		const dReal *attrValue = m_Body->getPosition();
		
		xVal = *(attrValue + 0);
		yVal = *(attrValue + 1);
		zVal = *(attrValue + 2);
		
		result = QString("x: %1 y: %2 z: %3").arg(xVal).arg(yVal).arg(zVal);
	}
	
	if (inspectAttribute == "linearvelocity" || inspectAttribute == "lv") {
		const dReal *attrValue = m_Body->getLinearVel();
		
		xVal = *(attrValue + 0);
		yVal = *(attrValue + 1);
		zVal = *(attrValue + 2);
		
		result = QString("x: %1 y: %2 z: %3").arg(xVal).arg(yVal).arg(zVal);
	}
	
	if (inspectAttribute == "mass" || inspectAttribute == "m") {
		dMass m = m_Body->getMass();

		dReal massVal = m.mass;

		result = QString("mass: %1").arg(massVal);
	}
	
	return result;
}

//
//
//
void BoardBody::stop()
{
	m_Body->disable();
}

//
//
//
void BoardBody::start()
{
	m_Body->enable();
}

//
//
//
void BoardBody::drawBody(QPainter *painter, const QStyleOptionGraphicsItem *option,
	const QRectF& sceneRect, bool showLabels, bool showJoints)
{
#if 0
	glPushAttrib(GL_CURRENT_BIT);
#endif
	const dReal *p = m_Body->getPosition();
	const dReal *r = m_Body->getRotation();

	dReal p1 = *(p + 0);
	dReal p2 = *(p + 1);
	dReal p3 = *(p + 2);

	dReal r1 = *(r + 0);
	dReal r2 = *(r + 1);
	dReal r3 = *(r + 2);

	int w = m_Pixmap.width();
	int h = m_Pixmap.height();
	
	if ((p1 + w) > sceneRect.width()) m_Body->addForce(-1, 0, 0);
	if (p1 < sceneRect.x()) m_Body->addForce(1, 0, 0);
	
	if ((p2 + h) > sceneRect.height()) m_Body->addForce(0, -1, 0);
	if (p2 < sceneRect.y()) m_Body->addForce(0, 1, 0);

	painter->drawPixmap(p1, p2, m_Pixmap);
	if (m_Current) {
		drawCurrent(p1, p2, w, h, painter);
	}
	
	if (showJoints) {
		int numJoints = m_Body->getNumJoints();
		
		for (int i = 0; i < numJoints; ++i) {
			dJointID jointId = m_Body->getJoint(i);
			dReal j1 = -1;
			dReal j2 = -1;
			bool enabled = dJointIsEnabled(jointId) == 1;
		
			if (jointId) {
				dVector3 result;

				dJointGetBallAnchor(jointId, result);
			
				j1 = result[0];
				j2 = result[1];
			}
		
			if (j1 != -1 && j2 != -1) {
				drawJoints(j1, j2, painter);
				drawJointLine(p1 + (w/2), p2 + (h/2), j1, j2, painter, enabled);
			}
		}
	}

	if (showLabels) {
		// don't do it for every body
		QFontMetrics fontMetrics = QApplication::fontMetrics();

		// top center
		painter->drawText(p1 + (w/2.0) - fontMetrics.width(m_Name)/2, p2, QString("%1").arg(m_Name));
	}
#if 0
	glPopAttrib();
#endif
}

//
//
//
void BoardBody::drawCurrent(dReal x, dReal y, dReal width, dReal height, QPainter *painter)
{
	painter->save();

	QBrush brush(Qt::DotLine);
	
	brush.setColor(Qt::red);
	
	QPen pen(Qt::DotLine);
	
	pen.setColor(Qt::red);
	
	painter->setPen(pen);
	painter->drawRect(x - 2, y - 2, width + 4, height + 4);
	painter->restore();
}

//
//
//
void BoardBody::drawJoints(dReal jX, dReal jY, QPainter *painter)
{
	painter->save();

	QPainterPath circlePath;
	
	circlePath.moveTo(jX + 2, jY + 2);
	circlePath.arcTo(jX - 2, jY - 2, JOINTSIZE, JOINTSIZE, 0.0, 360.0);

	QBrush brush(Qt::SolidPattern);
	
	brush.setColor(Qt::red);
	
	painter->setBrush(brush);

	painter->drawPath(circlePath);
	painter->restore();
}

//
//
//
void BoardBody::drawJointLine(dReal x1, dReal y1, dReal x2, dReal y2, QPainter *painter, bool enabled)
{
	painter->save();
	
	QPen pen(Qt::SolidPattern);

	pen.setColor(enabled ? Qt::black : Qt::gray);

	painter->setPen(pen);
	painter->drawLine(x1, y1, x2, y2);
#if 0
	if (!enabled) {
			glColor3f(1.0,0.0,0.0);
		}
	glBegin(GL_LINES);
		glVertex2i(x1, y1);
		glVertex2i(x2, y2);
	glEnd();
#endif
	painter->restore();
}

//
//
//
BoardBody::~BoardBody()
{
	delete m_Box;
	delete m_Body;
}

//
//
//
QString BoardBody::position() const
{
	const dReal *p = m_Body->getPosition();

	dReal p1 = *(p + 0);
	dReal p2 = *(p + 1);
	dReal p3 = *(p + 2);

	return QString("%1 %1 %1").arg(p1).arg(p2).arg(p3);
}

//
//
//
QString BoardBody::mass() const
{
	dMass m = m_Body->getMass();

	return QString("%1").arg(m.mass);
}
