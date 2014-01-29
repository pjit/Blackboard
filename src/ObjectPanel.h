//
//
#ifndef OBJECTPANEL_H
#define OBJECTPANEL_H

#include <QtGui/QSplitter>
#include <QtCore/QModelIndex>
#include "BoardPanel.h"

class HierarchyView;
class PropertyView;
class PropertyModel;

//
//
class ObjectPanel : public QSplitter
{
	Q_OBJECT
public:
	ObjectPanel(QWidget *parent = 0);
	~ObjectPanel();
	QSize minimumSizeHint() const;
	
protected slots:
	void slotBoardChanged(const BoardPanel&);
	void slotHierarchyItemClicked(const QModelIndex&);
private:
	HierarchyView *m_Hierarchy;
	PropertyView *m_PropertyView;
	PropertyModel *m_PropertyModel;
};

#endif // OBJECTPANEL_H
