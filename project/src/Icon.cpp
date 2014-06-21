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

value wx_icon_from_bytes(value inBytes, value width, value height)
{
	ByteData data = Val2ByteData(inBytes);
	if (data.length)
	{
		wxIcon * icon = new wxIcon(reinterpret_cast<char*>(data.data), Val2Int(width), Val2Int(height));
		if (icon)
			return WXToDeletingValue(icon);
	}
	return alloc_null();
}
DEFINE_PRIM(wx_icon_from_bytes,3)

value wx_icon_blank()
{
	wxIcon * icon = new wxIcon();
	return WXToDeletingValue(icon);
}
DEFINE_PRIM(wx_icon_blank,0)

value wx_icon_from_bitmap(value bmp)
{
	wxBitmap * bitmap;
	if (ValueToWX(bmp,bitmap))
	{
		wxIcon * icon = new wxIcon();
		icon->CopyFromBitmap(*bitmap);
		return WXToDeletingValue(icon);	
	}
	return alloc_null();
}
DEFINE_PRIM(wx_icon_from_bitmap,1)

int link_Icon() { return 0; }
