#pragma once
#include <map>

class Item;

class ItemManager
{
public:
	ItemManager();
	std::map<std::string, Item> m_Items;
};

