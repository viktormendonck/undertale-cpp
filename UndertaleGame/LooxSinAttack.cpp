#include "pch.h"
#include "LooxSinAttack.h"

LooxSinAttack::LooxSinAttack(const Vector2f& pos, int damage, AnimatedSprite* pBulletTex, const CollisionBox& fightRectCollider, const std::string& size, const Vector2f& dir,float delay)
	:	Bullet(pos,damage,pBulletTex , pBulletTex->GetRect(),fightRectCollider),
		m_Direction{ dir },
		m_CurrentState{size},
		m_Delay{delay},
		m_StartPos{pos}
{
	m_OrthoNormal = Vector2f(dir.y, -dir.x) / dir.Length();
}

void LooxSinAttack::Update(float deltaTime)
{
	if (m_Delay <= 0) {
		m_Incrementor += deltaTime * m_IncrementorSpeed;
		Vector2f dirFinal = m_Direction * m_Incrementor * m_BulletSpeedMulti;
		m_Pos = m_StartPos + dirFinal + m_OrthoNormal * m_SinWaveWidthMulti * sinf(m_Incrementor/m_SinWaveLengthMulti);
		m_DelayTillDespawn -= deltaTime;
		if (m_DelayTillDespawn <= 0)
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
		m_Delay -= deltaTime;
	}
}

void LooxSinAttack::Draw() const
{
	if (m_Delay <= 0) {
		m_pBulletTexture->SetAnimation(m_CurrentState);
		m_pBulletTexture->Draw(m_Pos);
	}
}
