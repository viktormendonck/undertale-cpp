#pragma once
#include "Vector2f.h"

class AnimatedSprite;

class Chara
{
public:
	Chara(AnimatedSprite* playerSprite, float speed);
	~Chara();

	void Update(float deltaTime);
	void PlayerButtonDownManager(const SDL_KeyboardEvent& e);
	void PlayerButtonUpManager(const SDL_KeyboardEvent& e);

	Vector2f GetPlayerPos() const;
private:
	AnimatedSprite* m_pSprite;
	std::string m_PreviousMovementState{}; //gets held to remember what way to look when Chara stops walking
	float m_Speed{};
	Vector2f m_CurrentSpeed{};

	float m_RunStopDelay{};
	float m_CurrentRunStopDelay{};
};


