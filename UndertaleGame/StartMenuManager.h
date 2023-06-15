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
	explicit StartMenuManager(ResourceManager* pResourceManager);

	void Draw() const;
	void OnButtonUp(const SDL_KeyboardEvent& e);
	MenuState GetMenuState() const;

private:
	void AddLetter(char letter);
	MenuState m_MenuState{ MenuState::startScreen };
	//sound edit
	int& m_AudioVolumeRef;
	//name edit
	ResourceManager* m_pResourceManager;
	Texture* m_pTempName;
	std::string m_PlayerName;
	//menu selection;
	int m_SelectedOption{};
	const Vector2f m_SelectionLocations[3]{Vector2f{210,250},Vector2f{210,215},Vector2f{210,183}};
};

