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
	/*if (m_CurrentRunStopDelay <=0) // cant stop movement, fix later
	{
		if (m_PreviousMovementState == "up")
		{
			m_pSprite->SetAnimation("upIdle");
			m_CurrentSpeed *= 0;
		}
		else if (m_PreviousMovementState == "left")
		{
			m_pSprite->SetAnimation("leftIdle");
			m_CurrentSpeed *= 0;
		}
		else if (m_PreviousMovementState == "down")
		{
			m_pSprite->SetAnimation("downIdle");
			m_CurrentSpeed *= 0;
		}
		else if (m_PreviousMovementState == "right")
		{
			m_pSprite->SetAnimation("rightIdle");
			m_CurrentSpeed *= 0;
		}
	}
	else
	{
		m_CurrentRunStopDelay -= deltaTime;
	}*/
}

void Chara::PlayerInputManager(const SDL_KeyboardEvent& e)
{
	if (e.keysym.sym == SDLK_w)
	{
		m_CurrentSpeed.y = m_Speed;
		m_pSprite->SetAnimation("up");
		m_PreviousMovementState = "up";
		m_CurrentRunStopDelay = m_RunStopDelay;
	}
	if (e.keysym.sym == SDLK_a)
	{
		m_CurrentSpeed.x = -m_Speed;
		m_pSprite->SetAnimation("left");
		m_PreviousMovementState = "left";
		m_CurrentRunStopDelay = m_RunStopDelay;
	}
	if (e.keysym.sym == SDLK_s)
	{
		m_CurrentSpeed.y = -m_Speed;
		m_pSprite->SetAnimation("down");
		m_PreviousMovementState = "down";
		m_CurrentRunStopDelay = m_RunStopDelay;
	}
	if (e.keysym.sym == SDLK_d)
	{
		m_CurrentSpeed.x = m_Speed;
		m_pSprite->SetAnimation("right");
		m_PreviousMovementState = "right";
		m_CurrentRunStopDelay = m_RunStopDelay;
	}
}

Vector2f Chara::GetPlayerPos() const
{
	return m_pSprite->m_pos;
}



