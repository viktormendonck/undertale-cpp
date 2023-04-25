#include "pch.h"
#include "FroggitJumpAttack.h"


FroggitJumpAttack::FroggitJumpAttack(AnimatedSprite* pBulletTex, int damage,FightChara* pFightChara)
	:
	Bullet(Vector2f(350,75),damage,pBulletTex,pFightChara)
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
		m_velocity += Gravity * deltaTime;
		m_Pos += m_velocity * deltaTime;
		break;
	}
	if (utils::IsOverlapping(m_pPlayer->GetLocationRect(), Rectf(m_Pos.ToPoint2f(), m_pBulletTexture->GetWidth(), m_pBulletTexture->GetHeight())))
	{
		m_pPlayer->DamageChara(m_Damage);
	}
}

void FroggitJumpAttack::Draw() const
{
	m_pBulletTexture->Draw(m_Pos);
}
