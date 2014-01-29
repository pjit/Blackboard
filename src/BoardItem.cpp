//
#include "BoardItem.h"
#include <QtGui/QGraphicsItem>

//
//
//
BoardItem::BoardItem()
	: m_Body(NULL), m_Parent(NULL)
{
	if (m_Parent) {
		m_Parent->addChild(this);
	}
}

//
//
//
BoardItem::BoardItem(BoardBody *body, BoardItem *parent)
	: m_Body(body), m_Parent(parent)
{
	Q_ASSERT(m_Body);
	
	m_Icon = QIcon(body->image());
	
	if (m_Parent) {
		m_Parent->addChild(this);
	}
}


//
//
//
BoardItem::BoardItem(const QString& name, const QIcon& icon, BoardItem *parent)
	: m_Parent(parent)
{
	if (m_Parent) {
		m_Parent->addChild(this);
	}
}

//
//
//
BoardItem::~BoardItem()
{
	qDeleteAll(m_Children);
}

//
//
//
void BoardItem::insertChild(int row, BoardItem* item)
{
	item->m_Parent = this;
	m_Children.insert(row, item);
}

//
//
//
void BoardItem::addChild(BoardItem* item)
{
	item->m_Parent = this;
	m_Children << item;
}

//
//
//
BoardItem* BoardItem::takeChild(int row)
{
	BoardItem *item = m_Children.takeAt(row);
	
	item->m_Parent = NULL;
	
	return item;
}

//
//
//
BoardItem* BoardItem::takeChild(BoardItem *item)
{
	BoardItem *takeItem = NULL;
	
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
void BoardItem::clear()
{
}

//
//
//
QVariant BoardItem::data(int column, int role) const
{
	if (column >= 0) {
		switch (role) {
			case Qt::DisplayRole:
			case Qt::EditRole:
				return m_Body->name();
				break;
			case Qt::DecorationRole:
				return m_Icon;
			default:
				break;	
		}
	}
	
	return QVariant();
}

//
//
//
bool BoardItem::setData(int column, const QVariant& value, int role)
{
	if (role == Qt::EditRole && column == 0) {
		m_Body->setName(value.toString());
	
		return true;
	}
	
	return false;
}

//
//
//
QString BoardItem::position() const
{
	return m_Body->position();
}

//
//
//
QString BoardItem::mass() const
{
	return m_Body->mass();
}

