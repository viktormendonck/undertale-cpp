#include "pch.h"
#include "Bullet.h"

#include "FightChara.h"
#include "utils.h"

Bullet::Bullet(Vector2f pos, int damage, AnimatedSprite* pBulletTex, FightChara* pFightChara)
	:
	m_Pos{pos},
	m_Damage{damage},
	m_pBulletTexture{pBulletTex},
	m_pPlayer{pFightChara}
{

}

