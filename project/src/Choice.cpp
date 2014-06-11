#include "HaxeAPI.h"

value wx_choice_create(value inParams,value inChoices)
{
	wxWindow * parent;
	if (!ValueToWX(val_array_i(inParams,0),parent))
		return alloc_null();
	
	try
	{
		wxWindowID id = (wxWindowID)Val2Int(val_array_i(inParams,1),wxID_ANY);
		wxPoint position = Val2Point(val_array_i(inParams,2));
		wxSize size = Val2Size(val_array_i(inParams,3));
		int flags = Val2Int(val_array_i(inParams,4));
   
		wxArrayString choices;
		Val2ArrayString(inChoices,choices);
		wxChoice *window = new wxChoice(parent,id,
										  position,size,choices,flags);

		return WXToValue(window);
	}
	catch (...) {return alloc_null();}
}
DEFINE_PRIM(wx_choice_create,2)

value wx_choice_set_label(value parent, value str)
{
	wxChoice * choice;
	if (ValueToWX(parent,choice))
	{
		choice->SetLabel(Val2Str(str));
	}
	return alloc_null();
}
DEFINE_PRIM(wx_choice_set_label,2)

value wx_choice_get_label(value parent)
{
	wxChoice * choice;
	if (ValueToWX(parent,choice))
	{
		return WXToValue(choice->GetLabel());
	}
	return alloc_null();
}
DEFINE_PRIM(wx_choice_get_label,1)

value wx_choice_set_selection(value parent, value index)
{
	wxChoice * choice;
	if (ValueToWX(parent,choice))
	{
		choice->SetSelection(Val2Int(index));
	}
	return alloc_null();
}
DEFINE_PRIM(wx_choice_set_selection,2)

value wx_choice_get_selection(value parent)
{
	wxChoice * choice;
	if (ValueToWX(parent,choice))
	{
		return alloc_int(choice->GetSelection());
	}
	return alloc_null();
}
DEFINE_PRIM(wx_choice_get_selection,1)

value wx_choice_clear(value parent)
{
	wxChoice * choice;
	if (ValueToWX(parent,choice))
	{
		choice->Clear();
	}
	return alloc_null();
}
DEFINE_PRIM(wx_choice_clear,1)

value wx_choice_append(value parent, value str)
{
	wxChoice * choice;
	if (ValueToWX(parent,choice))
	{
		choice->Append(Val2Str(str));
	}
	return alloc_null();
}
DEFINE_PRIM(wx_choice_append,2)

value wx_choice_get_string(value parent,value index)
{
	wxChoice * choice;
	if (ValueToWX(parent,choice))
	{
		return WXToValue(choice->GetString(Val2Int(index)));
	}
	return alloc_null();
}
DEFINE_PRIM(wx_choice_get_string,2)


int link_Choice() { return 0; }

