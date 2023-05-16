#include "pch.h"
#include "Room.h"
#include "CollisionBox.h"
#include "Texture.h"
#include "Door.h"

Room::Room(std::string roomName, Texture* pRoomTex, std::vector<Door> doors, std::vector<Interactable*> interactables, bool spawnable)
	:
	m_RoomName(roomName),
	m_pTexture(pRoomTex),
	m_Doors(doors),
	m_Interactables(interactables),
	m_CanSpawnEnemies(spawnable)
{
}

Texture* Room::GetTexture()
{
	return m_pTexture;
}

std::vector<Door> Room::GetDoors()
{
	return m_Doors;
}

void Room::Draw() const
{
	m_pTexture->Draw(Point2f(0, 0));
}
