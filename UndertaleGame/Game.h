#pragma once
#include "BaseGame.h"
#include "SoundManager.h"
#include "Vector2f.h"

class StartMenuManager;
class RoomManager;
class Adventure;
class Inventory;
class Texture;
class ParticleSystem;
class AnimatedSprite;
class ResourceManager;
class Player;
class FightPlayer;
class Fight;




class Game final : public BaseGame
{
public:
	explicit Game(const Window& window);
	Game(const Game& other) = delete;
	Game& operator=(const Game& other) = delete;
	Game(Game&& other) = delete;
	Game& operator=(Game&& other) = delete;
	// http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rh-override
	~Game();

	void Update(float deltaTime) override;
	void Draw() const override;

	// Event handling
	void ProcessKeyDownEvent(const SDL_KeyboardEvent& e) override;
	void ProcessKeyUpEvent(const SDL_KeyboardEvent& e) override;
	void ProcessMouseMotionEvent(const SDL_MouseMotionEvent& e) override;
	void ProcessMouseDownEvent(const SDL_MouseButtonEvent& e) override;
	void ProcessMouseUpEvent(const SDL_MouseButtonEvent& e) override;

private:
	enum class GameState
	{
		menu,
		infoScreen,
		adventure,
		fight,
		death
	};

	GameState m_GameState{};

	ParticleSystem* m_pParticleSystem{};
	ResourceManager* m_pResourceManager{};
	StartMenuManager* m_pMenu{};


	Player* m_pPlayer{};
	FightPlayer* m_pFightPlayer{};
	Inventory* m_pInventory{};

	Fight* m_pFight{};
	Adventure* m_pAdventure{};

	RoomManager* m_pRoomManager{};
	Rectf m_ViewPort{};

	GameState m_SavePreviousState{}; // save state for when you're in the infoState
	GameState m_NextGameState{};

	float m_ScreenTrancparancy{};
	float m_MaxScreenFadingTime{ 2 };
	float m_CurrentScreenFadingTime{ m_MaxScreenFadingTime };
	bool m_IsTransitioning{};
	// FUNCTIONS
	void Initialize();
	void Cleanup();
	void ClearBackground() const;
	void UpdateTransition(float deltaTime);

};
