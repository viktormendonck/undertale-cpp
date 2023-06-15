#include "pch.h"
#include "NapstaCryAttack.h"



NapstaCryAttack::NapstaCryAttack(AnimatedSprite* pBulletTex, int damage, float timer, const CollisionBox& fightRectCollider)
	:
	Bullet(Vector2f(350, 75), damage, pBulletTex, Rectf(0, 0, 12, 13),fightRectCollider),
	m_CountDownUntilSpawn(timer)
{
	m_Velocity.x = utils::RandFloatInRange(0, 50, 1);
	if (utils::RandBool())
	{
		m_Pos = m_SpawnLocations[0];
		m_Velocity.x = -m_Velocity.x;
	}
	else 
	{
		m_Pos = m_SpawnLocations[1];
		m_Velocity.x -= 20;
	}
}

void NapstaCryAttack::Update(float deltaTime)
{
	if (m_CountDownUntilSpawn <=0)
	{
		m_Velocity += m_Gravity * deltaTime;
		m_Pos += m_Velocity * deltaTime;
	}
	else
	{
		m_CountDownUntilSpawn -= deltaTime;
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
	if (m_CountDownUntilSpawn <= 0)
	{
		m_pBulletTexture->Draw(m_Pos);
	}
}
