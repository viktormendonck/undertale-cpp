#pragma once
#include "Inventory.h"
#include "Vector2f.h"

class AnimatedSprite;

class Player final
{
public:
	Player(AnimatedSprite* playerSprite, Inventory* pInv, float speed);
	~Player();

	Player(const Player& other) = delete; // Copy constructor
	Player& operator=(const Player& other) = delete; // Copy assignment operator

	Player(Player&& other) = delete; // Move constructor
	Player& operator=(Player&& other) = delete; // Move assignment operator

	void Update(float deltaTime);
	void Draw();
	void UpdateMovement();
	Inventory* GetInventory();

	Rectf GetRect();
	Vector2f GetPlayerPos() const;
	void SetPlayerPos(Vector2f pos);

private:
	AnimatedSprite* m_pSprite;
	Inventory* m_pInventory;
	std::string m_CurrentIdleStateName{}; //gets held to remember what way to look when Player stops walking
	float m_Speed{};
	Vector2f m_Velocity{};

	float m_RunStopDelay{};
	float m_CurrentRunStopDelay{};
	Vector2f m_Pos;
};


