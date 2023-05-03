#pragma once
#include "Vector2f.h"

class AnimatedSprite;

class Chara final
{
public:
	Chara(AnimatedSprite* playerSprite, float speed);
	~Chara();

	Chara(const Chara& other) = delete; // Copy constructor
	Chara& operator=(const Chara& other) = delete; // Copy assignment operator

	Chara(Chara&& other) = delete; // Move constructor
	Chara& operator=(Chara&& other) = delete; // Move assignment operator

	void Update(float deltaTime);
	void Draw();
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
	Vector2f m_Pos;
};


