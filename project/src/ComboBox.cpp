#include "HaxeAPI.h"

value wx_combo_box_create(value inParams,value inChoices)
{
	CreationParams params(inParams);
	wxArrayString choices;
	Val2ArrayString(inChoices,choices);
   wxComboBox *window = new wxComboBox(params.parent,params.id,params.text,
										  params.position,params.size,choices,params.flags);

   return WXToValue(window);
}
DEFINE_PRIM(wx_combo_box_create,2)

void wx_combo_box_set_label(value parent, value str)
{
	wxComboBox * combo;
	if (ValueToWX(parent,combo))
	{
		combo->SetLabel(Val2Str(str));
	}
}
DEFINE_PRIM(wx_combo_box_set_label,2)

value wx_combo_box_get_label(value parent)
{
	wxComboBox * combo;
	if (ValueToWX(parent,combo))
	{
		return alloc_string(combo->GetLabel());
	}
	return alloc_null();
}
DEFINE_PRIM(wx_combo_box_get_label,1)

value wx_combo_box_get_value(value parent)
{
	wxComboBox * combo;
	if (ValueToWX(parent,combo))
	{
		return alloc_string(combo->GetValue());
	}
	return alloc_null();
}
DEFINE_PRIM(wx_combo_box_get_value,1)

void wx_combo_box_clear(value parent)
{
	wxComboBox * combo;
	if (ValueToWX(parent,combo))
	{
		combo->Clear();
	}
}
DEFINE_PRIM(wx_combo_box_clear,1)

void wx_combo_box_append(value parent, value str)
{
	wxComboBox * combo;
	if (ValueToWX(parent,combo))
	{
		combo->Append(Val2Str(str));
	}
}
DEFINE_PRIM(wx_combo_box_append,2)


int link_ComboBox() { return 0; }

