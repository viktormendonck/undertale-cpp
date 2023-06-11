#include "pch.h"
#include "LooxBounceAttack.h"

#include <iostream>

#include "Bullet.h"


LooxBounceAttack::LooxBounceAttack(const Vector2f& pos, int damage, AnimatedSprite* pBulletTex, const CollisionBox& fightRectCollider, bool negation, float delay, float timeToLive)
	: Bullet(pos, damage, pBulletTex, pBulletTex->GetRect(), fightRectCollider),
	m_Delay{ delay },
	m_TimeToLive{ timeToLive }
{
	if (negation)
	{
		m_Velocity.y = -m_Velocity.y;
		m_Velocity.x = -m_Velocity.x;
	}
	if (utils::IsOverlapping(m_FightRectCollider.GetRight(), this->GetRect()))
	{
		m_Pos.x -= m_pBulletTexture->GetWidth();
	}
	if (utils::IsOverlapping(m_FightRectCollider.GetTop(), this->GetRect()))
	{
		m_Pos.y -= m_pBulletTexture->GetHeight();
	}
}

void LooxBounceAttack::Update(float deltaTime)
{
	if (m_Delay<=0)
	{
		m_TimeToLive -= deltaTime;
		Vector2f tempPos = m_Pos + m_Velocity * m_Speed * deltaTime;
		Rectf nextPosBulletRect = Rectf(tempPos.x,tempPos.y,this->GetRect().width, this->GetRect().height);
		bool overlapX{	utils::IsOverlapping(m_FightRectCollider.GetLeft(),nextPosBulletRect) || 
						utils::IsOverlapping(m_FightRectCollider.GetRight(),nextPosBulletRect) };
		bool overlapY{	utils::IsOverlapping(m_FightRectCollider.GetBottom(),nextPosBulletRect) ||
						utils::IsOverlapping(m_FightRectCollider.GetTop(),nextPosBulletRect) };
		if (overlapY)
		{
			m_Velocity.y = -m_Velocity.y;
		}
		if (overlapX)
		{
			m_Velocity.x = -m_Velocity.x;
		}
		m_Pos += m_Velocity * m_Speed * deltaTime;

		if (m_TimeToLive <=0)
		{
			m_IsActive = false;
		}
	} else
	{
		m_Delay -= deltaTime;
	}
}

void LooxBounceAttack::Draw() const
{
	if (m_Delay <= 0)
	{
		m_pBulletTexture->Draw(m_Pos);
	}
}
