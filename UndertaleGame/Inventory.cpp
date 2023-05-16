#include "pch.h"
#include "Inventory.h"
#include "ItemManager.h"
#include "Item.h"


Inventory::Inventory(int size,ItemManager* itemManager)
: m_MaxInvSize(size),
  m_ItemManager(itemManager)
{
	for (int i {}; i < m_MaxInvSize; ++i)
	{
		m_PlayerInventory.push_back(m_ItemManager->m_Items["-"]);
	}
}

void Inventory::DeleteItem(int itemNumber)
{
	for (int i{ m_MaxInvSize - 1  }; i >= 0; --i )
	{
		if (m_PlayerInventory[i].GetItemType() == ItemType::empty) continue;
		m_PlayerInventory[itemNumber] = m_PlayerInventory[i];
		m_PlayerInventory[i] = m_ItemManager->m_Items["-"];
		i = 0;
	}
}

void Inventory::InputItem(std::string itemType)
{
	int firstSpot{};
	bool notFull{false};
	for (int i{}; i < m_MaxInvSize; ++i)
	{
		notFull = notFull || m_PlayerInventory[i].GetItemType() == ItemType::empty;
		if (notFull)
		{
			firstSpot = i;
			i = m_MaxInvSize;
		}
	}
	if(notFull)
	{
		m_PlayerInventory[firstSpot] = m_ItemManager->m_Items[itemType];
	}

}

ItemType Inventory::GetItemType(int itemNumber)
{
	return m_PlayerInventory[itemNumber].GetItemType();
}

int Inventory::GetItemValue(int itemNumber)
{
	return m_PlayerInventory[itemNumber].GetValue();
}

std::string Inventory::GetItemName(int itemNumber)
{
	return m_PlayerInventory[itemNumber].GetName();
}

int Inventory::GetInvSize()
{
	return m_MaxInvSize;
}

Texture* Inventory::GetItemText(int itemNumber)
{
	return m_PlayerInventory[itemNumber].GetItemTexture();
}

int Inventory::GetCurrentItemAmount()
{
	int amount{};
	for (Item item: m_PlayerInventory)
	{
		if (item.GetItemType() != ItemType::empty)
		{
			++amount;
		}
	}
	return amount;
}
