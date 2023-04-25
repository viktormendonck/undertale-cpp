#pragma once
#include <vector>

#include "CollisionBox.h"
#include "Texture.h"
#include "Vector2f.h"


class EnemyManager;
class Enemy;
class FightChara;
class ResourceManager;
class ParticleSystem;

enum class FightState
{
	menu,
	fight,
	transition
};

class Fight
{
public:
	Fight() = delete;
	Fight(FightChara* pChara,Rectf screen,Texture* backGroundTexture,ParticleSystem* pParticleSystem);
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

	std::vector<Enemy*> m_pEnemies;
	Texture* m_pBackgroundTexture;
	std::vector<Texture*> m_pButtonTextures;

	ParticleSystem* m_pParticleSystem;

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

	
};

