#include "pch.h"
#include "FightPlayer.h"

#include <iostream>

#include "Fight.h"
#include "AnimatedSprite.h"
#include "Texture.h"
#include "utils.h"
#include "CollisionBox.h"
#include "Inventory.h"

FightPlayer::FightPlayer(Texture* heartTexture, AnimatedSprite* heartAnims, Inventory* pInv, float speed, int startHealth)
	:
	m_pHeartTexture{ heartTexture },
	m_pHeartAnims{ heartAnims },
	m_pInventory{pInv},
	m_Hp{ startHealth },
	m_MaxHp{startHealth},
	m_Speed{ speed },
	m_Pos{ 0,0 },
	m_JumpStrength{ 150 }
{
	m_LineCast = Linef(Point2f(m_Pos.x, m_Pos.y - 1), Point2f(m_Pos.x + m_pHeartTexture->GetWidth(), m_Pos.y - 1));
}

FightPlayer::~FightPlayer()
{
	//delete m_pHeartAnims;
	//delete m_pHeartTexture;

}

void FightPlayer::Draw()
{
	switch (m_State)
	{
	case (FightPlayerState::base):
		m_pHeartTexture->Draw(m_Pos.ToPoint2f());
		break;
	case (FightPlayerState::running):
		m_pHeartAnims->SetAnimation("flee");
		m_pHeartAnims->Draw(m_Pos);

		break;
	case (FightPlayerState::dying):
		m_pHeartAnims->SetAnimation("dying");
		m_pHeartAnims->Draw(m_Pos);
		break;
	}
}

void FightPlayer::Update(float deltaTime,Fight* fight, std::vector<CollisionBox> colliders)
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
		m_State = FightPlayerState::dying;
	}
}

void FightPlayer::DamageChara(int damage)
{
	m_Hp -= damage;
}

void FightPlayer::SetFightPlayerState(FightPlayerState state)
{
	m_State = state;
}

Rectf FightPlayer::GetLocationRect() const
{
	return Rectf(m_Pos.ToPoint2f(), m_pHeartTexture->GetWidth(), m_pHeartTexture->GetHeight());
}


bool FightPlayer::IsGravityMode() const
{
	return m_IsGravityMode;
}

void FightPlayer::SetPos(const Vector2f& pos)
{
	m_Pos = pos;
}

float FightPlayer::GetDamage() const
{
	return m_Damage;
}

int FightPlayer::GetHealth() const
{
	return m_Hp;
}

int FightPlayer::GetMaxHealth() const
{
	return m_MaxHp;
}

bool FightPlayer::IsDead()
{
	return m_Hp <= 0;
}

Inventory* FightPlayer::GetInv() const
{
	return m_pInventory;
}

void FightPlayer::UpdateMovement(float deltaTime)
{
	const Uint8* state{ SDL_GetKeyboardState(nullptr) };

	int xInputAxis{};
	int yInputAxis{};
	bool inputJump{};
	if (state[SDL_SCANCODE_W] || state[SDL_SCANCODE_UP]) yInputAxis = 1;
	if (state[SDL_SCANCODE_A] || state[SDL_SCANCODE_LEFT]) xInputAxis = -1;
	if (state[SDL_SCANCODE_S] || state[SDL_SCANCODE_DOWN]) yInputAxis = -1;
	if (state[SDL_SCANCODE_D] || state[SDL_SCANCODE_RIGHT]) xInputAxis = 1;
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
void FightPlayer::OnButtonUp(const SDL_KeyboardEvent& e)
{
	if (e.keysym.sym == SDLK_DELETE) m_IsGravityMode = !m_IsGravityMode;
}


