
//
#include "BlackBoardPanelScene.h"
#include <QtGui/QGraphicsObject>
#include <QtDeclarative/QDeclarativeEngine>
#include <QtDeclarative/QDeclarativeComponent>

//
//
//
BlackBoardPanelScene::BlackBoardPanelScene(QObject *parent)
	: QGraphicsScene(parent)
{
#if 0	
	QDeclarativeEngine *engine = new QDeclarativeEngine;
	
	QDeclarativeComponent component(engine, QUrl::fromLocalFile("./ui/application.qml"));
	
	QString errStr = component.errorString();
	
	QGraphicsObject *graphicsObject =  qobject_cast<QGraphicsObject *>(component.create());
	
	addItem(graphicsObject);
#endif
}


//
//
//
BlackBoardPanelScene::~BlackBoardPanelScene()
{
	
}

