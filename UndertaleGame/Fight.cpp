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
	m_FightBoundary = Rectf((screen.width - m_FightSquareDimentions) / 2,
								 m_BoxBottomOffset,
							m_FightSquareDimentions, 
							m_FightSquareDimentions);
	m_TextBox = Rectf	(	(screen.width - (screen.width - m_TextBoxSideOffset * 2)) / 2,
								 m_BoxBottomOffset,
							screen.width-m_TextBoxSideOffset*2,
							m_FightSquareDimentions);
	Vector2f pos{ m_FightBoundary.GetMiddle().x,m_FightBoundary.GetMiddle().y };
	m_pFightChara->SetPos(pos);
}	

Fight::~Fight()
{
	delete m_pBackgroundTexture;
	delete m_pFightChara;
	for (Enemy* enemy : m_pEnemies)
	{
		delete enemy;
	}

}

void Fight::Draw()
{
	Rectf srcRect{ 0,(m_pBackgroundTexture->GetHeight() / static_cast<float>(m_BackGroundsAmount)*static_cast<float>(m_IsBossFight)),m_pBackgroundTexture->GetWidth(),m_pBackgroundTexture->GetHeight() / static_cast<float>(m_BackGroundsAmount)};
	m_pBackgroundTexture->Draw(Point2f(0, 0), srcRect);

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
