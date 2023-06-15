#include "pch.h"
#include "FroggitJumpAttack.h"


FroggitJumpAttack::FroggitJumpAttack(AnimatedSprite* pBulletTex, int damage, const CollisionBox& fightRectCollider)
	:
	Bullet(Vector2f(350,75),damage,pBulletTex, pBulletTex->GetRect(),fightRectCollider)
{
	m_CountDownTimer = static_cast<float>(rand() % 3 + 1);
}


void FroggitJumpAttack::Update(float deltaTime)
{
	switch (m_AttackState)
	{
	case (AttackState::charging):
		m_pBulletTexture->SetAnimation("charging");
		if (m_CountDownTimer <=0)
		{
			m_AttackState = AttackState::jumping;
		} else
		{
		m_CountDownTimer -= deltaTime;
		}
		break;

	case (AttackState::jumping):
		m_pBulletTexture->SetAnimation("jumping");
		m_Velocity += m_Gravity * deltaTime;
		m_Pos += m_Velocity * deltaTime;
		m_CurrentTimeToLive -= deltaTime;
		if (m_CurrentTimeToLive < 0)
		{
			m_IsActive = false;
		}
		break;
	}
}

void FroggitJumpAttack::Draw() const
{
	m_pBulletTexture->Draw(m_Pos);
}
