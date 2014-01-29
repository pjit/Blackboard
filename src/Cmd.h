//
//
#ifndef CMD_H
#define CMD_H

#include <vector>
#include "CmdArg.h"

//
//
//
class Cmd
{
public:
	Cmd(const QString& helpString, const QString& name);
	Cmd(const QString& helpString, const QString& name, const QString& arg1Name, const QString& arg1Def);
	Cmd(const QString& helpString, const QString& name, const QString& arg1Name, const QString& arg1Def,
			const QString& arg2Name, const QString& arg2Def);
	Cmd(const QString& helpString, const QString& name, const QString& arg1Name, const QString& arg1Def,
			const QString& arg2Name, const QString& arg2Def,
			const QString& arg3Name, const QString& arg3Def);
	Cmd(const QString& helpString, const QString& name, const QString& arg1Name, const QString& arg1Def,
			const QString& arg2Name, const QString& arg2Def,
			const QString& arg3Name, const QString& arg3Def,
			const QString& arg4Name, const QString& arg4Def);
	~Cmd();
	//
	Cmd(const Cmd&);
	Cmd& operator=(const Cmd&);
	
	//
	QString name() const { return m_Name; }
	//
	int argumentCount() const { return m_Args.size(); }
	//
	void addArg(const CmdArg& arg);
	//
	void setArg(int index, const QString& value);
	CmdArg getArg(int index) const;
	//
	QString help() const { return m_Help; }
	// Returns entered version of command w/o any parsing
	QString fullName() const;
private:
	QString m_Name;
	QString m_Help;
	std::vector<CmdArg> m_Args;
};

#endif // CMD_H
