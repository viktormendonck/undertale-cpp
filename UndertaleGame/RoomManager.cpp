#include "pch.h"
#include "RoomManager.h"

#include "CollisionBox.h"
#include "Door.h"
#include "Interactable.h"
#include "GroundFall.h"
#include "ItemInteract.h"
#include "ResourceManager.h"
#include "RockInteract.h"
#include "Room.h"
#include "TextInteract.h"
#include "Vector2f.h"

RoomManager::RoomManager(ResourceManager* pResourceManager)
{
	std::vector<Door> Room1Doors{
		Door{Rectf(273,864,94,32),"Room1.5",Vector2f{310,40}},
		Door{Rectf(620,130,20,92),"Room2",Vector2f{40,150}},
	};
	std::vector<Door> Room1_5Doors{
		Door{Rectf(291,0,76,20),"Room1",Vector2f{273,760}}
	};
	std::vector<Door> Room2Doors{
		Door{Rectf(0,127,20,100),"Room1",Vector2f{560,160}},
		Door{Rectf(734,127,20,100),"Room3",Vector2f{40,200}},
	};
	std::vector<Door> Room2_5Doors{
		Door{Rectf(157,315,72,20),"Room2",Vector2f{161,210}},
		Door{Rectf(542,315,72,20),"Room2",Vector2f{559,210}},
	}; 
	std::vector<Door> Room3Doors{
		Door{Rectf(0,178,20,83),"Room2",Vector2f{660,170}},
		Door{Rectf(940,178,20,100),"Room4",Vector2f{40,480}},
	};
	std::vector<Door> Room4Doors{
		Door{Rectf(0,449,20,83),"Room3",Vector2f{885,190}},
		Door{Rectf(1180,209,20,80),"Room5",Vector2f{100,160}},
	};
	std::vector<Door> Room4_5Doors{
		Door{Rectf(320,550,60,20),"Room4",Vector2f{310,510}},
	};
	std::vector<Door> Room5Doors{
		Door{Rectf(72,144,20,80),"Room4",Vector2f{1140,220}},
	};

	std::vector<CollisionBox> Room1Walls{
		Rectf{0,750,92,97},
		Rectf{0,0,20,997},
		Rectf{91,812,182,53},
		Rectf{367,812,182,53},
		Rectf{549,215,91,34},
		Rectf{549,215,20,730},
		Rectf{549,0,91,128},
		Rectf{0,0,640,36},
		Rectf{0,0,91,676},
	};
	std::vector<CollisionBox> Room1_5Walls{
		Rectf{407,0,233,480},
		Rectf{0,0,252,480},
		Rectf{252,310,157,20},
		Rectf{242,0,49,78},
		Rectf{368,0,49,78},
	};
	std::vector<CollisionBox> Room2Walls{
		Rectf{0,230,755,20},
		Rectf{0,56,755,20},
		Rectf{0,56,86,71},
		Rectf{678,56,77,71},
	};
	std::vector<CollisionBox> Room2_5Walls{
		Rectf{0,0,96,480},
		Rectf{675,0,20,480},
		Rectf{0,0,755,46},
		Rectf{617,290,60,42},
		Rectf{230,290,311,42},
		Rectf{95,290,60,42},
	};
	std::vector<CollisionBox> Room3Walls{
		Rectf{0,0,89,176},
		Rectf{0,0,960,52},
		Rectf{878,0,82,176},
		Rectf{878,260,82,173},
		Rectf{0,260,89,173},
		Rectf{89,308,789,20},
	};
	std::vector<CollisionBox> Room4Walls{
		Rectf{0,531,739,20},
		Rectf{0,0,480,448},
		Rectf{0,0,1200,128},
		Rectf{1080,0,120,209},
		Rectf{1080,290,120,163},
		Rectf{721,367,360,335},

	};
	std::vector<CollisionBox> Room4_5Walls{
		Rectf{0,0,110,742},
		Rectf{0,0,510,448},
		Rectf{0,0,1200,128},
		Rectf{1110,0,90,742},
		Rectf{750,365,450,334},
		Rectf{382,525,368,40},
		Rectf{110,525,208,40},
	};
	std::vector<CollisionBox> Room5Walls{
		Rectf{87,222,31,212},
		Rectf{87,0,31,142},
		Rectf{0,0,640,62},
		Rectf{0,300,640,131},
		Rectf{518,0,20,480},
		Rectf{278,44,80,99},
		Rectf{278,224,80,99},
	};

	std::vector<Texture*> interactTextTextures1{
		pResourceManager->m_InteractableTextTextures[1],
		pResourceManager->m_InteractableTextTextures[2],
		pResourceManager->m_InteractableTextTextures[3],
		pResourceManager->m_InteractableTextTextures[4],
		pResourceManager->m_InteractableTextTextures[5],
		pResourceManager->m_InteractableTextTextures[6]
	};
	std::vector<Texture*> saveTextTextures{
		pResourceManager->m_InteractableTextTextures[10]
	};

	std::vector<Interactable*> room1Interacts{
		new TextInteract(Rectf(183,770,48,48),pResourceManager->m_InteractableTextTextures[0],interactTextTextures1),
		new TextInteract(Rectf(441,639,30,30),pResourceManager->m_InteractableTextTextures[0],saveTextTextures)

	};
	std::vector<Texture*> itemInteractTextTextures1{
		pResourceManager->m_InteractableTextTextures[13],
		pResourceManager->m_InteractableTextTextures[11],
		pResourceManager->m_InteractableTextTextures[12]
	};
	std::vector<Interactable*> room1_5Interacts{
		new ItemInteract(Rectf(309,228,40,55),pResourceManager->m_InteractableTextTextures[0],itemInteractTextTextures1,pResourceManager->m_StaticTextures[0],"Monster candy",5)
	};
	std::vector<Interactable*> room2Interacts{
		new GroundFall{Rectf(355,77,50,150),"Room2.5"}
	};
	std::vector<Interactable*> room2_5Interacts{};
	std::vector<Texture*> interactTextTextures2{
		pResourceManager->m_InteractableTextTextures[7]
	};
	std::vector<Interactable*> room3Interacts{
		new TextInteract(Rectf(296,334,41,48),pResourceManager->m_InteractableTextTextures[0],interactTextTextures2),
		new RockInteract(Rectf(339,137,40,36),pResourceManager->m_RoomCorrectionTiles[1],Rectf(462,135,43,43),Rectf(587,52,41,250),pResourceManager->m_RoomCorrectionTiles[2])
	};
	std::vector<Texture*> interactTextTextures3{
		pResourceManager->m_InteractableTextTextures[8]
	};
	std::vector<Interactable*> room4Interacts{
		new GroundFall{Rectf(480,130,144,300),"Room4.5"},
		new GroundFall{Rectf(737,210,5,159),"Room4.5"},
		new GroundFall{Rectf(855,130,7,100),"Room4.5"},
		new GroundFall{Rectf(979,290,100,77),"Room4.5"},
		new GroundFall{Rectf(979,170,40,121),"Room4.5"},
		new TextInteract(Rectf(919,395,41,48),pResourceManager->m_InteractableTextTextures[0],interactTextTextures3)
	};
	std::vector<Texture*> interactTextTextures4{
		pResourceManager->m_InteractableTextTextures[9]
	};
	std::vector<Interactable*> room4_5Interacts{
		new TextInteract(Rectf(950,400,41,48),pResourceManager->m_InteractableTextTextures[0],interactTextTextures4)
	};
	std::vector<Interactable*> room5Interacts{};
	
	
	m_pRooms.emplace("Room1", new Room("Room1", pResourceManager->m_RoomTextures[0], pResourceManager->m_RoomCorrectionTiles[0], Room1Doors, Room1Walls, room1Interacts, true));
	m_pRooms.emplace("Room1.5", new Room("Room1.5", pResourceManager->m_RoomTextures[1], pResourceManager->m_RoomCorrectionTiles[0], Room1_5Doors, Room1_5Walls, room1_5Interacts, false));
	m_pRooms.emplace("Room2", new Room("Room2", pResourceManager->m_RoomTextures[2], pResourceManager->m_RoomCorrectionTiles[0], Room2Doors, Room2Walls, room2Interacts, true));
	m_pRooms.emplace("Room2.5", new Room("Room2.5", pResourceManager->m_RoomTextures[3], pResourceManager->m_RoomCorrectionTiles[0], Room2_5Doors, Room2_5Walls, room2_5Interacts, true));
	m_pRooms.emplace("Room3", new Room("Room3", pResourceManager->m_RoomTextures[4], pResourceManager->m_RoomCorrectionTiles[0], Room3Doors, Room3Walls, room3Interacts, true));
	m_pRooms.emplace("Room4", new Room("Room4", pResourceManager->m_RoomTextures[5], pResourceManager->m_RoomCorrectionTiles[0], Room4Doors, Room4Walls, room4Interacts, true));
	m_pRooms.emplace("Room4.5", new Room("Room4.5", pResourceManager->m_RoomTextures[6], pResourceManager->m_RoomCorrectionTiles[0], Room4_5Doors, Room4_5Walls, room4_5Interacts, true));
	m_pRooms.emplace("Room5", new Room("Room5", pResourceManager->m_RoomTextures[7], pResourceManager->m_RoomCorrectionTiles[0], Room5Doors, Room5Walls, room5Interacts, false));

}

RoomManager::~RoomManager()
{
	delete m_pRooms["Room1"];
	delete m_pRooms["Room1.5"];
	delete m_pRooms["Room2"];
	delete m_pRooms["Room2.5"];
	delete m_pRooms["Room3"];
	delete m_pRooms["Room4"];
	delete m_pRooms["Room4.5"];
	delete m_pRooms["Room5"];

	//m_pRooms.erase(m_pRooms.begin(), m_pRooms.end());
	/*std::map<std::string, Room*>::iterator it{ m_pRooms.begin() };

	for (it; it != m_pRooms.end(); ++it)
	{
		m_pRooms.erase(it);
	}*/
}
