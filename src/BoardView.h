
//
//
#ifndef BOARDVIEW_H
#define BOARDVIEW_H

#include <QtGui/QGraphicsView>
#include <map>
#include "BoardModel.h"
#include "Board.h"

//
class Cmd;
class BoardCmd;

//
//
class BoardView : public QGraphicsView
{
	Q_OBJECT
public:
	BoardView(QWidget *parent = 0);
	~BoardView();

	//
	void init();
	//
	Board* board() const { return m_CurrentBoard; }
	BoardModel* model() const { return m_CurrentBoard->model(); }
	//
	void addBoard(const QString& boardName);
	void removeBoard(const QString& boardName);
	void setCurrent(const QString& boardName);
	void addScene(const QString& boardName);
	//
	QPointF getCurrentPosition() const { return m_CurrentPosition; }
signals:
	void commandResults(const QString&);
	
protected slots:
	void slotCommandEntered(const Cmd&);
protected:
	// OpenGL support
    void resizeEvent(QResizeEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
   void dragLeaveEvent(QDragLeaveEvent *event);
   void dragMoveEvent(QDragMoveEvent *event);
   void dropEvent(QDropEvent *event);
private:
	std::map<Board*, BoardModel*> m_BoardCollection;
	// Commands for board view
	std::map<QString, BoardCmd*> m_Commands;
	Board* m_CurrentBoard;
	// temp hack
	QPointF m_CurrentPosition;
};

#endif // BOARDVIEW_H
