#include "pch.h"
#include "Adventure.h"

#include <iostream>

#include "Door.h"
#include "Player.h"
#include "Room.h"
#include "RoomManager.h"
#include "Texture.h"

Adventure::Adventure(Player* pPlayer, RoomManager* pRoomManager, Rectf ViewPort)
	:
	m_pPlayer(pPlayer),
	m_pRoomManager(pRoomManager),
	m_pCurrentRoom(m_pRoomManager->m_pRooms["Room1"]),
	m_ViewPort(ViewPort)
{
	m_pPlayer->SetPlayerPos(Vector2f(96,726));
}

void Adventure::Draw() const
{
	glPushMatrix();
	glTranslatef(-m_CameraPos.x, -m_CameraPos.y, 0);
	m_pCurrentRoom->Draw();
	m_pPlayer->Draw();


	glPopMatrix();
}

void Adventure::Update(float deltaTime)
{
	m_pPlayer->Update(deltaTime);
	UpdateCameraPos();

	for(int i{}; i< m_pCurrentRoom->GetDoors().size();++i)
	{
		if (!m_pCurrentRoom->GetDoors()[i].IsColliding(m_pPlayer->GetRect())) continue;
		m_pPlayer->SetPlayerPos(m_pCurrentRoom->GetDoors()[i].GetExitLocation());
		m_pCurrentRoom = m_pRoomManager->m_pRooms[m_pCurrentRoom->GetDoors()[i].GetDestination()];
	}
}

void Adventure::ButtonDownManager(const SDL_KeyboardEvent& e)
{
}
void Adventure::ButtonUpManager(const SDL_KeyboardEvent& e)
{
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

