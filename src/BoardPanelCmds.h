//
//
#ifndef BOARDPANELCMDS_H
#define BOARDPANELCMDS_H

#include "BoardPanel.h"
//
class Cmd;

//
//
class BoardPanelCmd
{
	public:
		virtual bool execute(BoardPanel& board, const Cmd& cmd, QString& result) = 0; 
};

//
#define DECLARE_BOARDPANEL_CMD(Command) class Command : public BoardPanelCmd {\
													public: \
														Command() {} \
														~Command() {} \
														bool execute(BoardPanel& board, const Cmd& cmd, QString& result); \
													};

//
DECLARE_BOARDPANEL_CMD(AddBoard)
DECLARE_BOARDPANEL_CMD(RemoveBoard)	
DECLARE_BOARDPANEL_CMD(SelectBoard)
DECLARE_BOARDPANEL_CMD(AddScene)
#endif // BOARDPANELCMDS_H
