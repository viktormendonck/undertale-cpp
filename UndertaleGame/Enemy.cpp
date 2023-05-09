#include "pch.h"
#include "Enemy.h"

#include <iostream>

#include "FightChara.h"
#include "Texture.h"
#include "AnimatedSprite.h"
#include "Bullet.h"
#include "utils.h"


Enemy::Enemy(const int health, const int conversationAmount, AnimatedSprite* baseTexture, Texture* deathTexture, bool isFlying,FightChara& player, CollisionBox collider, EnemyType type)
	:
	m_Hp{health},
	m_MaxHp{health},
	m_ConversationAmount{conversationAmount},
	m_pTexture{baseTexture},
	m_pEnemyDeathTexture{deathTexture},
	m_IsFlying{isFlying},
	m_Player{player},
	m_Collider{collider},
	m_EnemyType{type}
{
	m_Pos = m_PossibleSpawnLocations[utils::RandInRange(0, 5)];
	m_Pos.y += static_cast<float>(m_IsFlying) * m_FlightOffset;
}

Enemy::~Enemy()
{
	this->DeleteBullets();
}

void Enemy::Draw()
{
	
	for (Bullet* bullet : m_Bullets)
	{
		if (bullet->IsActive()) {
			bullet->Draw();
		}
	}
	m_pTexture->Draw(m_Pos);
	DrawEnemy();
}

void Enemy::Update(float deltaTime)
{
	for (Bullet* bullet : m_Bullets)
	{
		if (bullet->IsActive() && utils::IsOverlapping(bullet->GetRect(),m_Player.GetLocationRect())) {
			m_Player.DamageChara(bullet->GetDamage());
			bullet->SetActivity(false);
		}
		if (bullet->IsActive()) {
			bullet->Update(deltaTime);
		}
	}
	UpdateEnemy(deltaTime);
	if (m_Hp <= (m_MaxHp/5) || m_ConversationAmount <=0)
	{
		m_IsMercyable = true;
	}
}


void Enemy::Converse()
{
	m_ConversationAmount--;
}

void Enemy::Damage(int damage)
{
	m_Hp -= damage;
}

bool Enemy::IsDead()
{
	return m_Hp <= 0;
}

bool Enemy::AreBulletsActive()
{
	bool result{};
	for (Bullet* bullet : m_Bullets)
	{
		result = result || bullet->IsActive();
	}
	return result;
}

void Enemy::DeleteBullets()
{
	for (int i{}; i < m_Bullets.size(); ++i)
	{
		delete m_Bullets[i];
	}
	m_Bullets.clear();
}

EnemyType Enemy::GetEnemyType()
{
	return m_EnemyType;
}


Texture* Enemy::GetDeathTexture()
{
	return m_pEnemyDeathTexture;
}

Vector2f Enemy::GetPos()
{
	return m_Pos;
}

bool Enemy::GetMercyAble()
{
	return m_IsMercyable;
}
