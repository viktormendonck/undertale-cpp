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

Item& Item::operator=(const Item& other)
{
	if (this != &other) { // check for self-assignment
		m_ItemType = other.m_ItemType;
		m_pNameTex = other.m_pNameTex;
		m_IsEquipable = other.m_IsEquipable;
		m_Name = other.m_Name;
		m_Value = other.m_Value;
	}
	return *this;

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

int Item::GetValue()
{
	return m_Value;
}

Texture* Item::GetItemTexture()
{
	return m_pNameTex;
}
