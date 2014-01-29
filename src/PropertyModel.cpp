//
#include "PropertyModel.h"
#include "PropertyItem.h"
#include "BoardItem.h"

//
//
//
PropertyModel::PropertyModel(const QString& name, QObject* parent)
	:  QAbstractItemModel(parent), m_Name(name)
{
	m_Root = new PropertyItem;
}

//
//
//
PropertyModel::~PropertyModel()
{
	delete m_Root;
}

//
//
//
Qt::ItemFlags PropertyModel::flags(const QModelIndex & index) const
{
	Qt::ItemFlags itemFlags = QAbstractItemModel::flags(index);
	
	if (index.isValid() && index.column() == 1) {
		return itemFlags|Qt::ItemIsEditable;
	}
	
	return itemFlags;
}

//
//
//
int PropertyModel::columnCount(const QModelIndex &parent) const
{
	//
	return 2;
}

//
//
//
int PropertyModel::rowCount(const QModelIndex &parent) const
{
	PropertyItem *item = itemForIndex(parent);
	
	return item ? item->childCount() : 0;
}

//
//
//
bool PropertyModel::hasChildren(const QModelIndex& parent) const
{
	return rowCount(parent) > 0;
}


//
//
//
QVariant PropertyModel::data(const QModelIndex &index, int role) const
{
	if (!m_Root || !index.isValid() || index.column() < 0 
		|| index.column() > 1) return QVariant();
	
	if (PropertyItem *item = itemForIndex(index)) {
		return item->data(index.column(), role);
	}
	
	return QVariant();
}

//
//
//
bool PropertyModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
	if (!index.isValid() || index.column() < 0 || index.column() > 1) return false;
	
	if (PropertyItem *item = itemForIndex(index)) {
		if (role == Qt::EditRole) {
			if (item->setData(index.column(), value, role)) emit dataChanged(index, index);
		}
	}
	
	return false;
}

//
//
//
QModelIndex PropertyModel::index(int row, int column, const QModelIndex &parent) const
{
	if (!m_Root || row < 0 || column < 0 || column > 1
		|| (parent.isValid() && parent.column() != 0)) {
		return QModelIndex();
	}
	
	PropertyItem *parentItem = itemForIndex(parent);
	
	if (PropertyItem *item = parentItem->childAt(row)) {
		return createIndex(row, column, item);
	}
	
	return QModelIndex();
}

//
//
//
QModelIndex PropertyModel::parent(const QModelIndex &index ) const
{
	if (!index.isValid()) return QModelIndex();
	
	if (PropertyItem *item = itemForIndex(index)) {
		if (PropertyItem *parentItem = item->parent()) {
			if (parentItem == m_Root) return QModelIndex();
			
			if (PropertyItem *grandParent = parentItem->parent()) {
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
PropertyItem* PropertyModel::itemForIndex(const QModelIndex& index) const
{
	if (index.isValid()) {
		if (PropertyItem *item = static_cast<PropertyItem*>(index.internalPointer())) {
			return item;
		}
	}
	
	return m_Root;
}

//
//
//
void PropertyModel::clear()
{
	delete m_Root;
	m_Root = new PropertyItem;
	reset();
}

//
//
//
PropertyItem *PropertyModel::addItem(const QString& name, const QString& value)
{
	m_Root = !m_Root ? new PropertyItem : m_Root;
	
	PropertyItem *rootItem = m_Root;
	
	PropertyItem *newItem = new PropertyItem(name, value ,rootItem);
	
	return newItem;
}

//
//
//
PropertyItem *PropertyModel::addPropertyItem(const QString& name, const QString& value, 
	const QString& parentItem)
{
	Q_ASSERT(m_Root);
	
	PropertyItem *rootItem = m_Root;
	
	for (int i = 0; i < m_Root->childCount(); ++i) {
		PropertyItem *item = m_Root->childAt(i);
		
		if (item->name() == parentItem) {
			rootItem = item;
			break;
		}
	}
	
	PropertyItem *newItem = new PropertyItem(name, value, rootItem);
	
	return newItem;
}

//
//
//
QVariant PropertyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (orientation == Qt::Horizontal) {
		switch (role) {
			case Qt::DisplayRole:
				return section == 0 ? "Property" : "Value";
				break;
			default:
				break;
		}
	}
	
	return QVariant();
}

//
//
//
void PropertyModel::update(const BoardItem *item)
{
	Q_ASSERT(item);
	
	clear();
	
	addItem("Name", item->name());
	addItem("Image", item->image());
	addItem("Position", item->position());
	addItem("Mass", item->mass());
}

