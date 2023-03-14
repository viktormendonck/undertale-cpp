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
#include "Chara.h"
#include "FightChara.h"

Game::Game(const Window& window)
	: BaseGame{ window }
	, m_pParticleSystem{new ParticleSystem{ 20, 0.6f}}
	, m_pTexture{ new Texture{"Sprites/test2.png"}}
	, m_pInfoScreenTexture{ new Texture{"Static_Screens/Controls.png"}}
{
	Initialize(window);
}

Game::~Game()
{
	Cleanup();
}

void Game::Initialize(const Window& window)
{
	m_pSpriteManager = new SpriteManager{};
	m_pChara = new Chara{ m_pSpriteManager->m_pAnimatedSprites[0],40 };
	m_pFightChara = new FightChara( m_pSpriteManager->m_pStaticTextures[0],m_pSpriteManager->m_pAnimatedSprites[1],5,20, Vector2f{window.width/2,window.height/2});

}

void Game::Cleanup()
{
	delete m_pTexture;
	delete m_pParticleSystem;
	delete m_pInfoScreenTexture;
}

void Game::Update(float deltaTime)
{
	m_pParticleSystem->Update(deltaTime);
	m_pSpriteManager->Update(deltaTime);

	switch (m_GameState)
	{
	case GameState::adventure:
		m_pChara->Update(deltaTime);
		break;
	case GameState::fight:

		break;
	case GameState::infoScreen:
		
		break;
	case GameState::startScreen:

		break;

	}
}

void Game::Draw() const
{
	ClearBackground();
	switch (m_GameState)
	{
	case GameState::adventure:
		glPushMatrix();
		glScalef(2, 2, 0);
		m_pChara->Draw();
		glPopMatrix();
		break;

	case GameState::infoScreen:
		m_pInfoScreenTexture->Draw(Point2f{ 0,0 });
		break;

	case GameState::startScreen:

		break;
	}

}

void Game::ProcessKeyDownEvent(const SDL_KeyboardEvent& e)
{
	m_pChara->PlayerButtonDownManager(e);
}

void Game::ProcessKeyUpEvent(const SDL_KeyboardEvent& e)
{
	m_pChara->PlayerButtonUpManager(e);
	//std::cout << "KEYUP event: " << e.keysym.sym << std::endl;
	switch (e.keysym.sym)
	{
	case SDLK_i:
		if (m_GameState == GameState::adventure)
		{
			m_GameState = GameState::infoScreen;
		} else
		{
			m_GameState = GameState::adventure;
		}
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
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}
