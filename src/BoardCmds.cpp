//
#include "BoardCmds.h"
#include "PrefManager.h"
#include "Cmd.h"
#include "CmdArg.h"
#include "BoardItem.h"
#include "BoardView.h"
#include "BoardModel.h"
#include "Board.h"
#include "BoardBox.h"
#include <QtGui/QGraphicsItem>
#include <QtGui/QGraphicsColorizeEffect>
#include <QtGui/QLayout>
#include <QtGui/QPushButton>
#include <QtGui/QLineEdit>
#include <QtGui/QGraphicsObject>

//
//
//
bool Rotate::execute(BoardView& boardView, const Cmd& cmd, QString& result)
{
	int degrees = cmd.getArg(0).value().toInt();
	
	result = QString("");
		
	QList<QGraphicsItem *> selectedItems = boardView.board()->selectedItems();
		
	if (selectedItems.size() > 0) {
		QGraphicsItem *selectedItem = selectedItems.at(0);
			
		selectedItem->setRotation(degrees);
	}
	else {
		result = QString("<font color=\"red\">Select an item first</font>");
	
		return false;
	}
	
	return true;
}

//
//
//
bool Move::execute(BoardView& boardView, const Cmd& cmd, QString& result)
{
	QList<QGraphicsItem *> selectedItems = boardView.board()->selectedItems();
	
	result = QString("");
		
	if (selectedItems.size() > 0) {
		QGraphicsItem *selectedItem = selectedItems.at(0);
		qreal x = cmd.getArg(0).value().toReal();
		qreal y = cmd.getArg(1).value().toReal();
			
		selectedItem->moveBy(x,y);
		
		return true;
	}
	
	result = QString("<font color=\"red\">Select an item first.</font>");
	
	return false;
}

//
//
//
bool Rect::execute(BoardView& boardView, const Cmd& cmd, QString& result)
{
	int x = cmd.getArg(0).value().toInt();
	int y = cmd.getArg(1).value().toInt();
	int width = cmd.getArg(2).value().toInt();
	int height = cmd.getArg(3).value().toInt();
		
	QGraphicsItem *item = boardView.board()->addRect(x, y, width, height);
	
	result = QString("");
	
	boardView.model()->beginModelReset();
	
	BoardItem *bItem = boardView.model()->addBoardItem(cmd.fullName(), "./images/BBRect.png", boardView.board()->name());
	boardView.model()->endModelReset();
	
	if (item) {
		item->setFlags(QGraphicsItem::ItemIsSelectable|QGraphicsItem::ItemIsMovable);
		item->setSelected(true);

		return true;
	}
	// give item to board
	
	return false;
}

//
//
//
bool BoxCmd::execute(BoardView& boardView, const Cmd& cmd, QString& result)
{
	result = QString("");
	
	QString bodyName = cmd.getArg(0).value().toString();
	QString bodyImg = cmd.getArg(1).value().toString();
	
	boardView.model()->beginModelReset();

	Q_ASSERT(boardView.board() != NULL);
	
	BoardBox *item = boardView.board()->getCurrentBox();
	
	if (item == NULL) {
		item = new BoardBox();
		
		boardView.board()->addItem(item);
	}
	BoardBody *body = item->addBody(bodyName, bodyImg.isEmpty() ? QString("./images/BBCircle.png") : bodyImg, boardView.getCurrentPosition());
	
	Q_ASSERT(body);
	
	// Current sim body
	boardView.board()->setCurrentBox(item);
	
	BoardItem *bItem = boardView.model()->addBoardItem(body, boardView.board()->name());
	
	boardView.model()->endModelReset();
	if (item) {
		item->setAcceptDrops(true);
		item->setFlags(QGraphicsItem::ItemIsSelectable|QGraphicsItem::ItemIsMovable);
		item->setSelected(true);

		return true;
	}
	// give item to board
	
	return false;
}

