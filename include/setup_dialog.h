/*
 * setup_dialog.h - dialog for setting up LMMS
 *
 * Linux MultiMedia Studio
 * Copyright (c) 2004-2005 Tobias Doerffel <tobydox@users.sourceforge.net>
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
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 */


#ifndef _SETUP_DIALOG_H
#define _SETUP_DIALOG_H

#include "qt3support.h"

#ifdef QT4

#include <QDialog>
#include <QMap>

#else

#include <qdialog.h>
#include <qmap.h>

#endif

#include "audio_device.h"
#include "midi_client.h"


class QComboBox;
class QLabel;
class QSlider;

class tabBar;


class setupDialog : public QDialog
{
	Q_OBJECT
public:
	enum configTabs
	{
		GENERAL_SETTINGS, AUDIO_SETTINGS, MIDI_SETTINGS
	} ;

	setupDialog( configTabs _tab_to_open = GENERAL_SETTINGS );
	~setupDialog();


protected slots:
	virtual void accept( void );


private slots:
	// general settings widget
	void setBufferSize( int _value );
	void resetBufSize( void );
	void displayBufSizeHelp( void );

	// audio settings widget
	void audioInterfaceChanged( const QString & _driver );
	void displayAudioHelp( void );

	// MIDI settings widget
	void midiInterfaceChanged( const QString & _driver );
	void displayMIDIHelp( void );


	void toggleToolTips( bool _disabled );
	void toggleKnobUsability( bool _classical );


private:
	tabBar * m_tabBar;

	QSlider * m_bufSizeSlider;
	QLabel * m_bufSizeLbl;
	int m_bufferSize;

	bool m_disableToolTips;
	bool m_classicalKnobUsability;


	typedef QMap<QString, audioDevice::setupWidget *> aswMap;
	typedef QMap<QString, midiClient::setupWidget *> mswMap;

	QComboBox * m_audioInterfaces;
	aswMap m_audioIfaceSetupWidgets;

	QComboBox * m_midiInterfaces;
	mswMap m_midiIfaceSetupWidgets;


} ;


#endif
