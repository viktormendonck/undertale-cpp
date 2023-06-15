#pragma once
#include "Bullet.h"
#include "CollisionBox.h"
#include "Vector2f.h"

class AnimatedSprite;

class LooxBounceAttack final : public Bullet
{
public:
	LooxBounceAttack(const Vector2f& pos, int damage, AnimatedSprite* pBulletTex, const CollisionBox& fightRectCollider, bool negation, float delay, float timeToLive);

	void Update(float deltaTime) override;
	void Draw() const override;

private:
	Vector2f m_Velocity{1,1};
	const float m_Speed{75};
	float m_Delay{};
	float m_TimeToLive{};
};

