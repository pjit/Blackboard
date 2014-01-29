//
#include "TabBarPanel.h"
#include "BoardView.h"
#include "Board.h"

//
//
//
TabBarPanel::TabBarPanel(QWidget *parent)
	: QTabBar(parent)
{
	m_BoardView = new BoardView(this);
}

//
//
//
TabBarPanel::~TabBarPanel()
{
}

//
//
//
void TabBarPanel::init()
{
}

//
//
//
Board* TabBarPanel::currentBoard()
{ 
	Q_ASSERT(m_BoardView);

	return m_BoardView->board(); 
}

//
//
//
QSize TabBarPanel::minimumSizeHint() const
{
	// TODO: Calculate from contents
	return QSize(0, 12);
}
