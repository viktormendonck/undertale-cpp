#include "pch.h"
#include "Game.h"

#include <iostream>

#include "Texture.h"
#include "utils.h"
#include "Vector2f.h"

Game::Game(const Window& window)
	: BaseGame{ window }
	, m_pFroggitTest{ new Texture("Sprites/test2.png") }
	, m_FroggitPos{ GetViewPort().width / 2, GetViewPort().height / 2 }
	, m_FroggitAlphaDataSize{ static_cast<int>(m_pFroggitTest->GetWidth() * m_pFroggitTest->GetHeight()) }
	, m_pFroggitAlphaData{ new float[m_FroggitAlphaDataSize] }
{
	Initialize();
}

Game::~Game()
{
	Cleanup();
}

void Game::Initialize()
{
	// Put all alpha data of texture into array
	glBindTexture(GL_TEXTURE_2D, m_pFroggitTest->GetTextureId());
	glGetTexImage(GL_TEXTURE_2D, 0, GL_ALPHA, GL_FLOAT, m_pFroggitAlphaData);
}

void Game::Cleanup()
{
	delete m_pFroggitTest;
	delete[] m_pFroggitAlphaData;

	for(const Particle* p : m_ParticleList)
	{
		delete p;
	}
}

void Game::Update(float deltaTime)
{

	for (size_t i{ 0 }; i < m_ParticleList.size(); ++i)
	{
		Particle* particle{ m_ParticleList[i] };

		if (particle->shouldMove == false) continue;

		m_ParticleList[i]->remainingLifetime -= deltaTime;
		particle->position += particle->velocity * deltaTime;

		particle->color.a = utils::Lerp(0, 1, particle->remainingLifetime / m_DissolveParticleLifetime);

		if(particle->remainingLifetime <= 0.f)
		{
			delete particle;
			m_ParticleList.erase(m_ParticleList.begin() + static_cast<long long>(i));
		}
	}

	if (!m_DissolveStarted) return;

	for(int i{ 0 }; i < m_DissolveParticlesPerSecond; ++i)
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

void Game::Draw() const
{

 	ClearBackground();

	for (const Particle* particle : m_ParticleList)
	{
		utils::SetColor(particle->color);
		utils::FillRect(particle->position.ToPoint2f(), 2, 2);
	}

	if (m_DrawFrog)
	{
		glPushMatrix();
		glTranslatef(m_FroggitPos.x, m_FroggitPos.y, 0);
		m_pFroggitTest->Draw();
		glPopMatrix();
	}
}

void Game::ProcessKeyDownEvent(const SDL_KeyboardEvent& e)
{
	//std::cout << "KEYDOWN event: " << e.keysym.sym << std::endl;
}

void Game::ProcessKeyUpEvent(const SDL_KeyboardEvent& e)
{
	std::cout << "KEYUP event: " << e.keysym.sym << std::endl;
	switch (e.keysym.sym)
	{
	case SDLK_SPACE:
		m_DrawFrog = false;

		m_DissolveStarted = true;
		m_CurrentDissolveParticles.clear();
		for (int i{ 0 }; i < m_FroggitAlphaDataSize; ++i)
		{
			if (m_pFroggitAlphaData[i] != 0.f)
			{
				const float randXVelocity{ static_cast<float>(rand() % 1000) / 1000.f * 90 - 45 };
				
				const float screenPixelX{ m_FroggitPos.x + static_cast<float>(i % static_cast<int>(m_pFroggitTest->GetWidth())) };
				const float screenPixelY{ m_FroggitPos.y + m_pFroggitTest->GetHeight() - static_cast<float>(i / static_cast<int>(m_pFroggitTest->GetWidth())) };

				Particle* item{ new Particle{
					false,
					Vector2f{ screenPixelX, screenPixelY },
					Vector2f{ randXVelocity, 75.f },
					m_DissolveParticleLifetime,
					Color4f{ 1, 1, 1, 1 }
				} };

				m_ParticleList.push_back(item);
				m_CurrentDissolveParticles.push_back(item);
			}
		}
		break;
	}
}

void Game::ProcessMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	//std::cout << "MOUSEMOTION event: " << e.x << ", " << e.y << std::endl;
}

void Game::ProcessMouseDownEvent(const SDL_MouseButtonEvent& e)
{
	//std::cout << "MOUSEBUTTONDOWN event: ";
	//switch ( e.button )
	//{
	//case SDL_BUTTON_LEFT:
	//	std::cout << " left button " << std::endl;
	//	break;
	//case SDL_BUTTON_RIGHT:
	//	std::cout << " right button " << std::endl;
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	std::cout << " middle button " << std::endl;
	//	break;
	//}

}

void Game::ProcessMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	//std::cout << "MOUSEBUTTONUP event: ";
	//switch ( e.button )
	//{
	//case SDL_BUTTON_LEFT:
	//	std::cout << " left button " << std::endl;
	//	break;
	//case SDL_BUTTON_RIGHT:
	//	std::cout << " right button " << std::endl;
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	std::cout << " middle button " << std::endl;
	//	break;
	//}
}

void Game::ClearBackground() const
{
	glClearColor(0.0f, 0.0f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}
