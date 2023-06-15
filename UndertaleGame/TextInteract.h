#pragma once
#include "Interactable.h"


class Texture;

class TextInteract final : public Interactable
{
public:
	TextInteract(const Rectf& collisionRect,Texture* pBaseTextTexture, const std::vector<Texture*>& pTextTextures);

	void Update(float deltaTime, Player* player);
	void Draw(const Vector2f& camera) const;
	void ButtonUpManager(const SDL_KeyboardEvent& e);

private:
	void OnInteract();
	const std::vector<Texture*> m_pTextTextures{};
	const Texture* m_pBaseTextBackGroundTexture{};
	int m_CurrentTextPage{};
	const int m_AmountOfTextPages{};
	bool m_IsColliding{};
};

