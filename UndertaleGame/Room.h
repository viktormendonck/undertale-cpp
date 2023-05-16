#pragma once
#include <vector>


class Door;
class Interactable;
struct Vector2f;
class Texture;
class CollisionBox;

class Room final
{
public:
	explicit Room(std::string roomName, Texture* pRoomTex,std::vector<Door> doors, std::vector<Interactable*> interactables, bool spawnAble);
	Texture* GetTexture();
	std::vector<Door> GetDoors();
	void Draw() const;
private:
	std::string m_RoomName{};
	Texture* m_pTexture{};
	std::vector<Door> m_Doors;
	std::vector<Interactable*> m_Interactables;
	bool m_CanSpawnEnemies{};

};

