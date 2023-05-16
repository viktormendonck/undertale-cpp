#pragma once
#include "CollisionBox.h"

class Door
{
public:
	Door(Rectf doorCollider,std::string destination, Vector2f spawnLocation);

	std::string GetDestination();
	bool IsColliding(Rectf player) const;
	Vector2f GetExitLocation();
private:
	CollisionBox m_DoorCollider{};
	std::string m_Destination{};
	Vector2f m_ExitLocation{};
};

