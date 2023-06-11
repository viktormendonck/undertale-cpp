#include "pch.h"
#include "NapstaCryAttack.h"



NapstaCryAttack::NapstaCryAttack(AnimatedSprite* pBulletTex, int damage, float timer, const CollisionBox& fightRectCollider)
	:
	Bullet(Vector2f(350, 75), damage, pBulletTex, Rectf(0, 0, 12, 13),fightRectCollider),
	m_CountDownTimer(timer)
{
	m_velocity.x = utils::RandFloatInRange(0, 50, 1);
	if (utils::RandBool())
	{
		m_Pos = m_SpawnLocations[0];
		m_velocity.x = -m_velocity.x;
	}
	else 
	{
		m_Pos = m_SpawnLocations[1];
		m_velocity.x -= 20;
	}
}

void NapstaCryAttack::Update(float deltaTime)
{
	if (m_CountDownTimer <=0)
	{
		m_velocity += Gravity * deltaTime;
		m_Pos += m_velocity * deltaTime;
	}
	else
	{
		m_CountDownTimer -= deltaTime;
	}
	if (utils::IsOverlapping(Rectf(m_Pos.ToPoint2f(), m_pBulletTexture->GetWidth(), m_pBulletTexture->GetHeight()),m_BulletCollider.GetRect()))
	{
		m_IsActive = false;
	} else if (m_Pos.y <=0)
	{
		m_IsActive = false;
	}
}

void NapstaCryAttack::Draw() const
{
	if (m_CountDownTimer <= 0)
	{
		m_pBulletTexture->Draw(m_Pos);
	}
}
