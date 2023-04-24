#include "pch.h"
#include "Froggit.h"

#include "AnimatedSprite.h"
#include "Texture.h"

Froggit::Froggit(Texture* pFroggitHead,AnimatedSprite* pBaseTexture, Texture* pDeathTexture, int health, int conversationAmount,float headMovementSpeed) 
	:
	Enemy(health, conversationAmount,pBaseTexture,pDeathTexture,false),
	m_pFroggitHead{pFroggitHead},
	m_BaseHeadOffset{Vector2f(pBaseTexture->GetWidth()/2,pBaseTexture->GetHeight())},
	m_HeadMovementSpeed{headMovementSpeed}
{
}

Froggit::~Froggit()
{
	delete m_pFroggitHead;
}

void Froggit::UpdateEnemy(float deltaTime)
{
	m_HeadMovingIncrementor = m_HeadMovingIncrementor + (deltaTime * m_HeadMovementSpeed);
	float x = cosf(m_HeadMovingIncrementor);
	float y = sinf(2 * m_HeadMovingIncrementor) / 2;
	m_CurrentHeadOffset = m_BaseHeadOffset + Vector2f(x, y);
}

void Froggit::DrawEnemy()
{
	Vector2f headPos = (Enemy::GetPos() + m_CurrentHeadOffset);
	m_pFroggitHead->Draw(Rectf(headPos.ToPoint2f(), m_pFroggitHead->GetWidth(), m_pFroggitHead->GetHeight()));
}

//void Froggit::Update(float deltaTime)
//{
//	Enemy::Update(deltaTime);
//	m_HeadMovingIncrementor = m_HeadMovingIncrementor + (deltaTime * m_HeadMovementSpeed);
//	float x = cosf(m_HeadMovingIncrementor);
//	float y = sinf(2 * m_HeadMovingIncrementor) / 2;
//	m_CurrentHeadOffset = m_BaseHeadOffset + Vector2f(x, y);
//}
//
//void Froggit::Draw()
//{
//	Enemy::Draw();
//	Vector2f headPos = (Enemy::GetPos() + m_CurrentHeadOffset);
//	m_pFroggitHead->Draw(Rectf(headPos.ToPoint2f(), m_pFroggitHead->GetWidth(), m_pFroggitHead->GetHeight()));
//}
