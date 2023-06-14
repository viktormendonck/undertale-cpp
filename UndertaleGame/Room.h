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
	explicit Room(const std::string& roomName, Texture* pRoomTex, Texture* pHoleTexture, const std::vector<Door>& doors, const std::vector<CollisionBox>& walls, const std::vector<Interactable*>& interactables, bool spawnAble);
	~Room();

	Room(const Room& other) = delete;
	Room& operator=(const Room& other) = delete;
	Room(Room&& other) = delete;
	Room& operator=(Room&& other) = delete;

	Texture* GetTexture();
	std::vector<Door> GetDoors();
	std::vector<CollisionBox> GetWalls();
	std::vector<Interactable*> GetInteractables();
	std::string GetName();
	bool GetSpawnable();
	void AddHole(const Vector2f& location);

	void Draw() const;
private:
	std::string m_RoomName{};
	Texture* m_pTexture{};
	Texture* m_pHoleTexture{};
	std::vector<Door> m_Doors;
	std::vector<CollisionBox> m_Walls;
	std::vector<Interactable*> m_Interactables;
	std::vector<Vector2f> m_HoleLocations{};
	bool m_CanSpawnEnemies{};

};

