#pragma once
#include "CollisionBox.h"


class Player;

class Interactable
{
public:
	Interactable() = delete;
	Interactable(const CollisionBox& collision, bool isSollid);
	virtual ~Interactable() =default;


	virtual void OnInteract() = 0;
	virtual void Update(float deltaTime, Player* player) = 0;
	virtual void Draw() const = 0;

	CollisionBox GetCollisionBox() const;
	bool GetSollidity() const;

protected:
	CollisionBox m_CollisionBox;
	bool m_IsSollid{};
};

