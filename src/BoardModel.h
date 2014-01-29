//
//
#ifndef BOARDMODEL_H
#define BOARDMODEL_H

#include <QtCore/QAbstractItemModel>
#include <QtCore/QModelIndex>
#include <QtCore/QVariant>

//
//
class BoardItem;
class BoardBody;

//
//
class BoardModel : public QAbstractItemModel
{
public:
	BoardModel(const QString&, QObject* parent = 0);
	~BoardModel();

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
   BoardItem* itemForIndex(const QModelIndex& index) const;
	void clear();
	//
	BoardItem *addItem(const QString& name);
	BoardItem *addBoardItem(const QString& name, const QString& iconPath, const QString& parentItem);
	BoardItem *addBoardItem(BoardBody *body, const QString& parentItem);
	//
	void beginModelReset() { }
	void endModelReset() { reset(); }
private:
	BoardItem *m_Root;
	QString m_Name;
};

#endif // BOARDMODEL_H
