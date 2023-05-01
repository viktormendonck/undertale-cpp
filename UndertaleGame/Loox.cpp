#include "pch.h"
#include "Loox.h"
#include "utils.h"

Loox::Loox(AnimatedSprite* pBaseTexture, Texture* pDeathTexture, int health, int conversationAmount, FightChara& player)
	: Enemy(health, conversationAmount, pBaseTexture, pDeathTexture, false, player)
{
}
void Loox::UpdateEnemy(float deltaTime)
{
}

void Loox::DrawEnemy()
{
}

void Loox::SpawnBullet(ResourceManager* resourceManager)
{
	m_Bullets.clear();
	int randAttack = utils::RandInRange(0, 1);
	if (randAttack == 0)
	{
		//m_Bullets.push_back(new );
	}
	else
	{
		for (int i{ 1 }; i < 6; ++i) {
			//m_Bullets.push_back(new });
		}
	}
}
