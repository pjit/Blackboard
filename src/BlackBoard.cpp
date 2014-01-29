//
//
//
#include <QtGui/QApplication>
#include <QtOpenGL/QGLWidget>
#include "BlackBoardApp.h"

//
//
//
int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	
	BlackBoardApp blackBoardApp;

	blackBoardApp.init();

	blackBoardApp.show();
#if 0
	GLWidget window;

	window.resize(800,400);
	window.show();
#endif
	return app.exec();
}
