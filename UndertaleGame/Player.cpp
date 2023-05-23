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
	 m_PlayerCollisionRect{ GetRect().left,GetRect().bottom,GetRect().width,GetRect().height / 3 }
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
	
	if (m_IsFalling)
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
			m_IsFalling = false;
			m_ChangedRoom = false;
		}
	} else
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
	//std::cout << "x:" << m_Pos.x<< " y top:" << m_Pos.y + GetRect().height / 3 << " y bottom:" << m_Pos.y<< "\n";
	}
}

void Player::Draw()
{
	m_pSprite->Draw(m_Pos);
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

void Player::StartFalling(const std::string& destination)
{
	m_IsFalling = true;
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
	return m_IsFalling;
}

std::string Player::GetFallDestination()
{
	return m_FallDestination;
}

Vector2f Player::GetFallStartLocation()
{
	return m_FallStartLocation;
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



