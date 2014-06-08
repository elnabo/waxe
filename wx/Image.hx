package wx;

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
	
	function new(inHandle:Dynamic, ?w:Int=-1, ?h:Int=-1) 
	{ 
		wxHandle = inHandle; 
		
		width = init_width = wx_image_width(wxHandle);
		height = init_height = wx_image_height(wxHandle);
	}
	
	public static function fromFile(name:String, type:WxBitmapType):Image
	{
		return new Image(wx_image_from_file(name,Type.enumIndex(type)));
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
		return new Image(wx_image_copy(wxHandle));
	}
	
   static var wx_image_from_file = Loader.load("wx_image_from_file",2);
   static var wx_image_rescale = Loader.load("wx_image_rescale",4);
   static var wx_image_copy = Loader.load("wx_image_copy",1);
   static var wx_image_width = Loader.load("wx_image_width",1);
   static var wx_image_height = Loader.load("wx_image_height",1);
   
}
