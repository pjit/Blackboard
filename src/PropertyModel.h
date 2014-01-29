//
//
#ifndef PROPERTYMODEL_H
#define PROPERTYMODEL_H

#include <QtCore/QAbstractItemModel>
#include <QtCore/QModelIndex>
#include <QtCore/QVariant>

//
//
class PropertyItem;
class BoardItem;

//
//
class PropertyModel : public QAbstractItemModel
{
public:
	PropertyModel(const QString&, QObject* parent = 0);
	~PropertyModel();

	//
	Qt::ItemFlags flags (const QModelIndex & index) const;
	QVariant headerData(int section, Qt::Orientation, int role = Qt::DisplayRole) const;
	int columnCount(const QModelIndex &parent = QModelIndex() ) const;
   QVariant data(const QModelIndex &index, int role = Qt::DisplayRole ) const;
   bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole);
   QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
   QModelIndex parent(const QModelIndex &index ) const;
   int rowCount(const QModelIndex &parent = QModelIndex()) const;
   bool hasChildren(const QModelIndex& parent) const;
   PropertyItem* itemForIndex(const QModelIndex& index) const;
	void clear();
	//
	PropertyItem *addItem(const QString& name, const QString& value);
	PropertyItem *addPropertyItem(const QString& name, const QString& value, const QString& parentItem);
	//
	void beginModelReset() { }
	void endModelReset() { reset(); }
	//
	void update(const BoardItem *item);
private:
	PropertyItem *m_Root;
	QString m_Name;
};

#endif // PROPERTYMODEL_H
