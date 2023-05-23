#pragma once
#include "Interactable.h"
class Door;

class GroundFall final: public Interactable 
{
public:
	GroundFall(const CollisionBox& collision, const std::string& destinationRoom);

	void Update(float deltaTime, Player* player);
	void OnInteract();
	void Draw() const;
protected:
	std::string m_destinationRoom{};
};

