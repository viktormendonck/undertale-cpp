#include "pch.h"
#include "Froggit.h"
#include "utils.h"
#include "AnimatedSprite.h"
#include "Bullet.h"
#include "Texture.h"
#include "FroggitJumpAttack.h"
#include "FroggitFlyAttack.h"
#include "ResourceManager.h"

Froggit::Froggit(Texture* pFroggitHead,AnimatedSprite* pBaseTexture, Texture* pDeathTexture, int health, int conversationAmount,float headMovementSpeed, FightPlayer& player, CollisionBox collider)
	:
	Enemy(health, conversationAmount,pBaseTexture,pDeathTexture,false,player,collider,EnemyType::froggit),
	m_pFroggitHead{pFroggitHead},
	m_HeadMovementSpeed{headMovementSpeed},
	m_BaseHeadOffset{Vector2f(0,pBaseTexture->GetHeight())}
{
}

Froggit::~Froggit()
{

}

void Froggit::UpdateEnemy(float deltaTime)
{
	m_HeadMovingIncrementor = m_HeadMovingIncrementor + (deltaTime * m_HeadMovementSpeed);
	float x = cosf(m_HeadMovingIncrementor) * 4 ;
	float y = sinf(2 * m_HeadMovingIncrementor) * 2;
	m_CurrentHeadOffset = m_BaseHeadOffset + Vector2f(x, y);
}

void Froggit::DrawEnemy()
{
	Vector2f headPos = (Enemy::GetPos() + m_CurrentHeadOffset);
	m_pFroggitHead->Draw(Rectf(headPos.ToPoint2f(), m_pFroggitHead->GetWidth(), m_pFroggitHead->GetHeight()));
}
void Froggit::SpawnBullet(ResourceManager* resourceManager)
{
	m_Bullets.clear();
	if (utils::RandBool())
	{
		m_Bullets.push_back(new FroggitJumpAttack{ resourceManager->m_BulletAnimatedSprites[0],6,m_Collider });
	} else
	{
		for (int i{}; i < 6; ++i) {
			m_Bullets.push_back(new FroggitFlyAttack{ resourceManager->m_BulletAnimatedSprites[1],3,Vector2f{static_cast<float>(utils::RandInRange(240,390)),230}, &m_Player, i,m_Collider }); 
		}
	}

}

