package wx;

import wx.Window;

class ComboBox extends ControlWithItems
{
	public var label(get,set):String;
	public var value(get,null):String;
	public var onSelected(null,set) : Dynamic->Void;
	public var onTextEnter(null,set) : Dynamic->Void;
	public var onTextUpdated(null,set) : Dynamic->Void;

   public static function create(inParent:Window, ?inID:Null<Int>, inValue:String="",
	                ?inPosition:Position,
                   ?inSize:Size, ?inChoices:Array<String>, ?inStyle:Int )
   {
		if (inParent==null)
			throw Error.INVALID_PARENT;
      var handle = wx_combo_box_create(
			[inParent.wxHandle,inID,inValue,inPosition,inSize, inStyle], inChoices );
      return new ComboBox(handle);
   }


   public function new(inHandle:Dynamic)
   {
	   super(inHandle);
   }

	function set_onSelected(f:Dynamic->Void)
	   {setHandler(wx.EventID.COMMAND_COMBOBOX_SELECTED,f); return f;}
	function set_onTextUpdated(f:Dynamic->Void)
	   {setHandler(wx.EventID.COMMAND_TEXT_UPDATED,f); return f;}
	function set_onTextEnter(f:Dynamic->Void)
	   {setHandler(wx.EventID.COMMAND_TEXT_ENTER,f); return f;}
	
	function get_label():String {return wx_combo_box_get_label(wxHandle);}
	function set_label(val:String):String {return wx_combo_box_set_label(wxHandle,val);}
	
	function get_value():String {return wx_combo_box_get_value(wxHandle);}
	
	public function clear()
	{
		wx_combo_box_clear(wxHandle);
	}
	
	public function append(val:String)
	{
		wx_combo_box_append(wxHandle,val);
	}

   static var wx_combo_box_create:Array<Dynamic>->Array<String>->Dynamic = Loader.load("wx_combo_box_create",2);
   static var wx_combo_box_set_label = Loader.load("wx_combo_box_set_label",2);
   static var wx_combo_box_get_label = Loader.load("wx_combo_box_get_label",1);
   static var wx_combo_box_get_value = Loader.load("wx_combo_box_get_value",1);
   static var wx_combo_box_clear = Loader.load("wx_combo_box_clear",1);
   static var wx_combo_box_append = Loader.load("wx_combo_box_append",2);
}
