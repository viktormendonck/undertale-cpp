#pragma once
#include "Vector2f.h"

class Texture;

class Enemy
{
public:
	Enemy(int health, int conversationAmount);
	~Enemy();

	void draw();
	void Update();

	void Damage(int damage);
	bool IsDead();

private:
	int m_hp;
	Texture* m_pEnemyTexture;
	Texture* m_pEnemyDeathTexture;
	Vector2f m_Pos;
	int m_ConversationAmount; // amount of times you have to do correct conversation inputs with this enemy to make giving them mercy possible

};

