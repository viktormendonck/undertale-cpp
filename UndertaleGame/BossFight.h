#pragma once
#include "Interactable.h"

class Texture;

class BossFight final : public Interactable
{
public:
	BossFight(const CollisionBox& collision, bool isSollid,Texture* texture);

	void Update(float deltaTime, Player* player);
	void Draw(const Vector2f& camera) const;
	void ButtonUpManager(const SDL_KeyboardEvent& e);

private:
	void OnInteract();

	Texture* m_pTexture{};
	bool m_IsActivated{};
	bool m_IsColliding{};
	bool m_HasTransmitted{};
};

