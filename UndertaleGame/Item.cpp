#include "pch.h"
#include "Item.h"

Item::Item(ItemType itemType, bool equipable, std::string name, float itemValue)
	: m_ItemType(itemType),
	  m_IsEquipable(equipable),
	  m_Name(name),
	  m_Value(itemValue)
{
}

ItemType Item::GetItemType()
{
	return m_ItemType;
}

bool Item::IsEquipable()
{
	return m_IsEquipable;
}

std::string Item::GetName()
{
	return m_Name;
}

float Item::GetValue()
{
	return m_Value;
}