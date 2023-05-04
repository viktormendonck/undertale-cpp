#include "pch.h"
#include "Loox.h"
#include "LooxAttack1.h"
#include "LooxAttack2.h"
#include "ResourceManager.h"
#include "utils.h"

Loox::Loox(AnimatedSprite* pBaseTexture, Texture* pDeathTexture, int health, int conversationAmount, FightChara& player, CollisionBox collider)
	: Enemy(health, conversationAmount, pBaseTexture, pDeathTexture, false, player,collider)
{
}
void Loox::UpdateEnemy(float deltaTime)
{
}

void Loox::DrawEnemy()
{
}

void Loox::SpawnBullet(ResourceManager* pResourceManager)
{
	Vector2f spawnLocations[12]{Vector2f(246,76),Vector2f(246,224),Vector2f(394,76),Vector2f(394,224),Vector2f(246,175),Vector2f(295,224),Vector2f(345,224),Vector2f(394,175),Vector2f(394,125),Vector2f(345,76),Vector2f(295,76),Vector2f(246,125) };
	const int locationArrayEnd{ 11 };
	m_Bullets.clear();
	if (utils::RandBool())
	{
		for (int i{}; i <= 6; ++i) {
			int randLocation{ utils::RandInRange(0,locationArrayEnd) };
			float angle{ (atan2f(m_Collider.GetRect().GetMiddle().y - spawnLocations[randLocation].y, m_Collider.GetRect().GetMiddle().x - spawnLocations[randLocation].x) + (static_cast<float>(utils::RandInRange(-15,15)* utils::g_Pi / 180)))};
			Vector2f angleVector{cosf(angle),sinf(angle)};
			m_Bullets.push_back(new LooxAttack1(spawnLocations[randLocation], 5, pResourceManager->m_BulletAnimatedSprites[2],m_Collider, "big", angleVector, 0.0f + i * m_DelayBetweenBullets));
			m_Bullets.push_back(new LooxAttack1(spawnLocations[randLocation], 3, pResourceManager->m_BulletAnimatedSprites[2],m_Collider, "med", angleVector, 0.2f + i * m_DelayBetweenBullets));
			m_Bullets.push_back(new LooxAttack1(spawnLocations[randLocation], 2, pResourceManager->m_BulletAnimatedSprites[2],m_Collider, "small", angleVector, 0.4f + i * m_DelayBetweenBullets));
		}
	}
	else
	{
		for(int i{}; i<=6; ++i)
		{
			const int nonCornerBegin{ 4 };
			int randLocation{ utils::RandInRange(nonCornerBegin, locationArrayEnd) };
			m_Bullets.push_back(new LooxAttack2(spawnLocations[randLocation], 2, pResourceManager->m_BulletAnimatedSprites[2], m_Collider, utils::RandBool(), i * 0.5, 5));
		}
	}
}
