#pragma once
#include <vector>

#include "BaseGame.h"
#include "Vector2f.h"

class Texture;
class ParticleSystem;
class AnimatedSprite;
class SpriteManager;

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
		game,
	};
	GameState m_GameState{ GameState::game };

	ParticleSystem* m_pParticleSystem{};
	Texture* m_pTexture{};
	Texture* m_pInfoScreenTexture{};
	Vector2f m_EnemyPos{};
	bool m_IsDead{};
	SpriteManager* m_pSpriteManager{};


		// FUNCTIONS
	void Initialize();
	void Cleanup();
	void ClearBackground() const;
};
