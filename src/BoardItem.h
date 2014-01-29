//
//
#ifndef BOARDITEM_H
#define BOARDITEM_H

#include <QtCore/QList>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include "BoardBody.h"

//
//
class QGraphicsItem;
class BoardItemData;

//
//
class BoardItem
{
public:
	BoardItem();
	BoardItem(const QString& name, const QIcon& icon, BoardItem *parent = NULL);
	BoardItem(BoardBody *body, BoardItem *parent = NULL);
	~BoardItem();

	//
	inline BoardItem* parent() const { return m_Parent; }
	inline BoardItem* childAt(int row) const { return m_Children.value(row); }
	inline int childCount() const { return m_Children.count(); }
	inline int rowOfChild(BoardItem *item) const { return m_Children.indexOf(item); }
	inline bool hasChildren() const { return !m_Children.isEmpty(); }
	inline QList<BoardItem*> children() const { return m_Children; }
	inline QString name() const { return m_Body->name(); }
	inline QString image() const { return m_Body->image(); }
	QString position() const;
	QString mass() const;
	//
	void insertChild(int row, BoardItem* item);
	void addChild(BoardItem* item);
	BoardItem* takeChild(int row);
	BoardItem* takeChild(BoardItem *item);
	void clear();
	bool setData(int column, const QVariant& value, int role);
	QVariant data(int column, int role = Qt::DisplayRole) const;
private:
	BoardItem *m_Parent;
	QList<BoardItem*> m_Children;
	BoardBody *m_Body;
	QIcon m_Icon;
	// Icon too
	// Listen through Board class.
	QGraphicsItem *m_Item;
};

#endif // BOARDITEM_H
