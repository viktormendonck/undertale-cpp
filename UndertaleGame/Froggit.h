#pragma once
#include "Enemy.h"


class Froggit : public Enemy
{
public:
	Froggit() = delete;
	Froggit(Texture* pFroggitHead, AnimatedSprite* pBaseTexture, Texture* pDeathTexture,int health, int conversationAmount, float headMovementSpeed);
	~Froggit();

	void Update(float deltaTime);

	void Draw();
	

private:
	Texture* m_pFroggitHead;

	float m_HeadMovingIncrementor{};
	float m_HeadMovementSpeed;

	Vector2f m_BaseHeadOffset;
	Vector2f m_CurrentHeadOffset;
};

