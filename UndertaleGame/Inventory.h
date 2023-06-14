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
	ItemType GetItemType(int itemNumber);
	int GetItemValue(int itemNumber);
	std::string GetItemName(int itemNumber);
	int GetInvSize();
	Texture* GetItemText(int itemNumber);
	int GetCurrentItemAmount();
private:
	std::vector<Item> m_PlayerInventory;
	int m_MaxInvSize;
	ItemManager* m_pItemManager;
};

