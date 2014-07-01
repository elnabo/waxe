package wx;

import haxe.io.Bytes;
import wx.Bitmap;

class Icon
{
	public var wxHandle:Dynamic;
	
	function new (handle:Dynamic)
	{
		wxHandle = handle;
		if (wxHandle == null)
			throw "Invalid icon creation";
	}
	
	public static function createFromFile(path:String, type:WxBitmapType)
	{
		return new Icon(wx_icon_from_file(path,Type.enumIndex(type)));
	}
	
	public static function createFromBytes(bytes:Bytes)
	{
		return new Icon(wx_icon_from_bitmap(Bitmap.fromBytes(bytes).wxHandle));
	}
	
	static var wx_icon_from_bitmap = Loader.load("wx_icon_from_bitmap",1);
	static var wx_icon_from_bytes = Loader.load("wx_icon_from_bytes",3);
	static var wx_icon_from_file = Loader.load("wx_icon_from_file",2);
}
