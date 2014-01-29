//
//
#ifndef TABBARPANEL_H
#define TABBARPANEL_H

#include <QtGui/QTabBar>
#include <map>

//
class BoardView;
class Board;

//
//
class TabBarPanel : public QTabBar
{
	Q_OBJECT
public:
	TabBarPanel(QWidget *parent = 0);
	~TabBarPanel();

	//
	void init();
	// Fix size
	QSize minimumSizeHint() const;
	//
	BoardView *boardView() { return m_BoardView; }
	Board* currentBoard();
private:
	BoardView *m_BoardView;
};

#endif // TABBARPANEL_H
