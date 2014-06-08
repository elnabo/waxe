#include "HaxeAPI.h"
#include <wx/mstream.h>
#include <wx/image.h>

value wx_bitmap_from_bytes(value inBytes)
{
	ByteData data = Val2ByteData(inBytes);
	if (data.length)
	{
		wxMemoryInputStream stream(data.data,data.length);
		wxBitmap *bitmap = new wxBitmap(wxImage(stream));
		if (bitmap)
			return WXToDeletingValue(bitmap);
	}
	return alloc_null();
}

value wx_bitmap_from_file(value name, value type)
{	
	wxBitmap * bitmap = new wxBitmap(Val2Str(name),Val2Int(type));
	if (bitmap)
		return WXToDeletingValue(bitmap);
	return alloc_null();
}

value wx_bitmap_from_image(value img, value type)
{	
	wxImage * image;
	if (!ValueToWX(img,image) || !image)
	{
		return alloc_null();
	}
		
	wxBitmap * bitmap = new wxBitmap(*image,Val2Int(type));
	if (bitmap)
		return WXToDeletingValue(bitmap);
	return alloc_null();
}

DEFINE_PRIM(wx_bitmap_from_bytes,1)
DEFINE_PRIM(wx_bitmap_from_file,2)
DEFINE_PRIM(wx_bitmap_from_image,2)

int link_Bitmap() { return 0; }

