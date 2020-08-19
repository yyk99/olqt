//
//
//

#include <ol/events/EventTarget.h>

ol::events::EventTarget::EventTarget()
{
}

ol::events::EventTarget::~EventTarget()
{
    dispose();
}

void ol::events::EventTarget::disposeInternal()
{
    // TODO: implement
}
