package wx;

import wx.Window;

class Choice extends ControlWithItems
{
	public var label(get,set):String;
	public var value(get,null):String;
	public var selection(get,set):Int;
	public var onSelected(null,set) : Dynamic->Void = function(_:Dynamic):Void{};

   public static function create(inParent:Window, ?inID:Null<Int>, 
	                ?inPosition:Position,
                   ?inSize:Size, ?inChoices:Array<String>, ?inStyle:Int )
   {
		if (inParent==null)
			throw Error.INVALID_PARENT;
      var handle = wx_choice_create(
			[inParent.wxHandle,inID,inPosition,inSize, inStyle], inChoices );
      return new Choice(handle);
   }


   public function new(inHandle:Dynamic)
   {
	   super(inHandle);
   }

	function set_onSelected(f:Dynamic->Void)
	   {setHandler(wx.EventID.COMMAND_CHOICE_SELECTED,f); return f;}
	
	function get_label():String {return wx_choice_get_label(wxHandle);}
	function set_label(val:String):String {return wx_choice_set_label(wxHandle,val);}
	
	function get_value():String 
	{
		var v = wx_choice_get_selection(wxHandle);
		if (v >= 0)
			return get_string(v);
		return null;
	}
	
	public function clear()
	{
		wx_choice_clear(wxHandle);
	}
	
	public function append(val:String)
	{
		wx_choice_append(wxHandle,val);
	}
	
	function get_selection():Int
	{
		return wx_choice_get_selection(wxHandle);
	}
	
	function get_string(id:Int):String
	{
		return wx_choice_get_string(wxHandle,id);
	}
	
	public function find_string(val:String):Int
	{
		return wx_choice_find_string(wxHandle,val);
	}
	
	function set_selection(i:Int):Int
	{
		wx_choice_set_selection(wxHandle,i);
		return i;
	}

   static var wx_choice_create:Array<Dynamic>->Array<String>->Dynamic = Loader.load("wx_choice_create",2);
   static var wx_choice_set_label = Loader.load("wx_choice_set_label",2);
   static var wx_choice_get_label = Loader.load("wx_choice_get_label",1);
   static var wx_choice_get_selection = Loader.load("wx_choice_get_selection",1);
   static var wx_choice_set_selection = Loader.load("wx_choice_set_selection",2);
   static var wx_choice_get_string = Loader.load("wx_choice_get_string",2);
   static var wx_choice_find_string = Loader.load("wx_choice_find_string",2);
   static var wx_choice_clear = Loader.load("wx_choice_clear",1);
   static var wx_choice_append = Loader.load("wx_choice_append",2);
}
