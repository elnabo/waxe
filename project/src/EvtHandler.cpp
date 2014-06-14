#include "HaxeAPI.h"

value wx_evt_handler_queue_event(value evtHandler, value evt)
{
	wxEvtHandler * handler;
	wxEvent * e;
	if (ValueToWX(evtHandler,handler) && ValueToWX(evt,e))
	{
		handler->QueueEvent(e);
	}
	
	return alloc_null();
}
DEFINE_PRIM(wx_evt_handler_queue_event,2)

int link_EvtHandler() { return 0; }
