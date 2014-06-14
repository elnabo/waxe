#include "HaxeAPI.h"

value wx_new_event_type()
{
	return alloc_int(wxNewEventType());
}
DEFINE_PRIM(wx_new_event_type,0)

value wx_queue_event(value dest, value event)
{
	wxWindow * handler;
	wxEvent * e;
	if (ValueToWX(dest,handler) && ValueToWX(event,e))
	{
		handler->GetEventHandler()->QueueEvent(e);
	}
	return alloc_null();
}
DEFINE_PRIM(wx_queue_event,2)


int link_Event() { return 0; }
