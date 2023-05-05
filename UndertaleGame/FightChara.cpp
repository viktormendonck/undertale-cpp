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
	m_Pos{ 0,0 },
	m_JumpStrength{ 150 }
{
	m_LineCast = Linef(Point2f(m_Pos.x, m_Pos.y - 1), Point2f(m_Pos.x + m_pHeartTexture->GetWidth(), m_Pos.y - 1));
}

FightChara::~FightChara()
{
	//delete m_pHeartAnims;
	//delete m_pHeartTexture;

}

void FightChara::Draw()
{
	switch (m_State)
	{
	case (FightCharaState::base):
		m_pHeartTexture->Draw(m_Pos.ToPoint2f());
		break;
	case (FightCharaState::running):
		m_pHeartAnims->SetAnimation("flee");
		m_pHeartAnims->Draw(m_Pos);

		break;
	case (FightCharaState::dying):
		m_pHeartAnims->SetAnimation("dying");
		m_pHeartAnims->Draw(m_Pos);
		break;
	}
}

void FightChara::Update(float deltaTime,Fight* fight, std::vector<CollisionBox> colliders)
{
	UpdateMovement(deltaTime);

	const Vector2f nextPlayerPos = m_Pos + (m_Velocity * deltaTime);
	const Rectf playerRect{ nextPlayerPos.ToPoint2f(),m_pHeartTexture->GetWidth(),m_pHeartTexture->GetHeight()};

	Vector2f correctionTotal{};
	// checks and corrects collisions
	for (int i{}; i < colliders.size(); ++i) 
	{
		const std::pair<bool, Vector2f> collisionOutput{ CollisionBox::SideCollisions(colliders[i], playerRect) };
		if (collisionOutput.first)
		{
			correctionTotal += collisionOutput.second;
		}
		if (collisionOutput.second.y < 0)
		{
			m_Velocity.y = 0;
		}
	}
	m_Pos = correctionTotal + nextPlayerPos;

	if (m_IsGravityMode)
	{
		m_IsGrounded = false;
		for (int i{}; i < colliders.size(); ++i)
		{
			CollisionBox player(playerRect);
			const float offset{5};
			Linef groundedCheck{player.GetBottom().point1.x+offset,player.GetBottom().point1.y,player.GetBottom().point2.x-offset,player.GetBottom().point2.y};
			if (utils::IsOverlapping(groundedCheck, colliders[i].GetRect())) m_IsGrounded = true;
		}
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

Rectf FightChara::GetLocationRect() const
{
	return Rectf(m_Pos.ToPoint2f(), m_pHeartTexture->GetWidth(), m_pHeartTexture->GetHeight());
}


bool FightChara::IsGravityMode() const
{
	return m_IsGravityMode;
}

void FightChara::SetPos(Vector2f pos)
{
	m_Pos = pos;
}

float FightChara::GetDamage()
{
	return m_Damage;
}

void FightChara::UpdateMovement(float deltaTime)
{
	const Uint8* state{ SDL_GetKeyboardState(nullptr) };

	int xInputAxis{};
	int yInputAxis{};
	bool inputJump{};
	if (state[SDL_SCANCODE_W]) yInputAxis = 1;
	if (state[SDL_SCANCODE_A]) xInputAxis = -1;
	if (state[SDL_SCANCODE_S]) yInputAxis = -1;
	if (state[SDL_SCANCODE_D]) xInputAxis = 1;
	if (state[SDL_SCANCODE_SPACE]) inputJump = true;

	if (!m_IsGravityMode) {
		m_Velocity = Vector2f(xInputAxis, yInputAxis) * m_Speed;
	} else
	{
		if (!m_IsGrounded) {
			m_Velocity.y -= m_Gravity * deltaTime;
		}
		if (m_IsGrounded) m_Velocity.y = 0;
		if (m_IsGrounded && inputJump) m_Velocity.y = m_JumpStrength;
		
		m_Velocity.x = xInputAxis * m_Speed;

	}
}
void FightChara::OnButtonUp(const SDL_KeyboardEvent& e)
{
	if (e.keysym.sym == SDLK_DELETE) m_IsGravityMode = !m_IsGravityMode;
}


