#pragma once
#include "Bullet.h"

class FightPlayer;

class FroggitFlyAttack final : public Bullet
{
public:

	FroggitFlyAttack(AnimatedSprite* pBulletTex, int damage,const Vector2f& startPos, FightPlayer* pPlayer, int bulletIteration, const CollisionBox& collider);

	virtual void Update(float deltaTime) override;
	virtual	void Draw() const override;

private:
	enum class AttackState
	{
		waiting, attacking
	};
	AttackState m_AttackState{ AttackState::waiting };
	FightPlayer* m_pPlayer{};
	Vector2f m_velocity{ -125,200 };
	Vector2f m_TargetLocation{};
	int m_MaxAttackDelay{1};
	float m_CurrentAttackDelay{};
	float m_Speed{ 1 };
	int m_CyclesTillDeath{ 2 };
	int m_CurrentCycle{};

	float m_BulletFlyTime{2};
	float m_CurrentBulletFlyTime{ m_BulletFlyTime };
};

