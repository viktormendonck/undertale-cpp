#include "pch.h"
#include "Napstablook.h"
#include "NapstaNotUpToIt.h"
#include "NapstaCryAttack.h"
#include "ResourceManager.h"
#include "SoundManager.h"
#include "utils.h"

Napstablook::Napstablook(AnimatedSprite* pBaseTexture, Texture* pDeathTexture, int health, int conversationAmount,FightPlayer& player, CollisionBox collider)
	:
	Enemy(health,conversationAmount,pBaseTexture,pDeathTexture,false,player,collider,EnemyType::napstablook)
{
	m_Pos.x = 270;
	SoundManager::GetInstance().SetMusic("ghostFight");
}

void Napstablook::UpdateEnemy(float deltaTime)
{
}

void Napstablook::DrawEnemy()
{
}

void Napstablook::SpawnBullet(ResourceManager* pResourceManager)
{
	if (utils::RandInRange(0,100)<25)
	{
		m_Bullets.push_back(new NapstaNotUpToIt(pResourceManager->m_BulletAnimatedSprites[4],m_FightRectCollider));
	} else
	{
		for (int i{}; i <= 30; ++i)
		{
			m_Bullets.push_back(new NapstaCryAttack(pResourceManager->m_BulletAnimatedSprites[3], 1,static_cast<float>(i)/6,m_FightRectCollider));
		}
		
	}
}
