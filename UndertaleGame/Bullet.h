#pragma once
#include "AnimatedSprite.h"
#include "CollisionBox.h"
#include "Vector2f.h"
#include "utils.h"

class FightChara;

class Bullet
{
public:
	Bullet(Vector2f pos, int damage, AnimatedSprite* pBulletTex, CollisionBox collider);
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
	CollisionBox m_Collider{};
};

