//
//
#ifndef CONTENTPANEL_H
#define CONTENTPANEL_H

#include <QtGui/QSplitter>
#include <QtCore/QModelIndex>

class BoardPanel;
class ObjectPanel;

//
//
class ContentPanel : public QSplitter
{
	Q_OBJECT
public:
	ContentPanel(QWidget *parent = 0);
	~ContentPanel();

	//
	void init();
protected slots:

private:
	ObjectPanel *m_ObjectPanel;
	BoardPanel *m_BoardPanel;
};

#endif // CONTENTPANEL_H
