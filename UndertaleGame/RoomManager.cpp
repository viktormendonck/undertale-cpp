#include "pch.h"
#include "RoomManager.h"

#include "ResourceManager.h"
#include "Room.h"
#include "Vector2f.h"
#include "Interactable.h"
#include "Door.h"

RoomManager::RoomManager(ResourceManager* pResourceManager)
{
	std::vector<Door> Room1Doors{
		Door{Rectf(273,824,94,32),"Room1.5",Vector2f{310,25}},
		Door{Rectf(620,130,20,92),"Room2",Vector2f{25,150}},
	};
	std::vector<Door> Room1_5Doors{
		Door{Rectf(291,0,76,20),"Room1",Vector2f{293,760}}
	};
	std::vector<Door> Room2Doors{
		Door{Rectf(1,127,20,100),"Room1",Vector2f{600,160}},
		Door{Rectf(734,127,20,100),"Room3",Vector2f{25,200}},
	};
	std::vector<Door> Room2_5Doors{
		Door{Rectf(157,315,72,20),"Room2",Vector2f{161,210}},
		Door{Rectf(542,315,72,20),"Room2",Vector2f{559,210}},
	};
	std::vector<Door> Room3Doors{
		Door{Rectf(1,178,20,83),"Room2",Vector2f{700,170}},
		Door{Rectf(940,178,20,100),"Room4",Vector2f{25,480}},
	};
	std::vector<Door> Room4Doors{
		Door{Rectf(1,178,20,83),"Room3",Vector2f{700,170}},
		Door{Rectf(1180,209,20,80),"Room5",Vector2f{100,160}},
	};
	std::vector<Door> Room4_5Doors{
		Door{Rectf(320,530,60,20),"Room4",Vector2f{310,510}},
	};
	std::vector<Door> Room5Doors{
		Door{Rectf(72,144,20,80),"Room4",Vector2f{1140,220}},
	};

	
	m_pRooms.emplace("Room1", new Room("Room1", pResourceManager->m_RoomTextures[0], Room1Doors, std::vector<Interactable*>{},true));
	m_pRooms.emplace("Room1.5", new Room("Room1.5", pResourceManager->m_RoomTextures[1], Room1_5Doors, std::vector<Interactable*>{},false));
	m_pRooms.emplace("Room2", new Room("Room2", pResourceManager->m_RoomTextures[2], Room2Doors, std::vector<Interactable*>{},true));
	m_pRooms.emplace("Room2.5", new Room("Room2.5", pResourceManager->m_RoomTextures[3], Room2_5Doors, std::vector<Interactable*>{},true));
	m_pRooms.emplace("Room3", new Room("Room3", pResourceManager->m_RoomTextures[4], Room3Doors, std::vector<Interactable*>{}, true));
	m_pRooms.emplace("Room4", new Room("Room4", pResourceManager->m_RoomTextures[5], Room4Doors, std::vector<Interactable*>{}, true));
	m_pRooms.emplace("Room4.5", new Room("Room4.5", pResourceManager->m_RoomTextures[6], Room4_5Doors, std::vector<Interactable*>{}, true));
	m_pRooms.emplace("Room5", new Room("Room5", pResourceManager->m_RoomTextures[7], Room5Doors, std::vector<Interactable*>{}, false));

}
