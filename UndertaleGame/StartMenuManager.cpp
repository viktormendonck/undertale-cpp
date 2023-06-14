#include "pch.h"
#include "StartMenuManager.h"

#include <sstream>

#include "ResourceManager.h"
#include "SoundManager.h"
#include "Texture.h"
#include "utils.h"

StartMenuManager::StartMenuManager(ResourceManager* pResourceManager)
	:  m_AudioVolumeRef(SoundManager::GetInstance().GetAudioVolumeRef()),
	 m_pResourceManager(pResourceManager)
{
	//m_pTempName = new Texture{ "","UI/determinationFont.ttf",45,Color4f(1,1,1,1)};
}



void StartMenuManager::Draw()
{
	switch (m_MenuState) {
	case (MenuState::nameScreen):
		m_pResourceManager->m_MiscTextures[6]->Draw();
		if (!m_PlayerName.empty())
		{
			m_pTempName->Draw(Point2f{ 260,275 });
		}
		break;
	case (MenuState::controlsScreen):
		m_pResourceManager->m_MiscTextures[5]->Draw();
		break;
	case (MenuState::optionsScreen):
		m_pResourceManager->m_MiscTextures[7]->Draw();
		utils::SetColor(Color4f(1, 1, 1, 1));
		
		utils::FillRect(Point2f(223, 265), static_cast<float>(m_AudioVolumeRef * 2), 24);
		break;
	case (MenuState::startScreen):
		m_pResourceManager->m_MiscTextures[4]->Draw();
		m_pResourceManager->m_MiscTextures[0]->Draw(m_SelectionLocations[m_SelectedOption].ToPoint2f());
		break;
	}
}

void StartMenuManager::OnButtonUp(const SDL_KeyboardEvent& e)
{
	
	switch (m_MenuState) {
	case (MenuState::nameScreen):
		if (static_cast<char>(e.keysym.sym)>=' ' && static_cast<char>(e.keysym.sym) <= 'z')
		{
			AddLetter(static_cast<char>(e.keysym.sym));
		}
		switch(e.keysym.sym)
		{
		case (SDLK_BACKSPACE):
			if (!m_PlayerName.empty())
			{
				m_PlayerName.pop_back();
				if (!m_PlayerName.empty())
				{
					delete m_pTempName;
					m_pTempName = new Texture{ m_PlayerName,"UI/determinationFont.ttf",30,Color4f(1,1,1,1) };
				}
			}
			break;
		case (SDLK_RETURN):
		case (SDLK_RETURN2):
			if (!m_PlayerName.empty())
			{
				delete m_pResourceManager->m_TextTextures[0];
				m_pResourceManager->m_TextTextures[0] = new Texture{ m_PlayerName,"UI/determinationFont.ttf",30,Color4f(1,1,1,1) };
				SoundManager::GetInstance().SetMusic("ruins");
				m_MenuState = MenuState::menuEnd;
			}
			break;
		case (SDLK_ESCAPE):
		case (SDLK_RSHIFT):
		case (SDLK_x):
			m_MenuState = MenuState::startScreen;
			break;
		}
		break;
	case(MenuState::optionsScreen):
		switch (e.keysym.sym)
		{
		case(SDLK_LEFT):
		case(SDLK_a):
			if (m_AudioVolumeRef != 0)
			{
				m_AudioVolumeRef -= 10;
				SoundManager::GetInstance().UpdateAudioLevel();
			}
			break;
		case(SDLK_RIGHT):
		case(SDLK_d):
			if (m_AudioVolumeRef != 100)
			{
				m_AudioVolumeRef += 10;
				SoundManager::GetInstance().UpdateAudioLevel();
			}
			break;
		case (SDLK_ESCAPE):
		case (SDLK_RSHIFT):
		case (SDLK_x):
			m_MenuState = MenuState::startScreen;
			break;
		}
		break;
	case(MenuState::controlsScreen):
		switch(e.keysym.sym)
		{
		case (SDLK_ESCAPE):
		case (SDLK_RSHIFT):
		case (SDLK_x):
			m_MenuState = MenuState::startScreen;
			break;
		}
		break;
	case(MenuState::startScreen):
		switch (e.keysym.sym)
		{
		case(SDLK_UP):
		case(SDLK_w):
			if (m_SelectedOption >0)
			{
				m_SelectedOption--;
			}
			break;
		case(SDLK_DOWN):
		case(SDLK_s):	
			if (m_SelectedOption < 2)
			{
				m_SelectedOption++;
			}
			break;
		case(SDLK_RETURN):
		case(SDLK_z):
			switch (m_SelectedOption)
			{
			case(0):
				m_MenuState = MenuState::nameScreen;
				break;
			case(1):
				m_MenuState = MenuState::optionsScreen;
				break;
			case(2):
				m_MenuState = MenuState::controlsScreen;
				break;
			}
			break;
		}
		break;
	}
}

MenuState StartMenuManager::GetMenuState()
{
	return m_MenuState;
}

void StartMenuManager::AddLetter(char letter)
{
	if (!m_PlayerName.empty())
	{
		delete m_pTempName;
	}
	std::stringstream stringStream{};
	stringStream << m_PlayerName << letter;
	m_PlayerName = stringStream.str();
	m_pTempName = new Texture{ m_PlayerName,"UI/determinationFont.ttf",30,Color4f(1,1,1,1) };
}
