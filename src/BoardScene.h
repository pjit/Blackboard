//
//
#ifndef BOARDSCENE_H
#define BOARDSCENE_H

#include "Board.h"
#include <QtGui/QGraphicsSceneEvent>

//
//
class BoardScene : public Board
{
	Q_OBJECT
public:
	BoardScene(const QString& name, BoardModel *model, QObject *parent = 0);
	~BoardScene();
	
	//
	void drawBackground(QPainter *painter, const QRectF &rect);
	//
private:
	void drawRuler(int location, const QRectF &rect);
	void drawBoundary(const QRectF &rect);
};
#endif // BOARDSCENE_H
