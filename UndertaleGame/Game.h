#pragma once
#include "BaseGame.h"
#include "Vector2f.h"

class Inventory;
class Texture;
class ParticleSystem;
class AnimatedSprite;
class ResourceManager;
class Chara;
class FightChara;
class Fight;

//test classes
// TODO: remove


class Game : public BaseGame
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
		startScreen,
		infoScreen,
		adventure,
		fight
	};
	GameState m_GameState{ GameState::fight };

	ParticleSystem* m_pParticleSystem{};
	Texture* m_pInfoScreenTexture{};
	Vector2f m_EnemyPos{};
	ResourceManager* m_pResourceManager{};
	Chara* m_pChara{};
	FightChara* m_pFightChara{};
	Inventory* m_pInventory{};
	Fight* m_pFight{};
	Rectf m_Window{};

	//TEST CLASSES
	// TODO: remove


		// FUNCTIONS
	void Initialize();
	void Cleanup();
	void ClearBackground() const;
};
