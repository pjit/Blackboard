//
//
#ifndef CMDARG_H
#define CMDARG_H

#include <QtCore/QVariant>

class CmdArg
{
public:
	explicit CmdArg(const QString& name, const QString& defValue);
	~CmdArg();
	//
	const QString& name() const { return m_Name; }
	//
	const QVariant& value() const { return m_Value; }
	// TODO: conversion

	void setValue(const QString& value) { m_Value = QVariant(value); }
private:
	QString m_Name;
	QVariant m_Value;
};


#endif // CMDARG_H
