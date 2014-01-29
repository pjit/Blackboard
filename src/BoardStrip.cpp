//
#include "BoardStrip.h"
#include "Cmd.h"
#include <QtGui/QGraphicsScene>
#include <QtGui/QGraphicsPixmapItem>
#include <QtGui/QResizeEvent>
#include <QtCore/QMimeData>
#include <QtGui/QDrag>
#include <QtGui/QApplication>

//
//
//
BoardStrip::BoardStrip(QWidget *parent)
	: QGraphicsView(parent), m_StripScene(NULL)
{
	viewport()->setAutoFillBackground(true);
	viewport()->setAcceptDrops(true);
	setAcceptDrops(true);
	
	setMaximumHeight(48 + 2);
	
	QSizePolicy szPolicy = sizePolicy();
	
	szPolicy.setVerticalPolicy(QSizePolicy::Fixed);
	
	setSizePolicy(szPolicy);
	
	m_ItemDrag = false;
	//setMouseTracking(true);
}

//
//
//
QSize BoardStrip::minimumSizeHint() const
{
	return QSize(0, 4*16 + 2);
}

//
//
//
void BoardStrip::resizeEvent(QResizeEvent *event)
{
	if (scene()) {
		scene()->setSceneRect(QRect(QPoint(0, 0), event->size()));
	}
    
	QGraphicsView::resizeEvent(event);
}

//
//
//
void BoardStrip::init()
{
	m_StripScene = new QGraphicsScene(this);
	
	setScene(m_StripScene);
}

//
//
//
void BoardStrip::setStripItems(const QList<QGraphicsItem*>& items)
{
	Q_ASSERT(m_StripScene);
	
	m_StripScene->clear();
	
	QRectF sRect = m_StripScene->sceneRect();
	
	int centerX = sRect.x() + sRect.width() / 2;

	for (int i = 0; i < items.size(); ++i) {
		if (QGraphicsPixmapItem *item = dynamic_cast<QGraphicsPixmapItem*>(items[i])) {
			
			QPointF offSet = item->offset();
			
			item->setOffset(centerX + 4 + i*48, offSet.y());

			m_StripScene->addItem(items[i]);
		}
	}
}

//
//
//
void BoardStrip::mousePressEvent(QMouseEvent *event)
{
	QString strKey;
	
	setCursor(QCursor());
	m_MousePressPosition = QPoint();
	m_ItemDrag = false;
	// for d-n-d
	if (QGraphicsItem *item = itemAt(event->pos())) {
		if (QGraphicsPixmapItem *pItem = dynamic_cast<QGraphicsPixmapItem*>(item)) {
			QVariant var = item->data(BoardStrip::kStripItemName);
			
			if (!var.isNull()) {
				if (var.toString() == "body") {
					m_MousePressPosition = event->pos();
					m_ItemDrag = true;
					setCursor(Qt::OpenHandCursor);
					QGraphicsView::mousePressEvent(event);
					return;
				}
			}
		}
	}
	
	QGraphicsView::mousePressEvent(event);
	
	if (QGraphicsItem *item = itemAt(event->pos())) {
      if (QGraphicsPixmapItem *pItem = dynamic_cast<QGraphicsPixmapItem*>(item)) {
			QVariant var = item->data(BoardStrip::kStopItemImagePress);
			
			if (!var.isNull()) {
				pItem->setPixmap(QPixmap(var.toString()));
				
				return;
			}
			
			var = item->data(BoardStrip::kPlayItemImagePress);
			
			if (!var.isNull()) {
				pItem->setPixmap(QPixmap(var.toString()));
				
				return;
			}
			
			var = item->data(BoardStrip::kIncStepSizeImagePress);
			
			if (!var.isNull()) {
				pItem->setPixmap(QPixmap(var.toString()));
				
				return;
			}
			
			var = item->data(BoardStrip::kDecStepSizeImagePress);
			
			if (!var.isNull()) {
				pItem->setPixmap(QPixmap(var.toString()));
				
				return;
			}
			
			var = item->data(BoardStrip::kLabelsImagePress);
			
			if (!var.isNull()) {
				pItem->setPixmap(QPixmap(var.toString()));
				
				return;
			}
			
			var = item->data(BoardStrip::kJointsImagePress);
			
			if (!var.isNull()) {
				pItem->setPixmap(QPixmap(var.toString()));
				
				return;
			}
      }
	}
}

