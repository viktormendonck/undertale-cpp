#include "pch.h"
#include "LooxSinAttack.h"

LooxSinAttack::LooxSinAttack(const Vector2f& pos, int damage, AnimatedSprite* pBulletTex, const CollisionBox& fightRectCollider, const std::string& size, const Vector2f& dir,float delay)
	:	Bullet(pos,damage,pBulletTex , pBulletTex->GetRect(),fightRectCollider),
		m_FlightPathDirection{ dir },
		m_CurrentState{size},
		m_CurrentDelayUntilDespawnable{delay},
		m_StartPos{pos}
{
	m_FlightPathOrthoNormal = Vector2f(dir.y, -dir.x) / dir.Length();
}

void LooxSinAttack::Update(float deltaTime)
{
	if (m_CurrentDelayUntilDespawnable <= 0) {
		m_Time += deltaTime * m_FlightSpeed;
		Vector2f dirFinal = m_FlightPathDirection * m_Time * m_BulletSpeedMultiplier;
		m_Pos = m_StartPos + dirFinal + m_FlightPathOrthoNormal * m_SinWaveWidthMultiplier * sinf(m_Time/m_SinWaveLengthMultiplier);
		m_DelayUntilDespawnable -= deltaTime;
		if (m_DelayUntilDespawnable <= 0)
		{
			bool overlapX{ utils::IsOverlapping(m_FightRectCollider.GetLeft(),this->GetRect()) || utils::IsOverlapping(m_FightRectCollider.GetRight(),this->GetRect()) };
			bool overlapY{ utils::IsOverlapping(m_FightRectCollider.GetBottom(),this->GetRect()) || utils::IsOverlapping(m_FightRectCollider.GetTop(),this->GetRect()) };
			if (overlapX||overlapY)
			{
				m_IsActive = false;
			}
		}
	} else
	{
		m_CurrentDelayUntilDespawnable -= deltaTime;
	}
}

void LooxSinAttack::Draw() const
{
	if (m_CurrentDelayUntilDespawnable <= 0) {
		m_pBulletTexture->SetAnimation(m_CurrentState);
		m_pBulletTexture->Draw(m_Pos);
	}
}
