//
#include "HierarchyView.h"

//
//
//
HierarchyView::HierarchyView(QWidget *parent)
	: QTreeView(parent)
{
}

//
//
//
HierarchyView::~HierarchyView()
{
}

//
//
//
QSize HierarchyView::minimumSizeHint() const
{
	// TODO: Calculate from contents
	return QSize(5*48, 0);
}

//
//
//
void HierarchyView::slotModelReset()
{
	expandAll();
}

//
//
//
void HierarchyView::createConnections()
{
	//Q_ASSERT(model());
	
	//connect(model(), SIGNAL(modelReset()), this, SLOT(slotModelReset()));
}
