#pragma once
#include "Interactable.h"


class Texture;

class TextInteract final : public Interactable
{
public:
	TextInteract(const Rectf& collisionRect,Texture* pBaseTextTexture, const std::vector<Texture*>& pTextTextures);

	void Update(float deltaTime, Player* player);
	void Draw() const;
	void OnInteract();

private:
	std::vector<Texture*> m_pTextTextures{};
	Texture* m_pBaseTextBackGroundTexture{};
	int m_CurrentTextPage{};
	int m_AmountOfTextPages{};
	float m_MinimumTextReadTime{1};
	float m_CurrentTextReadTime{m_MinimumTextReadTime};
};

