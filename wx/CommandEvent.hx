package wx;

import wx.Loader;

class CommandEvent extends Event
{
	public var int(get,set):Int;
	public var string(get,set):String;
	
	function new(handle:Dynamic)
	{
		super(handle);
	}
	
	public static function fromHandle(handle:Dynamic)
	{
		return new CommandEvent(handle);
	}
	
	public static function create(type:Int, ?id:Int=0)
	{
		var handle = wx_create_command_event(type,id);
		if (handle == null)
			return null;
		return new CommandEvent(handle);
	}
	
	function get_int():Int { return wx_command_event_get_int(wxHandle);}
	function set_int(val:Int):Int { wx_command_event_set_int(wxHandle,val); return val;}
	
	function get_string():String { return wx_command_event_get_string(wxHandle);}
	function set_string(val:String):String { wx_command_event_set_string(wxHandle,val); return val;}
	
	static var wx_create_command_event = Loader.load("wx_create_command_event",2);
	static var wx_command_event_get_string = Loader.load("wx_command_event_get_string",1);
	static var wx_command_event_set_string = Loader.load("wx_command_event_set_string",2);
	static var wx_command_event_get_int = Loader.load("wx_command_event_get_int",1);
	static var wx_command_event_set_int = Loader.load("wx_command_event_set_int",2);

}
