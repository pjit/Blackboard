//
#include "Cmd.h"

//
//
//
Cmd::Cmd(const QString& helpString, const QString& name)
	: m_Name(name), m_Help(QString("<b>syntax: ") + helpString + QString("</b>"))
{
}

//
//
//
Cmd::~Cmd()
{
}

//
//
//
void Cmd::addArg(const CmdArg& arg)
{
	// TODO: Validate
	m_Args.push_back(arg);
}

//
//
//
void Cmd::setArg(int index, const QString& value)
{
	if (index >= 0 && index < static_cast<int>(m_Args.size())) {
		m_Args.at(index).setValue(value);
	}
}

//
//
//
CmdArg Cmd::getArg(int index) const
{
	if (index >= 0 && index < static_cast<int>(m_Args.size())) {
		return m_Args[index];
	}

	return CmdArg("","");
}

//
//
//
Cmd::Cmd(const QString& helpString, const QString& name, const QString& arg1Name, const QString& arg1Def)
: m_Name(name)
{
	m_Help = QString("<b>syntax: ") + helpString + QString("</b>");
	
	CmdArg arg1(arg1Name, arg1Def);
	
	addArg(arg1);
}

//
//
//
Cmd::Cmd(const QString& helpString, const QString& name, const QString& arg1Name, const QString& arg1Def,
			const QString& arg2Name, const QString& arg2Def)
	: m_Name(name), m_Help(QString("<b>syntax: ") + helpString + QString("</b>"))
{
	CmdArg arg1(arg1Name, arg1Def);
	
	addArg(arg1);
	
	CmdArg arg2(arg2Name, arg2Def);
	
	addArg(arg2);
}

//
//
//
Cmd::Cmd(const QString& helpString, const QString& name, const QString& arg1Name, const QString& arg1Def,
			const QString& arg2Name, const QString& arg2Def,
			const QString& arg3Name, const QString& arg3Def)
	: m_Name(name), m_Help(QString("<b>syntax: ") + helpString + QString("</b>"))
{
	CmdArg arg1(arg1Name, arg1Def);
	
	addArg(arg1);
	
	CmdArg arg2(arg2Name, arg2Def);
	
	addArg(arg2);
	
	CmdArg arg3(arg3Name, arg3Def);
	
	addArg(arg3);
}

//
//
//
Cmd::Cmd(const QString& helpString, const QString& name, const QString& arg1Name, const QString& arg1Def,
			const QString& arg2Name, const QString& arg2Def,
			const QString& arg3Name, const QString& arg3Def,
			const QString& arg4Name, const QString& arg4Def)
	: m_Name(name), m_Help(QString("<b>syntax: ") + helpString + QString("</b>"))
{
	CmdArg arg1(arg1Name, arg1Def);
	
	addArg(arg1);
	
	CmdArg arg2(arg2Name, arg2Def);
	
	addArg(arg2);
	
	CmdArg arg3(arg3Name, arg3Def);
	
	addArg(arg3);
	
	CmdArg arg4(arg4Name, arg4Def);
	
	addArg(arg4);
}

//
//
//
Cmd::Cmd(const Cmd& cmd)
{
	m_Name = cmd.name();
	m_Help = cmd.help();
		
	for (int i = 0; i < cmd.argumentCount(); ++i) {
		m_Args.push_back(cmd.getArg(i));
	}
}

//
//
//
Cmd& Cmd::operator=(const Cmd& cmd)
{
	if (this != &cmd) {
		m_Name = cmd.name();
		m_Help = cmd.help();
		
		m_Args.clear();
		
		for (int i = 0; i < cmd.argumentCount(); ++i) {
			m_Args.push_back(cmd.getArg(i));
		}
	}
	
	return *this;
}

//
//
//
QString Cmd::fullName() const
{
	QString fullcommand(name());
	
	for (int i = 0; i < argumentCount(); ++i) {
		fullcommand += getArg(i).value().toString();
	}
	
	return fullcommand;
}