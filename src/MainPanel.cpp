//
#include "MainPanel.h"
#include "ContentPanel.h"
#include "BlackBoardPanel.h"
#include <QtGui/QVBoxLayout>

//
//
//
MainPanel::MainPanel(QWidget *parent)
	: QWidget(parent)
{
	// Set vertical layout to add ribbon/enhanced custom toolbar
	// at the top - above content panel 
	setLayout(new QVBoxLayout(this));
	
	m_ContentPanel = new ContentPanel(this);
	
	m_BBPanel = new BlackBoardPanel(this);

	layout()->addWidget(m_BBPanel);
	layout()->addWidget(m_ContentPanel);
}

//
//
//
MainPanel::~MainPanel()
{
}

//
//
//
void MainPanel::init()
{
	m_ContentPanel->init();
}
