#pragma once
#include "CollisionBox.h"


class Interactable
{
public:
	Interactable() = delete;
	Interactable(CollisionBox collision, bool isSollid);

	virtual void OnInteract() = 0;

	CollisionBox GetCollisionBox() const;
	bool GetSollidity() const;

protected:
	CollisionBox m_Collision;
	bool m_IsSollid{};
};

