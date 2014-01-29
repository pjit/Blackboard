//
//
#ifndef BOARDPANEL_H
#define BOARDPANEL_H

#include <QtGui/QSplitter>
#include <map>

class CmdWindow;
class TabBarPanel;
class BoardPanelCmd;
class Cmd;
class Board;
class BoardStrip;

//
//
class BoardPanel : public QSplitter
{
	Q_OBJECT
public:
	BoardPanel(QWidget *parent = 0);
	~BoardPanel();
	//
	void init();
	void addBoard(const QString& boardName);
	void removeBoard(const QString& boardName);
	void selectBoard(const QString& boardName);
	void addScene(const QString& boardName);
	Board* currentBoard() const;
signals:
	void commandResults(const QString&);
	void boardChanged(const BoardPanel&);

protected slots:
	void slotCommandEntered(const Cmd&);
	void slotTabChanged(int index);
private:
	TabBarPanel *m_TabPanel;
	BoardStrip *m_BoardStrip;
	CmdWindow *m_CmdView;
	// Commands for board view
	std::map<QString, BoardPanelCmd*> m_Commands;
	std::map<int, QString> m_Tabs;
};

#endif // BOARDPANEL_H
