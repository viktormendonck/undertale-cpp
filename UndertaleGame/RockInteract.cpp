#include "pch.h"
#include "RockInteract.h"

#include "Player.h"
#include "utils.h"

RockInteract::RockInteract(const Rectf& collisionRect, Texture* pRockTexture, const Rectf& buttonRect,const CollisionBox& barrierRect, Texture* pBarierTexture)
	:
	Interactable(collisionRect,true),
	m_pRockTexture(pRockTexture),
	m_pBarrierTexture(pBarierTexture),
	m_BarrierRect(barrierRect),
	m_buttonRect(buttonRect)
{
	m_RockMinX = m_CollisionBoxes[0].GetPos().x;
	m_RockMaxX = m_buttonRect.left + m_buttonRect.width;
}

void RockInteract::Update(float deltaTime, Player* player)
{
	m_PlayerPushRect = player->GetPlayerCollisionRect();
	if (player->GetFullPlayerRect().left > player->GetInteractCollisionRect().left)
	{
		m_PlayerPushRect.left -= 1;
	} else
	{
		m_PlayerPushRect.left += 1;
	}
	//check whether the barrier should be opened 
	m_DeactivateBarrier = (utils::IsOverlapping(m_PlayerPushRect, m_buttonRect) || utils::IsOverlapping(m_CollisionBoxes[0].GetRect(), m_buttonRect));
	if (m_DeactivateBarrier && m_CollisionBoxes.size() == 2)
	{
		m_CollisionBoxes.pop_back();
	} else if (m_CollisionBoxes.size() == 1&& !m_DeactivateBarrier)
	{
		PushCollisionBox(m_BarrierRect);
	}
	if (utils::IsOverlapping(m_PlayerPushRect,m_CollisionBoxes[0].GetRect()))
	{
		if (m_PlayerPushRect.left > player->GetInteractCollisionRect().left && m_RockMinX < m_CollisionBoxes[0].GetPos().x)
		{
			m_CollisionBoxes[0].SetLocation(m_CollisionBoxes[0].GetPos() - Vector2f(m_RockPushSpeed * deltaTime, 0));
		} else if (m_PlayerPushRect.left < player->GetInteractCollisionRect().left && m_RockMaxX > m_CollisionBoxes[0].GetPos().x+m_CollisionBoxes[0].GetRect().width)
		{
			m_CollisionBoxes[0].SetLocation(m_CollisionBoxes[0].GetPos() + Vector2f(m_RockPushSpeed * deltaTime, 0));
		}
	}
	
}

void RockInteract::Draw(const Vector2f& camera) const
{
	glPushMatrix();
	glTranslatef(-camera.x, -camera.y, 0);
	if (!m_DeactivateBarrier)
	{
		m_pBarrierTexture->Draw(m_BarrierRect.GetPos().ToPoint2f());
	}
	m_pRockTexture->Draw(m_CollisionBoxes[0].GetPos().ToPoint2f());
	glPopMatrix();
}

void RockInteract::ButtonUpManager(const SDL_KeyboardEvent& e)
{

}

void RockInteract::OnInteract()
{
}

void RockInteract::PushCollisionBox(CollisionBox collision)
{
	m_CollisionBoxes.push_back(collision);
}


