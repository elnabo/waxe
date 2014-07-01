#include "HaxeAPI.h"
value wx_frame_create(value inParams)
{
   CreationParams params(inParams,wxDEFAULT_FRAME_STYLE);
   wxFrame *frame = new wxFrame(params.parent,params.id,params.text,
                                params.position,params.size,params.flags);

   return WXToValue(frame);
}

DEFINE_PRIM(wx_frame_create,1)

value wx_frame_set_menu_bar(value inFrame, value inBar)
{
   wxFrame *frame;
   if (ValueToWX(inFrame,frame))
   {
      wxMenuBar *bar;
      ValueToWX(inBar,bar);
      frame->SetMenuBar(bar);
   }
   return alloc_null();
}
DEFINE_PRIM(wx_frame_set_menu_bar,2)

value wx_top_level_window_set_icon(value inWindow, value inIcon)
{
	wxTopLevelWindow * window;
	wxIcon * icon;
	if (ValueToWX(inWindow,window) && ValueToWX(inIcon,icon))
	{
		window->SetIcon(*icon);
	}
	return alloc_null();
}

DEFINE_PRIM(wx_top_level_window_set_icon,2)

value wx_top_level_window_iconize(value inWindow, value iconize)
{
	wxTopLevelWindow * window;
	if (ValueToWX(inWindow,window))
	{
		window->Iconize(Val2Bool(iconize));
	}
	return alloc_null();
}

DEFINE_PRIM(wx_top_level_window_iconize,2)

value wx_top_level_window_is_iconized(value inWindow)
{
	wxTopLevelWindow * window;
	if (ValueToWX(inWindow,window))
	{
		try
		{
			return alloc_bool(window->IsIconized());
		}
		catch(...)
		{
			return alloc_bool(false);
		}
	}
	return alloc_null();
}

DEFINE_PRIM(wx_top_level_window_is_iconized,1)

value wx_top_level_window_is_active(value inWindow)
{
	wxTopLevelWindow * window;
	if (ValueToWX(inWindow,window))
	{
		try
		{
			return alloc_bool(window->IsActive());
		}
		catch(...)
		{
			return alloc_bool(false);
		}
	}
	return alloc_null();
}

DEFINE_PRIM(wx_top_level_window_is_active,1)

int link_Frame() { return 0; }

