//
//
#ifndef TOOLBOXVIEW_H
#define TOOLBOXVIEW_H

#include <QtGui/QGraphicsView>

//
//
class ToolBoxView : public QGraphicsView
{
	Q_OBJECT
public:
	ToolBoxView(QWidget *parent = 0);
	~ToolBoxView();
	void init();
};

#endif // TOOLBOXVIEW_H
