#include "pch.h"
#include "Adventure.h"

#include <iostream>

#include "Door.h"
#include "Fight.h"
#include "Interactable.h"
#include "AdventureMenu.h"
#include "Player.h"
#include "Room.h"
#include "RoomManager.h"
#include "Texture.h"
#include "utils.h"

Adventure::Adventure(Player* pPlayer, FightPlayer* pFightPlayer,ResourceManager* pResourceManager, RoomManager* pRoomManager, const Rectf& viewPort, Texture* paralax)
	:
	m_pMenu(new AdventureMenu(pFightPlayer,pResourceManager)),
	m_pPlayer(pPlayer),
	m_pParallax(paralax),
	m_pRoomManager(pRoomManager),
	m_pCurrentRoom(m_pRoomManager->GetRooms()["Room1"]),
	m_ViewPort(viewPort) 
{
	m_pPlayer->SetPlayerPos(Vector2f(96,726));
	m_SavedRoom = m_pCurrentRoom->GetName();
}

Adventure::~Adventure()
{
	delete m_pMenu;
}

void Adventure::Draw() const
{
	glPushMatrix();
	glTranslatef(-m_CameraPos.x, -m_CameraPos.y, 0);
	glTranslatef(m_CameraPos.x/4, m_CameraPos.y/2, 0);
	m_pParallax->Draw();
	glTranslatef(-m_CameraPos.x/4, -m_CameraPos.y/2, 0);
	m_pCurrentRoom->Draw();
	glPopMatrix();
	for (int i{}; i < m_pCurrentRoom->GetInteractables().size(); ++i)
	{
		m_pCurrentRoom->GetInteractables()[i]->Draw(m_CameraPos);
	}
	glPushMatrix();
	glTranslatef(-m_CameraPos.x, -m_CameraPos.y, 0);
	m_pPlayer->Draw();
	glPopMatrix();
	utils::SetColor(Color4f(0, 0, 0, m_ScreenTransparency));
	utils::FillRect(m_ViewPort);

	if (m_InMenu)
	{
		m_pMenu->Draw();
	}

}

void Adventure::Update(float deltaTime)
{
	bool interactActivated{};
	std::vector<CollisionBox> playerColliders{m_pCurrentRoom->GetWalls()};
	for (int i{}; i < m_pCurrentRoom->GetInteractables().size(); ++i)
	{
		if(m_pCurrentRoom->GetInteractables()[i]->IsSolid())
		{
			for (CollisionBox coll :m_pCurrentRoom->GetInteractables()[i]->GetCollisionBox())playerColliders.push_back(coll);
		}
		interactActivated = interactActivated || m_pCurrentRoom->GetInteractables()[i]->IsActivated();
	}

	if (interactActivated || m_InMenu)
	{
		m_pPlayer->SetState(Player::PlayerState::interacting);
	}
	else if (m_pPlayer->GetState() != Player::PlayerState::falling)
	{
		m_pPlayer->SetState(Player::PlayerState::wandering);
	}




	m_pPlayer->Update(deltaTime,playerColliders);
	if (m_CurrentSpawnCheckDelay <=0)
	{
		if (m_pPlayer->GetVelocity() != Vector2f(0,0) && utils::RandInRange(0,100) <= 1 && m_pCurrentRoom->GetSpawnable())
		{
			m_AdventureEnd = true;
		}

		m_CurrentSpawnCheckDelay = m_maxSpawnCheckDelay;
	}
	m_CurrentSpawnCheckDelay -= deltaTime;

	if (m_pPlayer->GetInteractedWithBoss())
	{
		if (!m_IsBossFight)
		{
			m_AdventureEnd = true;
			m_IsBossFight = true;
		}
	}

	UpdateCameraPos();
	for (int i{}; i < m_pCurrentRoom->GetDoors().size(); ++i)
	{
		if (!m_pCurrentRoom->GetDoors()[i].IsColliding(m_pPlayer->GetPlayerCollisionRect())) continue;
		m_SavedSpawnLocation = m_pCurrentRoom->GetDoors()[i].GetExitLocation();
		m_SavedRoom = m_pCurrentRoom->GetDoors()[i].GetDestination();
		m_IsTransitioning = true;
	}
	if (!m_IsTransitioning) {
		for (int i{}; i < m_pCurrentRoom->GetInteractables().size(); ++i)
		{
			m_pCurrentRoom->GetInteractables()[i]->Update(deltaTime, m_pPlayer);
		}
		if (m_pPlayer->IsFalling() && m_pPlayer->HasChangedRoom() == false)
		{
			m_pCurrentRoom->AddHole(m_pPlayer->GetFallStartLocation());
			m_SavedRoom = m_pPlayer->GetFallDestination();
			m_SavedSpawnLocation = Vector2f(m_pPlayer->GetPlayerPos().x, m_pRoomManager->GetRooms()[m_SavedRoom]->GetTexture()->GetHeight());
			m_IsTransitioning = true;
		}
	}
	else
	{
		if (m_CurrentScreenFadingTime <= 0)
		{
			m_IsTransitioning = false;
			m_CurrentScreenFadingTime = m_MaxScreenFadingTime;
		}
		if (m_CurrentScreenFadingTime <= 1 && m_pCurrentRoom->GetName() != m_SavedRoom )
		{
			m_pCurrentRoom = m_pRoomManager->GetRooms()[m_SavedRoom];
			m_pPlayer->SetPlayerPos(m_SavedSpawnLocation);
			m_pPlayer->SetChangedRoom(true);
		} else if (m_CurrentScreenFadingTime <=1)
		{
			m_ScreenTransparency = abs(abs(m_CurrentScreenFadingTime - m_MaxScreenFadingTime/2)-m_MaxScreenFadingTime / 2);
		}
		else
		{
			m_ScreenTransparency = abs(m_CurrentScreenFadingTime -m_MaxScreenFadingTime);
		}
		m_CurrentScreenFadingTime -= deltaTime;
	}

}

