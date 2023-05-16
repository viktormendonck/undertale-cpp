#pragma once
#include <vector>

#include "CollisionBox.h"
#include "Texture.h"
#include "ResourceManager.h"
#include "Vector2f.h"
#include "Enemy.h"

class EnemyManager;
class FightChara;
class ParticleSystem;

enum class FightState
{
	menu,
	menuSelected,
	fight,
	transition
};

class Fight final
{
public:
	Fight() = delete;
	Fight(FightChara* pChara, Rectf screen, ResourceManager* pResourceManager, ParticleSystem* pParticleSystem, EnemyType enemy, bool isBossFight);
	~Fight();

	Fight(const Fight& other) = delete; // Copy constructor
	Fight& operator=(const Fight& other) = delete; // Copy assignment operator

	Fight(Fight&& other) = delete; // Move constructor
	Fight& operator=(Fight&& other) = delete; // Move assignment operator

	void Draw() const;
	void Update(float deltaTime);
	bool IsFightOver();

	CollisionBox GetFightBoundaryBox();
	void ButtonDownManager(const SDL_KeyboardEvent& e);
	void ButtonUpManager(const SDL_KeyboardEvent& e);

private:
	FightChara* m_pPlayer;

	Enemy* m_pEnemy;
	Texture* m_pBackgroundTexture;
	std::vector<Texture*> m_pButtonTextures;

	ParticleSystem* m_pParticleSystem;
	ResourceManager* m_pResourceManager;

	bool m_IsBossFight{};
	int m_BackGroundsAmount{ 2 };

	CollisionBox m_FightBoundary{};
	Rectf m_TextBox{};
	float m_FightSquareDimentions{ 150 };
	float m_TextBoxSideOffset{ 10 };
	float m_BoxLineWidth{ 2 };
	float m_box_bottom_offset{ 75 };


	Vector2f m_MiddleLocation{};

	FightState m_FightState{ FightState::fight };
	FightState m_PreviousFightState{ m_FightState };


	float m_BoxTransitionSpeed{ 1 };
	float m_BoxTransitionIncrementor{};
	Rectf m_CurrentTransitionRect{};

	std::vector<CollisionBox> m_Colliders{};
	const int m_PlatformAmount{ 3 };


	const float m_PlatformTimer{ 5 };
	float m_CurrentPlatformTimer{ 0 };

	//UI
	enum class UiState
	{
		fightSelected,
		actSelected,
		itemSelected,
		mercySelected,
		idle
	};
	Vector2f m_ButtonLocations[4]{ Vector2f{16,5},Vector2f{16 + 110 + 56,5},Vector2f{16 + 110 * 2 + 56 + 57,5},Vector2f{16 + 110 * 3 + 56 * 2 + 57,5} };
	int  m_ButtonsAmount{ 4 };
	UiState m_UiState{ UiState::idle };
	UiState m_MenuSelectedState{ UiState::idle };

	//Fightmenu variables

	Vector2f m_AttackBarLocation{ Vector2f(m_TextBox.left,m_TextBox.bottom) };
	Vector2f m_AttackBarStartLocation{};

	//fight menu variables
	float m_DistanceFromWall{};
	bool m_BarStopped{};
	int m_BarDirectionMulti{ 1 };
	float m_BarStoppedMaxCountDown{ 1 };
	float m_CurrentBarStoppedCountDown{ m_BarStoppedMaxCountDown };
	float m_BarSpeed{ 250 };
	float m_MaxPlayerDamageMulti{ 2.5f };
	bool m_FightEnded{};
	float m_UpdateTimeAfterDeath{ 3 };

	Vector2f m_UIInformationLocations[2]{ Vector2f{16,47},Vector2f{116,47} };
	const int m_AmountOfUITextTextures{ 2 };
	float m_PreviousHealth{};

	//ActMenu variables
	const int m_AmountOfActOptions{ 3 };
	const float m_MaxReadingTime{ 5 };
	float m_CurrentReadingTime{ m_MaxReadingTime };
	const int m_AmountOfTextLocations{ 4 };
	Vector2f m_TextLocations[4]{ Vector2f{50,180},Vector2f{330,180},Vector2f{50,110},Vector2f{330,110} };
	Vector2f m_ResponsePos{};
	Vector2f m_ResponsePosOrigin{ 50,200 };
	int m_CurrentSelectedOption{};
	bool m_HasActed{};

	//itemMenuVars
	int m_AmountOfItemPages{};
	int m_CurrentItemPage{};


	//Draw cleanup functions
	void DrawMenu() const;
	void DrawFight() const;
	void DrawMenuSelected() const;
	void DrawTransition() const;
	void DrawUI() const;
	void DrawPlatforms() const;
	void DrawActMenuOptions() const;
	void DrawActMenuResponses() const;
	


	//Update cleanup functions
	void UpdateMenu(float deltaTime);
	void UpdateFight(float deltaTime);
	void UpdateMenuSelected(float deltaTime);
	void UpdateTransition(float deltaTime);
	void UpdateUI(float deltaTime);
	void UpdatePlatforms(float deltaTime);

	void StartFightSegment();



	//Button input cleanup functions
	void ButtonUpMenuManager(const SDL_KeyboardEvent& e);
	void ButtonUpMenuSelectedManager(const SDL_KeyboardEvent& e);
	void ButtonUpFightManager(const SDL_KeyboardEvent& e);

};