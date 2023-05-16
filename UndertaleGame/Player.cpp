#include "pch.h"
#include "Player.h"
#include "AnimatedSprite.h"
#include "Inventory.h"

Player::Player(AnimatedSprite* playerSprite,Inventory* pInv, float speed)
	:m_pSprite{ playerSprite },
	 m_pInventory{pInv},
	 m_Speed{speed}
{
	m_RunStopDelay = 0.2f;
	m_CurrentRunStopDelay = m_RunStopDelay;
}

Player::~Player()
{
	//delete m_pSprite;
}

void Player::Update(float deltaTime)
{
	//TODO: collisions
	UpdateMovement();
	m_Pos += (m_Velocity * deltaTime);
}

void Player::Draw()
{
	m_pSprite->Draw(m_Pos);
}

Vector2f Player::GetPlayerPos() const
{
	return m_Pos;
}

void Player::SetPlayerPos(Vector2f pos)
{
	m_Pos = pos;
}

void Player::UpdateMovement()
{
	const Uint8* state{ SDL_GetKeyboardState(nullptr) };

	int xInputAxis{};
	int yInputAxis{};
	bool inputJump{};
	if (state[SDL_SCANCODE_W] || state[SDL_SCANCODE_UP])
	{
		yInputAxis = 1;
		std::string direction = "up";
		if (m_pSprite->GetCurrentAnimation() != direction)
		{
			m_pSprite->SetAnimation(direction);
		}
		m_CurrentIdleStateName = "upIdle";
	}
	if (state[SDL_SCANCODE_A] || state[SDL_SCANCODE_LEFT])
{
		xInputAxis = -1;
		std::string direction = "left";
		if (m_pSprite->GetCurrentAnimation() != direction )
		{
			m_pSprite->SetAnimation(direction);
		}
		m_CurrentIdleStateName = "leftIdle";
	}
	if (state[SDL_SCANCODE_S] || state[SDL_SCANCODE_DOWN])
{
		yInputAxis = -1;
		std::string direction = "down";
		if (m_pSprite->GetCurrentAnimation() != direction)
		{
			m_pSprite->SetAnimation(direction);
		}
		m_CurrentIdleStateName = "downIdle";
	}
	if (state[SDL_SCANCODE_D] || state[SDL_SCANCODE_RIGHT])
{
		xInputAxis = 1;

		std::string direction = "right";
		if (m_pSprite->GetCurrentAnimation() != direction)
		{
			m_pSprite->SetAnimation(direction);
		}
		m_CurrentIdleStateName = "rightIdle";
	}
	if (state[SDL_SCANCODE_SPACE]) inputJump = true;

	m_Velocity.x = xInputAxis * m_Speed;
	m_Velocity.y = yInputAxis * m_Speed;
	if (m_Velocity == Vector2f{ 0,0 })
	{
		m_pSprite->SetAnimation(m_CurrentIdleStateName);
	}
}


Inventory* Player::GetInventory()
{
	return m_pInventory;
}

Rectf Player::GetRect()
{
	return Rectf(m_Pos.ToPoint2f(), m_pSprite->GetWidth(), m_pSprite->GetHeight());
}



