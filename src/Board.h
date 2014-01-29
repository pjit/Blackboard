//
//
#ifndef BOARD_H
#define BOARD_H

#include <QtGui/QGraphicsScene>

class QGraphicsItemGroup;
class BoardModel;
class QGraphicsObject;
class BoardBox;

//
//
class Board : public QGraphicsScene
{
	Q_OBJECT
public:
	Board(const QString& name, BoardModel *model, QObject *parent = 0);
	~Board();

	//
	void Init();
	
	//
	void drawBackground(QPainter *painter, const QRectF &rect);
	//
	void setGrid(bool draw) { m_DrawGrid = draw; }
	void setGridSize(int size) { m_GridSize = size; }
	void setGridColor(const QColor& color) { m_GridColor = color; }
	//
	void group();
	void ungroup();
	//
	BoardModel* model() { return m_Model; }
	const QString& name() { return m_Name; }
	//
	void setDialog(QGraphicsObject *dialog);
	//
	void setCurrentBox(BoardBox* box) { m_CurrentBox = box; }
	BoardBox* getCurrentBox() { return m_CurrentBox; }
	//
	QList<QGraphicsItem*> getStripItems();
	
protected:
	void keyReleaseEvent(QKeyEvent *e);
	
private:
	QGraphicsItemGroup *m_Group; // Create collection of groups
	int m_GridSize;
	QColor m_GridColor;
	bool m_DrawGrid;
	BoardModel *m_Model;
	QString m_Name;
	BoardBox *m_CurrentBox;
	QList<QGraphicsItem *> m_StripItems;
};

#endif // BOARD_H
