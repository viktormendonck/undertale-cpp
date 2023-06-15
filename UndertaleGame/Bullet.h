#pragma once
#include "AnimatedSprite.h"
#include "CollisionBox.h"
#include "Vector2f.h"
#include "utils.h"

class FightPlayer;

class Bullet
{
public:
	Bullet(const Vector2f& pos, int damage, AnimatedSprite* pBulletTex, const CollisionBox& bulletCollider, const CollisionBox& fightRectCollider);
	virtual ~Bullet() = default;

	Bullet(const Bullet& other) = delete;
	Bullet& operator=(const Bullet& other) = delete;
	Bullet(Bullet&& other) = delete;
	Bullet& operator=(Bullet&& other) = delete;

	virtual void Update(float deltaTime) = 0;
	virtual void Draw() const = 0;
	bool IsActive() const;
	void SetActivity(bool active);
	Rectf GetRect() const;
	int GetDamage() const;

protected:
	Vector2f m_Pos{};
	const int m_Damage{};
	AnimatedSprite* m_pBulletTexture{};
	bool m_IsActive{true};
	CollisionBox m_BulletCollider{};
	const CollisionBox m_FightRectCollider{};
};

