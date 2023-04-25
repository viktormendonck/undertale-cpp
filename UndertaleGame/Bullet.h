#pragma once
#include "AnimatedSprite.h"
#include "Vector2f.h"
#include "FightChara.h"
#include "utils.h"

class FightChara;

class Bullet
{
public:
	Bullet(Vector2f pos, int damage, AnimatedSprite* pBulletTex, FightChara* pFightChara);
	virtual void Update(float deltaTime) = 0;
	virtual void Draw() const = 0;

protected:
	Vector2f m_Pos{};
	int m_Damage{};
	AnimatedSprite* m_pBulletTexture{};
	FightChara* m_pPlayer{};
};

