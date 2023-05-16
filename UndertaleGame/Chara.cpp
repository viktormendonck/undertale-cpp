#include "pch.h"
#include "Chara.h"
#include "AnimatedSprite.h"
#include "Inventory.h"

Chara::Chara(AnimatedSprite* playerSprite,Inventory* pInv, float speed)
	:m_pSprite{ playerSprite },
	 m_pInventory{pInv},
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
	//TODO: collisions
	UpdateMovement();
	m_Pos += (m_Velocity * deltaTime);
}

void Chara::Draw()
{
	m_pSprite->Draw(m_Pos);
}

Vector2f Chara::GetPlayerPos() const
{
	return m_Pos;
}
void Chara::UpdateMovement()
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

}

void Chara::ButtonUpManager(const SDL_KeyboardEvent& e)
{
	switch(e.keysym.sym)
	{
	case (SDLK_w):
	case (SDLK_UP):
	case (SDLK_a):
	case (SDLK_LEFT):
	case (SDLK_s):
	case (SDLK_DOWN):
	case (SDLK_d):
	case (SDLK_RIGHT):
		m_pSprite->SetAnimation(m_CurrentIdleStateName);
		break;
	}
}



