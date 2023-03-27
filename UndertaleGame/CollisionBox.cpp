#include "pch.h"
#include "CollisionBox.h"

CollisionBox::CollisionBox()
	: CollisionBox(Rectf())
{
}

CollisionBox::CollisionBox(Rectf rect)
	: m_Rect{rect}
{
	m_Bottom = Linef(Point2f(rect.left, rect.bottom), Point2f(rect.left + rect.width, rect.bottom));
	m_Left = Linef(Point2f(rect.left, rect.bottom), Point2f(rect.left, rect.bottom + rect.height));
	m_Right = Linef(Point2f(rect.left + rect.width , rect.bottom), Point2f(rect.left + rect.width, rect.bottom + rect.height));
	m_Top = Linef(Point2f(rect.left, rect.bottom+rect.height), Point2f(rect.left + rect.width, rect.bottom + rect.height));

}

CollisionBox::~CollisionBox()
{
}

CollisionBox::CollisionBox(const CollisionBox& other)
{
	m_Rect = other.m_Rect;
	m_Bottom = other.m_Bottom;
	m_Left = other.m_Left;
	m_Right = other.m_Right;
	m_Top = other.m_Top;
}

CollisionBox& CollisionBox::operator=(const CollisionBox& other) noexcept
{
	if (this != &other) { // check for self-assignment
		m_Rect = other.m_Rect;
		m_Bottom = other.m_Bottom;
		m_Left = other.m_Left;
		m_Right = other.m_Right;
		m_Top = other.m_Top;
	}
	return *this;
}


CollisionBox::CollisionBox(CollisionBox&& other)
{
	m_Rect = other.m_Rect;
	m_Bottom = other.m_Bottom;
	m_Left = other.m_Left;
	m_Right = other.m_Right;
	m_Top = other.m_Top;
}

CollisionBox& CollisionBox::operator=(CollisionBox&& other) noexcept
{
	if (this != &other) { // check for self-assignment
		m_Rect = other.m_Rect;
		m_Bottom = other.m_Bottom;
		m_Left = other.m_Left;
		m_Right = other.m_Right;
		m_Top = other.m_Top;
	}
	return *this;
}

Rectf CollisionBox::GetRect()
{
	return m_Rect;
}

Linef CollisionBox::GetBottom()
{
	return m_Bottom;
}

Linef CollisionBox::GetLeft()
{
	return m_Left;
}

Linef CollisionBox::GetRight()
{
	return m_Right;
}

Linef CollisionBox::GetTop()
{
	return m_Top;
}

