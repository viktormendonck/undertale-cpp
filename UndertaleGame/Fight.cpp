#include "pch.h"
#include "Fight.h"

#include "AnimatedSprite.h"
#include "FightChara.h"
#include "Enemy.h"
#include "ParticleSystem.h"
#include "utils.h"
#include "CollisionBox.h"
#include "Froggit.h"
#include "Loox.h"


Fight::Fight(FightChara* pChara, Rectf screen, ResourceManager* pResourceManager, ParticleSystem* pParticleSystem,EnemyType enemy, bool isBossFight)
	: m_pFightChara{pChara},
	  m_pBackgroundTexture{pResourceManager->m_StaticTextures[1]},
      m_pResourceManager{pResourceManager},
	  m_pParticleSystem{pParticleSystem}
{
	m_FightBoundary = CollisionBox(Rectf((screen.width - m_FightSquareDimentions) / 2, m_BoxBottomOffset,m_FightSquareDimentions, m_FightSquareDimentions));


	m_TextBox = Rectf	(	(screen.width - (screen.width - m_TextBoxSideOffset * 2)) / 2, m_BoxBottomOffset, screen.width-m_TextBoxSideOffset*2,m_FightSquareDimentions);
	Vector2f pos{ m_FightBoundary.GetRect().GetMiddle().x,m_FightBoundary.GetRect().GetMiddle().y };
	m_pFightChara->SetPos(pos);
	m_IsBossFight = false;

	
	const Vector2f platformSize{ 20,5 };
	for (int i{}; i < m_PlatformAmount; ++i)
	{
		m_Colliders.push_back(CollisionBox(Rectf(0,0,platformSize.x, platformSize.y)));
	}

	const float boxSize{ 5 };
	m_Colliders.push_back(CollisionBox(Rectf(m_FightBoundary.GetBottom().point1.x, m_FightBoundary.GetBottom().point1.y - boxSize, m_FightSquareDimentions, boxSize)));
	m_Colliders.push_back(CollisionBox(Rectf(m_FightBoundary.GetTop().point1, m_FightSquareDimentions, boxSize)));
	m_Colliders.push_back(CollisionBox(Rectf(m_FightBoundary.GetLeft().point1.x-boxSize,m_FightBoundary.GetLeft().point1.y-boxSize, boxSize,m_FightSquareDimentions+(boxSize*2))));
	m_Colliders.push_back(CollisionBox(Rectf(m_FightBoundary.GetRight().point1.x,m_FightBoundary.GetRight().point1.y-boxSize, boxSize,m_FightSquareDimentions+(boxSize*2))));


	switch (enemy)
	{
	case (EnemyType::froggit):
		m_pEnemy = new Froggit(m_pResourceManager->m_StaticEnemyTextures[0], m_pResourceManager->m_AnimatedSprites[2], m_pResourceManager->m_StaticEnemyTextures[1], 30, 2, 4, *m_pFightChara,m_FightBoundary);
		break;
	case (EnemyType::loox):
		m_pEnemy = new Loox(m_pResourceManager->m_AnimatedSprites[3], m_pResourceManager->m_StaticEnemyTextures[2], 50, 3, *m_pFightChara, m_FightBoundary);
		break;
	/*case (EnemyType::migosp):

		break;
	case (EnemyType::moldsmal):

		break;
	case (EnemyType::vegetoid):

		break;
	case (EnemyType::whimsum):

		break;*/
	}
	m_pEnemy->SpawnBullet(pResourceManager);

}	

Fight::~Fight()
{
	delete m_pEnemy;
}

void Fight::Draw()
{
	Rectf srcRect{ 0,(m_pBackgroundTexture->GetHeight() / static_cast<float>(m_BackGroundsAmount)*static_cast<float>(m_IsBossFight)),m_pBackgroundTexture->GetWidth(),m_pBackgroundTexture->GetHeight() / static_cast<float>(m_BackGroundsAmount)};
	m_pBackgroundTexture->Draw(Point2f(0, 0), srcRect);
	
	switch (m_FightState)
	{
	case (FightState::menu):
		utils::DrawRect(m_TextBox, m_BoxLineWidth);
		break;
	case (FightState::fight):
		{

			utils::SetColor(Color4f(1, 1, 1, 1));
			m_pFightChara->Draw();
			utils::DrawRect(m_FightBoundary.GetRect(), m_BoxLineWidth);

			if (m_pFightChara->IsGravityMode())
			{
				DrawPlatforms();
			}

			break;
		}
	case (FightState::transition):
		utils::DrawRect(m_CurrentTransitionRect, m_BoxLineWidth);
		break;
	}
	m_pEnemy->Draw();
	DrawUi();
}

