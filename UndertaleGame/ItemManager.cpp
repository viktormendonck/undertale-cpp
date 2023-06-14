#include "pch.h"
#include "ItemManager.h"

#include "Item.h"
#include "ResourceManager.h"

ItemManager::ItemManager(ResourceManager* pResourceManager)
	:
	m_Items{
		{"Stick",Item{ItemType::weapon,pResourceManager->m_ItemTextTextures[0],true,"Stick",0}},
		{"Toy knife",Item{ItemType::weapon,pResourceManager->m_ItemTextTextures[1],true,"Toy knife",3}},
		{"Bandage",Item{ItemType::armor,pResourceManager->m_ItemTextTextures[2],true,"Bandage",0}},
		{"Faded Ribbon",Item{ItemType::armor,pResourceManager->m_ItemTextTextures[3],true,"Faded Ribbon",3}},
		{"Monster candy",Item{ItemType::healing,pResourceManager->m_ItemTextTextures[4],false,"Monster candy",4}},
		{"-",Item{ItemType::empty,pResourceManager->m_ItemTextTextures[5],false,"-",0}}
	}
{
}



