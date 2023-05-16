#pragma once

class Texture;

enum class ItemType
{
	healing,
	armor,
	weapon,
	empty
};

class Item final
{
public:
	Item();
	explicit Item(ItemType itemType, Texture* pNameTex, bool equipable, std::string name, int itemValue);

	Item(const Item& other) = default; // Copy constructor
	Item& operator=(const Item& other); // Copy assignment operator

	Item(Item&& other) = default; // Move constructor
	Item& operator=(Item&& other) = default; // Move assignment operator


	ItemType GetItemType();
	bool IsEquipable();
	std::string GetName();
	int GetValue();
	Texture* GetItemTexture();
	

private:
	ItemType m_ItemType{};
	bool m_IsEquipable{};
	std::string m_Name{};
	Texture* m_pNameTex;

	int m_Value{};
};

