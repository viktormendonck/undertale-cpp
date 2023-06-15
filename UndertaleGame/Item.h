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

	ItemType GetItemType() const;
	bool IsEquipable() const;
	std::string GetName() const;
	int GetValue() const;
	Texture* GetItemTexture() const;
	

private:
	ItemType m_ItemType{};
	bool m_IsEquipable{};
	std::string m_Name{};
	Texture* m_pNameTex;

	int m_Value{};
};

