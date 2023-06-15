#pragma once
#include <vector>

#include "Item.h"

class ItemManager;

class Inventory final
{
public:
	Inventory(int size, ItemManager* itemManager);
	~Inventory();

	Inventory(const Inventory& other) = delete;
	Inventory& operator=(const Inventory& other) = delete;
	Inventory(Inventory&& other) = delete;
	Inventory& operator=(Inventory&& other) = delete;

	void DeleteItem(int itemNumber) ;
	void InputItem(const std::string& itemType);
	ItemType GetItemType(int itemNumber) const;
	int GetItemValue(int itemNumber) const;
	std::string GetItemName(int itemNumber) const;
	int GetInvSize() const;
	Texture* GetItemText(int itemNumber) const;
	int GetCurrentItemAmount() const;
private:
	std::vector<Item> m_PlayerInventory;
	const int m_MaxInvSize;
	ItemManager* m_pItemManager;
};

