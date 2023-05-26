#include "pch.h"
#include "Interactable.h"

Interactable::Interactable(const CollisionBox& collision, bool isSollid)
	:
	m_IsSollid(isSollid)
{
	m_CollisionBoxes.push_back(collision);
}


std::vector<CollisionBox> Interactable::GetCollisionBox() const
{
	return m_CollisionBoxes;
}

bool Interactable::IsSollid() const
{
	return m_IsSollid;
}
