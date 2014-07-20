package wx;

import haxe.io.Bytes;

import sys.FileSystem;
import sys.io.File;

import wx.Bitmap;

enum WxImageResizeQuality
{
    wxIMAGE_QUALITY_NEAREST;
    wxIMAGE_QUALITY_BILINEAR;
    wxIMAGE_QUALITY_BICUBIC;
    wxIMAGE_QUALITY_BOX_AVERAGE;
    wxIMAGE_QUALITY_HIGH;
}

class Image
{
	public var wxHandle:Dynamic;
	
	public var width(default,null):Int;
	public var height(default,null):Int;
	public var init_width(default,null):Int;
	public var init_height(default,null):Int;
	public var type(default,null):WxBitmapType;
	
	function new(inHandle:Dynamic, type:WxBitmapType) 
	{ 
		wxHandle = inHandle; 
		if (wxHandle == null)
		{
			throw "Invalid image creation";
		}
		this.type = type;
		width = init_width = wx_image_width(wxHandle);
		height = init_height = wx_image_height(wxHandle);
	}
	
	public static function fromFile(name:String, type:WxBitmapType):Image
	{
		return new Image(wx_image_from_file(name,Type.enumIndex(type)),type);
	}
	
	public static function getBlankImage(width:Int,height:Int):Image
	{
		return new Image(wx_image_blank(width,height),null);
	}
	
	public function rescale(width:Int, height:Int, quality:WxImageResizeQuality)
	{
		wx_image_rescale(wxHandle,width,height,quality);
		
		this.width = wx_image_width(wxHandle);
		this.height = wx_image_height(wxHandle);
		return this;
	}	
	
	public function clone():Image
	{
		return new Image(wx_image_copy(wxHandle),type);
	}
	
	public function getBytes(path:String):Bytes
	{
		if (type != null && wxHandle != null)
		{				
			wx_image_save_file(wxHandle,Type.enumIndex(type),path);
			
			if (FileSystem.exists(path))
			{
				var bytes = File.getBytes(path);
				FileSystem.deleteFile(path);
				return bytes;
			}
		}
		return null;
	}
	
	public function rotate(angle:Int):Image
	{
		wxHandle = wx_image_rotate(wxHandle,angle);
		
		var tmp = width;
		width = height;
		height = tmp;
		
		tmp = init_width;
		init_width = init_height;
		init_height = tmp;
		
		return this;
	}
	
	public function rotate90(clockwise:Bool=true):Image
	{
		wxHandle = wx_image_rotate90(wxHandle,clockwise);
		
		var tmp = width;
		width = height;
		height = tmp;
		
		tmp = init_width;
		init_width = init_height;
		init_height = tmp;
		
		return this;
	}
	
   static var wx_image_from_file = Loader.load("wx_image_from_file",2);
   static var wx_image_blank = Loader.load("wx_image_blank",2);
   static var wx_image_rescale = Loader.load("wx_image_rescale",4);
   static var wx_image_copy = Loader.load("wx_image_copy",1);
   static var wx_image_width = Loader.load("wx_image_width",1);
   static var wx_image_height = Loader.load("wx_image_height",1);
   static var wx_image_save_file = Loader.load("wx_image_save_file",3);
   static var wx_image_get_type = Loader.load("wx_image_get_type",1);
   static var wx_image_rotate90 = Loader.load("wx_image_rotate90",2);
   static var wx_image_rotate = Loader.load("wx_image_rotate",2);
   
}
