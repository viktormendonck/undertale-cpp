#pragma once
#include "Bullet.h"

class LooxAttack1 final : public Bullet
{
public:
	LooxAttack1() = delete;
	LooxAttack1(Vector2f pos, int damage, AnimatedSprite* pBulletTex, CollisionBox collider, std::string size,Vector2f dir, float delay);

	virtual void Update(float deltaTime) override;
	virtual	void Draw() const override;

private:
	Vector2f m_OrthoNormal;
	Vector2f m_Direction;
	Vector2f m_StartPos;
	std::string m_CurrentState;
	float m_Incrementor{};
	const float m_IncrementorSpeed{15};
	const float m_BulletSpeedMulti{ 3 };
	const float m_SinWaveLengthMulti{ 2 };
	const float m_SinWaveWidthMulti{ 4 };
	float m_Delay{};
	float m_DelayTillDespawn{ 2 };
};

