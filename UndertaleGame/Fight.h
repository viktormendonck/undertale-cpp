#pragma once
#include <vector>

#include "Texture.h"

class EnemyManager;
class Enemy;
class FightChara;
class SpriteManager;

enum class FightState
{
	menu,
	fight
};

class Fight
{
public:
	Fight();
	~Fight();

	void Draw();
	void Update(float deltaTime);

	Rectf GetFightBoundaryBox();

private:
	FightChara* m_pChara;
	std::vector<Enemy*> m_pEnemies;
	Texture* m_pBackgroundTexture;
	std::vector<Texture*> m_pButtonTextures;
	bool m_IsBossFight{};
	int m_BackGroundsAmount{2};
	
};

