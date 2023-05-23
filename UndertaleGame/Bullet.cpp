#include "pch.h"
#include "Bullet.h"

#include <iostream>

#include "utils.h"

Bullet::Bullet(const Vector2f& pos, int damage, AnimatedSprite* pBulletTex, const CollisionBox& collider)
	:
	m_Pos{pos},
	m_Damage{damage},
	m_pBulletTexture{pBulletTex},
	m_Collider{collider}
{

}



Bullet::~Bullet()
{
}

bool Bullet::IsActive()
{
	return m_IsActive;
}

void Bullet::SetActivity(bool active)
{
	m_IsActive = active;
}

Rectf Bullet::GetRect()
{
	return Rectf(m_Pos.ToPoint2f(), m_pBulletTexture->GetWidth(), m_pBulletTexture->GetHeight());
}

int Bullet::GetDamage()
{
	return m_Damage;
}

