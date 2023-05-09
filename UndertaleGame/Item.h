#pragma once

enum class ItemType
{
	healing,
	armor,
	weapon,
	empty
};

class Item
{
public:
	Item(ItemType itemType,bool equipable,std::string name,float itemValue);

	ItemType GetItemType();
	bool IsEquipable();
	std::string GetName();
	float GetValue();
	

private:
	ItemType m_ItemType{};
	bool m_IsEquipable{};
	std::string m_Name{};

	float m_Value{};
};

