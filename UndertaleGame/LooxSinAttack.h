#pragma once
#include "Bullet.h"

class LooxSinAttack final : public Bullet
{
public:
	LooxSinAttack(const Vector2f& pos, int damage, AnimatedSprite* pBulletTex, const CollisionBox& fightRectCollider, const std::string& size,const Vector2f& dir, float delay);

	void Update(float deltaTime) override;
	void Draw() const override;

private:
	Vector2f m_FlightPathOrthoNormal;
	Vector2f m_FlightPathDirection;
	Vector2f m_StartPos;
	std::string m_CurrentState;
	float m_Time{};
	const float m_FlightSpeed{15};
	const float m_BulletSpeedMultiplier{ 3 };
	const float m_SinWaveLengthMultiplier{ 2 };
	const float m_SinWaveWidthMultiplier{ 4 };
	float m_CurrentDelayUntilDespawnable{};
	float m_DelayUntilDespawnable{ 2 };
};

