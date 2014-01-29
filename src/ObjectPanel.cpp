//
#include "ObjectPanel.h"
#include "HierarchyView.h"
#include "PropertyView.h"
#include "PropertyModel.h"
#include "BoardModel.h"
#include "BoardItem.h"
#include "Board.h"

//
//
//
ObjectPanel::ObjectPanel(QWidget *parent)
	: QSplitter(Qt::Vertical, parent)
{
	m_Hierarchy = new HierarchyView(this);
	
	addWidget(m_Hierarchy);

	m_PropertyView = new PropertyView(this);
	
	addWidget(m_PropertyView);

	QList<int> initSize;
	//
	initSize.push_back(m_Hierarchy->minimumSizeHint().height());
	initSize.push_back(m_PropertyView->minimumSizeHint().height());
	//
	setSizes(initSize);
	
	//
	m_PropertyModel = new PropertyModel("PropertyModel", this);
	
	m_PropertyView->setModel(m_PropertyModel);
	
	//
	connect(m_Hierarchy, SIGNAL(clicked(const QModelIndex&)), this,
		SLOT(slotHierarchyItemClicked(const QModelIndex&)));
}

//
//
//
ObjectPanel::~ObjectPanel()
{
}

//
//
//
void ObjectPanel::slotHierarchyItemClicked(const QModelIndex& index)
{
	BoardModel *boardModel = static_cast<BoardModel*>(m_Hierarchy->model());
	
	Q_ASSERT(boardModel);
	
	BoardItem *item = boardModel->itemForIndex(index);

	Q_ASSERT(item);
	
	// clear old model
	m_PropertyModel->update(item);
}

//
//
//
//
//
//
void ObjectPanel::slotBoardChanged(const BoardPanel& boardPanel)
{
	m_Hierarchy->setModel(boardPanel.currentBoard()->model());
}

//
//
//
QSize ObjectPanel::minimumSizeHint() const
{
	// TODO: Calculate from contents
	return QSize(5*48, 0);
}

