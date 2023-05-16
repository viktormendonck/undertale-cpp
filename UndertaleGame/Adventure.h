#pragma once
#include "Vector2f.h"

class RoomManager;
class Room;
class Player;

class Adventure final
{
public:
	Adventure(Player* pPlayer,RoomManager* pRoomManager, Rectf ViewPort);
	void Draw() const;
	void Update(float deltaTime);
	void ButtonDownManager(const SDL_KeyboardEvent& e);
	void ButtonUpManager(const SDL_KeyboardEvent& e);
	bool GetAdventureEnd();
private:
	Vector2f m_CameraPos{};
	Player* m_pPlayer{};
	RoomManager* m_pRoomManager{};
	Room* m_pCurrentRoom{};
	Rectf m_ViewPort{};
	bool m_AdventureEnd{};

	void UpdateCameraPos();

};