//
//
//
void BoardStrip::mouseReleaseEvent(QMouseEvent *event)
{
	QString strKey;
	
	setCursor(QCursor());

	
	QGraphicsView::mouseReleaseEvent(event);

	if (QGraphicsItem *item = itemAt(event->pos())) {
      QVariant var = item->data(BoardStrip::kStopItemCommand);
      
      if (!var.isNull()) {
			strKey = var.toString();
			
			var = item->data(BoardStrip::kStopItemImage);
			
			if (!var.isNull()) {
				if (QGraphicsPixmapItem *pItem = dynamic_cast<QGraphicsPixmapItem*>(item)) {
					pItem->setPixmap(QPixmap(var.toString()));
				}
			}
			
			execCommand(strKey);
			
			return;
      }
      
      var = item->data(BoardStrip::kPlayItemCommand);
      
      if (!var.isNull()) {
			strKey = var.toString();
			
			var = item->data(BoardStrip::kPlayItemImage);
			
			if (!var.isNull()) {
				if (QGraphicsPixmapItem *pItem = dynamic_cast<QGraphicsPixmapItem*>(item)) {
					pItem->setPixmap(QPixmap(var.toString()));
				}
			}
			
			execCommand(strKey);
			
			return;
      }
      
      var = item->data(BoardStrip::kIncStepSizeCommand);
      
      if (!var.isNull()) {
			strKey = var.toString();
			
			var = item->data(BoardStrip::kIncStepSizeImage);
			
			if (!var.isNull()) {
				if (QGraphicsPixmapItem *pItem = dynamic_cast<QGraphicsPixmapItem*>(item)) {
					pItem->setPixmap(QPixmap(var.toString()));
				}
			}
			
			execCommand(strKey);
			
			return;
      }
      
      var = item->data(BoardStrip::kDecStepSizeCommand);
      
      if (!var.isNull()) {
			strKey = var.toString();
			
			var = item->data(BoardStrip::kDecStepSizeImage);
			
			if (!var.isNull()) {
				if (QGraphicsPixmapItem *pItem = dynamic_cast<QGraphicsPixmapItem*>(item)) {
					pItem->setPixmap(QPixmap(var.toString()));
				}
			}
			
			execCommand(strKey);
			
			return;
      }
      
      var = item->data(BoardStrip::kJointsCommand);
      
      if (!var.isNull()) {
			strKey = var.toString();

			if (strKey == "showjoints") {
				item->setData(BoardStrip::kJointsCommand, "hidejoints");
				
				QVariant var1 = item->data(BoardStrip::kJointsImagePress);
				QVariant var2 = item->data(BoardStrip::kJointsImage);
				
				if (!var1.isNull()) {
					item->setData(BoardStrip::kJointsImage, var1.toString());
				}
				if (!var2.isNull()) {
					item->setData(BoardStrip::kJointsImagePress, var2.toString());
				}
			}
			else {
				item->setData(BoardStrip::kJointsCommand, "showjoints");
				
				QVariant var1 = item->data(BoardStrip::kJointsImage);
				QVariant var2 = item->data(BoardStrip::kJointsImagePress);
				
				if (!var1.isNull()) {
					item->setData(BoardStrip::kJointsImagePress, var1.toString());
				}
				if (!var2.isNull()) {
					item->setData(BoardStrip::kJointsImage, var2.toString());
				}
			}
			strKey = item->data(BoardStrip::kJointsCommand).toString();
			var = item->data(BoardStrip::kJointsImage);
			
			if (!var.isNull()) {
				if (QGraphicsPixmapItem *pItem = dynamic_cast<QGraphicsPixmapItem*>(item)) {
					pItem->setPixmap(QPixmap(var.toString()));
				}
			}
			
			execCommand(strKey);
			
			return;
      }
      
      var = item->data(BoardStrip::kLabelsCommand);
      
      if (!var.isNull()) {
			strKey = var.toString();
			// Setup for next step
			if (strKey == "showlabels") {
				item->setData(BoardStrip::kLabelsCommand, "hidelabels");
				
				QVariant var1 = item->data(BoardStrip::kLabelsImagePress);
				QVariant var2 = item->data(BoardStrip::kLabelsImage);
				
				if (!var1.isNull()) {
					item->setData(BoardStrip::kLabelsImage, var1.toString());
				}
				if (!var2.isNull()) {
					item->setData(BoardStrip::kLabelsImagePress, var2.toString());
				}
			}
			else {
				item->setData(BoardStrip::kLabelsCommand, "showlabels");
				
				QVariant var1 = item->data(BoardStrip::kLabelsImage);
				QVariant var2 = item->data(BoardStrip::kLabelsImagePress);
				
				if (!var1.isNull()) {
					item->setData(BoardStrip::kLabelsImagePress, var1.toString());
				}
				if (!var2.isNull()) {
					item->setData(BoardStrip::kLabelsImage, var2.toString());
				}
			}
			// Get final command; execute and setup gui for next action
			strKey = item->data(BoardStrip::kLabelsCommand).toString();
			var = item->data(BoardStrip::kLabelsImage);
			
			if (!var.isNull()) {
				if (QGraphicsPixmapItem *pItem = dynamic_cast<QGraphicsPixmapItem*>(item)) {
					pItem->setPixmap(QPixmap(var.toString()));
				}
			}

			execCommand(strKey);
			
			return;
      }
	}
}