//
//
//
bool RemoveBody::execute(BoardView& boardView, const Cmd& cmd, QString& result)
{
	result = QString("");
	
	QString bodyName = cmd.getArg(0).value().toString();

	boardView.model()->beginModelReset();

	Q_ASSERT(boardView.board() != NULL);
	
	if (boardView.board()->getCurrentBox()) {
		boardView.board()->getCurrentBox()->removeBody(bodyName);
		
		return true;
	}
	
	return false;
}

//
//
//
bool DisableJoint::execute(BoardView& boardView, const Cmd& cmd, QString& result)
{
	result = QString("");
	
	QString bodyName = cmd.getArg(0).value().toString();

	boardView.model()->beginModelReset();

	Q_ASSERT(boardView.board() != NULL);
	
	if (boardView.board()->getCurrentBox()) {
		boardView.board()->getCurrentBox()->disableJoint(bodyName);
		
		return true;
	}
	
	return false;
}

//
//
//
bool EnableJoint::execute(BoardView& boardView, const Cmd& cmd, QString& result)
{
	result = QString("");
	
	QString bodyName = cmd.getArg(0).value().toString();

	boardView.model()->beginModelReset();

	Q_ASSERT(boardView.board() != NULL);
	
	if (boardView.board()->getCurrentBox()) {
		boardView.board()->getCurrentBox()->enableJoint(bodyName);
		
		return true;
	}
	
	return false;
}

//
//
//
bool SetMass::execute(BoardView& boardView, const Cmd& cmd, QString& result)
{
	result = QString("");
	
	QString bodyName = cmd.getArg(0).value().toString();
	dReal m = cmd.getArg(1).value().toDouble();

	Q_ASSERT(boardView.board() != NULL);
	
	if (boardView.board()->getCurrentBox() && m > 0) {
		boardView.board()->getCurrentBox()->setMass(bodyName, m);
		return true;
	}
	
	return false;
}

//
//
//
bool Inspect::execute(BoardView& boardView, const Cmd& cmd, QString& result)
{
	result = QString("");
	
	QString bodyName = cmd.getArg(0).value().toString();
	QString inspectAttribute = cmd.getArg(1).value().toString();

	// Current sim body
	if (boardView.board()->getCurrentBox()) {
		result = boardView.board()->getCurrentBox()->inspect(bodyName, inspectAttribute);
		
		return true;
	}
	
	return false;
}


//
//
//
bool SetGravity::execute(BoardView& boardView, const Cmd& cmd, QString& result)
{
	result = QString("");
	
	dReal x = cmd.getArg(0).value().toDouble();
	dReal y = cmd.getArg(1).value().toDouble();
	dReal z = cmd.getArg(2).value().toDouble();


	Q_ASSERT(boardView.board() != NULL);

	// Current sim body
	if (boardView.board()->getCurrentBox()) {
		boardView.board()->getCurrentBox()->setWorldGravity(x,y,z);
		
		return true;
	}
	
	return false;
}

//
//
//
bool SetStepSize::execute(BoardView& boardView, const Cmd& cmd, QString& result)
{
	result = QString("");
	
	dReal stepSize = cmd.getArg(0).value().toDouble();

	Q_ASSERT(boardView.board() != NULL);

	// Current sim body
	if (boardView.board()->getCurrentBox()) {
		boardView.board()->getCurrentBox()->setStepSize(stepSize);
		
		return true;
	}
	
	return false;
}

//
//
//
bool IncStepSize::execute(BoardView& boardView, const Cmd& cmd, QString& result)
{
	result = QString("");

	Q_ASSERT(boardView.board() != NULL);

	// Current sim body
	if (boardView.board()->getCurrentBox()) {
		boardView.board()->getCurrentBox()->incStepSize();
		
		return true;
	}
	
	return false;
}

