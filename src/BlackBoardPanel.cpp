//
#include "BlackBoardPanel.h"
#include "BlackBoardPanelScene.h"
#include <QtGui/QResizeEvent>

//
//
//
BlackBoardPanel::BlackBoardPanel(QWidget *parent)
	: QGraphicsView(parent)
{
	setAutoFillBackground(true);
	setMaximumHeight(128);
	
	QSizePolicy szPolicy = sizePolicy();
	
	szPolicy.setVerticalPolicy(QSizePolicy::Fixed);
	
	setSizePolicy(szPolicy);
	
	m_Scene = new BlackBoardPanelScene(this);
	
	setScene(m_Scene);
}

//
//
//
QSize BlackBoardPanel::minimumSizeHint() const
{
	return QSize(0, 5*16);
}

//
//
//
void BlackBoardPanel::resizeEvent(QResizeEvent *event)
{
	if (scene()) {
		scene()->setSceneRect(QRect(QPoint(2, 2), event->size()));
	}
    
	QGraphicsView::resizeEvent(event);
}
