#include "pch.h"
#include "Fight.h"
#include "EnemyManager.h"
#include "FightChara.h"
#include "Enemy.h"
#include "utils.h"



Fight::Fight(FightChara* pChara, Rectf screen,Texture* backGroundTexture)
	: m_pFightChara{pChara},
	  m_pBackgroundTexture{backGroundTexture}
{
	m_FightBoundary = Rectf(	(screen.width - m_FightSquareDimentions) / 2,
							(screen.height - m_FightSquareDimentions) / 2,
							m_FightSquareDimentions, 
							m_FightSquareDimentions);
	m_TextBox = Rectf	((screen.width - m_FightSquareDimentions) / 2,
							(screen.height - (screen.width - m_TextBoxOffset * 2)) / 2,
							screen.width-m_TextBoxOffset*2,
							m_FightSquareDimentions);
}	

Fight::~Fight()
{
}

void Fight::Draw()
{
	switch (m_FightState)
	{
	case (FightState::menu):

		break;
	case (FightState::menuToFight):

		break;
	case (FightState::fight):
		utils::DrawRect(m_FightBoundary, static_cast<float>(m_BoxLineWidth));
		m_pFightChara->Draw();
		break;
	case (FightState::fightToMenu):

		break;
	}
}

void Fight::Update(float deltaTime)
{
	switch (m_FightState)
	{
	case (FightState::menu):

		break;
	case (FightState::menuToFight):

		break;
	case (FightState::fight):
		m_pFightChara->Update(deltaTime,this);
		break;
	case (FightState::fightToMenu):

		break;
	}
}

Rectf Fight::GetFightBoundaryBox()
{
	return m_FightBoundary;
}

void Fight::ButtonDownManager(const SDL_KeyboardEvent& e)
{
	switch (m_FightState)
	{
	case (FightState::menu):

		break;
	case (FightState::menuToFight):

		break;
	case (FightState::fight):
		m_pFightChara->ButtonDownManager(e);
		break;
	case (FightState::fightToMenu):

		break;
	}
}

void Fight::ButtonUpManager(const SDL_KeyboardEvent& e)
{
	switch (m_FightState)
	{
	case (FightState::menu):

		break;
	case (FightState::menuToFight):

		break;
	case (FightState::fight):
		m_pFightChara->ButtonUpManager(e);
		break;
	case (FightState::fightToMenu):

		break;
	}
}
