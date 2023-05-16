#include "pch.h"
#include "Interactable.h"

Interactable::Interactable(CollisionBox collision, bool isSollid)
	:
	m_Collision(collision),
	m_IsSollid(isSollid)
{
}

CollisionBox Interactable::GetCollisionBox() const
{
	return m_Collision;
}

bool Interactable::GetSollidity() const
{
	return m_IsSollid;
}
