#pragma once
#include "Enemy.h"


class Froggit final : public Enemy
{
public:
	Froggit() = delete;
	Froggit(Texture* pFroggitHead, AnimatedSprite* pBaseTexture, Texture* pDeathTexture,int health, int conversationAmount, float headMovementSpeed, FightPlayer& player, CollisionBox collider);

	void UpdateEnemy(float deltaTime) override;
	void DrawEnemy() override;
	void SpawnBullet(ResourceManager* resourceManager) override;


private:
	const Texture* m_pFroggitHead;

	float m_HeadMovingIncrementor{};
	const float m_HeadMovementSpeed;

	const Vector2f m_BaseHeadOffset;
	Vector2f m_CurrentHeadOffset;
};

