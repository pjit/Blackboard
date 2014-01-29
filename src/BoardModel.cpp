//
#include "BoardModel.h"
#include "BoardItem.h"

//
//
//
BoardModel::BoardModel(const QString& name, QObject* parent)
	:  QAbstractItemModel(parent), m_Name(name)
{
	m_Root = new BoardItem;
}

//
//
//
BoardModel::~BoardModel()
{
	delete m_Root;
}

//
//
//
Qt::ItemFlags BoardModel::flags(const QModelIndex & index) const
{
	Qt::ItemFlags itemFlags = QAbstractItemModel::flags(index);
	
	if (index.isValid()) {
		return itemFlags|Qt::ItemIsEditable;
	}
	
	return itemFlags;
}

//
//
//
int BoardModel::columnCount(const QModelIndex &parent) const
{
	//
	return parent.isValid() && parent.column() != 0 ? 0 : 1;
}

//
//
//
int BoardModel::rowCount(const QModelIndex &parent) const
{
	/*if (!parent.isValid() && m_Root) return m_Root->childCount();
	
	if (BoardItem *item = itemForIndex(parent)) {
		return item->childCount();
	}*/
	if (parent.isValid() && parent.column() != 0) return 0;
	
	BoardItem *item = itemForIndex(parent);
	
	return item ? item->childCount() : 0;
	
	return 0;
}

//
//
//
bool BoardModel::hasChildren(const QModelIndex& parent) const
{
	return rowCount(parent) > 0;
}


//
//
//
QVariant BoardModel::data(const QModelIndex &index, int role) const
{
	if (!m_Root || !index.isValid() || index.column() < 0 
		|| index.column() >= 1) return QVariant();
	
	if (BoardItem *item = itemForIndex(index)) {
		return item->data(0, role);
	}
	
	return QVariant();
}

//
//
//
bool BoardModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
	if (!index.isValid() || index.column() != 0) return false;
	
	if (BoardItem *item = itemForIndex(index)) {
		if (role == Qt::EditRole) {
			if (item->setData(0, value, role)) emit dataChanged(index, index);
		}
	}
	
	return false;
}

//
//
//
QModelIndex BoardModel::index(int row, int column, const QModelIndex &parent) const
{
	if (!m_Root || row < 0 || column < 0 || column >= 1
		|| (parent.isValid() && parent.column() != 0)) {
		return QModelIndex();
	}
	
	BoardItem *parentItem = itemForIndex(parent);
	
	if (BoardItem *item = parentItem->childAt(row)) {
		return createIndex(row, column, item);
	}
	
	return QModelIndex();
}

//
//
//
QModelIndex BoardModel::parent(const QModelIndex &index ) const
{
	if (!index.isValid()) return QModelIndex();
	
	if (BoardItem *item = itemForIndex(index)) {
		if (BoardItem *parentItem = item->parent()) {
			if (parentItem == m_Root) return QModelIndex();
			
			if (BoardItem *grandParent = parentItem->parent()) {
				int row = grandParent->rowOfChild(parentItem);
				
				QModelIndex newIndex = createIndex(row, 0, parentItem);
				
				return newIndex;
			}
		}
	}

	return QModelIndex();
}

//
//
//
BoardItem* BoardModel::itemForIndex(const QModelIndex& index) const
{
	if (index.isValid()) {
		if (BoardItem *item = static_cast<BoardItem*>(index.internalPointer())) {
			return item;
		}
	}
	
	return m_Root;
}

//
//
//
void BoardModel::clear()
{
	delete m_Root;
	m_Root = new BoardItem;
	reset();
}

//
//
//
BoardItem *BoardModel::addItem(const QString& name)
{
	m_Root = !m_Root ? new BoardItem : m_Root;
	
	BoardItem *rootItem = m_Root;
	
	QIcon icon("./images/BBBoard.png");
	
	BoardItem *newItem = new BoardItem(name, icon ,rootItem);
	
	return newItem;
}

//
//
//
BoardItem *BoardModel::addBoardItem(BoardBody *body, const QString& parentItem)
{
	Q_ASSERT(m_Root);
	
	m_Root = !m_Root ? new BoardItem : m_Root;
	
	BoardItem *rootItem = m_Root;
	
	for (int i = 0; i < m_Root->childCount(); ++i) {
		BoardItem *item = m_Root->childAt(i);
		
		if (item->name() == parentItem) {
			rootItem = item;
			break;
		}
	}
	
	QIcon icon(body->image());
	
	BoardItem *newItem = new BoardItem(body, rootItem);
	
	return newItem;
}

//
//
//
BoardItem *BoardModel::addBoardItem(const QString& name, const QString& iconPath, 
	const QString& parentItem)
{
	Q_ASSERT(m_Root);
	
	BoardItem *rootItem = m_Root;
	
	for (int i = 0; i < m_Root->childCount(); ++i) {
		BoardItem *item = m_Root->childAt(i);
		
		if (item->name() == parentItem) {
			rootItem = item;
			break;
		}
	}
	
	QIcon icon(iconPath);
	
	BoardItem *newItem = new BoardItem(name, icon, rootItem);
	
	return newItem;
}

//
//
//
QVariant BoardModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (orientation == Qt::Horizontal) {
		if (section == 0) {
			switch (role) {
				case Qt::DisplayRole:
					return m_Name;
					break;
				default:
					break;
			}
		}
	}
	
	return QVariant();
}