#include "HaxeAPI.h"

value wx_create_command_event(value type, value id)
{
	try
	{
		wxCommandEvent * cmdEvt = new wxCommandEvent(Val2Int(type), Val2Int(id));
		return WXToValue(cmdEvt);
	}
	catch (...) { return alloc_null();}
}
DEFINE_PRIM(wx_create_command_event,2)

WIN_PROPERTY(wx_command_event,wxCommandEvent,string,GetString,SetString,Val2Str)
WIN_PROPERTY(wx_command_event,wxCommandEvent,int,GetInt,SetInt,Val2Int)

int link_CommandEvent() { return 0; }
