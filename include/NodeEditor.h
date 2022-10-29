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
#include <vector>
class Node
{
public:
	int a{0};
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
	std::vector<Node> m_Nodes;

protected:
	void saveSettings(QDomDocument& doc, QDomElement& element) override;
	void loadSettings( const QDomElement& element) override;
};

}
}
#endif // LMMS_NODEEDITOR_H
