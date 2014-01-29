//
//
#ifndef BOARDCMDS_H
#define BOARDCMDS_H

#include <QtGui/QGraphicsView>
#include "BoardView.h"

//
class Cmd;

//
//
class BoardCmd
{
	public:
		virtual bool execute(BoardView& board, const Cmd& cmd, QString& result) = 0; 
};

//
#define DECLARE_BOARD_CMD(Command) class Command : public BoardCmd {\
													public: \
														Command() {} \
														~Command() {} \
														bool execute(BoardView& board, const Cmd& cmd, QString& result); \
													};

//
DECLARE_BOARD_CMD(Rotate)
DECLARE_BOARD_CMD(Move)
DECLARE_BOARD_CMD(Rect)
DECLARE_BOARD_CMD(Circle)
DECLARE_BOARD_CMD(Position)
DECLARE_BOARD_CMD(Group)
DECLARE_BOARD_CMD(RemoveItem)
DECLARE_BOARD_CMD(UnGroup)
DECLARE_BOARD_CMD(Clear)
DECLARE_BOARD_CMD(Put)
DECLARE_BOARD_CMD(SetGrid)
DECLARE_BOARD_CMD(SetGridSize)
DECLARE_BOARD_CMD(SetGridColor)
DECLARE_BOARD_CMD(SetFillColor)
DECLARE_BOARD_CMD(BoxCmd) // addbody
DECLARE_BOARD_CMD(RemoveBody) //
DECLARE_BOARD_CMD(DisableJoint)
DECLARE_BOARD_CMD(EnableJoint)
DECLARE_BOARD_CMD(SetGravity)
DECLARE_BOARD_CMD(SetStepSize)
DECLARE_BOARD_CMD(AddForce)
DECLARE_BOARD_CMD(AddForceX)
DECLARE_BOARD_CMD(AddForceY)
DECLARE_BOARD_CMD(AddForceZ)
DECLARE_BOARD_CMD(ResetForce)
DECLARE_BOARD_CMD(SetPosition)
DECLARE_BOARD_CMD(SetMass)
DECLARE_BOARD_CMD(Stop)
DECLARE_BOARD_CMD(Start)
DECLARE_BOARD_CMD(Inspect)
DECLARE_BOARD_CMD(ShowLabels)
DECLARE_BOARD_CMD(ShowJoints)
DECLARE_BOARD_CMD(HideLabels)
DECLARE_BOARD_CMD(HideJoints)
DECLARE_BOARD_CMD(CreateJoint)
DECLARE_BOARD_CMD(IncStepSize)
DECLARE_BOARD_CMD(DecStepSize)
#endif // BOARDCMDS_H
