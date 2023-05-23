#include "pch.h"
#include "CollisionBox.h"

#include <iostream>

#include "utils.h"

CollisionBox::CollisionBox()
	: CollisionBox(Rectf())
{
}

CollisionBox::CollisionBox(Rectf rect)
	: m_Rect{ rect }
{
}
//rule of 5 
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

void CollisionBox::SetLocation(const Vector2f& delta)
{
	m_Rect.left = delta.x;
	m_Rect.bottom = delta.y;
}


std::pair<bool, Vector2f> CollisionBox::SideCollisions(CollisionBox collider, Rectf player)
{
	float offsetMultiplier{1.1f};
	Vector2f closestCorrection{ 10000,10000 };
	bool collided{};
	if (utils::IsOverlapping(collider.GetBottom(), player))
	{
		float tempDistance{ collider.GetBottom().point1.y - (player.bottom + player.height) };
		if (abs(closestCorrection.y) > abs(tempDistance) || abs(closestCorrection.x) > abs(tempDistance))
		{
			closestCorrection = Vector2f(0, tempDistance * offsetMultiplier);
		}
		collided = true;
	}
	if (utils::IsOverlapping(collider.GetTop(), player))
	{
		float tempDistance{ collider.GetTop().point1.y - player.bottom };
		if (abs(closestCorrection.y) > abs(tempDistance) || abs(closestCorrection.x) > abs(tempDistance))
		{
			closestCorrection = Vector2f(0, tempDistance * offsetMultiplier);
		}
		collided = true;
	}
	if (utils::IsOverlapping(collider.GetLeft(), player))
	{
		float tempDistance{ collider.GetLeft().point1.x - (player.left + player.width) };
		if (abs(closestCorrection.x) > abs(tempDistance) || abs(closestCorrection.y) > abs(tempDistance))
		{
			closestCorrection = Vector2f(tempDistance * offsetMultiplier, 0);
		}
		collided = true;
	}
	if (utils::IsOverlapping(collider.GetRight(), player))
	{
		float tempDistance{ collider.GetRight().point1.x - player.left };
		if (abs(closestCorrection.x) > abs(tempDistance) || abs(closestCorrection.y) > abs(tempDistance))
		{
			closestCorrection = Vector2f(tempDistance * offsetMultiplier, 0);
		}
		collided = true;
	}
	/*if (utils::IsOverlapping(collider.GetBottom(), player))
	{
		float tempDistance{ collider.GetBottom().point1.y - (player.bottom + player.height) };
		if (abs(closestCorrection.y) >abs(tempDistance) && closestCorrection.y != 0)
		{
			closestCorrection = Vector2f(0, tempDistance*offsetMultiplier);
		}
		collided = true;
	}
	if (utils::IsOverlapping(collider.GetTop(), player))
	{
		float tempDistance{ collider.GetTop().point1.y - player.bottom };
		if (abs(closestCorrection.y) > abs(tempDistance) && closestCorrection.y != 0)
		{
			closestCorrection = Vector2f(0, tempDistance * offsetMultiplier);
		}
		collided = true;
	}
	if (utils::IsOverlapping(collider.GetLeft(), player))
	{
		float tempDistance{ collider.GetLeft().point1.x - (player.left + player.width) };
		if (abs(closestCorrection.x) > abs(tempDistance) && closestCorrection.x != 0)
		{
			closestCorrection = Vector2f(tempDistance * offsetMultiplier, 0);
		}
		collided = true;
	}
	if (utils::IsOverlapping(collider.GetRight(), player))
	{
		float tempDistance{ collider.GetRight().point1.x - player.left };
		if (abs(closestCorrection.x) > abs(tempDistance) && closestCorrection.x != 0)
		{
			closestCorrection = Vector2f(tempDistance * offsetMultiplier, 0);
		}
		collided = true;
	}*/
	return { collided,closestCorrection };
}

