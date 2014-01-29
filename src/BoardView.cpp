//
#include "BoardView.h"
#include "Cmd.h"
#include "BoardCmds.h"
#include "BoardScene.h"
#include "BoardStrip.h"
#include <QtGui/QGraphicsItem>
#include <QtGui/QResizeEvent>
#include <QtOpenGL/QGLWidget>

//
//
//
BoardView::BoardView(QWidget *parent)
	: QGraphicsView(parent), m_CurrentBoard(NULL), m_CurrentPosition(QPointF(10,10))
{
	// init commands
	init();
	this->setAcceptDrops(true);
	viewport()->setAcceptDrops(true);
}

//
//
//
BoardView::~BoardView()
{
	std::map<QString, BoardCmd*>::iterator it = m_Commands.begin();
	
	while (it != m_Commands.end()) {
		delete (*it).second;
		++it;
	}
	
	// TODO Remove board and models??
}

//
//
//
void BoardView::init()
{	
	// We listen to these commands
	m_Commands.insert(std::pair<QString, BoardCmd*>("rotate", new Rotate()));
	m_Commands.insert(std::pair<QString, BoardCmd*>("move", new Move()));
	m_Commands.insert(std::pair<QString, BoardCmd*>("rect", new Rect()));
	m_Commands.insert(std::pair<QString, BoardCmd*>("circle", new Circle()));
	m_Commands.insert(std::pair<QString, BoardCmd*>("pos", new Position()));
	m_Commands.insert(std::pair<QString, BoardCmd*>("group", new Group()));
	m_Commands.insert(std::pair<QString, BoardCmd*>("remove", new RemoveItem()));
	m_Commands.insert(std::pair<QString, BoardCmd*>("ungroup", new UnGroup()));
	m_Commands.insert(std::pair<QString, BoardCmd*>("clear", new Clear()));
	m_Commands.insert(std::pair<QString, BoardCmd*>("put", new Put()));
	m_Commands.insert(std::pair<QString, BoardCmd*>("setgrid", new SetGrid()));
	m_Commands.insert(std::pair<QString, BoardCmd*>("setgridsize", new SetGridSize()));
	m_Commands.insert(std::pair<QString, BoardCmd*>("setgridcolor", new SetGridColor()));
	m_Commands.insert(std::pair<QString, BoardCmd*>("fillcolor", new SetFillColor()));
	m_Commands.insert(std::pair<QString, BoardCmd*>("addbody", new BoxCmd()));
	m_Commands.insert(std::pair<QString, BoardCmd*>("removebody", new RemoveBody()));
	m_Commands.insert(std::pair<QString, BoardCmd*>("disablejoint", new DisableJoint()));
	m_Commands.insert(std::pair<QString, BoardCmd*>("enablejoint", new EnableJoint()));
	m_Commands.insert(std::pair<QString, BoardCmd*>("setgravity", new SetGravity()));
	m_Commands.insert(std::pair<QString, BoardCmd*>("setstepsize", new SetStepSize()));
	m_Commands.insert(std::pair<QString, BoardCmd*>("addforce", new AddForce()));
	m_Commands.insert(std::pair<QString, BoardCmd*>("addforcex", new AddForceX()));
	m_Commands.insert(std::pair<QString, BoardCmd*>("addforcey", new AddForceY()));
	m_Commands.insert(std::pair<QString, BoardCmd*>("addforcez", new AddForceZ()));
	m_Commands.insert(std::pair<QString, BoardCmd*>("resetforce", new ResetForce()));
	m_Commands.insert(std::pair<QString, BoardCmd*>("setposition", new SetPosition()));
	m_Commands.insert(std::pair<QString, BoardCmd*>("stop", new Stop()));
	m_Commands.insert(std::pair<QString, BoardCmd*>("start", new Start()));
	m_Commands.insert(std::pair<QString, BoardCmd*>("inspect", new Inspect()));
	m_Commands.insert(std::pair<QString, BoardCmd*>("setmass", new SetMass()));
	m_Commands.insert(std::pair<QString, BoardCmd*>("showlabels", new ShowLabels()));
	m_Commands.insert(std::pair<QString, BoardCmd*>("showjoints", new ShowJoints()));
	m_Commands.insert(std::pair<QString, BoardCmd*>("hidelabels", new HideLabels()));
	m_Commands.insert(std::pair<QString, BoardCmd*>("hidejoints", new HideJoints()));
	m_Commands.insert(std::pair<QString, BoardCmd*>("createjoint", new CreateJoint()));
	m_Commands.insert(std::pair<QString, BoardCmd*>("incstepsize", new IncStepSize()));
	m_Commands.insert(std::pair<QString, BoardCmd*>("decstepsize", new DecStepSize()));
}