//
//
//
bool DecStepSize::execute(BoardView& boardView, const Cmd& cmd, QString& result)
{
	result = QString("");

	Q_ASSERT(boardView.board() != NULL);

	// Current sim body
	if (boardView.board()->getCurrentBox()) {
		boardView.board()->getCurrentBox()->decStepSize();
		
		return true;
	}
	
	return false;
}
//
//
//
bool AddForce::execute(BoardView& boardView, const Cmd& cmd, QString& result)
{
	result = QString("");
	
	QString bodyName = cmd.getArg(0).value().toString();
	dReal x = cmd.getArg(1).value().toDouble();
	dReal y = cmd.getArg(2).value().toDouble();
	dReal z = cmd.getArg(3).value().toDouble();


	Q_ASSERT(boardView.board() != NULL);

	// Current sim body
	if (boardView.board()->getCurrentBox()) {
		boardView.board()->getCurrentBox()->addForce(bodyName, x, y, z);
		
		return true;
	}
	
	return false;
}

//
//
//
bool AddForceX::execute(BoardView& boardView, const Cmd& cmd, QString& result)
{
	result = QString("");
	
	QString bodyName = cmd.getArg(0).value().toString();
	dReal x = cmd.getArg(1).value().toDouble();


	Q_ASSERT(boardView.board() != NULL);

	// Current sim body
	if (boardView.board()->getCurrentBox()) {
		boardView.board()->getCurrentBox()->addForce(bodyName, x, 0.0,0.0);
		
		return true;
	}
	
	return false;
}

//
//
//
bool AddForceY::execute(BoardView& boardView, const Cmd& cmd, QString& result)
{
	result = QString("");
	
	QString bodyName = cmd.getArg(0).value().toString();
	dReal y = cmd.getArg(1).value().toDouble();


	Q_ASSERT(boardView.board() != NULL);

	// Current sim body
	if (boardView.board()->getCurrentBox()) {
		boardView.board()->getCurrentBox()->addForce(bodyName, 0.0, y,0.0);
		
		return true;
	}
	
	return false;
}

//
//
//
bool AddForceZ::execute(BoardView& boardView, const Cmd& cmd, QString& result)
{
	result = QString("");
	
	QString bodyName = cmd.getArg(0).value().toString();
	dReal z = cmd.getArg(1).value().toDouble();


	Q_ASSERT(boardView.board() != NULL);

	// Current sim body
	if (boardView.board()->getCurrentBox()) {
		boardView.board()->getCurrentBox()->addForce(bodyName, 0.0, 0.0, z);
		
		return true;
	}
	
	return false;
}

//
//
//
bool ResetForce::execute(BoardView& boardView, const Cmd& cmd, QString& result)
{
	result = QString("");
	
	QString bodyName = cmd.getArg(0).value().toString();

	Q_ASSERT(boardView.board() != NULL);

	// Current sim body
	if (boardView.board()->getCurrentBox()) {
		boardView.board()->getCurrentBox()->resetForce(bodyName);
		
		return true;
	}

	return false;
}

//
//
//
bool SetPosition::execute(BoardView& boardView, const Cmd& cmd, QString& result)
{
	result = QString("");
	
	QString bodyName = cmd.getArg(0).value().toString();
	dReal x = cmd.getArg(1).value().toDouble();
	dReal y = cmd.getArg(2).value().toDouble();
	dReal z = cmd.getArg(3).value().toDouble();


	Q_ASSERT(boardView.board() != NULL);

	// Current sim body
	if (boardView.board()->getCurrentBox()) {
		boardView.board()->getCurrentBox()->setPosition(bodyName, x, y, z);
		
		return true;
	}
	
	return false;
}

//
//
//
bool Stop::execute(BoardView& boardView, const Cmd& cmd, QString& result)
{
	result = QString("");

	Q_ASSERT(boardView.board() != NULL);

	// Current sim body
	if (boardView.board()->getCurrentBox()) {
		boardView.board()->getCurrentBox()->stop();
		
		return true;
	}
	
	return false;
}

//
//
//
bool Start::execute(BoardView& boardView, const Cmd& cmd, QString& result)
{
	result = QString("");

	Q_ASSERT(boardView.board() != NULL);

	// Current sim body
	if (boardView.board()->getCurrentBox()) {
		boardView.board()->getCurrentBox()->start();
		
		return true;
	}
	
	return false;
}

