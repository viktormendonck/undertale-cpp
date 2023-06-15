#pragma once
#include "Bullet.h"

class NapstaCryAttack final : public Bullet
{
public:

	NapstaCryAttack(AnimatedSprite* pBulletTex, int damage,float timer, const CollisionBox& fightRectCollider);

	virtual void Update(float deltaTime) override;
	virtual	void Draw() const override;

private:
	std::vector<Vector2f> m_SpawnLocations{Vector2f{320,368},Vector2f{350,357}};
	Vector2f m_Velocity{ 0,0 };
	const Vector2f m_Gravity{ 0,-200 };
	float m_CountDownUntilSpawn{};
};

