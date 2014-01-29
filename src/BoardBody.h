//
//
#ifndef BOARDBODY_H
#define BOARDBODY_H

#include <ode/ode.h>
#include <QtGui/QPixmap>
#include <QtGui/QPainter>
#include <QtGui/QStyleOption>

//
#define JOINTSIZE 4

class QPixmap;

//
//
class BoardBody
{
public:
	BoardBody(const QString& name, const QString& image = QString(""));
	~BoardBody();

	//
	void init(dWorld *world, dSpace *space);
	void addForce(dReal x, dReal y, dReal z);
	void setPosition(dReal x, dReal y, dReal z);
	void resetForce();
	void stop();
	void start();
	void setMass(dReal mass);
	
	dBox* getBox() const { return m_Box; }
	dBody* getBody() const { return m_Body; }
	//
	void drawBody(QPainter *painter, const QStyleOptionGraphicsItem *option,
		const QRectF& sceneRect, bool showLabels = true, bool showJoints = true);
	//
	QString inspect(const QString& inspectAttribute);
	//
	void setCurrentItem(bool current) { m_Current = current; }
	//
	const QString& name() { return m_Name; }
	const QString& image() { return m_Image; }
	void setName(const QString& name) { m_Name = name; }
	QString position() const;
	QString mass() const;

private:
	void drawJoints(dReal jX, dReal jY, QPainter *painter);
	void drawCurrent(dReal x, dReal y, dReal width, dReal height, QPainter *painter);
	void drawJointLine(dReal x1, dReal y1, dReal x2, dReal y2, QPainter *painter, bool enabled);
private:
	QString m_Name;
	QString m_Image;
	dBox *m_Box;
	dBody *m_Body;
	QPixmap m_Pixmap;
	dReal m_BoxSide;
	bool m_Current;
};

#endif // BOARDBODY_H
