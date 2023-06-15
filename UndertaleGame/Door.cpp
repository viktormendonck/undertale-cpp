#include "pch.h"
#include "Door.h"
#include "utils.h"

Door::Door(Rectf doorCollider, std::string destination, Vector2f spawnLocation)
	:
	m_DoorCollider(doorCollider),
	m_Destination(destination),
	m_ExitLocation(spawnLocation)
{
}

std::string Door::GetDestination()
{
	return m_Destination;
}

bool Door::IsColliding(const Rectf& player) const
{
	return utils::IsOverlapping(player, m_DoorCollider.GetRect());
}

Vector2f Door::GetExitLocation() const
{
	return m_ExitLocation;
}
