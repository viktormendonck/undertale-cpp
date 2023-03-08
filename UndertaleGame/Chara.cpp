#include "pch.h"
#include "Chara.h"

#include "AnimatedSprite.h"

Chara::Chara(AnimatedSprite* playerSprite, float speed)
	:m_pSprite{ playerSprite },
	 m_Speed{speed}
{
	m_RunStopDelay = 0.2f;
	m_CurrentRunStopDelay = m_RunStopDelay;
}

Chara::~Chara()
{
}

void Chara::Update(float deltaTime)
{
	m_pSprite->m_pos += (m_CurrentSpeed * deltaTime);
}

void Chara::PlayerButtonDownManager(const SDL_KeyboardEvent& e)
{
	if (e.keysym.sym == SDLK_w)
	{
		m_CurrentSpeed.y = m_Speed;
		m_pSprite->SetAnimation("up");
		m_PreviousMovementState = "up";
	}
	if (e.keysym.sym == SDLK_a)
	{
		m_CurrentSpeed.x = -m_Speed;
		m_pSprite->SetAnimation("left");
		m_PreviousMovementState = "left";
	}
	if (e.keysym.sym == SDLK_s)
	{
		m_CurrentSpeed.y = -m_Speed;
		m_pSprite->SetAnimation("down");
		m_PreviousMovementState = "down";
	}
	if (e.keysym.sym == SDLK_d)
	{
		m_CurrentSpeed.x = m_Speed;
		m_pSprite->SetAnimation("right");
		m_PreviousMovementState = "right";
	}
}

void Chara::PlayerButtonUpManager(const SDL_KeyboardEvent& e)
{
	if (e.keysym.sym == SDLK_w)
	{
		m_CurrentSpeed.y = 0;
		m_pSprite->SetAnimation("upIdle");
	}
	if (e.keysym.sym == SDLK_a)
	{
		m_CurrentSpeed.x = 0;
		m_pSprite->SetAnimation("leftIdle");
	}
	if (e.keysym.sym == SDLK_s)
	{
		m_CurrentSpeed.y = 0;
		m_pSprite->SetAnimation("downIdle");
	}
	if (e.keysym.sym == SDLK_d)
	{
		m_CurrentSpeed.x = 0;
		m_pSprite->SetAnimation("rightIdle");
	}
}

Vector2f Chara::GetPlayerPos() const
{
	return m_pSprite->m_pos;
}



