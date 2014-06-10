#include "HaxeAPI.h"

value wx_radio_button_create(value inParams)
{
	CreationParams params(inParams);
   wxRadioButton *window = new wxRadioButton(params.parent,params.id,params.text,
										  params.position,params.size,params.flags);

   return WXToValue(window);
}
DEFINE_PRIM(wx_radio_button_create,1)

value wx_get_value(value parent)
{
	wxRadioButton * me;
	if (ValueToWX(parent,me))
		return alloc_bool(me->GetValue());
	return alloc_bool(false);
}
DEFINE_PRIM(wx_get_value,1)

value wx_set_value(value parent, value v)
{
	wxRadioButton * me;
	if (ValueToWX(parent,me))
	{
		me->SetValue(Val2Bool(v)); 
	}
	return alloc_null();
}
DEFINE_PRIM(wx_set_value,2)

int link_RadioButton() { return 0; }
