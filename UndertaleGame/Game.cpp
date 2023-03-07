#include "pch.h"
#include "Game.h"

#include <iostream>

#include "Texture.h"
#include "utils.h"
#include "Vector2f.h"
#include "ParticleSystem.h"
#include "AnimatedSprite.h"
#include <map>

#include "SpriteManager.h"

Game::Game(const Window& window)
	: BaseGame{ window }
	, m_pParticleSystem{new ParticleSystem{ 20, 0.6f}}
	, m_pTexture{ new Texture{"Sprites/test4.png"}}
{
	Initialize();
}

Game::~Game()
{
	Cleanup();
}

void Game::Initialize()
{
	m_pSpriteManager = new SpriteManager{};

}

void Game::Cleanup()
{
	delete m_pTexture;
	delete m_pParticleSystem;
}

void Game::Update(float deltaTime)
{
	m_pParticleSystem->Update(deltaTime);
	m_pSpriteManager->Update(deltaTime);
	std::string currentCharaDirection = m_pSpriteManager->m_pAnimatedSprites[0]->GetCurrentAnimation();
	
}

void Game::Draw() const
{
 	ClearBackground();
	glPushMatrix();
	glScalef(2, 2, 0);
	m_pSpriteManager->Draw();

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
	switch(e.keysym.sym)
	{
	case SDLK_w:
		m_pSpriteManager->m_pAnimatedSprites[0]->SetAnimation("up");
		break;
	case SDLK_a:
		m_pSpriteManager->m_pAnimatedSprites[0]->SetAnimation("left");
		break;
	case SDLK_s:
		m_pSpriteManager->m_pAnimatedSprites[0]->SetAnimation("down");
		break;
	case SDLK_d:
		m_pSpriteManager->m_pAnimatedSprites[0]->SetAnimation("right");
		break;
	}
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
	case SDLK_w:
		m_pSpriteManager->m_pAnimatedSprites[0]->SetAnimation("upIdle");
		break;
	case SDLK_a:
		m_pSpriteManager->m_pAnimatedSprites[0]->SetAnimation("leftIdle");
		break;
	case SDLK_s:
		m_pSpriteManager->m_pAnimatedSprites[0]->SetAnimation("downIdle");
		break;
	case SDLK_d:
		m_pSpriteManager->m_pAnimatedSprites[0]->SetAnimation("rightIdle");
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
