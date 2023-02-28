#include "pch.h"
#include "ParticleSystem.h"


ParticleSystem::ParticleSystem(int dissolveParticlesPerSecond, float dissolveParticleLifetime)
	: m_DissolveParticlesPerSecond{dissolveParticlesPerSecond},
	  m_DissolveParticleLifetime{dissolveParticleLifetime}
{
}

ParticleSystem::~ParticleSystem()
{
	for (const Particle* p : m_pParticleList)
	{
		delete p;
	}
}

void ParticleSystem::Draw()
{
	for (const Particle* pParticle : m_pParticleList)
	{
		utils::SetColor(pParticle->color);
		utils::FillRect(pParticle->position.ToPoint2f(), 2, 2);
	}
}

void ParticleSystem::Update(float deltaT)
{
	for (size_t i{ 0 }; i < m_pParticleList.size(); ++i)
	{
		Particle* particle{ m_pParticleList[i] };

		if (particle->shouldMove == false) continue;

		m_pParticleList[i]->remainingLifetime -= deltaT;
		particle->position += particle->velocity * deltaT;

		particle->color.a = utils::Lerp(0, 1, particle->remainingLifetime / m_DissolveParticleLifetime);

		if (particle->remainingLifetime <= 0.f)
		{
			delete particle;
			m_pParticleList.erase(m_pParticleList.begin() + static_cast<long long>(i));
		}
	}

	if (!m_DissolveStarted) return;

	for (int i{ 0 }; i < m_DissolveParticlesPerSecond; ++i)
	{
		m_CurrentDissolveParticles[m_CurrentDissolveIndex]->shouldMove = true;
		++m_CurrentDissolveIndex;

		if (m_CurrentDissolveIndex >= m_CurrentDissolveParticles.size())
		{
			m_DissolveStarted = false;
			m_CurrentDissolveIndex = 0;
			m_CurrentDissolveParticles.clear();
			break;
		}
	}
}

void ParticleSystem::StartDissolve(Vector2f spritePos, Texture* pTexture)
{
	const int textureAlphaDataSize = static_cast<int>(pTexture->GetHeight() * pTexture->GetWidth());
	float* pTextureAlphaData = new float[textureAlphaDataSize];

	glBindTexture(GL_TEXTURE_2D, pTexture->GetTextureId());
	glGetTexImage(GL_TEXTURE_2D, 0, GL_ALPHA, GL_FLOAT, pTextureAlphaData);

	m_DissolveStarted = true;
	m_CurrentDissolveParticles.clear();

	for (int i{ 0 }; i < textureAlphaDataSize; ++i)
	{
		if (pTextureAlphaData[i] != 0.f)
		{
			const float randXVelocity{ static_cast<float>(rand() % 1000) / 1000.f * 90 - 45 };

			const float screenPixelX{ spritePos.x + static_cast<float>(i % static_cast<int>(pTexture->GetWidth())) };
			const float screenPixelY{ spritePos.y + pTexture->GetHeight() - static_cast<float>(i / static_cast<int>(pTexture->GetWidth())) };

			Particle* item{ new Particle{
				false,
				Vector2f{ screenPixelX, screenPixelY },
				Vector2f{ randXVelocity, 75.f },
				m_DissolveParticleLifetime,
				Color4f{ 1, 1, 1, 1 }
			} };

			m_pParticleList.push_back(item);
			m_CurrentDissolveParticles.push_back(item);
		}
	}
	delete[] pTextureAlphaData;
}
