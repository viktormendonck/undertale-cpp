#pragma once
#include "Enemy.h"

class Napstablook final : public Enemy
{
public:
	Napstablook() = delete;
	Napstablook(AnimatedSprite* pBaseTexture, Texture* pDeathTexture, int health, int conversationAmount, FightPlayer& player, CollisionBox collider);
	void UpdateEnemy(float deltaTime);
	void DrawEnemy();
	void SpawnBullet(ResourceManager* pResourceManager);
private:

};

