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


