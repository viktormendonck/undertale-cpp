#pragma once
#include "Texture.h"
#include "utils.h"
#include "Vector2f.h"

class ParticleSystem
{
public:
	ParticleSystem(int dissolveParticlesPerSecond, float dissolveParticleLifetime);
	~ParticleSystem();

	void Draw();
	void Update(float deltaTime);
	void StartDissolve(Vector2f spritePos, Texture* pTexture);
	
	

private:
	struct Particle
	{
		bool shouldMove{ false };
		Vector2f position{ };
		Vector2f velocity{ };
		float remainingLifetime{ };
		Color4f color{ };
	};
	std::vector<Particle*> m_pParticleList{ };

	size_t m_CurrentDissolveIndex{ };
	std::vector<Particle*> m_CurrentDissolveParticles{ };

	Vector2f m_SpritePos{};

	const int m_DissolveParticlesPerSecond{ };
	const float m_DissolveParticleLifetime{ };
	bool m_DissolveStarted{ false };

};

