#include "pch.h"
#include "ItemManager.h"

#include "Item.h"

ItemManager::ItemManager()
	:
	m_Items{
		{"Stick",Item{ItemType::weapon,true,"Stick",0}},
		{"Toy knife",Item{ItemType::weapon,true,"Toy knife",3}},
		{"Bandage",Item{ItemType::armor,true,"Bandage",1}},
		{"Monster candy",Item{ItemType::healing,false,"Monster candy",1}},
		{"Spider donut",Item{ItemType::healing,false,"Spider donut",1}},
		{"Spider cider",Item{ItemType::healing,false,"Spider cider",1}},
		{"-",Item{ItemType::empty,false,"-",0}}
	}
{
}
