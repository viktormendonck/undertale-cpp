#pragma once
#include <map>

class ResourceManager;
class Item;

class ItemManager final
{
public:
	ItemManager(ResourceManager* pResourceManager);

	std::map<std::string, Item> m_Items;
};

