//
#include "CmdManager.h"

//
//
//
CmdManager::CmdManager()
{
	Init();
}

//
//
//
CmdManager::~CmdManager()
{
}

//
//
//
void CmdManager::registerCommand(const Cmd& cmd)
{
	QMap<QString, Cmd>::iterator it = m_CommandMap.find(cmd.name());

	if (it == m_CommandMap.end()) {
		m_Commands.push_back(cmd);

		m_CommandMap.insert(cmd.name(), cmd);
	}
}

//
//
//
//
void CmdManager::unregisterCommand(const Cmd& cmd)
{
	QMap<QString, Cmd>::iterator it = m_CommandMap.find(cmd.name());

	if (it != m_CommandMap.end()) {
		std::vector<Cmd>::iterator cmdIt = m_Commands.begin();

		while (cmdIt != m_Commands.end()) {
			if (cmd.name() == (*cmdIt).name()) {
				m_Commands.erase(cmdIt);
				break;
			}
			++cmdIt;
		}
		m_CommandMap.erase(it);
	}
}

//
//
//
bool CmdManager::getCommand(const QString& commandName, Cmd& cmd)
{
	std::vector<Cmd>::iterator cmdIt = m_Commands.begin();

	while (cmdIt != m_Commands.end()) {
		if (commandName == (*cmdIt).name()) {
			cmd = *cmdIt;
			
			return true;
		}
		++cmdIt;
	}

	return false;
}

//
//
//
void CmdManager::Init()
{
	m_Commands.clear();
	m_CommandMap.clear();
	
	registerCommand(Cmd("rotate [degrees]", "rotate","degrees","0"));
	registerCommand(Cmd("move [x] [y]", "move","x","0","y","0"));
	registerCommand(Cmd("circle [radius]", "circle","radius","0"));
	// phys-ode
	registerCommand(Cmd("addbody [bodyname] [imagepath]:def ./images/BBCircle.png","addbody","bodyname","","imagepath","./images/BBCircle.png"));
	registerCommand(Cmd("removebody [bodyname]","removebody","bodyname",""));
	registerCommand(Cmd("disablejoint [bodyname]","disablejoint","bodyname",""));
	registerCommand(Cmd("enablejoint [bodyname]","enablejoint","bodyname",""));
	registerCommand(Cmd("setgravity [x] [y] [z]", "setgravity","x","0.0","y","0.0","z","0.0"));
	registerCommand(Cmd("setstepsize [stepsize]:def 0.05", "setstepsize","stepsize","0.05"));
	registerCommand(Cmd("incstepsize", "incstepsize"));
	registerCommand(Cmd("decstepsize", "decstepsize"));
	registerCommand(Cmd("addforce [bodyname] [x] [y] [z]", "addforce","bodyname","","x","0.0","y","0.0","z","0.0"));
	registerCommand(Cmd("setmass [bodyname] [mass]","setmass","bodyname", "", "mass",""));
	registerCommand(Cmd("resetforce [bodyname]", "resetforce","bodyname",""));
	registerCommand(Cmd("setposition [bodyname] [x] [y] [z]", "setposition","bodyname","0","x","0.0","y","0.0","z","0.0"));
	registerCommand(Cmd("addforcex [bodyname] [x]","addforcex","bodyname","","x","0"));
	registerCommand(Cmd("addforcey [bodyname] [y]","addforcey","bodyname","","y","0"));
	registerCommand(Cmd("addforcez [bodyname] [z]","addforcez","bodyname","","z","0"));
	registerCommand(Cmd("inspect [bodyname] [force|position]","inspect","bodyname","","what",""));
	registerCommand(Cmd("","stop"));
	registerCommand(Cmd("","start"));
	registerCommand(Cmd("showlabels","showlabels"));
	registerCommand(Cmd("showjoints","showjoints"));
	registerCommand(Cmd("hidelabels","hidelabels"));
	registerCommand(Cmd("hidejoints","hidejoints"));
	registerCommand(Cmd("createjoint [body1] [body2]","createjoint","bodyname1","","bodyname2",""));
	//
	registerCommand(Cmd("rect [x] [y] [width] [height]","rect","x","0","y","0","width","0","height","0"));
	registerCommand(Cmd("","group"));
	registerCommand(Cmd("","remove"));
	registerCommand(Cmd("","ungroup"));
	registerCommand(Cmd("put [text]","put","text",""));
	registerCommand(Cmd("","cls"));
	registerCommand(Cmd("","clear"));
	registerCommand(Cmd("pos","pos"));
	registerCommand(Cmd("","exit"));
	registerCommand(Cmd("setgrid [on|off]","setgrid","draw",""));
	registerCommand(Cmd("setgridsize [size]","setgridsize","size",""));
	registerCommand(Cmd("setgridcolor [red] [green] [blue] [alpha]","setgridcolor","r","200","g","200","b","255","a","125"));
	registerCommand(Cmd("fillcolor [red] [green] [blue] [alpha]","fillcolor","r","255","g","255","b","255","a","255"));
	// board commands
	registerCommand(Cmd("addboard [boardname]","addboard","name",""));
   registerCommand(Cmd("removeboard [boardname]","removeboard","name",""));
	registerCommand(Cmd("selectboard [boardname","selectboard","name",""));
	registerCommand(Cmd("addscene [scenename]","addscene","name",""));
}
