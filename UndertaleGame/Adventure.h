#pragma once
#include "Texture.h"
#include "Vector2f.h"

class RoomManager;
class Room;
class Player;

class Adventure final
{
public:
	Adventure(Player* pPlayer,RoomManager* pRoomManager, const Rectf& viewPort,Texture* paralax);
	void Draw() const;
	void Update(float deltaTime);
	void ButtonDownManager(const SDL_KeyboardEvent& e);
	void ButtonUpManager(const SDL_KeyboardEvent& e);
	bool GetAdventureEnd();
private:
	Vector2f m_CameraPos{};
	Player* m_pPlayer{};
	Texture* m_pParalax{};
	RoomManager* m_pRoomManager{};
	Room* m_pCurrentRoom{};
	Rectf m_ViewPort{};
	bool m_AdventureEnd{};

	float m_ScreenTrancparancy{};
	float m_MaxScreenFadingTime{2};
	float m_CurrentScreenFadingTime{m_MaxScreenFadingTime};
	std::string m_SavedRoom{}; //saves the destination room for during transition
	Vector2f m_SavedSpawnLocation{}; // saves the spawn location for the room it will travel to
	bool m_IsTransitioning{};

	void UpdateCameraPos();

};

