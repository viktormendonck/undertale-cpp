#include "pch.h"
#include "Fight.h"

#include <sstream>

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
	  m_pParticleSystem{pParticleSystem},
      m_pResourceManager{pResourceManager},
	  m_IsBossFight{isBossFight}
{
	m_FightBoundary = CollisionBox(Rectf((screen.width - m_FightSquareDimentions) / 2, m_box_bottom_offset,m_FightSquareDimentions, m_FightSquareDimentions));
	m_TextBox = Rectf	(	(screen.width - (screen.width - m_TextBoxSideOffset * 2)) / 2, m_box_bottom_offset, screen.width-m_TextBoxSideOffset*2,m_FightSquareDimentions);

	//fight vars
	Vector2f pos{ m_FightBoundary.GetRect().GetMiddle().x,m_FightBoundary.GetRect().GetMiddle().y };
	m_pFightChara->SetPos(pos);
	const Vector2f platformSize{ 20,5 };
	for (int i{}; i < m_PlatformAmount; ++i)
	{
		m_Colliders.push_back(CollisionBox(Rectf(0,0,platformSize.x, platformSize.y)));
	}

	// fightmenu vars
	m_AttackBarStartLocation = Vector2f(m_TextBox.left, m_TextBox.bottom + 10);
	m_AttackBarLocation = m_AttackBarStartLocation;

	//actMenu vars
	


	//make collisions for the fight
	const float collisionBoxWidth{ 5 };
	m_Colliders.push_back(CollisionBox(Rectf(m_FightBoundary.GetBottom().point1.x, m_FightBoundary.GetBottom().point1.y - collisionBoxWidth, m_FightSquareDimentions, collisionBoxWidth)));
	m_Colliders.push_back(CollisionBox(Rectf(m_FightBoundary.GetTop().point1, m_FightSquareDimentions, collisionBoxWidth)));
	m_Colliders.push_back(CollisionBox(Rectf(m_FightBoundary.GetLeft().point1.x-collisionBoxWidth,m_FightBoundary.GetLeft().point1.y-collisionBoxWidth, collisionBoxWidth,m_FightSquareDimentions+(collisionBoxWidth*2))));
	m_Colliders.push_back(CollisionBox(Rectf(m_FightBoundary.GetRight().point1.x,m_FightBoundary.GetRight().point1.y-collisionBoxWidth, collisionBoxWidth,m_FightSquareDimentions+(collisionBoxWidth*2))));


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
}	

Fight::~Fight()
{
	delete m_pEnemy;
}
void Fight::StartFightSegment()
{
	m_MenuSelectedState = UiState::idle;
	m_FightState = FightState::fight;
	m_pEnemy->SpawnBullet(m_pResourceManager);
}

//Drawing functions
void Fight::Draw() const
{
	Rectf srcRect{ 0,(m_pBackgroundTexture->GetHeight() / static_cast<float>(m_BackGroundsAmount)*static_cast<float>(m_IsBossFight)),m_pBackgroundTexture->GetWidth(),m_pBackgroundTexture->GetHeight() / static_cast<float>(m_BackGroundsAmount)};
	m_pBackgroundTexture->Draw(Point2f(0, 0), srcRect);
	if (m_FightEnded)
	{
		m_pParticleSystem->Draw();
	}
	else {
		m_pEnemy->Draw();
	}
	switch (m_FightState)
	{
	case (FightState::menu):
		DrawMenu();
		break;
	case (FightState::fight):
		DrawFight();
		break;
	case(FightState::menuSelected):
		DrawMenuSelected();
		break;
	case (FightState::transition):
		DrawTransition();
		break;
	}
	DrawUI();
}

