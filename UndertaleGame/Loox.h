#pragma once
#include "Enemy.h"

class Loox final : public Enemy
{
public:
	Loox(AnimatedSprite* pBaseTexture, Texture* pDeathTexture, int health, int conversationAmount, FightPlayer& player, CollisionBox collider);

	void UpdateEnemy(float deltaTime) override;
	void DrawEnemy() override;
	void SpawnBullet(ResourceManager* pResourceManager) override;
private:
	float m_DelayBetweenBullets{1};
};

