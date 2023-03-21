#pragma once
#include "Vector2f.h"

class Texture;
class AnimatedSprite;

class Enemy
{
public:
	Enemy() = delete;
	Enemy(int health, int conversationAmount, AnimatedSprite* baseTexture, Texture* deathTexture);
	~Enemy();

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

};

