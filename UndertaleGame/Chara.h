#pragma once
#include "Vector2f.h"

class AnimatedSprite;

class Chara
{
public:
	Chara(AnimatedSprite* playerSprite);
	~Chara();

	void Update(float deltaTime);
	void PlayerInputManager();
	Vector2f GetPlayerPos();
private:
	AnimatedSprite* m_pSprite;
	std::string previousMovementState{}; //gets held to remember what way to look when Chara stops walking
};

