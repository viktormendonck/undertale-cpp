#include "pch.h"
#include "LooxAttack2.h"

#include "Bullet.h"

//TODO:doesnt really work that well, fix ASAP

LooxAttack2::LooxAttack2(Vector2f pos, int damage, AnimatedSprite* pBulletTex, CollisionBox collider, bool negation, float delay, float timeToLive)
	: Bullet(pos, damage, pBulletTex, collider),
	m_Delay{ delay },
	m_TimeToLive{ timeToLive }
{
	if (negation)
	{
		m_Velocity.y = -m_Velocity.y;
		m_Velocity.x = -m_Velocity.x;
	}
	if (utils::IsOverlapping(m_Collider.GetRight(), this->GetRect()))
	{
		m_Pos.x -= m_pBulletTexture->GetWidth();
	}
	if (utils::IsOverlapping(m_Collider.GetTop(), this->GetRect()))
	{
		m_Pos.y -= m_pBulletTexture->GetHeight();
	}
}

void LooxAttack2::Update(float deltaTime)
{
	if (m_Delay<=0)
	{
		m_TimeToLive -= deltaTime;
		bool overlapX{ utils::IsOverlapping(m_Collider.GetLeft(),this->GetRect()) || utils::IsOverlapping(m_Collider.GetRight(),this->GetRect()) };
		bool overlapY{ utils::IsOverlapping(m_Collider.GetBottom(),this->GetRect()) || utils::IsOverlapping(m_Collider.GetTop(),this->GetRect()) };
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

void LooxAttack2::Draw() const
{
	if (m_Delay <= 0)
	{
		m_pBulletTexture->Draw(m_Pos);
	}
}
