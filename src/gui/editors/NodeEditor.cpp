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
#include <nodes/DataModelRegistry>
#include "EffectRackView.h"

EffectNodeModel::EffectNodeModel() : QtNodes::NodeDataModel()
{
	auto ml = new QHBoxLayout;
	ml->setContentsMargins( 0, 4, 0, 0 );

	// create rack layout before creating the first channel
	m_effectChain = new lmms::EffectChain(nullptr); // Why nullptr for model? Used like this everywhere...
	m_racksWidget = new QWidget;
	m_rackView = new lmms::gui::EffectRackView(m_effectChain, m_racksWidget);
	m_racksLayout = new QStackedLayout( m_racksWidget );
	m_racksLayout->setContentsMargins( 0, 0, 0, 0 );
	m_racksWidget->setLayout( m_racksLayout );
	m_racksLayout->addWidget(m_rackView);
}

static std::shared_ptr<QtNodes::DataModelRegistry> registerDataModels()
{
	// Register node models here
	auto ret = std::make_shared<QtNodes::DataModelRegistry>();
	ret->registerModel<SoundSourceNodeModel>();
	ret->registerModel<SoundExportNodeModel>();
	ret->registerModel<SoundMixNodeModel>();
	ret->registerModel<EffectNodeModel>();
	return ret;
}

namespace lmms::gui {

NodeEditor::NodeEditor() :
	QMainWindow( getGUI()->mainWindow()->workspace()),
	m_flowScene(registerDataModels()),
	m_FlowView(&m_flowScene)
{
	this->setMinimumHeight(300);
	this->setMinimumWidth(700);
	this->setCentralWidget(&m_FlowView);

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












