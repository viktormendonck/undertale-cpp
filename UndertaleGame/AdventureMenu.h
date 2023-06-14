#pragma once
#include "FightPlayer.h"
#include "Texture.h"

	enum class MenuState
	{
		menu,
		inventory
	};

class AdventureMenu
{
public:
	AdventureMenu(FightPlayer* pFightPlayer, ResourceManager* pResourceManager);
	~AdventureMenu();
	void Draw();

	MenuState GetMenuState();
	void SetMenuState(MenuState menuState);

	void OnButtonUp(const SDL_KeyboardEvent& e);

private:

	MenuState m_MenuState{MenuState::menu};
	FightPlayer* m_pPlayer;

	ResourceManager* m_pResourceManager;
	const int m_AmountOfTextLocations{ 4 };

	int m_CurrentItemPage{};
	int m_CurrentSelectedOption{};

	Vector2f m_TextLocations[4]{ Vector2f{50,120},Vector2f{330,120},Vector2f{50,50},Vector2f{330,50} };

};

