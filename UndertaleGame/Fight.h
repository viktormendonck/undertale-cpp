#pragma once
#include <vector>

#include "CollisionBox.h"
#include "Texture.h"
#include "ResourceManager.h"
#include "Vector2f.h"
#include "Enemy.h"

class EnemyManager;
class FightPlayer;
class ParticleSystem;


class Fight final
{
public:
	Fight() = delete;
	Fight(FightPlayer* pChara, Rectf screen, ResourceManager* pResourceManager, ParticleSystem* pParticleSystem, EnemyType enemy);
	~Fight();

	Fight(const Fight& other) = delete; // Copy constructor
	Fight& operator=(const Fight& other) = delete; // Copy assignment operator

	Fight(Fight&& other) = delete; // Move constructor
	Fight& operator=(Fight&& other) = delete; // Move assignment operator

	void Draw() const;
	void Update(float deltaTime);
	bool IsFightOver();

	CollisionBox GetFightBoundaryBox() const ;
	void ButtonUpManager(const SDL_KeyboardEvent& e);

private:
	//UI
	enum class UiState
	{
		fightSelected,
		actSelected,
		itemSelected,
		mercySelected,
		idle
	};
	enum class FightState
	{
		menu,
		menuSelected,
		enemyAttack,
		transition
	};
	FightPlayer* m_pPlayer;

	Enemy* m_pEnemy;
	const Texture* m_pBackgroundTexture;
	const std::vector<Texture*> m_pButtonTextures;

	ParticleSystem* m_pParticleSystem;
	ResourceManager* m_pResourceManager;

	//enemy health bar vars

	Rectf m_HealthBarRemaining{0,0,0,5};
	Rectf m_HealthBar{0,0,150,5};
	float m_PreviousHealthBarWidth{};


	bool m_IsBossFight{};
	int m_BackGroundsAmount{ 2 };

	CollisionBox m_FightBoundary{};
	Rectf m_TextBox{};
	const float m_FightSquareDimensions{ 150 };
	const float m_TextBoxSideOffset{ 10 };
	const float m_BoxLineWidth{ 2 };
	const float m_BoxBottomOffset{ 75 };


	Vector2f m_MiddleLocation{};

	FightState m_FightState{ FightState::enemyAttack };
	FightState m_PreviousFightState{ m_FightState };


	const float m_BoxTransitionSpeed{ 1 };
	float m_BoxTransitionIncrementor{};
	Rectf m_CurrentTransitionRect{};

	std::vector<CollisionBox> m_Colliders{};
	const int m_PlatformAmount{ 3 };


	const float m_PlatformTimer{ 5 };
	float m_CurrentPlatformTimer{ 0 };

	const Vector2f m_ButtonLocations[4]{ Vector2f{16,5},Vector2f{16 + 110 + 56,5},Vector2f{16 + 110 * 2 + 56 + 57,5},Vector2f{16 + 110 * 3 + 56 * 2 + 57,5} };
	const int m_ButtonsAmount{ 4 };
	UiState m_UiState{ UiState::idle };
	UiState m_MenuSelectedState{ UiState::idle };

	//Fightmenu variables

	Vector2f m_AttackBarLocation{ Vector2f(m_TextBox.left,m_TextBox.bottom) };
	Vector2f m_AttackBarStartLocation{};

	//enemyAttack menu variables
	float m_DistanceFromWall{};
	bool m_BarStopped{};
	int m_BarDirectionMulti{ 1 };
	const float m_MaxBarStoppedCooldown{ 1.3f };
	float m_CurrentBarStoppedCooldown{ m_MaxBarStoppedCooldown };
	const float m_BarSpeed{ 250 };
	const float m_MaxPlayerDamageMulti{ 2.5f };
	bool m_FightEnded{};
	float m_UpdateTimeAfterDeath{ 3 };

	const Vector2f m_UIInformationLocations[2]{ Vector2f{16,47},Vector2f{116,47} };
	const int m_AmountOfUITextTextures{ 2 };
	int m_PreviousHealth{};

	//ActMenu variables
	const int m_AmountOfActOptions{ 3 };
	const float m_MaxReadingTime{ 5 };
	float m_CurrentReadingTime{ m_MaxReadingTime };
	const int m_AmountOfTextLocations{ 4 };
	const Vector2f m_TextLocations[4]{ Vector2f{50,180},Vector2f{330,180},Vector2f{50,110},Vector2f{330,110} };
	Vector2f m_ResponsePos{};
	const Vector2f m_ResponsePosOrigin{ 50,200 };
	int m_CurrentSelectedOption{};
	bool m_HasActed{};

	//itemMenuVars
	int m_AmountOfItemPages{};
	int m_CurrentItemPage{};



	//Draw cleanup functions
	void DrawMenu() const;
	void DrawEnemyAttack() const;
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