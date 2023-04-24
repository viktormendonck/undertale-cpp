#include "pch.h"
#include "CollisionBox.h"

#include "utils.h"

CollisionBox::CollisionBox()
	: CollisionBox(Rectf())
{
}

CollisionBox::CollisionBox(Rectf rect)
	: m_Rect{rect}
{
}

CollisionBox::~CollisionBox()
{
}

CollisionBox::CollisionBox(const CollisionBox& other)
{
	m_Rect = other.m_Rect;
}

CollisionBox& CollisionBox::operator=(const CollisionBox& other) noexcept
{
	if (this != &other) { // check for self-assignment
		m_Rect = other.m_Rect;
	}
	return *this;
}


CollisionBox::CollisionBox(CollisionBox&& other) noexcept
{
	m_Rect = other.m_Rect;
}

CollisionBox& CollisionBox::operator=(CollisionBox&& other) noexcept
{
	if (this != &other) { // check for self-assignment
		m_Rect = other.m_Rect;
	}
	return *this;
}

Rectf CollisionBox::GetRect() const
{
	return m_Rect;
}

Linef CollisionBox::GetBottom() const
{
	return Linef(Point2f(m_Rect.left, m_Rect.bottom), Point2f(m_Rect.left + m_Rect.width, m_Rect.bottom));
}

Linef CollisionBox::GetLeft() const
{
	return Linef(Point2f(m_Rect.left, m_Rect.bottom), Point2f(m_Rect.left, m_Rect.bottom + m_Rect.height));
	
}

Linef CollisionBox::GetRight() const
{
	return Linef(Point2f(m_Rect.left + m_Rect.width, m_Rect.bottom), Point2f(m_Rect.left + m_Rect.width, m_Rect.bottom + m_Rect.height));
}

Linef CollisionBox::GetTop() const
{
	return Linef(Point2f(m_Rect.left, m_Rect.bottom + m_Rect.height), Point2f(m_Rect.left + m_Rect.width, m_Rect.bottom + m_Rect.height));
}

Vector2f CollisionBox::GetLocation() const
{
	return Vector2f(m_Rect.left, m_Rect.bottom);
}

void CollisionBox::SetLocation(Vector2f delta)
{
	m_Rect.left = delta.x;
	m_Rect.bottom = delta.y;
}

std::pair<bool, Vector2f> CollisionBox::SideCollisions(std::vector<CollisionBox> colliders, Rectf player)
{
	Vector2f closestCorrection{100000,100000};
	bool collided{};
	for (int i{}; i<colliders.size();++i)
	{
		for (int i{}; i < colliders.size(); ++i)
		{
			if (utils::IsOverlapping(colliders[i].GetBottom(), player))
			{
				float tempDistance{ colliders[i].GetBottom().point1.y - (player.bottom + player.height) };
				if ((abs(closestCorrection.x) >abs(tempDistance) && closestCorrection.x != 0) || (abs(closestCorrection.y) > abs(tempDistance) && closestCorrection.y != 0))
				{
					closestCorrection = Vector2f(0, tempDistance);
				}
				tempDistance = colliders[i].GetBottom().point1.y - player.bottom;
				if ((abs(closestCorrection.x) > abs(tempDistance) && closestCorrection.x != 0) || (abs(closestCorrection.y) > abs(tempDistance) && closestCorrection.y != 0))
				{
					closestCorrection = Vector2f(0, tempDistance);
				}
				collided = true;
			}
			if (utils::IsOverlapping(colliders[i].GetTop(), player))
			{
				float tempDistance{ colliders[i].GetTop().point1.y - player.bottom };
				if ((abs(closestCorrection.x) > abs(tempDistance) && closestCorrection.x != 0) || (abs(closestCorrection.y) > abs(tempDistance) && closestCorrection.y != 0))
				{
					closestCorrection = Vector2f(0, tempDistance);
				}
				tempDistance = colliders[i].GetTop().point1.y - (player.bottom + player.height);
				if ((abs(closestCorrection.x) > abs(tempDistance) && closestCorrection.x != 0) || (abs(closestCorrection.y) > abs(tempDistance) && closestCorrection.y != 0))
				{
					closestCorrection = Vector2f(0, tempDistance);
				}
				collided = true;
			}
			if (utils::IsOverlapping(colliders[i].GetLeft(), player))
			{
				float tempDistance{ colliders[i].GetLeft().point1.x - (player.left + player.width) };
				if ((abs(closestCorrection.x) > abs(tempDistance) && closestCorrection.x != 0) || (abs(closestCorrection.y) > abs(tempDistance) && closestCorrection.y != 0))
				{
					closestCorrection = Vector2f(tempDistance, 0);
				}
				tempDistance = colliders[i].GetLeft().point1.x - player.left;
				if ((abs(closestCorrection.x) > abs(tempDistance) && closestCorrection.x != 0) || (abs(closestCorrection.y) > abs(tempDistance) && closestCorrection.y != 0))
				{
					closestCorrection = Vector2f(tempDistance, 0);
				}
				collided = true;
			}
			if (utils::IsOverlapping(colliders[i].GetRight(), player))
			{
				float tempDistance{ colliders[i].GetRight().point1.x - player.left };
				if ((abs(closestCorrection.x) > abs(tempDistance) && closestCorrection.x != 0) || (abs(closestCorrection.y) > abs(tempDistance) && closestCorrection.y != 0))
				{
					closestCorrection = Vector2f(tempDistance, 0);
				}
				tempDistance = colliders[i].GetRight().point1.x - (player.left + player.width);
				if ((abs(closestCorrection.x) > abs(tempDistance) && closestCorrection.x != 0) || (abs(closestCorrection.y) > abs(tempDistance) && closestCorrection.y != 0))
				{
					closestCorrection = Vector2f(tempDistance, 0);
				}
				collided = true;
			}
		}
	}
	return { collided,closestCorrection };
}

