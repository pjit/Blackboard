//
//
#ifndef PREFMANAGER_H
#define PREFMANAGER_H

#include <QtCore/QVariant>

//
//
class PrefManager
{
	public:
		static PrefManager& get() {
			static PrefManager prefMgr;
 
			return prefMgr;
		}

		void writeValue(const QString& name, QVariant &value);
		QVariant readValue(const QString& name);
		
	private:
		PrefManager() {}
		PrefManager(const PrefManager&);
		PrefManager& operator=(const PrefManager&);
		~PrefManager() {}
};

#endif // PREFMANAGER_H
