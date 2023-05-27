#include "pch.h"
#include "Adventure.h"

#include <iostream>

#include "Door.h"
#include "Interactable.h"
#include "Player.h"
#include "Room.h"
#include "RoomManager.h"
#include "Texture.h"
#include "utils.h"

Adventure::Adventure(Player* pPlayer, RoomManager* pRoomManager, const Rectf& viewPort, Texture* paralax)
	:
	m_pPlayer(pPlayer),
	m_pParalax(paralax),
	m_pRoomManager(pRoomManager),
	m_pCurrentRoom(m_pRoomManager->m_pRooms["Room1"]),
	m_ViewPort(viewPort) 
{
	m_pPlayer->SetPlayerPos(Vector2f(96,726));
	m_SavedRoom = m_pCurrentRoom->GetName();
}

void Adventure::Draw() const
{
	glPushMatrix();
	glTranslatef(-m_CameraPos.x, -m_CameraPos.y, 0);
	glTranslatef(m_CameraPos.x/4, m_CameraPos.y/2, 0);
	m_pParalax->Draw();
	glTranslatef(-m_CameraPos.x/4, -m_CameraPos.y/2, 0);
	m_pCurrentRoom->Draw();
	m_pPlayer->Draw();
	glPopMatrix();
	for (int i{}; i < m_pCurrentRoom->GetInteractables().size(); ++i)
	{
		m_pCurrentRoom->GetInteractables()[i]->Draw(m_CameraPos);
	}
	utils::SetColor(Color4f(0, 0, 0, m_ScreenTrancparancy));
	utils::FillRect(m_ViewPort);
}

void Adventure::Update(float deltaTime)
{
	std::vector<CollisionBox> playerColliders{m_pCurrentRoom->GetWalls()};
	for (int i{}; i < m_pCurrentRoom->GetInteractables().size(); ++i)
	{
		if(m_pCurrentRoom->GetInteractables()[i]->IsSollid())
		{
			for (CollisionBox coll :m_pCurrentRoom->GetInteractables()[i]->GetCollisionBox())
			playerColliders.push_back(coll);
		}
	}
	m_pPlayer->Update(deltaTime,playerColliders);
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
			m_SavedSpawnLocation = Vector2f(m_pPlayer->GetPlayerPos().x, m_pRoomManager->m_pRooms[m_SavedRoom]->GetTexture()->GetHeight());
			m_IsTransitioning = true;
		}
	} else
	{
		if (m_CurrentScreenFadingTime <= 0)
		{
			m_IsTransitioning = false;
			m_CurrentScreenFadingTime = m_MaxScreenFadingTime;
		}
		if (m_CurrentScreenFadingTime <= 1 && m_pCurrentRoom->GetName() != m_SavedRoom )
		{
			m_pCurrentRoom = m_pRoomManager->m_pRooms[m_SavedRoom];
			m_pPlayer->SetPlayerPos(m_SavedSpawnLocation);
			m_pPlayer->SetChangedRoom(true);
		} else if (m_CurrentScreenFadingTime <=1)
		{
			m_ScreenTrancparancy = abs(abs(m_CurrentScreenFadingTime - m_MaxScreenFadingTime/2)-m_MaxScreenFadingTime / 2);
		}
		else
		{
			m_ScreenTrancparancy = abs(m_CurrentScreenFadingTime -m_MaxScreenFadingTime);
		}
		m_CurrentScreenFadingTime -= deltaTime;

			
	}


}

void Adventure::ButtonDownManager(const SDL_KeyboardEvent& e)
{
}
void Adventure::ButtonUpManager(const SDL_KeyboardEvent& e)
{
	for (int i{}; i < m_pCurrentRoom->GetInteractables().size(); ++i)
	{
		m_pCurrentRoom->GetInteractables()[i]->ButtonUpManager(e);
	}
}

bool Adventure::GetAdventureEnd()
{
	return m_AdventureEnd;
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

