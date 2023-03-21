#include "pch.h"
#include "Enemy.h"
#include "Texture.h"
#include "AnimatedSprite.h"


Enemy::Enemy(const int health, const int conversationAmount, AnimatedSprite* baseTexture, Texture* deathTexture, bool isFlying)
	:
	m_hp{health},
	m_ConversationAmount{conversationAmount},
	m_pTexture{baseTexture},
	m_pEnemyDeathTexture{deathTexture},
	m_IsFlying{isFlying}
{

}

Enemy::~Enemy()
{
	delete m_pEnemyDeathTexture;
	delete m_pTexture;
}

void Enemy::Damage(int damage)
{
	m_hp -= damage;
}

bool Enemy::IsDead()
{
	return m_hp <= 0;
}

Texture* Enemy::GetDeathTexture()
{
	return m_pEnemyDeathTexture;
}

Vector2f Enemy::GetPos()
{
	return m_Pos;
}
