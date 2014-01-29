//
//
#ifndef BLACKBOARDAPP_H
#define BLACKBOARDAPP_H

#include "BlackBoard.h"
#include <QtGui/QMainWindow>

//
class MainPanel;

//
//
class BlackBoardApp : public QMainWindow
{
	Q_OBJECT
public:
	BlackBoardApp(QWidget *parent = 0);
	~BlackBoardApp();

	//
	void init();
protected:
	void closeEvent(QCloseEvent *e);
	
private:
	MainPanel *m_mainPanel;
};
#endif // BLACKBOARDAPP_H
