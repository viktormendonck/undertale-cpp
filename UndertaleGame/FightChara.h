#pragma once
#include "Vector2f.h"
#include "Fight.h"

class Inventory;
class Texture;
class AnimatedSprite;

enum class FightCharaState
{
	base,
	running,
	dying
};

class FightChara final
{
public:
	FightChara(Texture* heartTexture, AnimatedSprite* heartAnims, Inventory* pInv, float speed, int startHealth);
	~FightChara();

	FightChara(const FightChara& other) = delete; // Copy constructor
	FightChara& operator=(const FightChara& other) = delete; // Copy assignment operator

	FightChara(FightChara&& other) = delete; // Move constructor
	FightChara& operator=(FightChara&& other) = delete; // Move assignment operator

	void Draw();
	void Update(float deltaTime, Fight* fight, std::vector<CollisionBox> colliders);

	void DamageChara(int damage);
	void SetFightCharaState(FightCharaState state);
	Rectf GetLocationRect() const;
	bool IsGravityMode() const;
	void SetPos(Vector2f pos);
	float GetDamage() const;
	int GetHealth() const;
	int GetMaxHealth() const;
	Inventory* GetInv() const;
	void UpdateMovement(float deltaTime);

	void OnButtonUp(const SDL_KeyboardEvent& e);

private:
	FightCharaState m_State{ FightCharaState::base };
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



