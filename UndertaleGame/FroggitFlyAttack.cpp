#include "pch.h"
#include "FroggitFlyAttack.h"

#include "FightPlayer.h"

FroggitFlyAttack::FroggitFlyAttack(AnimatedSprite* pBulletTex, int damage, const Vector2f& startPos, FightPlayer* pPlayer, int bulletIteration, const CollisionBox& collider)
	:
	Bullet(startPos, damage, pBulletTex, collider),
	m_pPlayer{ pPlayer },
	m_CurrentAttackDelay{ static_cast<float>(m_MaxAttackDelay * bulletIteration + static_cast<float>(utils::RandFloatInRange(1,3,2))) }
{
}

void FroggitFlyAttack::Update(float deltaTime)
{

	switch (m_AttackState)
	{
	case (AttackState::waiting):
			if (m_CurrentAttackDelay <= 0)
		{
			m_CurrentAttackDelay = static_cast<float>(rand() % m_MaxAttackDelay + 1);
			m_TargetLocation = m_pPlayer->GetLocationRect().GetMiddle();
			m_AttackState = AttackState::attacking;
		}
		else
		{
			m_CurrentAttackDelay -= deltaTime;
		}
		break;
	case (AttackState::attacking):
		if (m_CurrentBulletFlyTime <= 0)
		{
			m_CurrentCycle++;
			if (m_CurrentCycle > m_CyclesTillDeath)
			{
				m_IsActive = false;
			}
			m_CurrentBulletFlyTime = m_BulletFlyTime;
			m_AttackState = AttackState::waiting;
		}
		else
		{
			m_CurrentBulletFlyTime -= deltaTime;
			float distance = sqrt(pow(m_TargetLocation.x - m_Pos.x, 2) + pow(m_TargetLocation.y - m_Pos.y, 2));
			float dx = (m_TargetLocation.x - m_Pos.x) / distance;
			float dy = (m_TargetLocation.y - m_Pos.y) / distance;
			m_Pos.x += dx * m_Speed;
			m_Pos.y += dy * m_Speed;
		}
			break;
		}
}

void FroggitFlyAttack::Draw() const
{
	m_pBulletTexture->Draw(m_Pos);
}





