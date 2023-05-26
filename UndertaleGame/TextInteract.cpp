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
	m_IsColliding = utils::IsOverlapping(m_CollisionBoxes[0].GetRect(), player->GetInteractCollisionRect());
}

void TextInteract::Draw(const Vector2f& camera) const
{
	if (m_CurrentTextPage >=0)
	{
		m_pBaseTextBackGroundTexture->Draw(Point2f(0,0));
		m_pTextTextures[m_CurrentTextPage]->Draw(Point2f(0,0));
	}

}

void TextInteract::ButtonUpManager(const SDL_KeyboardEvent& e)
{
	
	if ((e.keysym.sym == SDLK_RETURN || e.keysym.sym == SDLK_z ) && m_IsColliding)
	{
		OnInteract();
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
