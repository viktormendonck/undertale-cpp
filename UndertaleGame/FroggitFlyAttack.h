#pragma once
#include "Bullet.h"

class FightPlayer;

class FroggitFlyAttack final : public Bullet
{
public:

	FroggitFlyAttack(AnimatedSprite* pBulletTex, int damage,const Vector2f& startPos, FightPlayer* pPlayer, int bulletIteration, const CollisionBox& fightRectCollider);

	void Update(float deltaTime) override;
	void Draw() const override;

private:
	enum class AttackState
	{
		waiting, attacking
	};
	AttackState m_AttackState{ AttackState::waiting };
	FightPlayer* m_pPlayer{};
	Vector2f m_TargetLocation{};
	int m_MaxAttackDelay{1};
	float m_CurrentAttackDelay{};
	const float m_Speed{100};
	const int m_CyclesTillDeath{2};
	int m_CurrentCycle{};

	const float m_BulletFlyTime{2};
	float m_CurrentBulletFlyTime{ m_BulletFlyTime };
};

