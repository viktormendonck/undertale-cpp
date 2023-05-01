#include "pch.h"
#include "Game.h"

#include <iostream>

#include "Texture.h"
#include "utils.h"
#include "Vector2f.h"
#include "ParticleSystem.h"
#include "AnimatedSprite.h"
#include <map>

#include "ResourceManager.h"
#include "Chara.h"
#include "Fight.h"
#include "FightChara.h"
//TESTCLASSES
// TODO: remove
#include "FroggitFlyAttack.h"
#include "FroggitJumpAttack.h"

Game::Game(const Window& window)
	: BaseGame{ window }
	, m_pParticleSystem{new ParticleSystem{ 20, 0.6f}}
	, m_pInfoScreenTexture{ new Texture{"Static_Screens/Controls.png"}}
	, m_Window{ GetViewPort() }
{
	
	Initialize();
}

Game::~Game()
{
	Cleanup();
}

void Game::Initialize()
{
	m_pResourceManager = new ResourceManager{};
	m_pChara = new Chara{ m_pResourceManager->m_AnimatedSprites[0],40 };
	m_pFightChara = new FightChara(m_pResourceManager->m_StaticTextures[0], m_pResourceManager->m_AnimatedSprites[1], 100,
		20);
	//TESTSTUFF
	//TODO > remove
	m_pFight = new Fight(m_pFightChara, GetViewPort(), m_pResourceManager, m_pParticleSystem,EnemyType::loox,false);

}

void Game::Cleanup()
{
	delete m_pParticleSystem;
	delete m_pChara;
	delete m_pFightChara;
	delete m_pFight;
	delete m_pInfoScreenTexture;
	delete m_pResourceManager;
}

void Game::Update(float deltaTime)
{
	m_pParticleSystem->Update(deltaTime);
	m_pResourceManager->Update(deltaTime);

	switch (m_GameState)
	{
	case GameState::adventure:
		m_pChara->Update(deltaTime);
		break;
	case GameState::fight:
		m_pFight->Update(deltaTime);
		//TESTSTUFF
		// TODO: remove
		//m_pTESTFROGGITJUMPATTACK->Update(deltaTime);

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
	case GameState::fight:
		m_pFight->Draw();
		//TestStuff
		// TODO: remove
		//m_pTESTFROGGITJUMPATTACK->Draw();
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
	switch (m_GameState)
	{
	case GameState::adventure:
		m_pChara->PlayerButtonDownManager(e);
		break;
	case GameState::fight:
		m_pFight->ButtonDownManager(e);
		break;
	case GameState::infoScreen:

		break;
	case GameState::startScreen:

		break;

	}
}

void Game::ProcessKeyUpEvent(const SDL_KeyboardEvent& e)
{
	switch (m_GameState)
	{
	case GameState::adventure:
		m_pChara->PlayerButtonUpManager(e);
		break;
	case GameState::fight:
		m_pFight->ButtonUpManager(e);
		break;
	case GameState::infoScreen:

		break;
	case GameState::startScreen:

		break;

	}
	
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
