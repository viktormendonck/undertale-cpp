#pragma once
#include <vector>

#include "Vector2f.h"

class CollisionBox final
{
public:
	CollisionBox();
	CollisionBox(Rectf rect);
	~CollisionBox();

	CollisionBox(const CollisionBox& other); // Copy constructor
	CollisionBox& operator=(const CollisionBox& other) noexcept; // Copy assignment operator

	CollisionBox(CollisionBox&& other) noexcept; // Move constructor
	CollisionBox& operator=(CollisionBox&& other) noexcept; // Move assignment operator

	Rectf GetRect() const;
	Linef GetBottom() const;
	Linef GetLeft() const;
	Linef GetRight() const;
	Linef GetTop() const;
	Vector2f GetLocation() const;
	void SetLocation(Vector2f delta);

	static std::pair<bool, Vector2f> SideCollisions(CollisionBox collider, Rectf player);

private:
	Rectf m_Rect;
	
};

