#include "pch.h"
#include "Room.h"

#include <iostream>

#include "CollisionBox.h"
#include "Texture.h"
#include "Door.h"
#include "Interactable.h"
#include "utils.h"

Room::Room(const std::string& roomName, Texture* pRoomTex,Texture* holeTex, const std::vector<Door>& doors, const std::vector<CollisionBox>& walls, const std::vector<Interactable*>& interactables, bool spawnable)
	:
	m_RoomName(roomName),
	m_pTexture(pRoomTex),
	m_pHoleTexture(holeTex),
	m_Doors(doors),
	m_Walls(walls),
	m_Interactables(interactables),
	m_CanSpawnEnemies(spawnable)
{
}

Room::~Room()
{
	for (int i{};i < m_Interactables.size(); ++i)
	{
		delete m_Interactables[i];
	}
}

Texture* Room::GetTexture() const
{
	return m_pTexture;
}

std::vector<Door> Room::GetDoors() const
{
	return m_Doors;
}

std::vector<CollisionBox> Room::GetWalls() const
{
	return m_Walls;
}

std::vector<Interactable*> Room::GetInteractables() const
{
	return m_Interactables;
}

const std::string& Room::GetName() const
{
	return m_RoomName;
}

bool Room::GetSpawnable() const
{
	return m_CanSpawnEnemies;
}

void Room::AddHole(const Vector2f& location)
{
	m_HoleLocations.push_back(location);
}


void Room::Draw() const
{
	m_pTexture->Draw(Point2f(0, 0));
	for (int i{};i<m_HoleLocations.size();++i)
	{
		m_pHoleTexture->Draw(m_HoleLocations[i].ToPoint2f());
	}
#ifdef _DEBUG
	for (int i{}; i < m_Walls.size(); ++i) {
		utils::SetColor(Color4f(1, 0, 0, 1));
		utils::FillRect(m_Walls[i].GetRect());
	}
#endif
}
