#include "pch.h"
#include "Game.h"

#include <iostream>

#include "Texture.h"
#include "utils.h"
#include "Vector2f.h"
#include "ParticleSystem.h"
#include "AnimatedSprite.h"
#include <map>

Game::Game(const Window& window)
	: BaseGame{ window }
	, m_pParticleSystem{new ParticleSystem{ 20, 0.6f}}
	, m_pTexture{ new Texture{"Sprites/chara.png"}}
{
	Initialize();
}

Game::~Game()
{
	Cleanup();
}

void Game::Initialize()
{
	std::map<std::string, AnimationData> animData{
		{ "down",AnimationData{1,4} },
		{"downIdle",AnimationData{1,1} },
		{"left",AnimationData{2,2}},
		{"leftIdle",AnimationData{2,1}},
		{"right",AnimationData{3,2}},
		{"rightIdle",AnimationData{3,1}},
		{"up",AnimationData{4,4}},
		{"upIdle",AnimationData{4,1}}
	};
	m_pSprite = new AnimatedSprite{ m_pTexture,animData,19,29,"down"};
	m_pSprite->SetAnimation("down");
	m_pSprite->m_pos = Vector2f{ 100,100 };
}

void Game::Cleanup()
{
	delete m_pTexture;
	delete m_pParticleSystem;
}

void Game::Update(float deltaTime)
{
	m_pParticleSystem->Update(deltaTime);
	m_pSprite->Update(deltaTime);
}

void Game::Draw() const
{
 	ClearBackground();
	glPushMatrix();
	glScalef(2, 2, 0);
	m_pSprite->Draw();

	glPopMatrix();
	if (m_IsDead) {
		//m_pParticleSystem->Draw();
	} else
	{
		//m_pTexture->Draw(m_EnemyPos.ToPoint2f());
	}

}

void Game::ProcessKeyDownEvent(const SDL_KeyboardEvent& e)
{
	//std::cout << "KEYDOWN event: " << e.keysym.sym << std::endl;
}

void Game::ProcessKeyUpEvent(const SDL_KeyboardEvent& e)
{
	std::cout << "KEYUP event: " << e.keysym.sym << std::endl;
	switch (e.keysym.sym)
	{
	case SDLK_SPACE:
		m_IsDead = !m_IsDead;
		m_pParticleSystem->StartDissolve(m_EnemyPos, m_pTexture);
		break;
	case SDLK_0:
		m_pSprite->SetAnimation("down");
		break;
	case SDLK_1:
		m_pSprite->SetAnimation("downIdle");
		break;
	case SDLK_2:
		m_pSprite->SetAnimation("left");
		break;
	case SDLK_3:
		m_pSprite->SetAnimation("leftIdle");
		break;
	case SDLK_4:
		m_pSprite->SetAnimation("right");
		break;
	case SDLK_5:
		m_pSprite->SetAnimation("rightIdle");
		break;
	case SDLK_6:
		m_pSprite->SetAnimation("up");
		break;
	case SDLK_7:
		m_pSprite->SetAnimation("upIdle");
		break;
	}
}

void Game::ProcessMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	//std::cout << "MOUSEMOTION event: " << e.x << ", " << e.y << std::endl;
}

void Game::ProcessMouseDownEvent(const SDL_MouseButtonEvent& e)
{
	//std::cout << "MOUSEBUTTONDOWN event: ";
	//switch ( e.button )
	//{
	//case SDL_BUTTON_LEFT:
	//	std::cout << " left button " << std::endl;
	//	break;
	//case SDL_BUTTON_RIGHT:
	//	std::cout << " right button " << std::endl;
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	std::cout << " middle button " << std::endl;
	//	break;
	//}

}

void Game::ProcessMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	//std::cout << "MOUSEBUTTONUP event: ";
	//switch ( e.button )
	//{
	//case SDL_BUTTON_LEFT:
	//	std::cout << " left button " << std::endl;
	//	break;
	//case SDL_BUTTON_RIGHT:
	//	std::cout << " right button " << std::endl;
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	std::cout << " middle button " << std::endl;
	//	break;
	//}
}

void Game::ClearBackground() const
{
	glClearColor(0.0f, 0.0f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}
