#pragma once
class CollisionBox
{
public:
	CollisionBox();
	CollisionBox(Rectf rect );
	~CollisionBox();

	CollisionBox(const CollisionBox& other); // Copy constructor
	CollisionBox& operator=(const CollisionBox& other) noexcept; // Copy assignment operator

	CollisionBox(CollisionBox&& other); // Move constructor
	CollisionBox& operator=(CollisionBox&& other) noexcept; // Move assignment operator

	Rectf GetRect();
	Linef GetBottom();
	Linef GetLeft();
	Linef GetRight();
	Linef GetTop();


private:
	Rectf m_Rect;
	Linef m_Bottom{};
	Linef m_Left{};
	Linef m_Right{};
	Linef m_Top{};
};

