#pragma once
#include <map>

class ResourceManager;
class Item;

class ItemManager
{
public:
	ItemManager(ResourceManager* pResourceManager);
	//~ItemManager();
	std::map<std::string, Item> m_Items;
};

