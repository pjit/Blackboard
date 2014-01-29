//
#include "Board.h"
#include "Utility.h"
#include "PrefManager.h"
#include "BoardModel.h"
#include "BoardBox.h"
#include "BoardStrip.h"
#include <QtGui/QPainter>
#include <QtGui/QGraphicsItemGroup>
#include <QtCore/QVariant>
#include <QtGui/QKeyEvent>
#include <QtOpenGL/QGLWidget>
#include <QtGui/QLayout>
#include <QtGui/QGraphicsObject>

//
//
//
Board::Board(const QString& name, BoardModel *boardmodel, QObject *parent)
	: QGraphicsScene(parent), m_Group(NULL), m_GridSize(30), m_DrawGrid(true),
	m_Model(boardmodel), m_Name(name), m_CurrentBox(NULL)
{
	QVariant drawGrid = PrefManager::get().readValue("drawGrid");
	
	if (!drawGrid.isNull()) {
		m_DrawGrid = drawGrid.toString() == "ON";
	}
	
	QVariant gridSize = PrefManager::get().readValue("gridSize");
	
	if (!gridSize.isNull()) {
		m_GridSize = gridSize.toInt() != 0 ? gridSize.toInt() : m_GridSize;
	}
	
	m_GridColor = QColor(200, 200, 255, 125);
	
	QVariant gridColor = PrefManager::get().readValue("gridColor");
	
	if (!gridColor.isNull()) {
		m_GridColor = gridColor.value<QColor>();
	}
	
	Init();
}


//
//
//
Board::~Board()
{
	for (int i = 0; i < m_StripItems.size(); ++i) {
		delete m_StripItems[i];
	}
}

//
//
//
void Board::Init()
{
	// Init UI
	
	QGraphicsPixmapItem *stopItem = new QGraphicsPixmapItem(QPixmap("./images/Stop.png"));
	
	stopItem->setData(BoardStrip::kStopItemCommand, "stop");
	stopItem->setData(BoardStrip::kStopItemImage, "./images/Stop.png");
	stopItem->setData(BoardStrip::kStopItemImagePress, "./images/StopPress.png");
	
	QGraphicsPixmapItem *playItem = new QGraphicsPixmapItem(QPixmap("./images/Play.png"));
	
	playItem->setData(BoardStrip::kPlayItemCommand, "start");
	playItem->setData(BoardStrip::kPlayItemImage, "./images/Play.png");
	playItem->setData(BoardStrip::kPlayItemImagePress, "./images/PlayPress.png");
	
	QGraphicsPixmapItem *incStepSize = new QGraphicsPixmapItem(QPixmap("./images/StepSizePlus.png"));
	
	incStepSize->setData(BoardStrip::kIncStepSizeCommand, "incstepsize");
	incStepSize->setData(BoardStrip::kIncStepSizeImage, "./images/StepSizePlus.png");
	incStepSize->setData(BoardStrip::kIncStepSizeImagePress, "./images/StepSizePlusPress.png");
	
	QGraphicsPixmapItem *decStepSize = new QGraphicsPixmapItem(QPixmap("./images/StepSizeMinus.png"));
	
	decStepSize->setData(BoardStrip::kDecStepSizeCommand, "decstepsize");
	decStepSize->setData(BoardStrip::kDecStepSizeImage, "./images/StepSizeMinus.png");
	decStepSize->setData(BoardStrip::kDecStepSizeImagePress, "./images/StepSizeMinusPress.png");
	
		
	QGraphicsPixmapItem *labels = new QGraphicsPixmapItem(QPixmap("./images/BBStripLabels.png"));
	
	labels->setData(BoardStrip::kLabelsCommand, "showlabels");
	labels->setData(BoardStrip::kLabelsImage, "./images/BBStripLabels.png");
	labels->setData(BoardStrip::kLabelsImagePress, "./images/BBStripLabelsHide.png");
	
		
	QGraphicsPixmapItem *joints = new QGraphicsPixmapItem(QPixmap("./images/BBStripJoints.png"));
	
	joints->setData(BoardStrip::kJointsCommand, "showjoints");
	joints->setData(BoardStrip::kJointsImage, "./images/BBStripJoints.png");
	joints->setData(BoardStrip::kJointsImagePress, "./images/BBStripJointsHide.png");
	
	QGraphicsPixmapItem *bodyItem = new QGraphicsPixmapItem(QPixmap("./images/BBStripBall.png"));

	bodyItem->setData(BoardStrip::kStripItemName, "body");
	
	m_StripItems.push_back(bodyItem);
	m_StripItems.push_back(labels);
	m_StripItems.push_back(joints);
	m_StripItems.push_back(stopItem);
	m_StripItems.push_back(playItem);
	m_StripItems.push_back(decStepSize);
	m_StripItems.push_back(incStepSize);
	
}

//
//
//
QList<QGraphicsItem*> Board::getStripItems()
{
	return m_StripItems;
}

//
//
//
void Board::drawBackground(QPainter *painter, const QRectF &rect)
{
	if (m_DrawGrid) {
		int step = m_GridSize;  
	    
		painter->save();
		painter->setPen(QPen(m_GridColor));  
	   
		// Draw horizontal grid  
		qreal start = Utility::Round(rect.top(), step); 
	   
		if (start > rect.top()) {  
			start -= step;  
		}
	   
		for (qreal y = start - step; y < rect.bottom(); ) {  
			y += step;
			painter->drawLine(rect.left(), y, rect.right(), y);  
		}  
		// Now draw vertical grid  
		start = Utility::Round(rect.left(), step);  
	   
		if (start > rect.left()) {  
			start -= step;  
		}  
	   
		for (qreal x = start - step; x < rect.right(); ) {  
			x += step;  
			painter->drawLine(x, rect.top(), x, rect.bottom());  
		}
		painter->restore();
   }
}

//
//
//
void Board::group()
{
	if (m_Group) {
		destroyItemGroup(m_Group);
		m_Group = NULL;
	}
	m_Group = createItemGroup(selectedItems());
	
	if (m_Group) {
		m_Group->setFlags(QGraphicsItem::ItemIsSelectable|QGraphicsItem::ItemIsMovable);
		m_Group->setSelected(true);
	}
}

//
//
//
void Board::ungroup()
{
	if (m_Group) {
		destroyItemGroup(m_Group);
		m_Group = NULL;
	}
}

//
//
//
void Board::keyReleaseEvent(QKeyEvent *e)
{
	QList<QGraphicsItem *> items = selectedItems();
	
	for (int i = 0; i < items.size(); ++i) {
		QGraphicsItem *item = items.at(i);
	
		if (item) {
			QPointF p = item->pos();
		
			switch (e->key()) {
				case Qt::Key_Right:
					item->setPos(p.x() + 5, p.y());
					break;
				case Qt::Key_Left:
					item->setPos(p.x() - 5, p.y());
					break;
				case Qt::Key_Up:
					item->setPos(p.x(), p.y() - 5);
					break;
				case Qt::Key_Down:
					item->setPos(p.x(), p.y() + 5);
					break;
				case Qt::Key_Delete:
					removeItem(item);
					break;
				default:
					break;
			}
		}
	}
	
	QGraphicsScene::keyReleaseEvent(e);
}

//
//
//
void Board::setDialog(QGraphicsObject *dialog)
{
	if (dialog) {
		this->addItem(dialog);
	}
}
