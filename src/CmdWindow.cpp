//
#include "CmdWindow.h"
#include "CmdManager.h"
#include <QtGui/QKeyEvent>
#include <QtGui/QTextCursor>
#include <QtGui/QApplication>

//
//
//
CmdWindow::CmdWindow(QWidget *parent)
	: QTextEdit(parent), m_CmdManager(NULL)
{
}

//
//
//
CmdWindow::~CmdWindow()
{
	delete m_CmdManager;
}

//
//
//
void CmdWindow::init()
{	
	installEventFilter(this);
	//
	insertHtml(CMDWINDOWCURSOR);
	
	// Initialize command manager
	m_CmdManager = new CmdManager();
}

//
//
//
QSize CmdWindow::minimumSizeHint() const
{
	return QSize(0, 5*16);
}

//
//
//
void CmdWindow::showCursor()
{
	insertHtml(QString("<br/>") + CMDWINDOWCURSOR);
	
	QTextCursor c = textCursor();
	
	c.movePosition(QTextCursor::End);
	
	setTextCursor(c);
}

//
//
//
bool CmdWindow::execute()
{	
	QTextCursor cursor = textCursor();
    
	cursor.movePosition(QTextCursor::StartOfLine, QTextCursor::MoveAnchor, 1);
	cursor.movePosition(QTextCursor::EndOfLine, QTextCursor::KeepAnchor, 1);
				
	QString cmdText = cursor.selectedText();
	
	// Get full command text
	cmdText = cmdText.remove(0, 2);
	
	QString commandText = cmdText.simplified();
	
		// If "exit" just call quit.
	// TODO give view change to save
	if (commandText == "exit") {
		qApp->closeAllWindows();
	}
	
	// Tokenize it based on "space" for now
	QStringList cmdTokens = commandText.split(' ');
	
	if (cmdTokens.size() > 0) {
		QString commandName = cmdTokens.at(0);
		Cmd cmdObj("","");
		
		if (m_CmdManager->getCommand(commandName, cmdObj)) {
			// special handling
			if (cmdObj.name() == "cls") {
				clear();
				
				insertHtml(CMDWINDOWCURSOR);
				
				return true;
			}
			
			int argsPassed = cmdTokens.size() - 1;
			int argsExpected = cmdObj.argumentCount();
			
			if (argsPassed == argsExpected) {
				Cmd cmdToExecute = cmdObj;
				
				for (int i = 0; i < argsPassed; ++i) {
					cmdToExecute.setArg(i, cmdTokens.at(i+1));
				}
			
				emit commandEntered(cmdToExecute);
			}
			else if (argsPassed < argsExpected) {
				Cmd cmdToExecute = cmdObj;
				int i = 0;
				bool commandOk = true;
				
				for (; i < argsPassed; ++i) {
					cmdToExecute.setArg(i, cmdTokens.at(i+1));
				}
				for (int j = i; j < argsExpected; ++j) {
					if (!cmdToExecute.getArg(j).value().toString().isEmpty()) {
						cmdToExecute.setArg(i, cmdToExecute.getArg(j).value().toString());
					}
					else {
					   commandOk = false;
						slotCommandResults(cmdObj.help());
						break;
					}
				}
				if (commandOk) {
					emit commandEntered(cmdToExecute);
				}
			}
			else {
				slotCommandResults(cmdObj.help());
			}
		}
		else {
			slotCommandResults(QString("Invalid Command"));
		}
		showCursor();
		
		return true;
	}

	showCursor();

	return false;
}

//
//
//
bool CmdWindow::eventFilter(QObject *obj, QEvent *event)
{
	if (obj == this) {
		if (event->type() == QEvent::KeyPress) {
			QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
			
			switch (keyEvent->key()) {
			case Qt::Key_Backspace:
			case Qt::Key_Left:
			case Qt::Key_Right:
			case Qt::Key_Down:
			case Qt::Key_Up:
			{
				QTextCursor cursor = textCursor();
    
				cursor.movePosition(QTextCursor::StartOfLine, QTextCursor::MoveAnchor, 1);
				cursor.movePosition(QTextCursor::EndOfLine, QTextCursor::KeepAnchor, 1);
				// If it prompt, consume.
				if (cursor.selectedText() == CMDWINDOWCURSORPLAIN) {
					return true; // Consume
				}
			}
			break;
				
			case Qt::Key_Enter:
			case Qt::Key_Return:
				execute();
				return true;
				break;
			}
			return false;		
		}
		else {
			return QObject::eventFilter(obj, event);
		}
    }
	else {
		return QObject::eventFilter(obj, event);
    }
}

//
//
//
void CmdWindow::slotCommandResults(const QString& result)
{
	insertHtml(QString("<br/>") + result);
}

//
//
//
void CmdWindow::mouseReleaseEvent(QMouseEvent *e)
{
	QTextEdit::mouseReleaseEvent(e);
}
