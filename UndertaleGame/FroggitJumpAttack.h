#pragma once
#include "Bullet.h"


class FroggitJumpAttack final: public Bullet 
{
public:

	FroggitJumpAttack(AnimatedSprite* pBulletTex, int damage, FightChara* pFightChara);

	virtual void Update(float deltaTime) override;
	virtual	void Draw() const override;

private:
	enum class AttackState
	{
		charging, jumping
	};
	AttackState m_AttackState{ AttackState::charging };
	Vector2f m_velocity{-125,200};
	Vector2f Gravity{0,-260};
	float m_CountDownTimer{};
};

