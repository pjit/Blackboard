//
#include "ToolBoxView.h"
#include <QtGui/QGraphicsItem>
#include <QtGui/QGraphicsScene>

//
//
//
ToolBoxView::ToolBoxView(QWidget *parent)
	: QGraphicsView(parent)
{
	this->setAutoFillBackground(true);
}

//
//
//
ToolBoxView::~ToolBoxView()
{
}

//
//
//
void ToolBoxView::init()
{
	QGraphicsScene *toolBoxScene = new QGraphicsScene(this);

	QGraphicsPixmapItem *item1 = toolBoxScene->addPixmap(QPixmap(QString("./images/BBCircle.png")));

	item1->setPos(0,0);
	item1->setFlags(QGraphicsItem::ItemIsSelectable);

	QGraphicsPixmapItem *item2 = toolBoxScene->addPixmap(QPixmap(QString("./images/BBRect.png")));

	item2->setPos(64,64);
	item2->setFlags(QGraphicsItem::ItemIsSelectable);

	setScene(toolBoxScene);
}

