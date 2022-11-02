//
// Created by IVANS on 02/11/2022.
//

#ifndef LMMS_NODEEDITORTRACK_H
#define LMMS_NODEEDITORTRACK_H

#include "Track.h"


namespace lmms{

class NodeEditorTrack : public Track
{
	Q_OBJECT
public:
	explicit NodeEditorTrack( TrackContainer* tc);
	~NodeEditorTrack() override = default;

	bool play( const TimePos & _start, const fpp_t _frames,
		const f_cnt_t _frame_base, int _clip_num = -1 ) override;

	QString nodeName() const override
	{
		return "automationtrack";
	}

	gui::TrackView * createView( gui::TrackContainerView* ) override;
	Clip* createClip(const TimePos & pos) override;

	void saveTrackSpecificSettings( QDomDocument & _doc,
		QDomElement & _parent ) override;
	void loadTrackSpecificSettings( const QDomElement & _this ) override;

private:
	friend class AutomationTrackView;



};

}

#endif // LMMS_NODEEDITORTRACK_H
