#pragma once
#include <vector>

#include "Interactable.h"
#include "Vector2f.h"
class Inventory;
class Item;
class Player;
class Texture;

class ItemInteract final : public Interactable
{
public:
	ItemInteract(const Rectf& collisionRect, Texture* pBaseTextTexture, std::vector<Texture*> pItemInteractTextures, Texture* pSelectedIconTexture, const std::string& item, int amountOfItems);

	void Update(float deltaTime, Player* player);
	void Draw(const Vector2f& camera) const;
	void ButtonUpManager(const SDL_KeyboardEvent& e);
	
private:
	void OnInteract();
	std::vector<Texture*> m_TextTextures{};
	Texture* m_pBaseTextBackGroundTexture{};
	Texture* m_pSelectedIconTexture{};
	std::vector<Vector2f> m_TextLocations{Vector2f{0,0},Vector2f{133,45},Vector2f{283,47}};
	Inventory* m_pPlayerInventory{};
	std::string m_ItemName{"empty"};
	int m_AmountOfItems{};

	int m_CurrentSelectedOption{};
	int m_AmountOfSelectOptions{};
	bool m_IsColliding{};
	bool m_IsActivated{};

	bool m_InitializeInventoryFlag{};
};