//
//
//
bool Circle::execute(BoardView& boardView, const Cmd& cmd, QString& result)
{
	result = QString("");
	
	int radius = cmd.getArg(0).value().toInt();
	
	boardView.model()->beginModelReset();

	Q_ASSERT(boardView.board() != NULL);
	
	QGraphicsItem *item = boardView.board()->addEllipse(0, 0, radius, radius);
	
	boardView.model()->addBoardItem(cmd.fullName(), "./images/BBCircle.png", boardView.board()->name());
	
	boardView.model()->endModelReset();
	if (item) {
		item->setFlags(QGraphicsItem::ItemIsSelectable|QGraphicsItem::ItemIsMovable);
		item->setSelected(true);
		
		return true;
	}
	// give item to board
	
	return false;
}

//
//
//
bool Position::execute(BoardView& boardView, const Cmd& cmd, QString& result)
{
	result = QString("");
	
	QList<QGraphicsItem *> selectedItems = boardView.board()->selectedItems();
		
	if (selectedItems.size() > 0) {
		QGraphicsItem *selectedItem = selectedItems.at(0);
			
		QPointF p = selectedItem->pos();
			
		result = QString("x = %1, y = %2").arg(p.x()).arg(p.y());
		
		return true;
	}
	result = QString("<font color=\"red\">Select an item first.</font>");
	
	return false;
	
}

//
//
//
bool RemoveItem::execute(BoardView& boardView, const Cmd& cmd, QString& result)
{
	result = QString("");
	
	QList<QGraphicsItem *> selectedItems = boardView.board()->selectedItems();
		
	if (selectedItems.size() > 0) {
		for (int i = 0; i < selectedItems.size(); ++i) {
			boardView.board()->removeItem(selectedItems.at(i));
		}
		
		return true;
	}
	result = QString("<font color=\"red\">Select an item to remove</font>");
	// give item to board
	
	return false;
}

//
//
//
bool Group::execute(BoardView& boardView, const Cmd& cmd, QString& result)
{
	result = QString("");
	
	QList<QGraphicsItem *> selectedItems = boardView.board()->selectedItems();
		
	if (selectedItems.size() > 1) {
		boardView.board()->group();
		
		return true;
	}
	result = QString("<font color=\"red\">Select 2 or more items to group - use control key to do multi-selection</font>");
	// give item to board
	
	return false;
}

//
//
//
bool UnGroup::execute(BoardView& boardView, const Cmd& cmd, QString& result)
{
	result = QString("");
	
	boardView.board()->ungroup();
	
	return true;
	
}

//
//
//
bool Clear::execute(BoardView& boardView, const Cmd& cmd, QString& result)
{
	result = QString("");
	
	boardView.board()->clear();
	boardView.model()->clear();
	
	return true;
	
}

//
//
//
bool Put::execute(BoardView& boardView, const Cmd& cmd, QString& result)
{
	result = QString("");
	
	QString text = cmd.getArg(0).value().toString();
		
	QGraphicsItem *item = boardView.board()->addText(text);
	
	if (item) {
		item->setFlags(QGraphicsItem::ItemIsSelectable|QGraphicsItem::ItemIsMovable);
		item->setSelected(true);
		
		return true;
	}
	
	// give item to board
	return false;
}

//
//
//
bool ShowLabels::execute(BoardView& boardView, const Cmd& cmd, QString& result)
{
	result = QString("");

	Q_ASSERT(boardView.board() != NULL);

	QVariant var("ON");

	PrefManager::get().writeValue("showBodyLabel", var);

	// Current sim body
	if (boardView.board()->getCurrentBox()) {

		boardView.board()->getCurrentBox()->showLabels(true);

		return true;
	}
	
	return false;
}

//
//
//
bool HideLabels::execute(BoardView& boardView, const Cmd& cmd, QString& result)
{
	result = QString("");

	Q_ASSERT(boardView.board() != NULL);

	QVariant var("OFF");

	PrefManager::get().writeValue("showBodyLabel", var);

	// Current sim body
	if (boardView.board()->getCurrentBox()) {

		boardView.board()->getCurrentBox()->showLabels(false);

		return true;
	}
	
	return false;
}

