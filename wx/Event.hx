package wx;

import wx.Loader;

class Event 
{
	public var wxHandle(default,null):Dynamic;
	
	function new(handle:Dynamic)
	{
		wxHandle = handle;
	}
	
	public static function fromHandle(handle:Dynamic)
	{
		return new Event(handle);
	}
	
	public static function queueEvent(dest:Window,event:Event)
	{
		wx_queue_event(dest.wxHandle,event.wxHandle);
	}
	
	static var wx_queue_event = Loader.load("wx_queue_event",2);
}

class EventType
{
	public static function newEventType():Int
	{
		return wx_new_event_type();
	}
	
	static var wx_new_event_type = Loader.load("wx_new_event_type",0);
}
