#include "pch.h"
#include "GroundFall.h"

#include "Player.h"
#include "SoundManager.h"
#include "utils.h"

GroundFall::GroundFall(const CollisionBox& collision, const std::string& destinationRoom)
	:
	Interactable(collision, false),
	m_destinationRoom{destinationRoom}
{
}

void GroundFall::Update(float deltaTime, Player* player)
{
	if (utils::IsOverlapping(player->GetPlayerCollisionRect(),m_CollisionBoxes[0].GetRect()))
	{
		player->StartFalling(m_destinationRoom);
		SoundManager::GetInstance().PlaySoundEffect("fall");
	}
}

void GroundFall::OnInteract()
{

}

void GroundFall::Draw(const Vector2f& camera) const
{
}

void GroundFall::ButtonUpManager(const SDL_KeyboardEvent& e)
{
}

