//
// Created by IVANS on 02/11/2022.
//

#include "NodeEditorTrackView.h"
#include "AutomationClip.h"
#include "NodeEditorTrack.h"
#include "embed.h"
#include "Engine.h"
#include "ProjectJournal.h"
#include "StringPairDrag.h"
#include "TrackContainerView.h"
#include "TrackLabelButton.h"

namespace lmms::gui
{

NodeEditorTrackView::NodeEditorTrackView( NodeEditorTrack * _at, TrackContainerView* tcv ) :
	TrackView( _at, tcv )
{
	setFixedHeight( 32 );
	auto tlb = new TrackLabelButton(this, getTrackSettingsWidget());
	tlb->setIcon(embed::getIconPixmap("NodeEditor_track"));
	tlb->move(3, 1);
	tlb->show();
	setModel(_at);
}

void NodeEditorTrackView::dragEnterEvent( QDragEnterEvent * _dee )
{
	StringPairDrag::processDragEnterEvent( _dee, "automatable_model" );
}




void NodeEditorTrackView::dropEvent( QDropEvent * _de )
{
	QString type = StringPairDrag::decodeKey( _de );
	QString val = StringPairDrag::decodeValue( _de );
	if( type == "automatable_model" )
	{
		auto mod = dynamic_cast<AutomatableModel*>(Engine::projectJournal()->journallingObject(val.toInt()));
		if( mod != nullptr )
		{
			TimePos pos = TimePos( trackContainerView()->
								  currentPosition() +
				( _de->pos().x() -
					getTrackContentWidget()->x() ) *
					TimePos::ticksPerBar() /
					static_cast<int>( trackContainerView()->pixelsPerBar() ) )
							  .toAbsoluteBar();

			if( pos.getTicks() < 0 )
			{
				pos.setTicks( 0 );
			}

			Clip * clip = getTrack()->createClip( pos );
			auto autoClip = dynamic_cast<AutomationClip*>(clip);
			autoClip->addObject( mod );
		}
	}

	update();
}


} // namespace lmms::gui
