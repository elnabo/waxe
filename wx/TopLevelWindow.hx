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
   
   static var wx_top_level_window_set_icon = Loader.load("wx_top_level_window_set_icon",2);
}
