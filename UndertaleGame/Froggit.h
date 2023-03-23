#pragma once
#include "Enemy.h"


class Froggit : public Enemy
{
public:
	Froggit() = delete;
	Froggit(Texture* pFroggitHead, AnimatedSprite* pBaseTexture, Texture* pDeathTexture,int health, int conversationAmount, float headMovementSpeed);
	~Froggit();

	Froggit(const Froggit& other) = delete; // Copy constructor
	Froggit& operator=(const Froggit& other) = delete; // Copy assignment operator

	Froggit(Froggit&& other) = delete; // Move constructor
	Froggit& operator=(Froggit&& other) = delete; // Move assignment operator

	void Update(float deltaTime);

	void Draw();
	

private:
	Texture* m_pFroggitHead;

	float m_HeadMovingIncrementor{};
	float m_HeadMovementSpeed;

	Vector2f m_BaseHeadOffset;
	Vector2f m_CurrentHeadOffset;
};

