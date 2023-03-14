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
	fight,
	fightToMenu,
	menuToFight
};

class Fight
{
public:
	Fight(FightChara* pChara,Rectf screen,Texture* backGroundTexture);
	~Fight();

	void Draw();
	void Update(float deltaTime);

	Rectf GetFightBoundaryBox();
	void ButtonDownManager(const SDL_KeyboardEvent& e);
	void ButtonUpManager(const SDL_KeyboardEvent& e);

private:
	FightChara* m_pFightChara;

	std::vector<Enemy*> m_pEnemies;
	Texture* m_pBackgroundTexture;
	std::vector<Texture*> m_pButtonTextures;

	bool m_IsBossFight{};
	int m_BackGroundsAmount{2};

	Rectf m_FightBoundary{};
	Rectf m_TextBox{};
	float m_FightSquareDimentions{150};
	float m_TextBoxOffset{10};
	float m_BoxLineWidth{ 4 };

	FightState m_FightState{ FightState::fight };
	
};

