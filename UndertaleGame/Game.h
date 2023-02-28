#pragma once
#include <vector>

#include "BaseGame.h"
#include "Vector2f.h"

class Texture;

struct Particle
{
	bool shouldMove{ false };
	Vector2f position{ };
	Vector2f velocity{ };
	float remainingLifetime{ };
	Color4f color{ };
};

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
	std::vector<Particle*> m_ParticleList{ };

	bool m_DrawFrog{ true };
	Texture* m_pFroggitTest;
	Vector2f m_FroggitPos{ };

	const float m_DissolveParticleLifetime{ .6f };
	const int m_DissolveParticlesPerSecond{ 20 };

	int m_FroggitAlphaDataSize;
	float* m_pFroggitAlphaData;

	bool m_DissolveStarted{ false };

	size_t m_CurrentDissolveIndex{ 0 };

	std::vector<Particle*> m_CurrentDissolveParticles{ };

		// FUNCTIONS
	void Initialize();
	void Cleanup();
	void ClearBackground() const;
};
