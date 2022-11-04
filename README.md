# Node Editor inside LMMS
Flexible audio routing? Visual approach? Instrument mixing? Custom CC control patterns? Mastering setups??? If you can dream it you can make it using node editor.

(disclaimer) anything here may be changed at any point (disclaimer)

Why?
------------
I have always had issues adopting to DAW interface, specifically when trying to do something custom. Most DAW workstations designs make you follow a specific pattern of music production. While usually flexibily is there, to access specific things or patterns of usage requires long hours with the manual or watching massive amount of youtube. However, coming from Animation/VFX/Games, a lot of state-of-the-art software uses node-based workflow to simplify tasks. (Houdini, Blender, Unreal...).

Looking at how modular synthesizers allow people experiment and create amazing pieces from simple waves, I became a strong believer of connecting everything to everything. Discovering LMMS as an active open-source project, and having a modular node-based DAW in mind for a long time, I decided to implement node editor as a feature to support creative approach to sound-synthesis, arrangement, recording and mixing. AKA create your own dataflow for your flow!

How?
-----------
I will incrementally implement Node Editor as a base feature of LMMS DAW. Node Editor will become intermediate step of processing of any track excluding automation. Node Editor will also become a separate track entity. 

NodeEditor itself based on [paceholder/nodeeditor](https://github.com/paceholder/nodeeditor) by Dmitry Pinaev and contributors. 

Task list: 
* Introduce NodeEditor to LMMS Views (Done)
* while(!done)
	1. Create new node models 
	2. Create widgets for node controls 
	3. Connect to LMMS internals 
	4. Test and experiment
* Create basic nodes (Sound source, Effect Rack, Mix, Export to Mixer)
* Create MIDI, instrument and sample nodes (Instrument, Sample, MIDI In, MIDI mix? )
* Create logic nodes ( switch, condition, AND, OR etc) 
* Think of more nodes 

### That how it looks like now: 
![NodeEditor_LMMS](https://user-images.githubusercontent.com/15091484/200057985-8b4d959b-947e-4e6d-ae30-417a04b474e0.png)

Feel free to comment, share, try, blame me for my code, contribute and help! 




# ![LMMS Logo](https://raw.githubusercontent.com/LMMS/artwork/master/Icon%20%26%20Mimetypes/lmms-64x64.svg) LMMS

[![Build status](https://circleci.com/gh/LMMS/lmms.svg?style=shield)](https://circleci.com/gh/LMMS/lmms)
[![Latest stable release](https://img.shields.io/github/release/LMMS/lmms.svg?maxAge=3600)](https://lmms.io/download)
[![Overall downloads on Github](https://img.shields.io/github/downloads/LMMS/lmms/total.svg?maxAge=3600)](https://github.com/LMMS/lmms/releases)
[![Join the chat at Discord](https://img.shields.io/badge/chat-on%20discord-7289DA.svg)](https://discord.gg/3sc5su7)
[![Localise on transifex](https://img.shields.io/badge/localise-on_transifex-green.svg)](https://www.transifex.com/lmms/lmms/)

**New PRs may be affected by ongoing reorganization ([#5592](https://github.com/LMMS/lmms/issues/5592)). Please be prepared to rebase your PR as necessary.**

What is LMMS?
--------------

LMMS is a free cross-platform alternative to commercial programs like
FL Studio®, which allow you to produce music with your computer. This includes
the creation of melodies and beats, the synthesis and mixing of sounds, and
arranging of samples. You can have fun with your MIDI-keyboard and much more;
all in a user-friendly and modern interface.

[Homepage](https://lmms.io)<br>
[Downloads/Releases](https://github.com/LMMS/lmms/releases)<br>
[Developer Wiki](https://github.com/LMMS/lmms/wiki)<br>
[Artist & User Wiki/Documentation](https://lmms.io/documentation)<br>
[Sound Demos](https://lmms.io/showcase/)<br>
[LMMS Sharing Platform](https://lmms.io/lsp/) Share your songs!

Features
---------

* Song-Editor for composing songs
* Pattern-Editor for creating beats and patterns
* An easy-to-use Piano-Roll for editing patterns and melodies
* A Mixer with unlimited mixer channels and arbitrary number of effects
* Many powerful instrument and effect-plugins out of the box
* Full user-defined track-based automation and computer-controlled automation sources
* Compatible with many standards such as SoundFont2, VST(i), LADSPA, GUS Patches, and full MIDI support
* MIDI file importing and exporting

Building
---------

See [Compiling LMMS](https://github.com/LMMS/lmms/wiki/Compiling) on our
wiki for information on how to build LMMS.


Join LMMS-development
----------------------

If you are interested in LMMS, its programming, artwork, testing, writing demo
songs, (and improving this README...) or something like that, you're welcome
to participate in the development of LMMS!

Information about what you can do and how can be found in the
[wiki](https://github.com/LMMS/lmms/wiki).

Before coding a new big feature, please _always_
[file an issue](https://github.com/LMMS/lmms/issues/new) for your idea and
suggestions about your feature and about the intended implementation on GitHub,
or ask in one of the tech channels on Discord and wait for replies! Maybe there are different ideas, improvements, or hints, or
maybe your feature is not welcome/needed at the moment.
