//
//
#ifndef CMDWINDOW_H
#define CMDWINDOW_H

#include <QtGui/QTextEdit>

#define CMDWINDOWCURSOR "<b>&gt;</b> "
#define CMDWINDOWCURSORPLAIN "> "
#define CMDWINDOWPLAINCURSOR "> "

class CmdManager;
class Cmd;

//
//
class CmdWindow : public QTextEdit
{
	Q_OBJECT
public:
	CmdWindow(QWidget *parent = 0);
	~CmdWindow();

	//
	void init();
	//
	// Fix size
	QSize minimumSizeHint() const;
signals:
	void commandEntered(const Cmd&);
protected slots:
   void slotCommandResults(const QString&);
protected:
	bool eventFilter(QObject *obj, QEvent *event);
	void mouseReleaseEvent(QMouseEvent *e);

private:
	void showCursor();
	bool execute();
	
	CmdManager *m_CmdManager;
};

#endif // CMDWINDOW_H