void Fight::DrawMenu() const
{
	utils::DrawRect(m_TextBox, m_BoxLineWidth);
}
void Fight::DrawFight() const
{
	utils::SetColor(Color4f(1, 1, 1, 1));
	m_pFightChara->Draw();
	utils::DrawRect(m_FightBoundary.GetRect(), m_BoxLineWidth);

	if (m_pFightChara->IsGravityMode())
	{
		DrawPlatforms();
	}
}
void Fight::DrawMenuSelected() const
{
	switch (m_MenuSelectedState)
	{
	case(UiState::fightSelected):
		m_pResourceManager->m_StaticTextures[2]->Draw(m_TextBox);
		m_pResourceManager->m_MiscAnimatedSprites[0]->Draw(m_AttackBarLocation);
		if (m_BarStopped)
		{
			m_pResourceManager->m_MiscAnimatedSprites[1]->Draw(m_pEnemy->GetPos());
		}
		break;
	case (UiState::actSelected):

		if (m_HasActed)
		{
			DrawActMenuResponses();
		}
		else
		{
			DrawActMenuOptions();
		}
		break;
		
	case(UiState::itemSelected):

		break;
	case (UiState::mercySelected):
		m_pResourceManager->m_TextTextures[2]->Draw(m_TextLocations[0].ToPoint2f());
		m_pResourceManager->m_TextTextures[3]->Draw(m_TextLocations[2].ToPoint2f());
		m_pResourceManager->m_StaticTextures[0]->Draw((m_TextLocations[m_CurrentSelectedOption] - Vector2f{ 25,-5 }).ToPoint2f());
		break;
	}
	utils::DrawRect(m_TextBox, m_BoxLineWidth);
}

void Fight::DrawTransition() const
{
	utils::DrawRect(m_CurrentTransitionRect, m_BoxLineWidth);
}
void Fight::DrawPlatforms() const
{
	utils::SetColor(Color4f(1, 1, 1, 1));
	for (int i{}; i<m_PlatformAmount;++i)
	{
		utils::FillRect(m_Colliders[i].GetRect());
	}
}
void Fight::DrawUI() const
{
	for (int i{}; i < m_ButtonsAmount; ++i)
	{
		m_pResourceManager->m_UiElementSprites[i]->Draw(m_ButtonLocations[i]);
	}
	for (int i{}; i< m_AmountOfUITextTextures; ++i)
	{
		m_pResourceManager->m_TextTextures[i]->Draw(m_UIInformationLocations[i].ToPoint2f());
	}
}
void Fight::DrawActMenuOptions() const
{
	switch (m_pEnemy->GetEnemyType())
	{
	case(EnemyType::froggit):
		for (int i{}; i < m_AmountOfTextLocations; ++i)
		{
			m_pResourceManager->m_FroggitTextTextures[i]->Draw(m_TextLocations[i].ToPoint2f());
		}
		break;
	case (EnemyType::loox):
		for (int i{}; i < m_AmountOfTextLocations; ++i)
		{
			m_pResourceManager->m_FroggitTextTextures[i]->Draw(m_TextLocations[i].ToPoint2f());\
		}

		break;
	}
	//draw the heart in front of the selected tex
	m_pResourceManager->m_StaticTextures[0]->Draw((m_TextLocations[m_CurrentSelectedOption] - Vector2f{ 25,-5 }).ToPoint2f());
}
void Fight::DrawActMenuResponses() const
{
	switch (m_pEnemy->GetEnemyType())
	{
	case(EnemyType::froggit):
		m_pResourceManager->m_FroggitTextTextures[m_CurrentSelectedOption + m_AmountOfTextLocations]->Draw(m_ResponsePos.ToPoint2f());
		break;
	case (EnemyType::loox):
		m_pResourceManager->m_LooxTextTextures[m_CurrentSelectedOption + m_AmountOfTextLocations]->Draw(m_ResponsePos.ToPoint2f());
		break;
	}
}

//Update Finctions
void Fight::Update(const float deltaTime)
{
	if (m_FightEnded)
	{
		m_UpdateTimeAfterDeath -= deltaTime;
		m_pParticleSystem->Update(deltaTime);
	}
	else {
		switch (m_FightState)
		{
		case (FightState::menu):
			UpdateMenu(deltaTime);
			break;
		case (FightState::menuSelected):
			UpdateMenuSelected(deltaTime);
			break;
		case (FightState::fight):
			UpdateFight(deltaTime);
			break;
		case (FightState::transition):
			UpdateTransition(deltaTime);
			break;
		}
		m_pEnemy->Update(deltaTime);
		UpdateUI(deltaTime);
		m_FightEnded = m_pEnemy->IsDead();
		if (m_FightEnded)
		{
			m_pParticleSystem->StartDissolve(m_pEnemy->GetPos(), m_pEnemy->GetDeathTexture());
		}
	}
}

