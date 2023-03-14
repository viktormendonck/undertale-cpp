#pragma once
#include "Enemy.h"


class Froggit : Enemy
{
public:
	Froggit(Texture* pFroggitHead,int health, int conversationAmount);
	~Froggit();

	void Update(float deltaTime);
	void Draw();
	

private:
	Texture* m_pFroggitHead;
	float HeadMovingIncrementor;
	Vector2f m_HeadOffsetFromBody;

};

