#pragma once
#include <map>

#include "Vector2f.h"
class Texture;
class ResourceManager;
enum class MenuState
{
	startScreen,
	optionsScreen,
	controlsScreen,
	nameScreen,
	menuEnd,
};

class StartMenuManager final
{
public:
	StartMenuManager(ResourceManager* pResourceManager);

	void Draw();
	void OnButtonUp(const SDL_KeyboardEvent& e);
	MenuState GetMenuState();

private:
	void AddLetter(char letter);
	MenuState m_MenuState{ MenuState::startScreen };

	//sound edit
	int& m_AudioVolumeRef;
	//name edit

	ResourceManager* m_pResourceManager;
	Texture* m_pTempName;
	std::string m_PlayerName;
	bool m_NameBoxSelected;
	//menu selection;
	int m_SelectedOption{};
	Vector2f m_SelectionLocations[3]{Vector2f{210,250},Vector2f{210,215},Vector2f{210,183}};

	
};

