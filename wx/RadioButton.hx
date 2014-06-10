package wx;

class RadioButton extends Window
{
	public static inline var wxRB_GROUP:Int = 0x0004;
	public static inline var wxRB_SINGLE:Int = 0x0008;
	
	
	public var onSelected(null,set) : Dynamic->Void;
	public var value(get,set):Bool;
	
	public static function create(inParent:Window,
				?inID:Null<Int>, inLabel:String="",
				?inPosition:{x:Float,y:Float},
			    ?inSize:{width:Int,height:Int},
			    ?inStyle:Int=0)
	{
		if (inParent==null)
			throw Error.INVALID_PARENT;
		var args:Array<Dynamic> = [inParent.wxHandle,inID,inLabel,inPosition,inSize, inStyle];
		var handle = wx_radio_button_create(args);
		return new RadioButton(handle);
	}
	
	function set_onSelected(f:Dynamic->Void) {setHandler(wx.EventID.COMMAND_RADIOBUTTON_SELECTED,f); return f;}
	private function get_value():Bool { return wx_get_value(wxHandle);}
	private function set_value(val:Bool):Bool { wx_set_value(wxHandle,val); return val;}
	
	static var wx_radio_button_create = Loader.load("wx_radio_button_create",1);
	static var wx_set_value = Loader.load("wx_set_value",2);
	static var wx_get_value = Loader.load("wx_get_value",1);
}
