//
#include "BoardPanelCmds.h"
#include "PrefManager.h"
#include "Cmd.h"
#include "CmdArg.h"

//
//
//
bool AddBoard::execute(BoardPanel& boardPanel, const Cmd& cmd, QString& result)
{
	result = QString("");
	
	QString text = cmd.getArg(0).value().toString();
		
	// TODO Check return status
	boardPanel.addBoard(text);

	return true;
}

//
//
//
bool RemoveBoard::execute(BoardPanel& boardPanel, const Cmd& cmd, QString& result)
{
	result = QString("");
	
	QString text = cmd.getArg(0).value().toString();

	boardPanel.removeBoard(text);

	return true;
}

//
//
//
bool SelectBoard::execute(BoardPanel& boardPanel, const Cmd& cmd, QString& result)
{
	result = QString("");
	
	QString text = cmd.getArg(0).value().toString();

	boardPanel.selectBoard(text);

	return true;
}

//
//
//
bool AddScene::execute(BoardPanel& boardPanel, const Cmd& cmd, QString& result)
{
	result = QString("");
	
	QString text = cmd.getArg(0).value().toString();
		
	// TODO Check return status
	boardPanel.addScene(text);

	return true;
}