void Fight::UpdateMenu(float deltaTime)
{
}
void Fight::UpdateFight(float deltaTime)
{
	m_pFightChara->Update(deltaTime, this, m_Colliders);
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
	if (m_PreviousHealth != m_pFightChara->GetHealth())
	{
		float playerHealth= m_pFightChara->GetHealth();
		std::stringstream hpStringStream;
		hpStringStream << playerHealth << "/" << m_pFightChara->GetMaxHealth() << "HP";
		m_pResourceManager->m_TextTextures[1] = new Texture{ hpStringStream.str(),"UI/determinationFont.ttf",30,Color4f(1,1,1,1) };
	}
}
void Fight::UpdateMenuSelected(float deltaTime)
{
	switch (m_MenuSelectedState)
	{
	case(UiState::fightSelected):
	{

		if (!m_BarStopped)
		{
			Vector2f nextPos{ m_AttackBarLocation.x + m_BarSpeed * deltaTime ,m_AttackBarLocation.y };
			Rectf barRect{ nextPos.x, nextPos.y, m_pResourceManager->m_MiscAnimatedSprites[0]->GetWidth(), m_pResourceManager->m_MiscAnimatedSprites[0]->GetWidth() };
			if (utils::IsOverlapping(Linef(m_TextBox.left, m_TextBox.bottom, m_TextBox.left, m_TextBox.bottom + m_TextBox.height), barRect) ||
				utils::IsOverlapping(Linef(m_TextBox.left + m_TextBox.width, m_TextBox.bottom, m_TextBox.left + m_TextBox.width, m_TextBox.bottom + m_TextBox.height), barRect))
			{
				m_BarDirectionMulti *= -1;
			}
			m_AttackBarLocation.x += m_BarSpeed * deltaTime * m_BarDirectionMulti;


		}
		else
		{
			if (static_cast<int>((m_CurrentBarStoppedCountDown * 10)) % 2 == 0)
			{
				m_pResourceManager->m_MiscAnimatedSprites[0]->SetAnimation("active");
			}
			else
			{
				m_pResourceManager->m_MiscAnimatedSprites[0]->SetAnimation("inactive");
			}

			if (m_CurrentBarStoppedCountDown <= 0)
			{
				float maxDistanceFromSide{ m_TextBox.width / 2 };
				float damageMultiplier{ (m_DistanceFromWall / maxDistanceFromSide) * m_MaxPlayerDamageMulti };
				m_CurrentBarStoppedCountDown = m_BarStoppedMaxCountDown;
				m_BarStopped = false;
				m_AttackBarLocation = m_AttackBarStartLocation;

				m_pEnemy->Damage(static_cast<float>(m_pFightChara->GetDamage()) * damageMultiplier);
				StartFightSegment();
			}
			else
			{
				m_CurrentBarStoppedCountDown -= deltaTime;
			}
		}


		break;
	}
	case (UiState::actSelected): 
	{
		if(m_HasActed)
		{
			m_CurrentReadingTime -= deltaTime;
			if (m_CurrentReadingTime <=0)
			{
				m_CurrentReadingTime = m_MaxReadingTime;
				m_HasActed = false;
				m_CurrentSelectedOption = 0;
				StartFightSegment();
			}
		}
		break;
	}
	case(UiState::itemSelected):

		break;
	case (UiState::mercySelected):

		break;
	}
}
void Fight::UpdateTransition(float deltaTime)
{
	float distance{};
	if (m_PreviousFightState == FightState::fight)
	{
		distance = m_TextBox.left - m_FightBoundary.GetRect().left;
	}
	else
	{
		distance = m_FightBoundary.GetRect().left - m_TextBox.left;
	}

	if (m_BoxTransitionIncrementor < m_BoxTransitionSpeed)
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
void Fight::UpdateUI(float deltaTime)
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

// Button Manager
void Fight::ButtonDownManager(const SDL_KeyboardEvent& e)
{

}

void Fight::ButtonUpManager(const SDL_KeyboardEvent& e)
{
	switch (m_FightState)
	{
	case (FightState::menu):
		ButtonUpMenuManager(e);
		break;
	case (FightState::menuSelected):
		ButtonUpMenuSelectedManager(e);
		break;
	case (FightState::fight):
		ButtonUpFightManager(e);
		break;
	}
}
void Fight::ButtonUpMenuManager(const SDL_KeyboardEvent& e)
{
	switch (e.keysym.sym)
	{
	case (SDLK_a):
	case (SDLK_LEFT):
		if (m_UiState != UiState::fightSelected)
		{
			m_UiState = static_cast<UiState>(static_cast<int>(m_UiState) - 1);
		}
		break;
	case (SDLK_d):
	case(SDLK_RIGHT):
		if (m_UiState != UiState::mercySelected)
		{
			m_UiState = static_cast<UiState>(static_cast<int>(m_UiState) + 1);
		}
		break;
	case (SDLK_RETURN):
	case (SDLK_x):
		m_FightState = FightState::menuSelected;
		m_MenuSelectedState = m_UiState;
		m_UiState = UiState::idle;
		break;
	}
}
void Fight::ButtonUpMenuSelectedManager(const SDL_KeyboardEvent& e)
{
	switch (m_MenuSelectedState)
	{
	case(UiState::fightSelected):
		switch (e.keysym.sym)
		{
		case (SDLK_RETURN):
		case (SDLK_x):
			{
			m_BarStopped = true;
			float distanceFromLeftWall = m_AttackBarLocation.x - m_TextBox.left;
			float distanceFromRightWall = abs(m_AttackBarLocation.x - m_TextBox.left - m_TextBox.width);
			if (distanceFromLeftWall < distanceFromRightWall)
			{
				m_DistanceFromWall = distanceFromLeftWall;
			}
			else
			{
				m_DistanceFromWall = distanceFromRightWall;
			}
			break;
			}
		}
		break;
	case (UiState::actSelected):
		if (m_HasActed)
		{
			switch (e.keysym.sym)
			{
			case (SDLK_RETURN):
			case(SDLK_x):
				m_CurrentReadingTime = 0;
				break;
			}

		}else 
		{
			switch (e.keysym.sym)
			{
			case (SDLK_w):
			case (SDLK_UP):
				if (m_CurrentSelectedOption == 2)
				{
					m_CurrentSelectedOption = 0;
				}
				break;
			case (SDLK_s):
			case (SDLK_DOWN):
				m_CurrentSelectedOption = 2;
				break;
			case (SDLK_a):
			case (SDLK_LEFT):
				if (m_CurrentSelectedOption>0)
				{
					--m_CurrentSelectedOption;
				}
				break;
			case (SDLK_d):
			case (SDLK_RIGHT):
				if (m_CurrentSelectedOption < m_AmountOfTextLocations)
				{
					++m_CurrentSelectedOption;
				}
				break;
			case (SDLK_RETURN):
			case (SDLK_x):
				m_HasActed = !m_HasActed;
				switch (m_pEnemy->GetEnemyType())
				{
				case(EnemyType::froggit):
					m_ResponsePos = m_ResponsePosOrigin - Vector2f{ 0,m_pResourceManager->m_FroggitTextTextures[m_CurrentSelectedOption + m_AmountOfTextLocations]->GetHeight() };
					break;
				case (EnemyType::loox):
					m_ResponsePos = m_ResponsePosOrigin - Vector2f{ 0,m_pResourceManager->m_LooxTextTextures[m_CurrentSelectedOption + m_AmountOfTextLocations]->GetHeight() };
					break;
				}
				break;
			case (SDLK_ESCAPE):
				m_FightState = FightState::menu;
				m_MenuSelectedState = UiState::idle;
				m_UiState = UiState::fightSelected;
				break;
			}
		}
		break;

	case(UiState::itemSelected):
		switch (e.keysym.sym)
		{
		case (SDLK_ESCAPE):
			m_FightState = FightState::menu;
			m_MenuSelectedState = UiState::idle;
			m_UiState = UiState::fightSelected;
			break;
		}
		break;
	case (UiState::mercySelected):
		switch (e.keysym.sym)
		{
		case (SDLK_w):
		case (SDLK_UP):
			if (m_CurrentSelectedOption == 2)
			{
				m_CurrentSelectedOption = 0;
			}
			break;
		case (SDLK_s):
		case (SDLK_DOWN):
			if (m_CurrentSelectedOption == 0)
			{
				m_CurrentSelectedOption = 2;
			}
			break;
		case (SDLK_ESCAPE):
			m_FightState = FightState::menu;
			m_MenuSelectedState = UiState::idle;
			m_UiState = UiState::fightSelected;
			break;
		}
		break;
	}



}
void Fight::ButtonUpFightManager(const SDL_KeyboardEvent& e)
{
	m_pFightChara->OnButtonUp(e);
}

//getters and setters

bool Fight::IsFightOver()
{
	return m_FightEnded && m_UpdateTimeAfterDeath <=0;
}
CollisionBox Fight::GetFightBoundaryBox()
{
	return m_FightBoundary;
}