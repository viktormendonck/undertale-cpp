#pragma once
#include <map>
class Room;
class ResourceManager;
class Door;

class RoomManager
{
public:
	RoomManager() = delete;
	explicit RoomManager(ResourceManager* pResourceManager);
	std::map<std::string, Room*> m_pRooms;
};

