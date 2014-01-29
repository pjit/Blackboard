//
//
#ifndef BOARDSTRIPPANEL_H
#define BOARDSTRIPPANEL_H

#include <QtGui/QGraphicsView>
#include <QtCore/QList>

class QGraphicsScene;
class QGraphicsItem;
class Cmd;

//
//
class BoardStrip : public QGraphicsView
{
	Q_OBJECT
public:
	enum {
	   kStripItemName,
		kStopItemCommand,
		kStopItemImage,
		kStopItemImagePress,
		kPlayItemCommand,
		kPlayItemImage,
		kPlayItemImagePress,
		kIncStepSizeCommand,
		kIncStepSizeImage,
		kIncStepSizeImagePress,
		kDecStepSizeCommand,
		kDecStepSizeImage,
		kDecStepSizeImagePress,
		kLabelsCommand,
		kLabelsImage,
		kLabelsImagePress,
		kJointsCommand,
		kJointsImage,
		kJointsImagePress
	};
	BoardStrip(QWidget *parent = 0);
	~BoardStrip() {}
	
	void init();
	QSize minimumSizeHint() const;
	void resizeEvent(QResizeEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void dragEnterEvent(QDragEnterEvent *event);
   void dragLeaveEvent(QDragLeaveEvent *event);
   void dragMoveEvent(QDragMoveEvent *event);
   void dropEvent(QDropEvent *event);
	//
	void setStripItems(const QList<QGraphicsItem*>& items);
signals:
	void stripCommandEntered(const Cmd&);

private:
	void execCommand(const QString& cmdStr);
private:
	QGraphicsScene *m_StripScene;
	QPoint m_MousePressPosition;
	bool m_ItemDrag;
};

#endif // BOARDSTRIPPANEL_H
