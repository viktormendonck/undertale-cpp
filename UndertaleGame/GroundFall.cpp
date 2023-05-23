#include "pch.h"
#include "GroundFall.h"

#include "Player.h"
#include "utils.h"

GroundFall::GroundFall(const CollisionBox& collision, const std::string& destinationRoom)
	:
	Interactable(collision, false),
	m_destinationRoom{destinationRoom}
{
}

void GroundFall::Update(float deltaTime, Player* player)
{
	if (utils::IsOverlapping(player->GetPlayerCollisionRect(),m_CollisionBox.GetRect()))
	{
		player->StartFalling(m_destinationRoom);
	}
}

void GroundFall::OnInteract()
{

}

void GroundFall::Draw() const
{
}

