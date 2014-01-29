//
#include "PropertyItem.h"

//
//
//
PropertyItem::PropertyItem()
	: m_Name(""), m_Value(""), m_Parent(NULL)
{
	if (m_Parent) {
		m_Parent->addChild(this);
	}
}

//
//
//
PropertyItem::PropertyItem(const QString& name, const QString& value, PropertyItem *parent)
	: m_Parent(parent), m_Name(name), m_Value(value)
{
	if (m_Parent) {
		m_Parent->addChild(this);
	}
}

//
//
//
PropertyItem::~PropertyItem()
{
	qDeleteAll(m_Children);
}

//
//
//
void PropertyItem::insertChild(int row, PropertyItem* item)
{
	item->m_Parent = this;
	m_Children.insert(row, item);
}

//
//
//
void PropertyItem::addChild(PropertyItem* item)
{
	item->m_Parent = this;
	m_Children << item;
}

//
//
//
PropertyItem* PropertyItem::takeChild(int row)
{
	PropertyItem *item = m_Children.takeAt(row);
	
	item->m_Parent = NULL;
	
	return item;
}

//
//
//
PropertyItem* PropertyItem::takeChild(PropertyItem *item)
{
	PropertyItem *takeItem = NULL;
	
	for (int i = 0; i < m_Children.size(); ++i) {
		takeItem = m_Children.at(i);
		
		if (takeItem == item && takeItem->name() == item->name()) {
			takeItem = m_Children.takeAt(i);
			takeItem->m_Parent = NULL;
			
			return takeItem;
		}
	}
	
	return NULL;
}

//
//
//
void PropertyItem::clear()
{
}

//
//
//
QVariant PropertyItem::data(int column, int role) const
{
	if (column == 0 || column == 1) {
		switch (role) {
			case Qt::DisplayRole:
			case Qt::EditRole:
				return column == 0 ? m_Name : m_Value;
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
bool PropertyItem::setData(int column, const QVariant& value, int role)
{
	if (role == Qt::EditRole && column == 0) {
		m_Name = value.toString();
	
		return true;
	}
	if (role == Qt::EditRole && column == 1) {
		m_Value = value.toString();
	
		return true;
	}
	
	return false;
}