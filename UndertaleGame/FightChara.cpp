#include "pch.h"
#include "FightChara.h"

#include <iostream>

#include "Fight.h"
#include "AnimatedSprite.h"
#include "Texture.h"
#include "utils.h"
#include "CollisionBox.h"

FightChara::FightChara(Texture* heartTexture, AnimatedSprite* heartAnims, float speed, int startHealth)
	:
	m_pHeartTexture{ heartTexture },
	m_pHeartAnims{ heartAnims },
	m_Hp{ startHealth },
	m_Speed{ speed },
	m_pos{ 0,0 },
	m_JumpStrength{ 150 }
{
	m_LineCast = Linef(Point2f(m_pos.x, m_pos.y - 1), Point2f(m_pos.x + m_pHeartTexture->GetWidth(), m_pos.y - 1));
}

FightChara::~FightChara()
{
	delete m_pHeartAnims;
	delete m_pHeartTexture;

}

void FightChara::Draw()
{
	switch (m_State)
	{
	case (FightCharaState::base):
		m_pHeartTexture->Draw(m_pos.ToPoint2f());
		break;
	case (FightCharaState::running):
		m_pHeartAnims->SetAnimation("flee");
		m_pHeartAnims->Draw(m_pos);

		break;
	case (FightCharaState::dying):
		m_pHeartAnims->SetAnimation("dying");
		m_pHeartAnims->Draw(m_pos);
		break;
	}
}

void FightChara::Update(float deltaTime,Fight* fight)
{
	m_LineCast = Linef(Point2f(m_pos.x, m_pos.y-1), Point2f(m_pos.x + m_pHeartTexture->GetWidth(), m_pos.y-1));
	const Vector2f nextPlayerPos = m_pos + (m_Velocity * deltaTime);
	const Rectf playerRect{ nextPlayerPos.ToPoint2f(),m_pHeartTexture->GetWidth(),m_pHeartTexture->GetHeight()};

	CollisionBox fightBorder = fight->GetFightBoundaryBox();


	if (m_IsGravityMode) {
		if (!(utils::IsOverlapping(fight->GetFightBoundaryBox().GetBottom(), playerRect) || utils::IsOverlapping(fight->GetFightBoundaryBox().GetTop(), playerRect)))
		{
			m_IsGrounded = false;
			m_Velocity.y -= m_Gravity * deltaTime;
		}
		else
		{
			m_IsGrounded = true;
			m_Velocity.y = 0;
		}
	}

	if (!(utils::IsOverlapping(fight->GetFightBoundaryBox().GetBottom(),playerRect) || utils::IsOverlapping(fight->GetFightBoundaryBox().GetTop(),playerRect)))
	{
		m_pos.y = nextPlayerPos.y;
	}
	if (!(utils::IsOverlapping(fight->GetFightBoundaryBox().GetLeft(), playerRect) || utils::IsOverlapping(fight->GetFightBoundaryBox().GetRight(), playerRect)))
	{
		m_pos.x = nextPlayerPos.x;
	}

	if (m_Hp<=0)
	{
		m_State = FightCharaState::dying;
	}
}

void FightChara::DamageChara(int damage)
{
	m_Hp -= damage;
}

void FightChara::SetFightCharaState(FightCharaState state)
{
	m_State = state;
}

void FightChara::SetPos(Vector2f pos)
{
	m_pos = pos;
}

void FightChara::ButtonDownManager(const SDL_KeyboardEvent& e)
{
	if (!m_IsGravityMode) {
		switch (e.keysym.sym)
		{
		case (SDLK_w):
			m_Velocity.y = m_Speed;
			break;
		case (SDLK_a):
			m_Velocity.x = -m_Speed;
			break;
		case (SDLK_s):
			m_Velocity.y = -m_Speed;
			break;
		case (SDLK_d):
			m_Velocity.x = m_Speed;
			break;
		}
	} else
	{
		switch (e.keysym.sym)
		{
		case (SDLK_a):
			m_Velocity.x = -m_Speed;
			break;
		case (SDLK_d):
			m_Velocity.x = m_Speed;
			break;
		}
	}
}

void FightChara::ButtonUpManager(const SDL_KeyboardEvent& e)
{
	if (!m_IsGravityMode) {
		switch (e.keysym.sym)
		{
		case (SDLK_w):
			m_Velocity.y = 0;
			break;
		case (SDLK_a):
			m_Velocity.x = 0;
			break;
		case (SDLK_s):
			m_Velocity.y = 0;
			break;
		case (SDLK_d):
			m_Velocity.x = 0;
			break;
		case(SDLK_DELETE):
			m_IsGravityMode = !m_IsGravityMode;
			break;
		}
	}
	else
	{
		switch (e.keysym.sym)
		{
		case (SDLK_a):
			m_Velocity.x = 0;
			break;
		case (SDLK_d):
			m_Velocity.x = 0;
			break;
		case (SDLK_SPACE):
			if (m_IsGrounded) {
				m_Velocity.y += m_JumpStrength;
				m_pos += Vector2f(0, 1);
			}
			break;
		case(SDLK_DELETE):
			m_IsGravityMode = !m_IsGravityMode;
			break;
		}
	}
}



