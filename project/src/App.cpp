#include <wx/wx.h>
#include <wx/image.h>

#include <stdio.h>

#define NEKO_COMPATIBLE
#ifndef STATIC_LINK
#define IMPLEMENT_API
#endif

#include <hx/CFFI.h>
#include "HaxeAPI.h"
#include "WaxeBinVersion.h"
#include <WaxeWorksVersion.h>


// --- Bootstrap Object ---------------------------

static value sgOnInit;

class wxWidgetsApp : public wxApp
{
public:
    wxWidgetsApp()
    {
    }
    virtual ~wxWidgetsApp() { }
    virtual bool OnInit()
    {
       wxImage::AddHandler( new wxPNGHandler );
	   wxImage::AddHandler( new wxJPEGHandler );
	   wxImage::AddHandler( new wxGIFHandler );
	   wxImage::AddHandler( new wxPNMHandler );
	   wxImage::AddHandler( new wxPCXHandler );
	   wxImage::AddHandler( new wxICOHandler );
	   wxImage::AddHandler( new wxCURHandler );
	   wxImage::AddHandler( new wxANIHandler );
	   wxImage::AddHandler( new wxTGAHandler );
	   wxImage::AddHandler( new wxXPMHandler );

       val_call0(sgOnInit);

       SetExitOnFrameDelete(true);

       return true;
    }

};

IMPLEMENT_APP_NO_MAIN(wxWidgetsApp)


// --- Interface ---------------------------------

value wx_boot(value inOnInit)
{
  sgOnInit = inOnInit;
  wchar_t *prog[] = { (wchar_t *)0};
  int argc = 0;
  int result =  wxEntry(argc,prog);
  return alloc_int(result);
}
DEFINE_PRIM(wx_boot,1)

value wx_quit()
{
   wxTheApp->ExitMainLoop();
   return val_null;
}
DEFINE_PRIM(wx_quit,0)

value wx_set_top_window(value inWindow)
{
	wxTopLevelWindow *window;
	if (ValueToWX(inWindow,window))
   	wxTheApp->SetTopWindow(window);
   return val_null;
}
DEFINE_PRIM(wx_set_top_window,1)


value wx_get_ndll_version()
{
   return alloc_int( WAXE_BINARY_VERSION );
}
DEFINE_PRIM(wx_get_ndll_version,0);

value wx_get_waxe_works_version()
{
   return alloc_string( WAXE_WORKS_VERSION );
}
DEFINE_PRIM(wx_get_waxe_works_version,0);


int link_App() { return 0; }



