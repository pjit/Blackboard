//
//
#ifndef HIERARCHYVIEW_H
#define HIERARCHYVIEW_H

#include <QtGui/QTreeView>

//
//
class HierarchyView : public QTreeView
{
	Q_OBJECT
public:
	HierarchyView(QWidget *parent = 0);
	~HierarchyView();

	// Fix size
	QSize minimumSizeHint() const;
	//
	void createConnections();
protected slots:
	void slotModelReset();
};

#endif // HIERARCHYVIEW_H
