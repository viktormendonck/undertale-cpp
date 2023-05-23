#include "pch.h"
#include "Interactable.h"

Interactable::Interactable(const CollisionBox& collision, bool isSollid)
	:
	m_CollisionBox(collision),
	m_IsSollid(isSollid)
{
}


CollisionBox Interactable::GetCollisionBox() const
{
	return m_CollisionBox;
}

bool Interactable::IsSollid() const
{
	return m_IsSollid;
}