//
//
//
bool ShowJoints::execute(BoardView& boardView, const Cmd& cmd, QString& result)
{
	result = QString("");

	Q_ASSERT(boardView.board() != NULL);

   QVariant var("ON");

	PrefManager::get().writeValue("showJoints", var);
	
	// Current sim body
	if (boardView.board()->getCurrentBox()) {
		boardView.board()->getCurrentBox()->showJoints(true);

		return true;
	}
	
	return false;
}

//
//
//
bool HideJoints::execute(BoardView& boardView, const Cmd& cmd, QString& result)
{
	result = QString("");

	Q_ASSERT(boardView.board() != NULL);

   QVariant var("OFF");

	PrefManager::get().writeValue("showJoints", var);
	
	// Current sim body
	if (boardView.board()->getCurrentBox()) {
		boardView.board()->getCurrentBox()->showJoints(false);

		return true;
	}
	
	return false;
}

//
//
//
bool CreateJoint::execute(BoardView& boardView, const Cmd& cmd, QString& result)
{
	result = QString("");
	
	QString body1 = cmd.getArg(0).value().toString();
	QString body2 = cmd.getArg(1).value().toString();

	Q_ASSERT(boardView.board() != NULL);
	
	if (body1.toUpper() == body2.toUpper()) {
		result = QString("Cannot create joint between bodies - same names for both bodies");
		
		return false;
	}

	// Current sim body
	if (boardView.board()->getCurrentBox()) {
		boardView.board()->getCurrentBox()->createJoint(body1, body2);
		
		return true;
	}
	
	return false;
}

//
//
//
bool SetGrid::execute(BoardView& boardView, const Cmd& cmd, QString& result)
{
	result = QString("");
	
	QString text = cmd.getArg(0).value().toString().toUpper();
		
	if (text == "OFF" || text == "ON") {
		boardView.board()->setGrid(text == "OFF" ? false : true);
		
		boardView.board()->update();
        
        QVariant var(text);
		
		PrefManager::get().writeValue("drawGrid", var);
	
		return true;
	}
	
	return false;
}

//
//
//
bool SetGridSize::execute(BoardView& boardView, const Cmd& cmd, QString& result)
{
	result = QString("");
	
	int size = cmd.getArg(0).value().toInt();
		
	if (size > 0) {
		boardView.board()->setGridSize(size);
		
		boardView.board()->update();
        
        QVariant var(size);
		
		PrefManager::get().writeValue("gridSize", var);
	
		return true;
	}
	
	return false;
}

//
//
//
bool SetGridColor::execute(BoardView& boardView, const Cmd& cmd, QString& result)
{
	result = QString("");
	
	int r = cmd.getArg(0).value().toInt();
	int g = cmd.getArg(1).value().toInt();
	int b = cmd.getArg(2).value().toInt();
	int a = 125;
		
	QColor color(r,g,b,a);
	
	boardView.board()->setGridColor(color);
	
	boardView.board()->update();
	
	QVariant gridColor = color;
		
	PrefManager::get().writeValue("gridColor", gridColor);
	
	return true;
}

//
//
//
bool SetFillColor::execute(BoardView& boardView, const Cmd& cmd, QString& result)
{
	result = QString("");
	
	int r = cmd.getArg(0).value().toInt();
	int g = cmd.getArg(1).value().toInt();
	int b = cmd.getArg(2).value().toInt();
	int a = cmd.getArg(3).value().toInt();
		
	QColor color(r,g,b,a);
	
	QList<QGraphicsItem *> selectedItems = boardView.board()->selectedItems();
		
	if (selectedItems.size() > 0) {
		QGraphicsColorizeEffect *colorEffect = new QGraphicsColorizeEffect();
		
		colorEffect->setColor(color);
		
		for (int i = 0; i < selectedItems.size(); ++i) {
			QGraphicsItem *item = selectedItems.at(i);
			
			item->setGraphicsEffect(colorEffect);
		}
		
		return true;
	}
	result = QString("<font color=\"red\">Select an item to color</font>");
	// give item to board
	
	return false;
}
