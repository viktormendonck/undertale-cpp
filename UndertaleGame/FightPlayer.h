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
	bool IsDead() const;
	Inventory* GetInv() const;
	void UpdateMovement(float deltaTime);


	void OnButtonUp(const SDL_KeyboardEvent& e);


private:
	FightPlayerState m_State{ FightPlayerState::base };
	const Texture* m_pHeartTexture;
	AnimatedSprite* m_pHeartAnims;
	Inventory* m_pInventory;
	int m_Hp;
	const int m_MaxHp;
	float m_Speed;
	bool m_IsGravityMode{false};
	Vector2f m_Pos{};
	Vector2f m_Velocity{};

	float m_Damage{ 10 };
	const float m_Gravity{ 120 };
	float  m_JumpStrength{};

	Linef m_LineCast{};

	bool m_IsGrounded{};
};



