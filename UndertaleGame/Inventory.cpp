#include "pch.h"
#include "Inventory.h"
#include "ItemManager.h"
#include "Item.h"


Inventory::Inventory(int size,ItemManager* itemManager)
: m_MaxInvSize(size),
  m_pItemManager(itemManager)
{
	for (int i {}; i < m_MaxInvSize; ++i)
	{
		m_PlayerInventory.push_back(m_pItemManager->m_Items["-"]);
	}
}

Inventory::~Inventory()
{
	delete m_pItemManager;
}

void Inventory::DeleteItem(int itemNumber)
{
	for (int i{ m_MaxInvSize - 1  }; i >= 0; --i )
	{
		if (m_PlayerInventory[i].GetItemType() == ItemType::empty) continue;
		m_PlayerInventory[itemNumber] = m_PlayerInventory[i];
		m_PlayerInventory[i] = m_pItemManager->m_Items["-"];
		i = 0;
	}
}

void Inventory::InputItem(const std::string& itemType)
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
		m_PlayerInventory[firstSpot] = m_pItemManager->m_Items[itemType];
	}

}

ItemType Inventory::GetItemType(int itemNumber) const
{
	return m_PlayerInventory[itemNumber].GetItemType();
}

int Inventory::GetItemValue(int itemNumber) const
{
	return m_PlayerInventory[itemNumber].GetValue();
}

std::string Inventory::GetItemName(int itemNumber) const
{
	return m_PlayerInventory[itemNumber].GetName();
}

int Inventory::GetInvSize() const
{
	return m_MaxInvSize;
}

Texture* Inventory::GetItemText(int itemNumber) const
{
	return m_PlayerInventory[itemNumber].GetItemTexture();
}

int Inventory::GetCurrentItemAmount() const
{
	int amount{};
	for (const Item& item: m_PlayerInventory)
	{
		if (item.GetItemType() != ItemType::empty)
		{
			++amount;
		}
	}
	return amount;
}
