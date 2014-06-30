package wx;

class TopLevelWindow extends Window
{
   public function new(inHandle:Dynamic)
   {
	   super(inHandle);
   }
   
   public function setIcon(icon:Icon)
   {
	   wx_top_level_window_set_icon(wxHandle,icon.wxHandle);
   }
   
   public function iconize(iconize:Bool)
   {
	   wx_top_level_window_iconize(wxHandle,iconize);
   }
   
   public function isIconized():Null<Bool>
   {
	   var res = wx_top_level_window_is_iconized(wxHandle);
	   if (res != null)
	       return res;
	   throw "isIconized error";		
   }
   
   static var wx_top_level_window_set_icon = Loader.load("wx_top_level_window_set_icon",2);
   static var wx_top_level_window_iconize = Loader.load("wx_top_level_window_iconize",2);
   static var wx_top_level_window_is_iconized = Loader.load("wx_top_level_window_is_iconized",1);
}
