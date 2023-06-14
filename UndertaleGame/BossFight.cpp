#include "pch.h"
#include "BossFight.h"
#include "Player.h"
#include "Texture.h"
#include "utils.h"

BossFight::BossFight(const CollisionBox& collision, bool isSollid, Texture* texture)
	:
	Interactable(collision,isSollid),
	m_pTexture(texture)
{
}

void BossFight::Update(float deltaTime, Player* player)
{
	if(!m_IsActivated)
	{
		m_IsColliding = utils::IsOverlapping(m_CollisionBoxes[0].GetRect(), player->GetInteractCollisionRect());
	} else if (!m_HasTransmitted)
	{
		if (player->GetInteractedWithBoss())
		{
			player->SetInteractedWithBoss(false);
			m_IsSollid = false;
		}
		player->SetInteractedWithBoss(true);
	}
}

void BossFight::Draw(const Vector2f& camera) const
{
	if (!m_IsActivated)
	{
		m_pTexture->Draw(m_CollisionBoxes[0].GetPos().ToPoint2f());
	}
}

void BossFight::ButtonUpManager(const SDL_KeyboardEvent& e)
{
	if (m_IsColliding && (e.keysym.sym == SDLK_RETURN || e.keysym.sym == SDLK_z))
	{
		m_IsActivated = true;
	}
}

void BossFight::OnInteract()
{

}