//
//
//
void BoardView::slotCommandEntered(const Cmd& cmd)
{
	std::map<QString, BoardCmd*>::const_iterator it = m_Commands.find(cmd.name());
	QString result("Invalid Command");
	
	if (it != m_Commands.end()) {
		if (!(*it).second->execute(*this, cmd, result)) {
			emit commandResults(result);
		}
		else {
			if (!result.isEmpty()) emit commandResults(result);
		}
	}
	else {
		emit commandResults(result);
	}
}

//
//
//
void BoardView::addBoard(const QString& boardName)
{
	Q_ASSERT(!boardName.isEmpty());

	BoardModel *boardModel = new BoardModel(boardName, this);
	Board *board = new Board(boardName, boardModel, this);

	m_BoardCollection.insert(std::pair<Board*, BoardModel*>(board, boardModel));

	m_CurrentBoard = board;

	setScene(m_CurrentBoard);

}

//
//
//
void BoardView::removeBoard(const QString& boardName)
{
	Q_ASSERT(!boardName.isEmpty());

}

//
//
//
void BoardView::setCurrent(const QString& boardName)
{
	Q_ASSERT(!boardName.isEmpty());

	for (std::map<Board*, BoardModel*>::const_iterator it = m_BoardCollection.begin();
		it != m_BoardCollection.end(); ++it) {
		if ((*it).first->name() == boardName) {
			m_CurrentBoard = (*it).first;
			setScene(m_CurrentBoard);
			break;
		}
	}
}

//
//
//
void BoardView::resizeEvent(QResizeEvent *event)
{
	if (scene()) {
		scene()->setSceneRect(QRect(QPoint(0, 0), event->size()));
	}
    
	QGraphicsView::resizeEvent(event);
}

//
//
//
void BoardView::mouseReleaseEvent(QMouseEvent *event)
{
	m_CurrentPosition = event->pos();

	QGraphicsView::mouseReleaseEvent(event);
}

//
//
//
void BoardView::addScene(const QString& boardName)
{
	Q_ASSERT(!boardName.isEmpty());

	setViewport(new QGLWidget(QGLFormat(QGL::SampleBuffers)));
	setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

	BoardModel *boardModel = new BoardModel(boardName, this);
	BoardScene *board = new BoardScene(boardName, boardModel, this);

	m_BoardCollection.insert(std::pair<Board*, BoardModel*>(board, boardModel));

	m_CurrentBoard = board;

	setScene(m_CurrentBoard);
	
	resizeEvent(new QResizeEvent(size(), size()));
}

//
//
//

void BoardView::dragLeaveEvent(QDragLeaveEvent *event)
{
    /*SourceWidget *source = qobject_cast<SourceWidget *>(event->source());
    
    if (source) {
        event->setDropAction(Qt::CopyAction);
        event->accept();
    }*/
}

//
//
//

void BoardView::dragEnterEvent(QDragEnterEvent *event)
{
    /*SourceWidget *source = qobject_cast<SourceWidget *>(event->source());
    
    if (source) {
        event->setDropAction(Qt::CopyAction);
        event->accept();
    }*/
    
    event->accept();
}

//
//
//
void BoardView::dragMoveEvent(QDragMoveEvent *event)
{/*
    SourceWidget *source = qobject_cast<SourceWidget *>(event->source());
    
    if (source) {
        event->setDropAction(Qt::CopyAction);
        event->accept();
    }*/
	//QGraphicsView::dragMoveEvent(event);
	event->accept();
}

//
//
//
void BoardView::dropEvent(QDropEvent *event)
{
    BoardStrip *source = qobject_cast<BoardStrip *>(event->source());
    
    if (source) {
		  const QMimeData *mimeData = event->mimeData();
		  
        std::map<QString, BoardCmd*>::const_iterator it = m_Commands.find("addbody");
        
        if (it != m_Commands.end()) {
				BoardCmd *cmd = (*it).second;
				Cmd cmdObj("","addbody");
				
				CmdArg arg1("bodyname", "ball");
				CmdArg arg2("imagepath", "./images/BBCircle.png");

				cmdObj.addArg(arg1);
				cmdObj.addArg(arg2);
				
				QString result("");
				
				m_CurrentPosition = event->pos();
				
				cmd->execute(*this, cmdObj, result);
        
			  event->accept();
        }
    }
    QGraphicsView::dropEvent(event);
}
