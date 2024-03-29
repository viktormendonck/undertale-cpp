#include "pch.h"
#include "Item.h"

class Texture;

Item::Item()
	: m_ItemType(ItemType::empty),
	m_IsEquipable(false),
	m_Name("-"),
	m_Value(0)
{
}

Item::Item(ItemType itemType,Texture* pNameTex, bool equipable, std::string name, int itemValue)
	: m_ItemType(itemType),
	  m_pNameTex(pNameTex),
	  m_IsEquipable(equipable),
	  m_Name(name),
	  m_Value(itemValue)
{
}


ItemType Item::GetItemType() const
{
	return m_ItemType;
}

bool Item::IsEquipable() const
{
	return m_IsEquipable;
}

std::string Item::GetName() const
{
	return m_Name;
}

int Item::GetValue() const
{
	return m_Value;
}

Texture* Item::GetItemTexture() const
{
	return m_pNameTex;
}
