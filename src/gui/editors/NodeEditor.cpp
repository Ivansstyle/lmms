//
// Created by IVANS on 29/10/2022.
//

#include "NodeEditor.h"


#include <QAction>
#include <QApplication>
#include <QCloseEvent>
#include <QColorDialog>
#include <QComboBox>
#include <QFontDatabase>
#include <QLineEdit>
#include <QMdiArea>
#include <QTextEdit>
#include <QToolBar>
#include <QDomCDATASection>


#include "embed.h"
#include "Engine.h"

#include "lmms_basics.h"
#include "EffectChain.h"
#include "Track.h"
#include "GuiApplication.h"
#include "MainWindow.h"

namespace lmms::gui {

NodeEditor::NodeEditor() :
	QMainWindow( getGUI()->mainWindow()->workspace())
{
	this->setMinimumHeight(300);
	this->setMinimumWidth(700);
}

void NodeEditor::nodeAdded()
{
	printf("Node added! ");
}
void NodeEditor::saveSettings(QDomDocument& doc, QDomElement& element)
{
	printf("NodeEditor::SaveSettings is not implemented!!!");
}
void NodeEditor::loadSettings(const QDomElement& element)
{
	printf("NodeEditor::SaveSettings is not implemented!!!");
}
void NodeEditor::closeEvent(QCloseEvent* _ce)
{
	QWidget::closeEvent(_ce);
}
void NodeEditor::setupActions()
{
	printf("Setting up Node Editor...");
}

}












