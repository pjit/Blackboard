//
//
#ifndef PROPERTYVIEW_H
#define PROPERTYVIEW_H

#include <QtGui/QTreeView>

//
//
class PropertyView : public QTreeView
{
	Q_OBJECT
public:
	PropertyView(QWidget *parent = 0);
	~PropertyView();

	// Fix size
	QSize minimumSizeHint() const;
};

#endif // PROPERTYVIEW_H
