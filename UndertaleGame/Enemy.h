#pragma once
#include "Vector2f.h"

class Texture;
class AnimatedSprite;

class Enemy
{
public:
	Enemy() = delete; // default constructor
	Enemy(int health, int conversationAmount, AnimatedSprite* baseTexture, Texture* deathTexture, bool isFlying); // constructor
	~Enemy(); // destructor

	Enemy(const Enemy& other) = delete; // Copy constructor
	Enemy& operator=(const Enemy& other) = delete; // Copy assignment operator

	Enemy(Enemy&& other) = delete; // Move constructor
	Enemy& operator=(Enemy&& other) = delete; // Move assignment operator

	void draw( );
	void Update(float deltaTime);

	void Damage(int damage);
	bool IsDead();

	Texture* GetDeathTexture();
	Vector2f GetPos();

private:
	int m_hp;
	int m_ConversationAmount; // amount of times you have to do correct conversation inputs with this enemy to make giving them mercy possible
	AnimatedSprite* m_pTexture;
	Texture* m_pEnemyDeathTexture;
	Vector2f m_Pos{};

	const bool m_IsFlying;

};

