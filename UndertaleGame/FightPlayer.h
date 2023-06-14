#pragma once
#include "Vector2f.h"
#include "Fight.h"

class Inventory;
class Texture;
class AnimatedSprite;

enum class FightPlayerState
{
	base,
	running,
	dying
};

class FightPlayer final
{
public:
	FightPlayer(Texture* heartTexture, AnimatedSprite* heartAnims, Inventory* pInv, float speed, int startHealth);
	~FightPlayer();

	FightPlayer(const FightPlayer& other) = delete; // Copy constructor
	FightPlayer& operator=(const FightPlayer& other) = delete; // Copy assignment operator

	FightPlayer(FightPlayer&& other) = delete; // Move constructor
	FightPlayer& operator=(FightPlayer&& other) = delete; // Move assignment operator

	void Draw();
	void Update(float deltaTime, Fight* fight, std::vector<CollisionBox> colliders);

	void Damage(int damage);
	void SetFightPlayerState(FightPlayerState state);
	Rectf GetLocationRect() const;
	bool IsGravityMode() const;
	void SetPos(const Vector2f& pos);
	float GetDamage() const;
	int GetHealth() const;
	int GetMaxHealth() const;
	bool IsDead();
	Inventory* GetInv() const;
	void UpdateMovement(float deltaTime);


	void OnButtonUp(const SDL_KeyboardEvent& e);


private:
	FightPlayerState m_State{ FightPlayerState::base };
	Texture* m_pHeartTexture;
	AnimatedSprite* m_pHeartAnims;
	Inventory* m_pInventory;
	int m_Hp;
	int m_MaxHp;
	float m_Speed;
	bool m_IsGravityMode{false};
	Vector2f m_Pos{};
	Vector2f m_Velocity{};

	float m_Damage{ 10 };
	float m_Gravity{ 120 };
	float  m_JumpStrength{};

	Linef m_LineCast{};

	bool m_IsGrounded{};
};



