#pragma once
#include <map>
class Adventure;
class Room;
class ResourceManager;
class Door;

class RoomManager final
{
public:
	explicit RoomManager(ResourceManager* pResourceManager);
	~RoomManager();

	RoomManager(const RoomManager& other) = delete;
	RoomManager& operator=(const RoomManager& other) = delete;
	RoomManager(RoomManager&& other) = delete;
	RoomManager& operator=(RoomManager&& other) = delete;

	std::map<std::string, Room*> m_pRooms;
};