void Adventure::ButtonDownManager(const SDL_KeyboardEvent& e)
{
}
void Adventure::ButtonUpManager(const SDL_KeyboardEvent& e)
{
	if (m_InMenu)
	{
		m_pMenu->OnButtonUp(e);
		if (m_pMenu->GetMenuState() == MenuState::menu && (e.keysym.sym == SDLK_ESCAPE || e.keysym.sym == SDLK_x))
		{
			m_InMenu = false;
		}
	} else
	{
		for (int i{}; i < m_pCurrentRoom->GetInteractables().size(); ++i)
		{
			m_pCurrentRoom->GetInteractables()[i]->ButtonUpManager(e);
		}
		if ((e.keysym.sym == SDLK_RCTRL || e.keysym.sym == SDLK_c)&& m_pPlayer->GetState() == Player::PlayerState::wandering)
		{
			m_InMenu = true;
		}else if ((e.keysym.sym == SDLK_LCTRL)) //todo remove
		{
			m_AdventureEnd = true;
		}
	}
}

bool Adventure::GetAdventureEnd() const
{
	return m_AdventureEnd;
}

void Adventure::SetAdventureEnd(bool newVal)
{
	m_AdventureEnd = newVal;
}

bool Adventure::IsBossFight() const
{
	return m_IsBossFight;
}


void Adventure::UpdateCameraPos()
{
	Rectf roomRect =m_pCurrentRoom->GetTexture()->GetRect();

	m_CameraPos.x = m_pPlayer->GetPlayerPos().x - m_ViewPort.width / 2;
	m_CameraPos.y = m_pPlayer->GetPlayerPos().y - m_ViewPort.height / 2;
	if (m_CameraPos.x <0)
	{
		m_CameraPos.x = 0;
	}
	if (m_CameraPos.x+m_ViewPort.width > roomRect.width)
	{
		m_CameraPos.x = roomRect.width - m_ViewPort.width;
	}
	if (m_CameraPos.y < 0)
	{
		m_CameraPos.y = 0;
	}
	if (m_CameraPos.y+m_ViewPort.height > roomRect.height)
	{
		m_CameraPos.y = roomRect.height - m_ViewPort.height;
	}
}

