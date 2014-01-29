//
//
#ifndef CMDMANAGER_H
#define CMDMANAGER_H

#include <QtCore/QMap>
#include "Cmd.h"

class CmdManager
{
public:
	CmdManager();
	~CmdManager();

	//
	void registerCommand(const Cmd& cmd);
	//
	void unregisterCommand(const Cmd& cmd);
	//
	bool getCommand(const QString& commandName, Cmd& cmd);
	//
	void Init();
private:
	std::vector<Cmd> m_Commands;
	// Fast retrieval
	QMap<QString, Cmd> m_CommandMap;
};

#endif // CMDMANAGER_H
