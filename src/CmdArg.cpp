//
#include "CmdArg.h"

//
//
//
CmdArg::CmdArg(const QString& name, const QString& defValue)
: m_Name(name) , m_Value(QVariant(defValue))
{
}

//
//
//
CmdArg::~CmdArg()
{
}
