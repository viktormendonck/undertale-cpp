#pragma once
#include <map>

#include "Inventory.h"
#include "Vector2f.h"

class CollisionBox;
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

	void Update(float deltaTime, std::vector<CollisionBox> colliders);
	void Draw();
	void UpdateMovement();
	Inventory* GetInventory();

	Rectf GetRect();
	Vector2f GetPlayerPos() const;
	void SetPlayerPos(const Vector2f& pos);
	Rectf GetPlayerCollisionRect();

	void StartFalling(const std::string& destination);
	void SetChangedRoom(bool e);
	bool HasChangedRoom();
	bool IsFalling();
	std::string GetFallDestination();
	Vector2f GetFallStartLocation();

private:
	AnimatedSprite* m_pSprite;
	Inventory* m_pInventory;
	std::string m_CurrentIdleStateName{}; //gets held to remember what way to look when Player stops walking
	float m_Speed{};
	Vector2f m_Velocity{};
	Rectf m_PlayerCollisionRect{};

	float m_RunStopDelay{};
	float m_CurrentRunStopDelay{};
	Vector2f m_Pos;

	bool m_IsFalling{};
	bool m_ChangedRoom{};
	float m_FallSpeed{ 400 };
	Vector2f m_FallStartLocation{};
	std::string m_FallDestination{};

	float m_TimeIncrementor{};
	int m_CurrentSpinDirection{};
	float m_SpinSpeed{ 12 };
	std::string m_SpinAnimation[4]{ "upIdle","rightIdle", "downIdle","leftIdle" };

};


