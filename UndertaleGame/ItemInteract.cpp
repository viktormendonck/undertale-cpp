#include "pch.h"
#include "ItemInteract.h"

#include <iostream>

#include "Player.h"
#include "SoundManager.h"
#include "Texture.h"
#include "utils.h"


ItemInteract::ItemInteract(const Rectf& collisionRect, Texture* pBaseTextTexture, const std::vector<Texture*>& pItemInteractTextures, Texture* pSelectedIconTexture, const std::string& item, int amountOfItems)
	:
	Interactable(collisionRect,true),
	m_TextTextures(pItemInteractTextures),
	m_pBaseTextBackGroundTexture(pBaseTextTexture),
	m_pSelectedIconTexture(pSelectedIconTexture),
	m_ItemName(item),
	m_AmountOfItems(amountOfItems)
{

}

void ItemInteract::Update(float deltaTime, Player* player)
{
	if (!m_InitializeInventoryFlag)
	{
		m_InitializeInventoryFlag = true;
		m_pPlayerInventory = player->GetInventory();
	}
	m_IsColliding = utils::IsOverlapping(m_CollisionBoxes[0].GetRect(), player->GetInteractCollisionRect());
}

void ItemInteract::Draw(const Vector2f& camera) const
{
	if (m_IsActivated) {
		m_pBaseTextBackGroundTexture->Draw(Point2f());
		for (int i{}; i < m_TextTextures.size();++i)
		{
			m_TextTextures[i]->Draw(m_TextLocations[i].ToPoint2f());
		}
		const Vector2f selectedPosition = m_TextLocations[m_CurrentSelectedOption + 1] + Vector2f{-20,15};
		m_pSelectedIconTexture->Draw(selectedPosition.ToPoint2f());
	}
}

void ItemInteract::ButtonUpManager(const SDL_KeyboardEvent& e)
{
	if (m_IsColliding && m_AmountOfItems > 0)
	{
		switch(e.keysym.sym)
		{
		case(SDLK_RETURN):
		case(SDLK_z):
			if (m_IsActivated)
			{
				OnInteract();
				SoundManager::GetInstance().PlaySoundEffect("select");
			}
			else
			{
				m_IsActivated = true;
				m_CurrentSelectedOption = 0;
			}
			break;
		case(SDLK_LEFT):
		case(SDLK_a):
			if (m_IsActivated && m_CurrentSelectedOption == 1)
			{
				--m_CurrentSelectedOption;
				SoundManager::GetInstance().PlaySoundEffect("changeSelection");
			}
			break;
		case(SDLK_RIGHT):
		case(SDLK_d):
			if (m_IsActivated && m_CurrentSelectedOption == 0)
			{
				++m_CurrentSelectedOption;
				SoundManager::GetInstance().PlaySoundEffect("changeSelection");
			}
			break;
		}
	}
}

void ItemInteract::OnInteract()
{
	if (m_CurrentSelectedOption == 0 && m_AmountOfItems > 0)
	{
		m_pPlayerInventory->InputItem(m_ItemName);
		--m_AmountOfItems;
		
	}
	m_IsActivated = false;
}


