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

	enum class PlayerState
	{
		wandering,
		falling,
		interacting
	};

	void Update(float deltaTime, std::vector<CollisionBox> colliders);
	void Draw();
	Inventory* GetInventory();

	Rectf GetRect() const;
	Vector2f GetPlayerPos() const;
	void SetPlayerPos(const Vector2f& pos);

	Rectf GetPlayerCollisionRect() const;
	Rectf GetInteractCollisionRect() const;
	Rectf GetFullPlayerRect() const;

	void SetState(PlayerState playerState);
	PlayerState GetState() const;

	void StartFalling(const std::string& destination);
	void SetChangedRoom(bool newVal);
	bool HasChangedRoom() const;
	bool IsFalling() const;
	const std::string& GetFallDestination() const;
	Vector2f GetFallStartLocation() const;
	Vector2f GetVelocity() const;

	void SetInteractedWithBoss(bool newVal);
	bool GetInteractedWithBoss() const;



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

	Vector2f m_Pos;

	bool m_ChangedRoom{};
	const float m_BaseFallSpeed{ 250 };
	float m_FallSpeed{ m_BaseFallSpeed };
	const float m_FallGravity{ 300 };
	Vector2f m_FallStartLocation{};
	std::string m_FallDestination{};

	float m_SpinTimeIncrementer{};
	int m_CurrentSpinDirection{};
	const float m_SpinSpeed{ 12 };
	const std::string m_SpinAnimation[4]{ "upIdle","rightIdle", "downIdle","leftIdle" };

	bool m_HasInteractedWithBoss{};
};


