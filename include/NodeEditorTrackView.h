//
// Created by IVANS on 02/11/2022.
//

#ifndef LMMS_NODEEDITORTRACKVIEW_H
#define LMMS_NODEEDITORTRACKVIEW_H

#include "TrackView.h"




namespace lmms{
class NodeEditorTrack;
class NodeEditor;

namespace gui {

class NodeEditorTrackView : public TrackView
{
public:
	NodeEditorTrackView(NodeEditorTrack* at, TrackContainerView* tcv);
	~NodeEditorTrackView() override = default;

	void dragEnterEvent(QDragEnterEvent* _dee) override;
	void dropEvent(QDropEvent* _de) override;

private:
	NodeEditor * m_nodeEditor;
	void showNodeEditor();
};

}
}
#endif // LMMS_NODEEDITORTRACKVIEW_H