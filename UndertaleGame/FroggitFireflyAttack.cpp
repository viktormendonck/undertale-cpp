#include "pch.h"
#include "FroggitFireflyAttack.h"

FroggitFireflyAttack::FroggitFireflyAttack(AnimatedSprite* pBulletTex, int damage, FightChara* pFightChara, Vector2f startPos)
	:
	Bullet(startPos,damage,pBulletTex,pFightChara)
{
}

void FroggitFireflyAttack::Update(float deltaTime)
{
}

void FroggitFireflyAttack::Draw() const
{

}

