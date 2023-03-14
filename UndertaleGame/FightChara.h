#pragma once
#include "Vector2f.h"
#include "Fight.h"

class Texture;
class AnimatedSprite;

enum class FightCharaState
{
	base,
	running,
	dying
};

class FightChara
{
public:
	FightChara(Texture* heartTexture, AnimatedSprite* heartAnims, float speed, int startHealth);
	~FightChara();

	void Draw();
	void Update(float deltaTime, Fight* fight);

	void DamageChara(int damage);
	void SetFightCharaState(FightCharaState state);
	Rectf GetLocationRect();
	void SetPos(Vector2f pos);

	void ButtonDownManager(const SDL_KeyboardEvent& e);
	void ButtonUpManager(const SDL_KeyboardEvent& e);

private:
	FightCharaState m_State{ FightCharaState::base };
	Texture* m_pHeartTexture;
	AnimatedSprite* m_pHeartAnims;
	int m_Hp;
	float m_Speed;
	bool m_IsGravityMode{false};
	Vector2f m_pos{};
	Vector2f m_Velocity{};
};

inline Rectf FightChara::GetLocationRect()
{
	return Rectf(m_pos.ToPoint2f(), m_pHeartTexture->GetWidth(), m_pHeartTexture->GetHeight());
}

