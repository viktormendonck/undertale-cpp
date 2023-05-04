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
	fight,
	transition
};

class Fight final
{
public:
	Fight() = delete;
	Fight(FightChara* pChara,Rectf screen,ResourceManager* pResourceManager,ParticleSystem* pParticleSystem, EnemyType enemy ,bool isBossFight);
	~Fight();

	Fight(const Fight& other) = delete; // Copy constructor
	Fight& operator=(const Fight& other) = delete; // Copy assignment operator

	Fight(Fight&& other) = delete; // Move constructor
	Fight& operator=(Fight&& other) = delete; // Move assignment operator

	void Draw();
	void Update(float deltaTime);

	CollisionBox GetFightBoundaryBox();
	void ButtonDownManager(const SDL_KeyboardEvent& e);
	void ButtonUpManager(const SDL_KeyboardEvent& e);

private:
	FightChara* m_pFightChara;

	Enemy* m_pEnemy;
	Texture* m_pBackgroundTexture;
	std::vector<Texture*> m_pButtonTextures;

	ParticleSystem* m_pParticleSystem;
	ResourceManager* m_pResourceManager;

	bool m_IsBossFight{};
	int m_BackGroundsAmount{2};

	CollisionBox m_FightBoundary;
	Rectf m_TextBox{};
	float m_FightSquareDimentions{150};
	float m_TextBoxSideOffset{10};
	float m_BoxLineWidth{ 2 };
	float m_BoxBottomOffset{ 75 };


	Vector2f m_MiddleLocation{};

	FightState m_FightState{ FightState::fight };
	FightState m_PreviousFightState{ FightState::fight };


	float m_BoxTransitionSpeed{ 1 };
	float m_BoxTransitionIncrementor{};
	Rectf m_CurrentTransitionRect{};

	std::vector<CollisionBox> m_Colliders{};
	const int m_PlatformAmount{3};

	void DrawPlatforms() const;
	void UpdatePlatforms(float deltaTime);

	const float m_PlatformTimer{ 5 };
	float m_CurrentPlatformTimer{0};

	//UI
	enum class UiState
	{
		fightSelected,
		actSelected,
		itemSelected,
		mercySelected,
		idle

	};
	void DrawUi() const;
	void UpdateUi(float deltaTime);
	Vector2f m_ButtonLocations[4]{ Vector2f{16,15},Vector2f{16+110+56,15},Vector2f{16+110*2+56+57,15},Vector2f{16+110*3+56*2+57,15} };
	int  m_ButtonsAmount{ 4 };
	UiState m_UiState{ UiState::idle };
	
};

