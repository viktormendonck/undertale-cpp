#pragma once
#include <map>

#include "CollisionBox.h"
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

	enum class PlayerState
	{
		wandering,
		falling,
		interacting
	};

	void Update(float deltaTime, std::vector<CollisionBox> colliders);
	void Draw();
	Inventory* GetInventory();

	Rectf GetRect();
	Vector2f GetPlayerPos() const;
	void SetPlayerPos(const Vector2f& pos);

	Rectf GetPlayerCollisionRect();
	Rectf GetInteractCollisionRect();
	Rectf GetFullPlayerRect();

	void SetState(PlayerState playerState);
	PlayerState GetState();

	void StartFalling(const std::string& destination);
	void SetChangedRoom(bool e);
	bool HasChangedRoom();
	bool IsFalling();
	std::string GetFallDestination();
	Vector2f GetFallStartLocation();
	Vector2f GetVelocity();

	void SetInteractedWithBoss(bool b);
	bool GetInteractedWithBoss();



private:
	void UpdateMovement();
	void UpdateCollisionSelection();
	PlayerState m_PlayerState{PlayerState::wandering};
	AnimatedSprite* m_pSprite;
	Inventory* m_pInventory;
	std::string m_CurrentIdleStateName{}; //gets held to remember what way to look when Player stops walking
	float m_Speed{};
	Vector2f m_Velocity{};
	Rectf m_PlayerCollisionRect{};
	Rectf m_InteractCollisionRect{};

	float m_RunStopDelay{};
	float m_CurrentRunStopDelay{};
	Vector2f m_Pos;

	bool m_ChangedRoom{};
	float m_FallSpeed{ 400 };
	Vector2f m_FallStartLocation{};
	std::string m_FallDestination{};

	float m_TimeIncrementor{};
	int m_CurrentSpinDirection{};
	float m_SpinSpeed{ 12 };
	std::string m_SpinAnimation[4]{ "upIdle","rightIdle", "downIdle","leftIdle" };

	bool m_HasInteractedWithBoss{};

};


