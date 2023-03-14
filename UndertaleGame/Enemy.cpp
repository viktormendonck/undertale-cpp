#include "pch.h"
#include "Enemy.h"


Enemy::Enemy(int health, int conversationAmount)
	: m_hp{},
	  m_ConversationAmount{conversationAmount}
{

}

Enemy::~Enemy()
{

}

void Enemy::Damage(int damage)
{
	m_hp -= damage;
}

bool Enemy::IsDead()
{
	return m_hp <= 0;
}
