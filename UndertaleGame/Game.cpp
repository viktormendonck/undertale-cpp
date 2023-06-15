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
#include "SoundManager.h"
#include "StartMenuManager.h"
//TESTCLASSES
// TODO: remove
//#include "LooxAttack1.h"

Game::Game(const Window& window)
	: BaseGame{ window }
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
	m_pFightPlayer = new FightPlayer(m_pResourceManager->m_MiscTextures[0], m_pResourceManager->m_AnimatedSprites[1],m_pInventory, 100, 20);
	m_pRoomManager = new RoomManager(m_pResourceManager);
	m_pAdventure = new Adventure(m_pPlayer,m_pFightPlayer,m_pResourceManager,m_pRoomManager,m_ViewPort,m_pResourceManager->m_RoomTextures[8]);
	m_pParticleSystem = new ParticleSystem{ 20, 0.6f};
	m_pMenu = new StartMenuManager(m_pResourceManager);
	m_GameState = GameState::menu;
	m_NextGameState = GameState::menu;
	SoundManager::GetInstance().Initialize();
	SoundManager::GetInstance().SetMusic("menu");
}

void Game::Cleanup()
{
	delete m_pParticleSystem;
	delete m_pPlayer;
	delete m_pFightPlayer;
	delete m_pFight;
	delete m_pAdventure;
	delete m_pRoomManager;
	delete m_pInventory;
	delete m_pResourceManager;
	delete m_pMenu;
	SoundManager::GetInstance().CleanUp();
}

void Game::Update(float deltaTime)
{
	if (m_pFightPlayer->GetHealth() <=0)
	{
		m_NextGameState = GameState::death;
		if (SoundManager::GetInstance().GetCurrentSong() != "death")
		{
			SoundManager::GetInstance().SetMusic("death");
		}
	}
	UpdateTransition(deltaTime);
	m_pParticleSystem->Update(deltaTime);
	m_pResourceManager->Update(deltaTime);

	switch (m_GameState)
	{
	case GameState::adventure:
		m_pAdventure->Update(deltaTime);
		if (m_pAdventure->GetAdventureEnd())
		{
			m_NextGameState = GameState::fight;
			if (m_pAdventure->IsBossFight())
			{
				delete m_pFight;
				m_pFight = new Fight(m_pFightPlayer, GetViewPort(), m_pResourceManager, m_pParticleSystem, EnemyType::napstablook);
			} else
			{
				delete m_pFight;
				m_pFight = new Fight(m_pFightPlayer, GetViewPort(), m_pResourceManager, m_pParticleSystem, static_cast<EnemyType>(utils::RandInRange(0, 1)));
			}
			m_pAdventure->SetAdventureEnd(false);
		}
		break;
	case GameState::fight:
		m_pFight->Update(deltaTime);
		if (m_pFight->IsFightOver())
		{
			m_NextGameState = GameState::adventure;
			SoundManager::GetInstance().SetMusic("ruins");
		}
		break;
	case GameState::menu:
		if (m_pMenu->GetMenuState() == MenuState::menuEnd)
		{
			m_NextGameState = GameState::adventure;
		}
		
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
		m_pResourceManager->m_MiscTextures[5]->Draw(Point2f{0,0});
		break;
	case GameState::menu:
		m_pMenu->Draw();
		break;
	case GameState::death:
		m_pResourceManager->m_MiscTextures[8]->Draw();
		break;
	}
	utils::SetColor(Color4f(0, 0, 0, m_ScreenTrancparancy));
	utils::FillRect(GetViewPort());

}

void Game::ProcessKeyDownEvent(const SDL_KeyboardEvent& e)
{
	switch (m_GameState)
	{
	case GameState::adventure:
		m_pAdventure->ButtonDownManager(e);
		break;
	case GameState::fight:
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
	case GameState::menu:
		m_pMenu->OnButtonUp(e);
		break;

	}
	
	switch (e.keysym.sym)
	{
	case SDLK_i:
		if (m_pMenu->GetMenuState() == MenuState::nameScreen){ return; }
		if (m_GameState == GameState::infoScreen)
		{
			m_NextGameState = m_SavePreviousState;
		}  else
		{
			m_SavePreviousState = m_GameState;
			system("CLS");
			std::cout << "Controls:\nArrow Keys/wasd:movement\nz or enter: confirm\nX/Shift:Cancel\nDel:Activate Gravity Mode(In enemyAttack, this is not original undertale)\nSpace: Jump (in gravity mode)\n";
			m_NextGameState = GameState::infoScreen;
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

void Game::UpdateTransition(float deltaTime)
{
	if (m_GameState != m_NextGameState)
	{
		m_IsTransitioning = true;
	}
	if (m_IsTransitioning)
	{
		if (m_CurrentScreenFadingTime <= 0)
		{
			m_CurrentScreenFadingTime = m_MaxScreenFadingTime;
			m_IsTransitioning = false;
		}
		if (m_CurrentScreenFadingTime <= 1 && m_GameState != m_NextGameState)
		{
			m_GameState = m_NextGameState;
		}
		else if (m_CurrentScreenFadingTime <= 1)
		{
			m_ScreenTrancparancy = abs(abs(m_CurrentScreenFadingTime - m_MaxScreenFadingTime / 2) - m_MaxScreenFadingTime / 2);
		}
		else
		{
			m_ScreenTrancparancy = abs(m_CurrentScreenFadingTime - m_MaxScreenFadingTime);
		}
		m_CurrentScreenFadingTime -= deltaTime;
	}
}
