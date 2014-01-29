//
#include "PropertyView.h"
#include <QtGui/QHeaderView>

//
//
//
PropertyView::PropertyView(QWidget *parent)
	: QTreeView(parent)
{
	setRootIsDecorated(false);
	
	header()->show();
}

//
//
//
PropertyView::~PropertyView()
{
}

//
//
//
QSize PropertyView::minimumSizeHint() const
{
	// TODO: Calculate from contents
	return QSize(1*48, 0);
}
