#include "pch.h"
#include "Interactable.h"

Interactable::Interactable(const CollisionBox& collision, bool isSolid)
	:
	m_IsSolid(isSolid)
{
	m_CollisionBoxes.push_back(collision);
}


bool Interactable::IsActivated()
{
	return m_IsActivated;
}

std::vector<CollisionBox> Interactable::GetCollisionBox() const
{
	return m_CollisionBoxes;
}

bool Interactable::IsSolid() const
{
	return m_IsSolid;
}
