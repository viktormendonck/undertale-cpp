#include "pch.h"
#include "Bullet.h"

#include <iostream>

#include "utils.h"

Bullet::Bullet(const Vector2f& pos, int damage, AnimatedSprite* pBulletTex, const CollisionBox& bulletCollider, const CollisionBox& fightRectCollider)
	:
	m_Pos{pos},
	m_Damage{damage},
	m_pBulletTexture{pBulletTex},
	m_BulletCollider{bulletCollider},
	m_FightRectCollider(fightRectCollider)
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
	return Rectf(m_Pos.ToPoint2f(), m_BulletCollider.GetRect().width, m_BulletCollider.GetRect().height);
}

int Bullet::GetDamage()
{
	return m_Damage;
}

