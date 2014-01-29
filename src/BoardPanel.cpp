//
#include "BoardPanel.h"
#include "BoardView.h"
#include "Board.h"
#include "TabBarPanel.h"
#include "BoardPanelCmds.h"
#include "CmdWindow.h"
#include "Cmd.h"
#include "BoardScene.h"
#include "BoardStrip.h"
#include <QtOpenGL/QGLWidget>

//
//
//
BoardPanel::BoardPanel(QWidget *parent)
	: QSplitter(Qt::Vertical, parent)
{
	m_TabPanel = new TabBarPanel(this);

	addWidget(m_TabPanel);
	
	m_CmdView = new CmdWindow(this);
	
	m_CmdView->init();
	
	m_BoardStrip = new BoardStrip(this);

	m_BoardStrip->init();
	
	addWidget(m_TabPanel->boardView());
	addWidget(m_BoardStrip);
	addWidget(m_CmdView);
	
	QList<int> initSize;
	
	initSize.push_back(m_TabPanel->minimumSizeHint().height());
	initSize.push_back(m_TabPanel->maximumHeight());
	initSize.push_back(m_BoardStrip->minimumSizeHint().height());
	initSize.push_back(m_CmdView->minimumSizeHint().height());
	
	setSizes(initSize);
}

//
//
//
void BoardPanel::init()
{
	m_Commands.insert(std::pair<QString, BoardPanelCmd*>("addboard", new AddBoard()));
	m_Commands.insert(std::pair<QString, BoardPanelCmd*>("removeboard", new RemoveBoard()));
	m_Commands.insert(std::pair<QString, BoardPanelCmd*>("selectboard", new SelectBoard()));
	m_Commands.insert(std::pair<QString, BoardPanelCmd*>("addscene", new AddScene()));
	
	connect(m_TabPanel, SIGNAL(currentChanged(int)), this, SLOT(slotTabChanged(int)));
	connect(m_CmdView, SIGNAL(commandEntered(const Cmd&)), this, SLOT(slotCommandEntered(const Cmd&)));
	connect(m_CmdView, SIGNAL(commandEntered(const Cmd&)), m_TabPanel->boardView(), SLOT(slotCommandEntered(const Cmd&)));
	connect(m_TabPanel->boardView(), SIGNAL(commandResults(const QString&)), m_CmdView, SLOT(slotCommandResults(const QString&)));
	connect(m_BoardStrip, SIGNAL(stripCommandEntered(const Cmd&)), m_TabPanel->boardView(), SLOT(slotCommandEntered(const Cmd&)));

	//
	addScene("Untitled1");
	
	// initialize strip
	Q_ASSERT(m_BoardStrip);
	Q_ASSERT(m_TabPanel);
	
	m_BoardStrip->setStripItems(m_TabPanel->currentBoard()->getStripItems());
}

//
//
//
void BoardPanel::slotCommandEntered(const Cmd& cmd)
{
	std::map<QString, BoardPanelCmd*>::const_iterator it = m_Commands.find(cmd.name());
	QString result("Invalid Command");
	
	if (it != m_Commands.end()) {
		if (!(*it).second->execute(*this, cmd, result)) {
			emit commandResults(result);
		}
		
		if (!result.isEmpty()) emit commandResults(result);
	}
	else {
		emit commandResults(result);
	}
}

//
//
//
void BoardPanel::slotTabChanged(int index)
{
	std::map<int,QString>::const_iterator it = m_Tabs.find(index);

	if (it != m_Tabs.end()) {
		m_TabPanel->boardView()->setCurrent((*it).second);

		emit boardChanged(*this);
	}
}

//
//
//
Board* BoardPanel::currentBoard() const
{ 
	return m_TabPanel->currentBoard(); 
}

//
//
//
BoardPanel::~BoardPanel()
{
}

//
//
//
void BoardPanel::addBoard(const QString& boardName)
{
	Q_ASSERT(!boardName.isEmpty());
	Q_ASSERT(m_TabPanel);
	Q_ASSERT(m_TabPanel->boardView());

	m_TabPanel->boardView()->addBoard(boardName);

	// TODO if sucessful add
	int index = m_TabPanel->addTab(boardName);

	m_Tabs.insert(std::pair<int, QString>(index, boardName));

	m_TabPanel->setCurrentIndex(index);
	// First time it does not happen
	emit boardChanged(*this);
}

//
//
//
void BoardPanel::removeBoard(const QString& boardName)
{
	Q_ASSERT(!boardName.isEmpty());
	Q_ASSERT(m_TabPanel);
	Q_ASSERT(m_TabPanel->boardView());

	m_TabPanel->boardView()->removeBoard(boardName);
}


//
//
//
void BoardPanel::selectBoard(const QString& boardName)
{
	Q_ASSERT(!boardName.isEmpty());
	Q_ASSERT(m_TabPanel);
	Q_ASSERT(m_TabPanel->boardView());

	for (std::map<int, QString>::const_iterator it = m_Tabs.begin();
		it != m_Tabs.end(); ++it ) {
		if ((*it).second == boardName) {
			m_TabPanel->setCurrentIndex((*it).first);
		}
	}
}

//
//
//
void BoardPanel::addScene(const QString& boardName)
{
	Q_ASSERT(!boardName.isEmpty());
	Q_ASSERT(m_TabPanel);
	Q_ASSERT(m_TabPanel->boardView());

	m_TabPanel->boardView()->addScene(boardName);

	// TODO if sucessful add
	int index = m_TabPanel->addTab(boardName);

	m_Tabs.insert(std::pair<int, QString>(index, boardName));

	m_TabPanel->setCurrentIndex(index);
	
	// First time it does not happen
	emit boardChanged(*this);
}
