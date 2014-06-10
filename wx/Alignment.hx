package wx;

class Alignment
{
    /**
		A value different from any valid alignment value.

		Note that you shouldn't use 0 for this as it's the value of (valid)
		alignments wxALIGN_LEFT and wxALIGN_TOP.

		@since 2.9.1
	*/
    public static var wxALIGN_INVALID(default,null) = -1;

    public static var wxALIGN_NOT(default,null) = 0x0000;
    public static var wxALIGN_CENTER_HORIZONTAL(default,null) = 0x0100;
    public static var wxALIGN_CENTRE_HORIZONTAL(default,null) = 0x0100;
    public static var wxALIGN_LEFT(default,null) = 0x0000;
    public static var wxALIGN_TOP(default,null) = 0x0000;
    public static var wxALIGN_RIGHT(default,null) = 0x0200;
    public static var wxALIGN_BOTTOM (default,null)= 0x0400;
    public static var wxALIGN_CENTER_VERTICAL(default,null) = 0x0800;
    public static var wxALIGN_CENTRE_VERTICAL(default,null) = 0x0800;

    public static var wxALIGN_CENTER(default,null) = (0x0100 | 0x0800);
    public static var wxALIGN_CENTRE(default,null) = (0x0100 | 0x0800);

    /** A mask to extract alignment from the combination of flags. */
    public static var wxALIGN_MASK(default,null) = 0x0f00;
}
