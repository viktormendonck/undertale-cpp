#include "pch.h"
#include "NapstaNotUpToIt.h"

NapstaNotUpToIt::NapstaNotUpToIt(AnimatedSprite* pBulletTex, const CollisionBox& fightRectCollider)
	:
	Bullet(Vector2f(270,130),0,pBulletTex,Rectf(0,0,0,0),fightRectCollider)
{
}

void NapstaNotUpToIt::Update(float deltaTime)
{
	m_AttackCountDownLength -= deltaTime;
	if (m_AttackCountDownLength <=0)
	{
		m_IsActive = false;
	}
}

void NapstaNotUpToIt::Draw() const
{
	m_pBulletTexture->Draw(m_Pos);
}

