#pragma once
#include "Bullet.h"


class FroggitJumpAttack final: public Bullet 
{
public:

	FroggitJumpAttack(AnimatedSprite* pBulletTex, int damage, const CollisionBox& fightRectCollider);

	void Update(float deltaTime) override;
	void Draw() const override;

private:
	enum class AttackState
	{
		charging, jumping
	};
	AttackState m_AttackState{ AttackState::charging };
	Vector2f m_Velocity{-125,200};
	const Vector2f m_Gravity{0,-260};
	float m_CountDownTimer{};
	const float m_TimeToLive{.85f};
	float m_CurrentTimeToLive{m_TimeToLive};
};

