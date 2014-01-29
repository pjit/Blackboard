//
#include "PrefManager.h"
#include <QtCore/QSettings>
#include <QtCore/QSize>

//
//
//
void PrefManager::writeValue(const QString& name, QVariant &value)
{
	QSettings appSettings;

	if (name == "mainWindowSize") appSettings.setValue(name, value.toSize());
	if (name == "drawGrid") appSettings.setValue(name, value.toString());
	if (name == "gridSize") appSettings.setValue(name, value.toInt());
	
	if (name == "gridColor") {
		appSettings.setValue(name, value);
	}
}

//
//
//
QVariant PrefManager::readValue(const QString& name)
{
	QSettings appSettings;
	
	if (name == "mainWindowSize") return appSettings.value(name).toSize();
	if (name == "drawGrid") return appSettings.value(name).toString();
	if (name == "gridSize") return appSettings.value(name).toInt();
	if (name == "gridColor") return appSettings.value(name);
	
	return QVariant();
}
