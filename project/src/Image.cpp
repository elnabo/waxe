#include "HaxeAPI.h"
#include <wx/mstream.h>

#include <iostream>

value wx_image_from_file(value name, value type)
{	
	try
	{
		wxImage * image = new wxImage(Val2Str(name),Val2Int(type));
		if (image)
			return WXToDeletingValue(image);
		return alloc_null();
	}
	catch (...)
	{
		return alloc_null();
	}
}

value wx_image_blank(value width, value height)
{
	try
	{
		wxImage * image = new wxImage(Val2Int(width),Val2Int(height),true);
		if (image)
			return WXToDeletingValue(image);
		return alloc_null();
	}
	catch (...)
	{
		return alloc_null();
	}
}

value wx_image_rescale(value src, value width, value height, value quality)
{
	wxImage * image;
	if (!ValueToWX(src,image) || !image)
		return alloc_null();
	image->Rescale(Val2Int(width),Val2Int(height),static_cast<wxImageResizeQuality>(Val2Int(quality)));
	return alloc_null();
}

value wx_image_copy(value img)
{
	try
	{
		wxImage * image;		
		if (!ValueToWX(img,image) || !image)
			return alloc_null();
		
		wxImage * copy = new wxImage(image->GetSize(),true);
		copy->Paste(*image,0,0);
		return WXToDeletingValue(copy);
	}
	catch (...)
	{
		return alloc_null();
	}
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

value wx_image_save_file(value img, value type, value tmpName)
{
	wxImage * image;
	if (!ValueToWX(img,image) || !image)
		return alloc_null();
		
	//~ image->SaveFile(Val2Str(tmpName), Val2Int(type));
	image->SaveFile(Val2Str(tmpName), image->GetType());	
	return alloc_null();
}

value wx_image_get_type(value img)
{
	wxImage * image;
	if (!ValueToWX(img,image) || !image)
		return alloc_null();
	return alloc_int(image->GetType());
}

value wx_image_rotate(value img, value degree)
{
	wxImage * image;
	if (!ValueToWX(img,image) || !image)
		return alloc_null();
		
	double pi = 3.14159265358979323846;
	wxImage rotation = image->Rotate(pi*Val2Int(degree)/180.0, wxPoint(image->GetWidth()/2,image->GetHeight()/2));
	wxImage * res = new wxImage(rotation.GetWidth(),rotation.GetHeight());
	res->Paste(rotation,0,0);
	if (res)
	{
		res->SetType(image->GetType());
		return WXToDeletingValue(res);
	}
	return alloc_null();
}

DEFINE_PRIM(wx_image_from_file,2)
DEFINE_PRIM(wx_image_blank,2)
DEFINE_PRIM(wx_image_rescale,4)
DEFINE_PRIM(wx_image_copy,1)
DEFINE_PRIM(wx_image_width,1)
DEFINE_PRIM(wx_image_height,1)
DEFINE_PRIM(wx_image_save_file,3)
DEFINE_PRIM(wx_image_get_type,1)
DEFINE_PRIM(wx_image_rotate,2)

int link_Image() { return 0; }
