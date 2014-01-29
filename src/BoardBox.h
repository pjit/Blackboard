//
//
#ifndef BOARDBOX_H
#define BOARDBOX_H

#include <QtGui/QGraphicsItem>
#include <ode/ode.h>
#include <vector>
#include <map>

//
//
class QGraphicsItem;
class QGraphicsObject;
class BoardBody;

//
//
class BoardBox : public QGraphicsItem
{
public:
	BoardBox(QGraphicsItem *parent = 0);
	~BoardBox();
	//
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                QWidget *widget);
   //
   static void nearCallback(void *data, dGeomID o1, dGeomID o2);
   //
   void setWorldGravity(dReal x, dReal y, dReal z);
   void setStepSize(dReal stepSize);
   void stop();
   void start();
   BoardBody *addBody(const QString& name, const QString& image, const QPointF& p = QPointF(10,10));
   bool removeBody(const QString& name);
   bool disableJoint(const QString& name);
   bool enableJoint(const QString& name);
   void addForce(const QString& bodyName, dReal x, dReal y, dReal z);
   void resetForce(const QString& name);
   void setPosition(const QString& bodyName, dReal x, dReal y, dReal z);
   void setMass(const QString& name, dReal mass);
   void incStepSize();
   void decStepSize();
   //
   QString inspect(const QString& bodyName, const QString& inspectAttribute);
   void showLabels(bool show) { m_ShowLabels = show; }
   void showJoints(bool show) { m_ShowJoints = show; }
   void createJoint(const QString& bodyName1, const QString& bodyName2);
   //
   dWorld* getWorld() const { return m_World; }
   dJointGroup* getJointGroup() const { return m_JointGroup; }
   //
   void setCurrentItem(const QString& item);
protected:
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
   void mousePressEvent(QGraphicsSceneMouseEvent *event);
   void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
private:
	dBody *getBody(const QString& name);
	void initJoints();
	bool bodyExists(const QString& name);
	void createJoint(const BoardBody*, const BoardBody*);
private:
	dWorld *m_World;
	dHashSpace *m_Space;
	dJointGroup *m_JointGroup;
	dReal m_StepSize;
	
	//
	bool m_ShowLabels;
	bool m_ShowJoints;
	
	typedef std::vector<std::pair<QString, BoardBody*> > Bodies;
	
	Bodies m_Bodies;
	std::vector<dBallJoint*> m_Joints;
};

#endif // BOARDBOX_H