//
//
//
void BoardStrip::execCommand(const QString& cmdStr)
{
	if (!cmdStr.isEmpty()) {
	   Cmd cmdObj("", cmdStr);
      
      emit stripCommandEntered(cmdObj);
	}
}

//
//
//
void BoardStrip::mouseMoveEvent(QMouseEvent *e)
{
	 
	 
	 if (QGraphicsItem *item = itemAt(e->pos())) {
		if (QGraphicsPixmapItem *pItem = dynamic_cast<QGraphicsPixmapItem*>(item)) {
			QVariant var = item->data(BoardStrip::kStripItemName);
			
			if (!var.isNull()) {
				if (var.toString() == "body") {
					setCursor(Qt::OpenHandCursor);
				}
			}
		}
	}

	 if (QLineF(e->pos(), m_MousePressPosition).length() < QApplication::startDragDistance()) {
	      m_MousePressPosition = QPoint();
         return;
    }
	 
	 if (!m_ItemDrag) return;
	 
     QDrag *drag = new QDrag(this);
     QMimeData *mime = new QMimeData;

     drag->setMimeData(mime);

     QImage image("./images/BBCircle.png");

     mime->setImageData(image);

     drag->setPixmap(QPixmap::fromImage(image));
     drag->setHotSpot(QPoint(15, 30));

     drag->exec();
     m_MousePressPosition = QPoint();
     setCursor(Qt::OpenHandCursor);
}

//
//
//
void BoardStrip::dragEnterEvent(QDragEnterEvent *event)
{

}

//
//
//
void BoardStrip::dragLeaveEvent(QDragLeaveEvent *event)
{
	m_ItemDrag = false;
	m_MousePressPosition = QPoint();
}	

//
//
//
void BoardStrip::dragMoveEvent(QDragMoveEvent *event)
{
	event->accept();
}

//
//
//
void BoardStrip::dropEvent(QDropEvent *event)
{

}
