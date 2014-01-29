//
#include "ContentPanel.h"
#include "ObjectPanel.h"
#include "BoardPanel.h"
#include "BoardView.h"
#include "Board.h"
#include "BoardModel.h"
#include "BoardItem.h"
#include "BoardBox.h"

//
//
//
ContentPanel::ContentPanel(QWidget *parent)
	: QSplitter(Qt::Horizontal, parent)
{
	m_ObjectPanel = new ObjectPanel(this);
	
	addWidget(m_ObjectPanel);
	
	m_BoardPanel = new BoardPanel(this);
	
	addWidget(m_BoardPanel);
	
	QList<int> initSize;
	//
	initSize.push_back(m_ObjectPanel->minimumSizeHint().width());
	initSize.push_back(m_BoardPanel->maximumWidth());
	//
	setSizes(initSize);
}

//
//
//
ContentPanel::~ContentPanel()
{
}

//
//
//
void ContentPanel::init()
{
	connect(m_BoardPanel, SIGNAL(boardChanged(const BoardPanel&)), m_ObjectPanel, SLOT(slotBoardChanged(const BoardPanel&)));
	// Init contained widgets
	m_BoardPanel->init();
}
