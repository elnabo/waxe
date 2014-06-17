#include "HaxeAPI.h"
#include <wx/mstream.h>

value wx_icon_from_file(value path, value type)
{
	wxIcon * icon = new wxIcon(Val2Str(path),static_cast<wxBitmapType>(Val2Int(type)));
	if (icon)
		return WXToDeletingValue(icon);
	return alloc_null();
}

DEFINE_PRIM(wx_icon_from_file,2)

int link_Icon() { return 0; }
