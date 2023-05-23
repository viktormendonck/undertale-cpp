#pragma once
#include "Interactable.h"


class Texture;

class TextInteract final : public Interactable
{
public:
	TextInteract(const Rectf& collisionRect, const std::vector<Texture*>& pTextTextures);

	void Update(float deltaTime, Player* player);
	void Draw() const;
	void OnInteract();

private:
	std::vector<Texture*> m_pTextTextures;
	int m_CurrentTextPage{};
};

