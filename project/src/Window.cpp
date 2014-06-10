#include "HaxeAPI.h"

value wx_window_create(value inParams)
{
	CreationParams params(inParams);
   wxWindow *window = new wxWindow(params.parent,params.id,
										  params.position,params.size,params.flags);
   window->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
   return WXToValue(window);
}
DEFINE_PRIM(wx_window_create,1)

value wx_window_fit(value inWindow)
{
   wxWindow *window;
   if (ValueToWX(inWindow,window))
       window->Fit();
   return alloc_null();
}
DEFINE_PRIM(wx_window_fit,1)

value wx_window_refresh(value inWindow)
{
   wxWindow *window;
   if (ValueToWX(inWindow,window))
       window->Refresh();
   return alloc_null();
}
DEFINE_PRIM(wx_window_refresh,1)

value wx_window_destroy(value inWindow)
{
   wxWindow *window;
   if (ValueToWX(inWindow,window))
       window->Destroy();
   return alloc_null();
}
DEFINE_PRIM(wx_window_destroy,1)

void wx_window_set_foreground_colour(value inWindow, value r, value g ,value b, value a)
{
	wxWindow *window;
	if (ValueToWX(inWindow,window))
	{
		wxColour * c = new wxColour(Val2Int(r),Val2Int(g),Val2Int(b),Val2Int(a));
		window->SetForegroundColour(*c);
	}
}
DEFINE_PRIM(wx_window_set_foreground_colour,5)

void wx_window_set_font_size(value inWindow, value ptSize)
{
	wxWindow *window;
	if (ValueToWX(inWindow,window))
	{
		wxFont font = window->GetFont();
		wxFont * newFont = new wxFont(Val2Int(ptSize), font.GetFamily(), font.GetStyle(),font.GetWeight(),
			font.GetUnderlined(),font.GetFaceName(),font.GetEncoding());
		window->SetFont(*newFont);
	}
}
DEFINE_PRIM(wx_window_set_font_size,2)

void wx_window_freeze(value inWindow)
{
	wxWindow *window;
	if (ValueToWX(inWindow,window))
	{
		window->Freeze();
	}
}
DEFINE_PRIM(wx_window_freeze,1)

void wx_window_thaw(value inWindow)
{
	wxWindow *window;
	if (ValueToWX(inWindow,window))
	{
		window->Thaw();
	}
}
DEFINE_PRIM(wx_window_thaw,1)

void wx_window_enable(value inWindow)
{
	wxWindow *window;
	if (ValueToWX(inWindow,window))
	{
		window->Enable();
	}
}
DEFINE_PRIM(wx_window_enable,1)

void wx_window_disable(value inWindow)
{
	wxWindow *window;
	if (ValueToWX(inWindow,window))
	{
		window->Disable();
	}
}
DEFINE_PRIM(wx_window_disable,1)



WIN_PROPERTY(wx_window,wxWindow,size,GetSize,SetSize,Val2Size)
WIN_PROPERTY(wx_window,wxWindow,client_size,GetClientSize,SetClientSize,Val2Size)
WIN_PROPERTY(wx_window,wxWindow,position,GetPosition,SetPosition,Val2Point)
WIN_PROPERTY(wx_window,wxWindow,sizer,GetSizer,SetSizer,Val2Sizer)
WIN_PROPERTY(wx_window,wxWindow,shown,IsShown,Show,Val2Bool)
WIN_PROPERTY(wx_window,wxWindow,bg_colour,GetBackgroundColour,SetBackgroundColour,Val2Colour)
WIN_PROPERTY(wx_window,wxWindow,name,GetName,SetName,Val2Str)

int link_Window() { return 0; }

