#include "pch.h"
#include "Player.h"

#include <iostream>

#include "AnimatedSprite.h"
#include "CollisionBox.h"
#include "Inventory.h"
#include "utils.h"

Player::Player(AnimatedSprite* playerSprite,Inventory* pInv, float speed)
	:m_pSprite{ playerSprite },
	 m_pInventory{pInv},
	 m_Speed{speed},
	 m_PlayerCollisionRect{ GetRect().left,GetRect().bottom,GetRect().width,GetRect().height / 3 },
	 m_InteractCollisionRect{ 0,0,GetRect().width,GetRect().height / 2 }
{
	m_RunStopDelay = 0.2f;
	m_CurrentRunStopDelay = m_RunStopDelay;
}

Player::~Player()
{
	//delete m_pSprite;
}

void Player::Update(float deltaTime, std::vector<CollisionBox> colliders)
{
	UpdateCollisionSelection();
	switch(m_PlayerState)
	{
	case(PlayerState::wandering):
		{
		UpdateMovement();
		m_ChangedRoom = false;
		const Vector2f nextPlayerPos = m_Pos + (m_Velocity * deltaTime);
		Vector2f correctionTotal{};
		m_PlayerCollisionRect = Rectf(GetRect().left, GetRect().bottom, GetRect().width, GetRect().height / 3);
		for (int i{}; i < colliders.size(); ++i)
		{

			const std::pair<bool, Vector2f> collisionOutput{ CollisionBox::SideCollisions(colliders[i],m_PlayerCollisionRect ) };
			if (collisionOutput.first)
			{
				correctionTotal += collisionOutput.second;
			}
			if (collisionOutput.second.y < 0)
			{
				m_Velocity.y = 0;
			}
		}
		m_Pos = nextPlayerPos + correctionTotal;
		}
		break;
	case(PlayerState::falling):
		{
		m_TimeIncrementor += deltaTime * m_SpinSpeed;
		int saveSpinDirection{m_CurrentSpinDirection};
		m_CurrentSpinDirection = static_cast<int>(m_TimeIncrementor) % 4;
		if (saveSpinDirection != m_CurrentSpinDirection)
		{
			m_pSprite->SetAnimation(m_SpinAnimation[m_CurrentSpinDirection]);
		}
		m_Pos.y -= m_FallSpeed * deltaTime;
		if (m_Pos.y <= m_FallStartLocation.y && m_ChangedRoom)
		{
			m_PlayerState = PlayerState::wandering;
			m_ChangedRoom = false;
		}
		}
		break;
	case(PlayerState::interacting):
		{
			
		}
		break;
	}
	
}

void Player::UpdateCollisionSelection()
{
	std::string direction{ m_pSprite->GetCurrentAnimation() };

	if (direction == "upIdle" || direction == "up")
	{
		m_InteractCollisionRect.left = m_Pos.x;
		m_InteractCollisionRect.bottom = m_Pos.y + m_InteractCollisionRect.height;
	}
	if (direction == "downIdle" || direction == "down")
	{
		m_InteractCollisionRect.left = m_Pos.x;
		m_InteractCollisionRect.bottom = m_Pos.y - m_InteractCollisionRect.height;
	}
	if (direction == "leftIdle" || direction == "left")
	{
		m_InteractCollisionRect.bottom = m_Pos.y;
		m_InteractCollisionRect.left = m_Pos.x - m_InteractCollisionRect.width;
	}
	if (direction == "rightIdle" || direction == "right")
	{
		m_InteractCollisionRect.bottom = m_Pos.y;
		m_InteractCollisionRect.left = m_Pos.x + m_InteractCollisionRect.width;
	}
}

void Player::Draw()
{
	m_pSprite->Draw(m_Pos);
#ifdef _DEBUG
	utils::FillRect(m_InteractCollisionRect);
#endif
}

Vector2f Player::GetPlayerPos() const
{
	return m_Pos;
}

void Player::SetPlayerPos(const Vector2f& pos)
{
	m_Pos = pos;
}

Rectf Player::GetPlayerCollisionRect()
{
	return m_PlayerCollisionRect;
}

Rectf Player::GetInteractCollisionRect()
{
	return m_InteractCollisionRect;
}

Rectf Player::GetFullPlayerRect()
{
	return Rectf(m_Pos.x, m_Pos.y, m_pSprite->GetWidth(), m_pSprite->GetHeight());
}

void Player::SetPlayerState(PlayerState playerState)
{
	m_PlayerState = playerState;
}

Player::PlayerState Player::GetState()
{
	return m_PlayerState;
}

void Player::StartFalling(const std::string& destination)
{
	m_PlayerState = PlayerState::falling;
	m_FallStartLocation = m_Pos;
	m_FallDestination = destination;
}

void Player::SetChangedRoom(bool e)
{
	m_ChangedRoom = e;
}

bool Player::HasChangedRoom()
{
	return m_ChangedRoom;
}

bool Player::IsFalling()
{
	return m_PlayerState == PlayerState::falling;
}

std::string Player::GetFallDestination()
{
	return m_FallDestination;
}

Vector2f Player::GetFallStartLocation()
{
	return m_FallStartLocation;
}

void Player::ButtonUpManager(const SDL_KeyboardEvent& e)
{
	
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



