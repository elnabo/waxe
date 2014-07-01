package wx;

enum WxBitmapType
{
    wxBITMAP_TYPE_INVALID; // should be == 0 for compatibility!
    wxBITMAP_TYPE_BMP;
    wxBITMAP_TYPE_BMP_RESOURCE;
    wxBITMAP_TYPE_ICO;
    wxBITMAP_TYPE_ICO_RESOURCE;
    wxBITMAP_TYPE_CUR;
    wxBITMAP_TYPE_CUR_RESOURCE;
    wxBITMAP_TYPE_XBM;
    wxBITMAP_TYPE_XBM_DATA;
    wxBITMAP_TYPE_XPM;
    wxBITMAP_TYPE_XPM_DATA;
    wxBITMAP_TYPE_TIFF;
    wxBITMAP_TYPE_TIFF_RESOURCE;
    wxBITMAP_TYPE_GIF;
    wxBITMAP_TYPE_GIF_RESOURCE;
    wxBITMAP_TYPE_PNG;
    wxBITMAP_TYPE_PNG_RESOURCE;
    wxBITMAP_TYPE_JPEG;
    wxBITMAP_TYPE_JPEG_RESOURCE;
    wxBITMAP_TYPE_PNM;
    wxBITMAP_TYPE_PNM_RESOURCE;
    wxBITMAP_TYPE_PCX;
    wxBITMAP_TYPE_PCX_RESOURCE;
    wxBITMAP_TYPE_PICT;
    wxBITMAP_TYPE_PICT_RESOURCE;
    wxBITMAP_TYPE_ICON;
    wxBITMAP_TYPE_ICON_RESOURCE;
    wxBITMAP_TYPE_ANI;
    wxBITMAP_TYPE_IFF;
    wxBITMAP_TYPE_TGA;
    wxBITMAP_TYPE_MACCURSOR;
    wxBITMAP_TYPE_MACCURSOR_RESOURCE;
}

class Bitmap
{
   public var wxHandle:Dynamic;

   function new(inHandle:Dynamic) 
   { 
	   wxHandle = inHandle; 
       if (wxHandle == null)
          throw "Invalid bitmap creation";
   }
   
   public function size()
   {
	   return wx_bitmap_get_size(wxHandle);
   }

   public static function fromBytes(inBytes:haxe.io.Bytes)
   {
      if (inBytes==null)
         throw("Bad bitmap data");
      return new Bitmap( wx_bitmap_from_bytes(inBytes.getData()) );
   }

   public static function fromResource(inResorceName:String)
   {
       return fromBytes( haxe.Resource.getBytes(inResorceName));
   }
   
   public static function fromFile(name:String, type:WxBitmapType)
   {
      return new Bitmap( wx_bitmap_from_file(name,type) );
   }
   
   public static function fromImage(img:Image, type:Int=-1)
   {
      return new Bitmap( wx_bitmap_from_image(img.wxHandle,type) );
   }

   static var wx_bitmap_get_size = Loader.load("wx_bitmap_get_size",1);
   static var wx_bitmap_from_bytes = Loader.load("wx_bitmap_from_bytes",1);
   static var wx_bitmap_from_file = Loader.load("wx_bitmap_from_file",2);
   static var wx_bitmap_from_image = Loader.load("wx_bitmap_from_image",2);
}
