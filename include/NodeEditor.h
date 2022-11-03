/*
* AutomationEditor.cpp - implementation of AutomationEditor which is used for
*						actual setting of dynamic values
*
* Copyright (c) 2006-2008 Ivans Saponenko <code.ivans.style>
*
* This file is part of LMMS - https://lmms.io
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public
* License as published by the Free Software Foundation; either
* version 2 of the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* General Public License for more details.
*
* You should have received a copy of the GNU General Public
* License along with this program (see COPYING); if not, write to the
* Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
* Boston, MA 02110-1301 USA.
*
*/
//
// Created by IVANS on 29/10/2022.
//

#ifndef LMMS_NODEEDITOR_H
#define LMMS_NODEEDITOR_H

#include <QMainWindow>
#include "lmms_basics.h"
#include "JournallingObject.h"
#include "SerializingObject.h"
// Finally loading
#include <nodes/Node>
#include <nodes/FlowView>
#include <nodes/FlowScene>
#include <vector>

// Node data models
#include <nodes/NodeDataModel>


class SoundNodeData : public QtNodes::NodeData
{
public:
	QtNodes::NodeDataType type() const override {
		return QtNodes::NodeDataType{"SoundNodeData", "Sound Node Data"};
	}
};

class MidiNodeData : public QtNodes::NodeData
{
public:
	QtNodes::NodeDataType type() const override {
		return QtNodes::NodeDataType{"MidiNodeData", "Midi Node Data"};
	}
};

class SoundSourceNodeModel : public QtNodes::NodeDataModel
{
	Q_OBJECT
public:
	virtual ~SoundSourceNodeModel(){}
private:
	SoundNodeData m_out_soundData;
public:
	QString caption() const override {return {"Sound Source Data Model"};}
	QString name() const override {return {"SoundSourceDataModel"};}
	unsigned int nPorts(QtNodes::PortType portType) const override {
		uint result = -1;
		switch (portType)
		{
		case QtNodes::PortType::In:
			result = 0;
			break;
		case QtNodes::PortType::None:
			break;
		case QtNodes::PortType::Out:
			result = 1;
			break;
		}
		return result;
	}
	QtNodes::NodeDataType dataType(QtNodes::PortType portType, QtNodes::PortIndex portIndex) const override {
		switch (portType)
		{
		case QtNodes::PortType::Out:
			switch (portIndex)
			{
			case 0:
				return SoundNodeData().type();
			}
		}
		return {};
	}
	std::shared_ptr<QtNodes::NodeData> outData(QtNodes::PortIndex port) override
	{
		switch(port)
		{
		case 0:
			return std::make_shared<SoundNodeData>(m_out_soundData);
		}
	}
	QWidget * embeddedWidget() override {return nullptr; /* add embedded widget to control stuff here*/};

	void setInData(std::shared_ptr<QtNodes::NodeData>, int) override {
		// Nothing to set in
	}
};
class SoundExportNodeModel : public QtNodes::NodeDataModel
{
	Q_OBJECT
public:
	virtual ~SoundExportNodeModel(){}
private:
	 SoundNodeData m_in_soundData;

public:
	QString caption() const override {return QString("Sound Export Data Model");}
	QString name() const override {return QString("SoundExportDataModel");}

	uint nPorts(QtNodes::PortType portType) const override
	{
		uint result = -1;
		switch (portType)
		{
		case QtNodes::PortType::In:
			result = 1;
			break;
		case QtNodes::PortType::None:
			break;
		case QtNodes::PortType::Out:
			result = 0;
			break;
		}
		return result;
	}
	QtNodes::NodeDataType dataType(QtNodes::PortType portType, QtNodes::PortIndex portIndex) const override {
		switch (portType)
		{
		case QtNodes::PortType::In:
			switch (portIndex)
			{
			case 0:
				return SoundNodeData().type();
			}
			break;
		case QtNodes::PortType::Out:
			switch (portIndex)
			{
			case 0:
				return SoundNodeData().type();
			}
		}
		return {};
	}
	void setInData(std::shared_ptr<QtNodes::NodeData> nodeData, QtNodes::PortIndex port) override
	{
		switch (port)
		{
		case 0:
			std::shared_ptr<QtNodes::NodeData> m_in_soundData(nodeData);
		}
	}
	std::shared_ptr<QtNodes::NodeData> outData(QtNodes::PortIndex port) override
	{
		// No out data yet
		// Any out data goes here
		return nullptr;
	}
	QWidget * embeddedWidget() override {return nullptr; /* add embedded widget to control stuff here*/};
};

class SoundMixNodeModel : public QtNodes::NodeDataModel
{
	Q_OBJECT
public:
	virtual ~SoundMixNodeModel(){}

private:
	SoundNodeData m_in0_soundData;
	SoundNodeData m_in1_soundData;
	SoundNodeData m_out_soundData;

public:
	QString caption() const override {return QString("Sound Mix Data Model");}
	QString name() const override {return QString("SoundMixDataModel");}
	uint nPorts(QtNodes::PortType portType) const override{
		uint result = -1;
		switch (portType)
		{
		case QtNodes::PortType::In:
			result = 2;
			break;
		case QtNodes::PortType::None:
			break;
		case QtNodes::PortType::Out:
			result = 1;
			break;
		}
		return result;
	}
	QtNodes::NodeDataType dataType(QtNodes::PortType portType, QtNodes::PortIndex portIndex) const override {
		switch (portType)
		{
		case QtNodes::PortType::In:
			switch (portIndex)
			{
			case 0:
				return SoundNodeData().type();
			case 1:
				return  SoundNodeData().type();
			}
			break;
		case QtNodes::PortType::Out:
			switch (portIndex)
			{
			case 0:
				return SoundNodeData().type();
			}
		}
	}
	void setInData(std::shared_ptr<QtNodes::NodeData> nodeData, QtNodes::PortIndex port) override
	{
		switch (port)
		{
		case 0:
			//m_in0_soundData = SoundNodeData(nodeData);
			printf("Out 1");
			break;
		case 1:
			printf("Out 2");
			//std::shared_ptr<QtNodes::NodeData> m_in1_soundData(nodeData);
			break;
		}
	}
	std::shared_ptr<QtNodes::NodeData> outData(QtNodes::PortIndex port) override
	{
		switch (port)
		{
		case 0:
			return std::make_shared<SoundNodeData>(m_out_soundData);
		}
	}
	QWidget * embeddedWidget() override {return nullptr; /* add embedded widget to control stuff here*/};
};



namespace lmms {
namespace gui {
class NodeEditor : public QMainWindow, public JournallingObject
{
	Q_OBJECT

public:
	NodeEditor();
	~NodeEditor() override = default;

	[[nodiscard]] inline QString nodeName() const override { return "nodeeditor"; }

protected:
	void closeEvent(QCloseEvent* _ce) override;
	void setupActions();

private slots:
	void nodeAdded();


private:
	QtNodes::FlowScene m_flowScene;
	QtNodes::FlowView m_FlowView;
	std::vector<int> m_Nodes;

protected:
	void saveSettings(QDomDocument& doc, QDomElement& element) override;
	void loadSettings( const QDomElement& element) override;
};

}
}
#endif // LMMS_NODEEDITOR_H
