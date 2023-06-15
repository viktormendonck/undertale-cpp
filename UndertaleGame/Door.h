#pragma once
#include "CollisionBox.h"

class Door final
{
public:
	Door(Rectf doorCollider,std::string destination, Vector2f spawnLocation);

	std::string GetDestination();
	bool IsColliding(const Rectf& player) const;
	Vector2f GetExitLocation() const;
private:
	const CollisionBox m_DoorCollider{};
	const std::string m_Destination{};
	const Vector2f m_ExitLocation{};
};

