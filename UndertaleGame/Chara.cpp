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
	//delete m_pSprite;
}

void Chara::Update(float deltaTime)
{
	// add collision function here, checks if chara is allowed to move further, prevent from walking through walls
	m_Pos += (m_CurrentSpeed * deltaTime);
}

void Chara::Draw()
{
	m_pSprite->Draw(m_Pos);
}

void Chara::PlayerButtonDownManager(const SDL_KeyboardEvent& e)
{
	if (e.keysym.sym == SDLK_w)
	{
		m_CurrentSpeed.y = m_Speed;
		if (m_PreviousMovementState == "up") {return;}
		m_pSprite->SetAnimation("up");
		m_PreviousMovementState = "up";
	}
	if (e.keysym.sym == SDLK_a)
	{
		m_CurrentSpeed.x = -m_Speed;
		if (m_PreviousMovementState == "left") { return; }
		m_pSprite->SetAnimation("left");
		m_PreviousMovementState = "left";
	}
	if (e.keysym.sym == SDLK_s)
	{
		m_CurrentSpeed.y = -m_Speed;
		if (m_PreviousMovementState == "down") { return; }
		m_pSprite->SetAnimation("down");
		m_PreviousMovementState = "down";
	}
	if (e.keysym.sym == SDLK_d)
	{
		m_CurrentSpeed.x = m_Speed;
		if (m_PreviousMovementState == "right") { return; }
		m_pSprite->SetAnimation("right");
		m_PreviousMovementState = "right";
	}
}

void Chara::PlayerButtonUpManager(const SDL_KeyboardEvent& e)
{
	if (e.keysym.sym == SDLK_w)
	{
		m_CurrentSpeed.y = 0;
		if (m_PreviousMovementState != "up") { return;}
		m_pSprite->SetAnimation("upIdle");
		m_PreviousMovementState = "upIdle";
	}
	if (e.keysym.sym == SDLK_a)
	{
		m_CurrentSpeed.x = 0;
		if (m_PreviousMovementState != "left") { return; }
		m_pSprite->SetAnimation("leftIdle");
		m_PreviousMovementState = "leftIdle";
	}
	if (e.keysym.sym == SDLK_s)
	{
		m_CurrentSpeed.y = 0;
		if (m_PreviousMovementState != "down") { return; }
		m_pSprite->SetAnimation("downIdle");
		m_PreviousMovementState = "downIdle";
	}
	if (e.keysym.sym == SDLK_d)
	{
		m_CurrentSpeed.x = 0;
		if (m_PreviousMovementState != "right") { return; }
		m_pSprite->SetAnimation("rightIdle");
		m_PreviousMovementState = "rightIdle";
	}
}

Vector2f Chara::GetPlayerPos() const
{
	return m_Pos;
}



