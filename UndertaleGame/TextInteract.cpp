#include "pch.h"
#include "TextInteract.h"

#include "Player.h"
#include "Texture.h"
#include "utils.h"

TextInteract::TextInteract(const Rectf& collisionRect, Texture* pBaseTextTexture, const std::vector<Texture*>& pTextTextures)
	:
	Interactable(collisionRect,true),
	m_pTextTextures(pTextTextures),
	m_pBaseTextBackGroundTexture(pBaseTextTexture),
	m_CurrentTextPage(-1)
{
	m_AmountOfTextPages = m_pTextTextures.size();
}

void TextInteract::Update(float deltaTime, Player* player)
{
	if (m_CurrentTextPage != -1)
	{
		player->SetPlayerState(Player::PlayerState::interacting);
	} else if(player->GetState() != Player::PlayerState::falling)
	{
		player->SetPlayerState(Player::PlayerState::wandering);
	}
	if (m_CurrentTextReadTime <=0)
	{
		const Uint8* state{ SDL_GetKeyboardState(nullptr) };
		if ((state[SDL_SCANCODE_RETURN] ||state[SDL_SCANCODE_C])&& utils::IsOverlapping(m_CollisionBox.GetRect(),player->GetInteractCollisionRect()))
		{
			m_CurrentTextReadTime = m_MinimumTextReadTime;
			OnInteract();
		}
	} else
	{
		m_CurrentTextReadTime -= deltaTime;
	}
}

void TextInteract::Draw() const
{
	if (m_CurrentTextPage >=0)
	{
		m_pBaseTextBackGroundTexture->Draw(Point2f(0,0));
		m_pTextTextures[m_CurrentTextPage]->Draw(Point2f(0,0));
	}

}

void TextInteract::OnInteract()
{
	if (m_CurrentTextPage < m_AmountOfTextPages-1)
	{
		++m_CurrentTextPage;
	}
	else if (m_CurrentTextPage == m_AmountOfTextPages - 1)
	{
		m_CurrentTextPage = -1;
	}
}
