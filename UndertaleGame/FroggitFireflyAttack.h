#pragma once
#include "Bullet.h"

class FightChara;

class FroggitFireflyAttack final : public Bullet
{
public:

	FroggitFireflyAttack(AnimatedSprite* pBulletTex, int damage, FightChara* pFightChara ,Vector2f startPos );

	virtual void Update(float deltaTime) override;
	virtual	void Draw() const override;

private:
	enum class AttackState
	{
		waiting, attacking
	};
	AttackState m_AttackState{ AttackState::waiting };
	Vector2f m_velocity{ -125,200 };
	Vector2f m_CurrentPlayerLocation{};
};

