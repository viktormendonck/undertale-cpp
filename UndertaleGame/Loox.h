#pragma once
#include "Enemy.h"

class Loox : public Enemy
{
public:
	Loox() = delete;
	Loox(AnimatedSprite* pBaseTexture, Texture* pDeathTexture, int health, int conversationAmount, FightChara& player);
	void UpdateEnemy(float deltaTime) override;
	void DrawEnemy() override;
	void SpawnBullet(ResourceManager* resourceManager) override;
private:

};

