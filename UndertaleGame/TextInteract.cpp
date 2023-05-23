#include "pch.h"
#include "TextInteract.h"

TextInteract::TextInteract(const Rectf& collisionRect, const std::vector<Texture*>& pTextTextures)
	:
	Interactable(collisionRect,true),
	m_pTextTextures(pTextTextures)
{
}

void TextInteract::Update(float deltaTime, Player* player)
{


	const Uint8* state{ SDL_GetKeyboardState(nullptr) };
	if (state[SDL_SCANCODE_RETURN])
	{
		
	}
}

void TextInteract::Draw() const
{

}

void TextInteract::OnInteract()
{

}
