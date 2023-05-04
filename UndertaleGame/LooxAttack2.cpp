#include "pch.h"
#include "LooxAttack2.h"

#include <iostream>

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
		//TODO: remove commented out testcode
		//std::cout << "x:" << m_Pos.x << "y:" << m_Pos.y << std::endl;
		m_TimeToLive -= deltaTime;
		Vector2f tempPos = m_Pos + m_Velocity * m_Speed * deltaTime;
		Rectf nextPosBulletRect = Rectf(tempPos.x,tempPos.y,this->GetRect().width, this->GetRect().height);
		bool overlapX{	utils::IsOverlapping(m_Collider.GetLeft(),nextPosBulletRect) || 
						utils::IsOverlapping(m_Collider.GetRight(),nextPosBulletRect) };
		bool overlapY{	utils::IsOverlapping(m_Collider.GetBottom(),nextPosBulletRect) ||
						utils::IsOverlapping(m_Collider.GetTop(),nextPosBulletRect) };
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
