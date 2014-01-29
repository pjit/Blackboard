//
#include "BoardScene.h"
#include <QtOpenGL/QGLWidget>

//
//
//
BoardScene::BoardScene(const QString& name, BoardModel *boardmodel, QObject *parent)
	: Board(name, boardmodel, parent)
{
}

//
//
//
BoardScene::~BoardScene()
{
}

//
//
//
void BoardScene::drawBackground(QPainter *painter, const QRectF &rect)
{
	QPaintEngine::Type type = painter->paintEngine()->type();

	if (painter->paintEngine()->type()
                == QPaintEngine::OpenGL || painter->paintEngine()->type()
                == QPaintEngine::OpenGL2) {
#if 1
	painter->save();
	// Background color
	glClearColor(0.75f, 0.75f, 0.75f, 0.5f);
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	drawBoundary(rect);
	
	drawRuler(0, rect);
	//drawRuler(1, rect);
	//drawRuler(2, rect);
	//drawRuler(3, rect);

	painter->restore();
#endif
	}
	else {
		qWarning("OpenGLScene: drawBackground needs a "
                     "QGLWidget to be set as viewport on the "
                     "graphics view");
      return;
	}
}
//
//
//
void BoardScene::drawRuler(int location, const QRectF &rect)
{
	GLfloat org1, org2, org3;
	
	org1 = rect.center().x();
	org2 = rect.center().y();

float ORG[3] = {org1,org2,0};

	float XP[3] = {rect.width(),0,0}, XN[3] = {-rect.width(),0,0},
	YP[3] = {0,rect.height(),0}, YN[3] = {0,-rect.height(),0},
	ZP[3] = {0,0,1}, ZN[3] = {0,0,-1};

glPushMatrix ();

glTranslatef (-2.4, -1.5, -5);
glRotatef (5 , 1,0,0);
glRotatef (5, 0,1,0);
glScalef (0.25, 0.25, 0.25);

glLineWidth (2.0);

glBegin (GL_LINES);
glColor3f (1,0,0); // X axis is red.
glVertex3fv (ORG);
glVertex3fv (XP ); 
glColor3f (0,1,0); // Y axis is green.
glVertex3fv (ORG);
glVertex3fv (YP );
glColor3f (0,0,1); // z axis is blue.
glVertex3fv (ORG);
glVertex3fv (ZP ); 
glEnd();

glPopMatrix ();
#if 0
	// location = 0 ... horizontal , bottom
	// location = 1 ... horizontal , top
	// location = 2 ... vertical , left
	// location = 3 ... vertical , right
	int numTicks = rect.width();
	GLfloat tickLength = 5;

	glColor3f(1.0, 1.0, 1.0);
	//
	glPushMatrix(); // save current transform matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	GLfloat xMin = static_cast<GLfloat>(rect.x() + rect.width()/2 - 2);
	GLfloat xMax = static_cast<GLfloat>(xMin + 2);
	
	GLfloat yMin = static_cast<GLfloat>(rect.y() + rect.height()/2 - 2);
	GLfloat yMax = static_cast<GLfloat>(yMin + 2);

	glOrtho(xMin, xMax, yMin, yMax, -1.0, 1.0);

	if (location == 0)	 {// vertical ruler
		GLfloat xStart = location == 0 ? xMin + 1 : xMax - 1;

		glBegin(GL_LINES);
		glVertex3f(xStart, yMin, 0.0);
		glVertex3f(xStart, yMax, 0.0);
		glEnd();

		int numTicks = 0;//rect.height()/5;

		GLfloat yStep = (yMax - yMin) / (GLfloat)(numTicks); // numTicks

		for (int i = 0; i < numTicks; ++i) {
			GLfloat yValue = (GLfloat)(i)*yStep;
			GLfloat xLeft = xStart - (GLfloat)0.5*tickLength;
			GLfloat xRight = xStart + (GLfloat)0.5*tickLength*2;

			glBegin(GL_LINES);
			glVertex3f(xLeft, yValue, 0.0);
			glVertex3f(xRight, yValue, 0.0);
			glEnd();
		}
	}
	if (location == 2) { // horizonatal ruler
		GLfloat yStart = location == 2 ? yMin + 1 : yMax - 1;

		glBegin(GL_LINES);
		glVertex3f(xMin, yStart, 0.0);
		glVertex3f(xMax, yStart, 0.0);
		glEnd();
		
		int numTicks = 0; //rect.width()/5;

		float xStep = (xMax - xMin) / (GLfloat)(numTicks); // numTicks

		for (int j = 0; j < numTicks; j++) {
			GLfloat xValue = (GLfloat)(j) * xStep;
			GLfloat yBottom = yStart - (GLfloat)0.5*tickLength;
			GLfloat yTop = yStart + (GLfloat)0.5*tickLength;

			glBegin(GL_LINES);
			glVertex3f(xValue, yBottom, 0.0);
			glVertex3f(xValue, yTop, 0.0);
			glEnd();
		}
	}
	if (location == 3) { // horizonatal ruler
		GLfloat yStart = location == 3 ? yMin + 1 : yMax - 1;

		glBegin(GL_LINES);
		glVertex3f(xMin, yStart, 0.0);
		glVertex3f(xMax, yStart, 0.0);
		glEnd();
		
		int numTicks = 0; //rect.width()/5;

		float xStep = (xMax - xMin) / (GLfloat)(numTicks); // numTicks

		for (int j = 0; j < numTicks; j++) {
			GLfloat xValue = (GLfloat)(j) * xStep;
			GLfloat yBottom = yStart - (GLfloat)0.5*tickLength;
			GLfloat yTop = yStart + (GLfloat)0.5*tickLength;

			glBegin(GL_LINES);
			glVertex3f(xValue, yBottom, 0.0);
			glVertex3f(xValue, yTop, 0.0);
			glEnd();
		}
	}
	//
	glPopMatrix();	 // restore transform matrix
#endif
}

//
//
//
void BoardScene::drawBoundary(const QRectF &rect)
{
	GLfloat boundaryWidth = 1;

	glColor3f(1.0, 1.0, 1.0);
	//
	glPushMatrix(); // save current transform matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	GLfloat xMin = static_cast<GLfloat>(rect.x());
	GLfloat xMax = static_cast<GLfloat>(rect.x() + rect.width());
	
	GLfloat yMin = static_cast<GLfloat>(rect.y());
	GLfloat yMax = static_cast<GLfloat>(rect.y() + rect.height());

	glOrtho(xMin, xMax, yMin, yMax, -1.0, 1.0);

	// Vertical side
	GLfloat xStart = xMin + 1;

	glBegin(GL_LINES);
	glVertex3f(xStart, yMin, 0.0);
	glVertex3f(xStart, yMax, 0.0);
	glEnd();

	xStart = xMax - 1;
	
	glBegin(GL_LINES);
	glVertex3f(xStart, yMin, 0.0);
	glVertex3f(xStart, yMax, 0.0);
	glEnd();

	// Horizontal side
	GLfloat yStart = yMin + 1;

	glBegin(GL_LINES);
	glVertex3f(xMin, yStart, 0.0);
	glVertex3f(xMax, yStart, 0.0);
	glEnd();

	yStart = yMax - 1;

	glBegin(GL_LINES);
	glVertex3f(xMin, yStart, 0.0);
	glVertex3f(xMax, yStart, 0.0);
	glEnd();
	//
	glPopMatrix();
}

