#include "HaxeAPI.h"
#include <wx/mstream.h>

value wx_image_from_file(value name, value type)
{	
	wxImage * image = new wxImage(Val2Str(name),Val2Int(type));
	if (image)
		return WXToDeletingValue(image);
	return alloc_null();
}

void wx_image_rescale(value src, value width, value height, value quality)
{
	wxImage * image;
	if (!ValueToWX(src,image) || !image)
		return ;
	image->Rescale(Val2Int(width),Val2Int(height),static_cast<wxImageResizeQuality>(Val2Int(quality)));
}

value wx_image_copy(value img)
{
	wxImage * image;		
	if (!ValueToWX(img,image) || !image)
		return alloc_null();
		
	wxImage * copy = new wxImage(image->GetSize(),true);
	copy->Paste(*image,0,0);
	return WXToDeletingValue(copy);
}

value wx_image_width(value img)
{
	wxImage * image;
	if (!ValueToWX(img,image) || !image)
		return alloc_int(-1);
		
	return alloc_int(image->GetWidth());
}

value wx_image_height(value img)
{
	wxImage * image;
	if (!ValueToWX(img,image) || !image)
		return alloc_int(-1);
		
	return alloc_int(image->GetHeight());
}

DEFINE_PRIM(wx_image_from_file,2)
DEFINE_PRIM(wx_image_rescale,4)
DEFINE_PRIM(wx_image_copy,1)
DEFINE_PRIM(wx_image_width,1)
DEFINE_PRIM(wx_image_height,1)

int link_Image() { return 0; }