//
//
#ifndef BLACKBOARDPANELSCENE_H
#define BLACKBOARDPANELSCENE_H
#include <QtGui/QGraphicsScene>


//
//
class BlackBoardPanelScene : public QGraphicsScene
{
	Q_OBJECT
public:
	BlackBoardPanelScene(QObject *parent = 0);
	~BlackBoardPanelScene();

private:
};
#endif // BLACKBOARDPANELSCENE_H
