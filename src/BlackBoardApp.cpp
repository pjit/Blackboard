//
#include "BlackBoardApp.h"
#include "MainPanel.h"
#include "PrefManager.h"
#include <QtGui/QApplication>
#include <ode/ode.h>


//
//
//
BlackBoardApp::BlackBoardApp(QWidget *parent)
	: QMainWindow(parent)
{
}

//
//
//
BlackBoardApp::~BlackBoardApp()
{
}

//
//
//
void BlackBoardApp::init()
{
	QApplication::setApplicationName(APPNAME);
	QApplication::setOrganizationName(COMPANYNAME);
	
	QSize windowSize = PrefManager::get().readValue("mainWindowSize").toSize();
	
	resize(windowSize);
	
	m_mainPanel = new MainPanel(this);
	
	m_mainPanel->init();
	
	this->setCentralWidget(m_mainPanel);
	// Init ODE
	// create world
    dInitODE2(0);
}

//
//
//
void BlackBoardApp::closeEvent(QCloseEvent *e)
{
    QVariant var(size());
    
	PrefManager::get().writeValue("mainWindowSize", var);

	// De-init ODE
	dCloseODE();
}