void Fight::Update(const float deltaTime)
{
	switch (m_FightState)
	{
	case (FightState::menu):

		break;
	case (FightState::fight):
		m_pFightChara->Update(deltaTime,this, m_Colliders);
		if (m_pFightChara->IsGravityMode())
		{
			UpdatePlatforms(deltaTime);
		}

		if (!m_pEnemy->AreBulletsActive())
		{
			m_FightState = FightState::transition;
			m_PreviousFightState = FightState::fight;
			m_CurrentTransitionRect = m_FightBoundary.GetRect();
			m_pEnemy->DeleteBullets();
		}
		break;
	case (FightState::transition):
		float distance {};
		if (m_PreviousFightState == FightState::fight)
		{
			distance = m_TextBox.left - m_FightBoundary.GetRect().left;
		}
		else
		{
			distance = m_FightBoundary.GetRect().left - m_TextBox.left;
		}

		if ( m_BoxTransitionIncrementor < m_BoxTransitionSpeed)
		{
			m_BoxTransitionIncrementor += deltaTime / m_BoxTransitionSpeed;
			m_CurrentTransitionRect.left += deltaTime * distance / m_BoxTransitionSpeed;
			m_CurrentTransitionRect.width += distance * -2 * deltaTime / m_BoxTransitionSpeed;
		}
		else
		{
			m_BoxTransitionIncrementor = 0;
			if (m_PreviousFightState == FightState::fight)
			{
				m_FightState = FightState::menu;
				m_UiState = UiState::fightSelected;
			}
			else
			{
				m_pEnemy->SpawnBullet(m_pResourceManager);
				m_FightState = FightState::fight;
				m_UiState = UiState::idle;
			}
		}
		break;
	}
	m_pEnemy->Update(deltaTime);
	UpdateUi(deltaTime);
}


CollisionBox Fight::GetFightBoundaryBox()
{
	return m_FightBoundary;
}
void Fight::ButtonDownManager(const SDL_KeyboardEvent& e)
{

}
void Fight::ButtonUpManager(const SDL_KeyboardEvent& e)
{
	switch (m_FightState)
	{
	case (FightState::menu):
		switch (e.keysym.sym)
		{
		case (SDLK_0):
			m_FightState = FightState::transition;
			m_PreviousFightState = FightState::menu;
			m_CurrentTransitionRect = m_TextBox;
			break;
		case (SDLK_a):
			if (m_UiState != UiState::fightSelected)
			{
				m_UiState = static_cast<UiState>(static_cast<int>(m_UiState) - 1);
			}
			break;
		case (SDLK_d):
			if (m_UiState != UiState::mercySelected)
			{
				m_UiState = static_cast<UiState>(static_cast<int>(m_UiState) + 1);
			}
			break;
		case (SDLK_RETURN):

			break;
		}


		break;
	case (FightState::fight):
		m_pFightChara->OnButtonUp(e);

		break;

	case (FightState::transition):
		break;
	}
}
void Fight::UpdatePlatforms(float deltaTime)
{

	if (m_CurrentPlatformTimer <=0)
	{
		m_CurrentPlatformTimer = m_PlatformTimer;
		const float platformOffset{ 30 };
		for (int i{}; i < m_PlatformAmount; ++i)
		{
			const int randHeight{ utils::RandInRange(m_FightBoundary.GetRect().bottom + platformOffset,m_FightBoundary.GetRect().bottom + m_FightBoundary.GetRect().height - platformOffset) };
			const int randWidth{ utils::RandInRange(m_FightBoundary.GetRect().left + platformOffset,
				             m_FightBoundary.GetRect().left + m_FightBoundary.GetRect().width - platformOffset) };

			m_Colliders[i].SetLocation(Vector2f(randWidth,randHeight));
		}

	} else
	{
		m_CurrentPlatformTimer -= deltaTime;
	}
}


void Fight::DrawPlatforms() const
{
	utils::SetColor(Color4f(1, 1, 1, 1));
	for (int i{}; i<m_PlatformAmount;++i)
	{
		utils::FillRect(m_Colliders[i].GetRect());
	}
}

void Fight::DrawUi() const
{
	for (int i{}; i < m_ButtonsAmount; ++i)
	{
		m_pResourceManager->m_UiElementSprites[i]->Draw(m_ButtonLocations[i]);
	}
}

void Fight::UpdateUi(float deltaTime)
{
	for (int i{}; i < m_ButtonsAmount; ++i)
	{
		m_pResourceManager->m_UiElementSprites[i]->SetAnimation("inactive");
	}
	if (m_UiState != UiState::idle && m_FightState == FightState::menu)
	{
		m_pResourceManager->m_UiElementSprites[static_cast<int>(m_UiState)]->SetAnimation("active");
	}
}
