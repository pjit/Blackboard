//
//
#ifndef PROPERTYITEM_H
#define PROPERTYITEM_H

#include <QtCore/QList>
#include <QtCore/QVariant>

//
//
class PropertyItem
{
public:
	PropertyItem();
	PropertyItem(const QString& name, const QString& value, PropertyItem *parent = NULL);
	~PropertyItem();

	//
	inline PropertyItem* parent() const { return m_Parent; }
	inline PropertyItem* childAt(int row) const { return m_Children.value(row); }
	inline int childCount() const { return m_Children.count(); }
	inline int rowOfChild(PropertyItem *item) const { return m_Children.indexOf(item); }
	inline bool hasChildren() const { return !m_Children.isEmpty(); }
	inline QList<PropertyItem*> children() const { return m_Children; }
	inline QString name() const { return m_Name; }
	inline QString value() const { return m_Value; }
	//
	void insertChild(int row, PropertyItem* item);
	void addChild(PropertyItem* item);
	PropertyItem* takeChild(int row);
	PropertyItem* takeChild(PropertyItem *item);
	void clear();
	bool setData(int column, const QVariant& value, int role);
	QVariant data(int column, int role = Qt::DisplayRole) const;
private:
	PropertyItem *m_Parent;
	QList<PropertyItem*> m_Children;
	QString m_Name;
	QString m_Value;
};

#endif // PROPERTYITEM_H
