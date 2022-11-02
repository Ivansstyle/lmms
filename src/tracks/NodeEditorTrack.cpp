//
// Created by IVANS on 02/11/2022.
//

#include "NodeEditorTrack.h"
#include "NodeEditorTrackView.h"


namespace lmms {

NodeEditorTrack::NodeEditorTrack(TrackContainer* tc)
	: Track(Track::NodeEditorTrack, tc)
{
	setName(tr("NodeEditor track"));
}

bool NodeEditorTrack::play(const TimePos& time_start, const fpp_t _frames, const f_cnt_t _frame_base, int _clip_num)
{
	return false;
}

gui::TrackView* NodeEditorTrack::createView(gui::TrackContainerView* tcv)
{
	return new gui::NodeEditorTrackView(this, tcv);
}

Clip* NodeEditorTrack::createClip(const TimePos& pos)
{
	//	auto p = new NodeEditorClip(this);
	//	p->movePosition(pos);
	//	return p;
	return nullptr;
}

void NodeEditorTrack::saveTrackSpecificSettings(QDomDocument& _doc, QDomElement& _this)
{
}

void NodeEditorTrack::loadTrackSpecificSettings(const QDomElement& _this)
{
	// just in case something somehow wrent wrong...
	//	if( type() == HiddenNodeEditorTrack )
	//	{
	//		setMuted( false );
	//	}
}
}