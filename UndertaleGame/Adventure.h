#pragma once
#include "Texture.h"
#include "Vector2f.h"

class FightPlayer;
class ResourceManager;
class ParticleSystem;
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
	void SetAdventureEnd(bool b);
	bool IsBossFight();
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

	//info for new fights

	float m_maxSpawnCheckDelay{1};
	float m_CurrentSpawnCheckDelay{m_maxSpawnCheckDelay};

	bool m_IsBossFight{};

	void UpdateCameraPos();

};

