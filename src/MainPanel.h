//
//
#ifndef MAINPANEL_H
#define MAINPANEL_H

#include <QtGui/QWidget>

class ContentPanel;
class BlackBoardPanel;

//
//
class MainPanel : public QWidget
{
	Q_OBJECT
public:
	MainPanel(QWidget *parent = 0);
	~MainPanel();

	//
	void init();
private:
	ContentPanel *m_ContentPanel;
	BlackBoardPanel *m_BBPanel;
};

#endif // MAINPANEL_H
