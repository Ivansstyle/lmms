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
#include <QLabel>


#include "embed.h"
#include "Engine.h"

#include "lmms_basics.h"
#include "EffectChain.h"
#include "Track.h"
#include "GuiApplication.h"
#include "MainWindow.h"
#include <nodes/DataModelRegistry>
#include "EffectRackView.h"
#include "Knob.h"

SoundMixNodeModel::SoundMixNodeModel() : QtNodes::NodeDataModel()
{
	m_mixWidget = new QWidget();
	auto ml = new QHBoxLayout(m_mixWidget);
	m_volumeAKnob = new lmms::gui::Knob(m_mixWidget, tr("Mix A"));
	m_volumeAKnob->setLabel(tr("Mix A"));

	m_volumeBKnob = new lmms::gui::Knob(m_mixWidget, tr("Mix B"));
	m_volumeBKnob->setLabel(tr("Mix B"));
	ml->addWidget(m_volumeAKnob);
	ml->addWidget(m_volumeBKnob);
}

SoundSourceNodeModel::SoundSourceNodeModel() : QtNodes::NodeDataModel()
{
	m_inputWidget = new QWidget();
	auto ml = new QHBoxLayout(m_inputWidget);
	m_inputSelector = new QComboBox(m_inputWidget);

	// Set selector to track names, and connect track change to update track names
	auto noTrackSelected = QString(tr("No Track Selected"));
	m_inputSelector->addItem(noTrackSelected);
	auto label = new QLabel("Input from track:");
	ml->addWidget(label);
	ml->addWidget(m_inputSelector);

}

SoundExportNodeModel::SoundExportNodeModel() : QtNodes::NodeDataModel()
{
//	m_volumeKnob = new Knob( knobSmall_17, getTrackSettingsWidget(),
//		tr( "Volume" ) );
//	m_volumeKnob->setVolumeKnob( true );
//	m_volumeKnob->setModel( &_it->m_volumeModel );
//	m_volumeKnob->setHintText( tr( "Volume:" ), "%" );
//	m_volumeKnob->move( widgetWidth-2*24, 2 );
//	m_volumeKnob->setLabel( tr( "VOL" ) );
//	m_volumeKnob->show();
//
//	m_panningKnob = new Knob( knobSmall_17, getTrackSettingsWidget(),
//		tr( "Panning" ) );
//	m_panningKnob->setModel( &_it->m_panningModel );
//	m_panningKnob->setHintText(tr("Panning:"), "%");
//	m_panningKnob->move( widgetWidth-24, 2 );
//	m_panningKnob->setLabel( tr( "PAN" ) );
//	m_panningKnob->show();

	m_exportWidget = new QWidget;
	auto ml = new QHBoxLayout(m_exportWidget);
	QString labelStyleSheet = "font-size: 6pt;";
	m_panKnob = new lmms::gui::Knob(m_exportWidget, tr("PAN"));
	m_volumeKnob = new lmms::gui::Knob(m_exportWidget, tr("VOLUME"));
	m_mixerSpinbox = new lmms::gui::MixerLineLcdSpinBox(2, nullptr, tr("Mixer Channel"), nullptr); // Track View set as nullptr
	m_volumeKnob->setVolumeKnob(true);
	m_volumeKnob->setLabel("VOL");
	m_panKnob->setLabel("PAN");
//	auto label = new QLabel(tr("CHANNEL"),m_exportWidget);
//	label->setStyleSheet(labelStyleSheet);
	m_mixerSpinbox->setLabel("CHANNEL");

	ml->addWidget(m_panKnob);
	ml->addWidget(m_volumeKnob);
	ml->addWidget(m_mixerSpinbox);
}

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












