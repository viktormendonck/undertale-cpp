#pragma once
#include "Bullet.h"

class NapstaNotUpToIt final : public Bullet
{
	//the not really up for it attack
public:
	NapstaNotUpToIt(AnimatedSprite* pBulletTex, const CollisionBox& fightRectCollider);
	void Update(float deltaTime) override;
	void Draw() const override;
private:
	float m_AttackCountDownLength{3};
};

