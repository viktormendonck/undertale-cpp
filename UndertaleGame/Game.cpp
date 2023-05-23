#include "pch.h"
#include "Game.h"

#include <iostream>

#include "Texture.h"
#include "utils.h"
#include "Vector2f.h"
#include "ParticleSystem.h"
#include "AnimatedSprite.h"
#include <map>

#include "Adventure.h"
#include "ResourceManager.h"
#include "Player.h"
#include "Fight.h"
#include "FightPlayer.h"
#include "ItemManager.h"
#include "RoomManager.h"
//TESTCLASSES
// TODO: remove
//#include "LooxAttack1.h"

Game::Game(const Window& window)
	: BaseGame{ window }
	, m_pParticleSystem{new ParticleSystem{ 20, 0.6f}}
	, m_pInfoScreenTexture{ new Texture{"Static_Screens/Controls.png"}}
	, m_ViewPort{ GetViewPort() }
{
	
	Initialize();
}

Game::~Game()
{
	Cleanup();
}

void Game::Initialize()
{
	m_pResourceManager = new ResourceManager{"Viktor"};
	m_pInventory = new Inventory{ 10,new ItemManager{m_pResourceManager} };
	m_pPlayer = new Player{ m_pResourceManager->m_AnimatedSprites[0],m_pInventory,200 };
	m_pFightChara = new FightPlayer(m_pResourceManager->m_StaticTextures[0], m_pResourceManager->m_AnimatedSprites[1],m_pInventory, 100, 20);
	m_pRoomManager = new RoomManager(m_pResourceManager);
	m_pAdventure = new Adventure(m_pPlayer,m_pRoomManager,m_ViewPort);
	//TESTSTUFF
	//TODO > remove
	m_pFight = new Fight(m_pFightChara, GetViewPort(), m_pResourceManager, m_pParticleSystem, static_cast<EnemyType>(utils::RandInRange(0, 1)), false);
}

void Game::Cleanup()
{
	delete m_pParticleSystem;
	delete m_pPlayer;
	delete m_pFightChara;
	delete m_pFight;
	delete m_pAdventure;
	delete m_pRoomManager;
	delete m_pInventory;
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
		m_pAdventure->Update(deltaTime);
		if (m_pAdventure->GetAdventureEnd())
		{
			m_GameState = GameState::fight;
			m_pFight = new Fight(m_pFightChara, GetViewPort(), m_pResourceManager, m_pParticleSystem,static_cast<EnemyType>(utils::RandInRange(0,1)),false);
		}
		break;
	case GameState::fight:
		m_pFight->Update(deltaTime);
		if (m_pFight->IsFightOver())
		{
			m_GameState = GameState::adventure;
		}
		break;
	case GameState::infoScreen:
		
		break;

	}
}

void Game::Draw() const
{
	ClearBackground();
	switch (m_GameState)
	{
	case GameState::adventure:
		m_pAdventure->Draw();
		break;
	case GameState::fight:
		m_pFight->Draw();
		break;
	case GameState::infoScreen:
		m_pInfoScreenTexture->Draw(Point2f{ 0,0 });
		break;

	}

}

void Game::ProcessKeyDownEvent(const SDL_KeyboardEvent& e)
{
	switch (m_GameState)
	{
	case GameState::adventure:
		m_pAdventure->ButtonDownManager(e);
		break;
	case GameState::fight:
		m_pFight->ButtonDownManager(e);
		break;
	case GameState::infoScreen:

		break;

	}
}

void Game::ProcessKeyUpEvent(const SDL_KeyboardEvent& e)
{
	switch (m_GameState)
	{
	case GameState::adventure:
		m_pAdventure->ButtonUpManager(e);
		break;
	case GameState::fight:
		m_pFight->ButtonUpManager(e);
		break;
	case GameState::infoScreen:

		break;

	}
	
	switch (e.keysym.sym)
	{
	case SDLK_i:
		if (m_GameState == GameState::infoScreen)
		{
			m_GameState = m_SavePreviousState;
		}  else
		{
			m_SavePreviousState = m_GameState;
			system("CLS");
			std::cout << "Controls:\nArrow Keys/wasd:movement\nz or enter: confirm\nX/Shift:Cancel\nDel:Activate Gravity Mode(In enemyAttack, this is not original undertale)\nSpace: Jump (in gravity mode)\n";
			m_GameState = GameState::infoScreen;
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
