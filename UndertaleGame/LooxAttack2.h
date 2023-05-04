#pragma once
#include "Bullet.h"
#include "CollisionBox.h"
#include "Vector2f.h"

class AnimatedSprite;

class LooxAttack2 final : public Bullet
{
public:
	LooxAttack2(Vector2f pos, int damage, AnimatedSprite* pBulletTex, CollisionBox collider, bool negation , float delay, float timeToLive);

	virtual void Update(float deltaTime) override;
	virtual	void Draw() const override;

private:
	Vector2f m_Velocity{1,1};
	float m_Speed{75};
	float m_Delay{};
	float m_TimeToLive{};
};

