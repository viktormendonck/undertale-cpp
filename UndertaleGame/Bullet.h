#pragma once
#include "AnimatedSprite.h"
#include "CollisionBox.h"
#include "Vector2f.h"
#include "utils.h"

class FightPlayer;

class Bullet
{
public:
	Bullet(const Vector2f& pos, int damage, AnimatedSprite* pBulletTex, const CollisionBox& buletCollider, const CollisionBox& fightRectCollider);
	virtual ~Bullet();

	virtual void Update(float deltaTime) = 0;
	virtual void Draw() const = 0;
	bool IsActive();
	void SetActivity(bool active);
	Rectf GetRect();
	int GetDamage();

protected:
	Vector2f m_Pos{};
	int m_Damage{};
	AnimatedSprite* m_pBulletTexture{};
	bool m_IsActive{true};
	CollisionBox m_BulletCollider{};
	CollisionBox m_FightRectCollider{};
};

