//
//
#ifndef BLACKBOARDPANEL_H
#define BLACKBOARDPANEL_H

#include <QtGui/QGraphicsView>


class BlackBoardPanelScene;

//
//
class BlackBoardPanel : public QGraphicsView
{
	Q_OBJECT
public:
	BlackBoardPanel(QWidget *parent = 0);
	~BlackBoardPanel() {}
	
	QSize minimumSizeHint() const;
	void resizeEvent(QResizeEvent *event);
private:
	BlackBoardPanelScene *m_Scene;
};

#endif // BLACKBOARDPANEL_H
