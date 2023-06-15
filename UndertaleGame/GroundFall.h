#pragma once
#include "Interactable.h"
class Door;

class GroundFall final: public Interactable 
{
public:
	GroundFall(const CollisionBox& collision, const std::string& destinationRoom);

	void Update(float deltaTime, Player* player);
	void Draw(const Vector2f&) const;
	void ButtonUpManager(const SDL_KeyboardEvent& e);
protected:
	void OnInteract();
	const std::string m_destinationRoom{};
};

