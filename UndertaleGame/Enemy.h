#pragma once
#include <vector>

#include "CollisionBox.h"
#include "Vector2f.h"

class Bullet;
class FightChara;
class Texture;
class AnimatedSprite;
class ResourceManager;

enum class EnemyType
{
	froggit,
	loox/*,
	migosp,
	moldsmal,
	vegetoid,
	whimsum*/
};

class Enemy
{
public:
	Enemy() = delete; // default constructor
	Enemy(int health, int conversationAmount, AnimatedSprite* baseTexture, Texture* deathTexture, bool isFlying, FightChara& player, CollisionBox collider); // constructor
	virtual ~Enemy(); // destructor

	Enemy(const Enemy& other) = delete; // Copy constructor
	Enemy& operator=(const Enemy& other) = delete; // Copy assignment operator

	Enemy(Enemy&& other) = delete; // Move constructor
	Enemy& operator=(Enemy&& other) = delete; // Move assignment operator

	void Draw();
	virtual void DrawEnemy() = 0;
	void Update(float deltaTime);
	virtual void UpdateEnemy(float deltaTime) = 0;
	virtual void SpawnBullet(ResourceManager* resourceManager) = 0;

	void Damage(int damage);
	bool IsDead();
	bool AreBulletsActive();
	void DeleteBullets();

	Texture* GetDeathTexture();
	Vector2f GetPos();

protected:
	int m_hp;
	int m_ConversationAmount; // amount of times you have to do correct conversation inputs with this enemy to make giving them mercy possible
	AnimatedSprite* m_pTexture;
	Texture* m_pEnemyDeathTexture;
	Vector2f m_Pos{};

	const bool m_IsFlying;
	float m_FlightOffset{118};
	Point2f m_PossibleSpawnLocations[6]{ Point2f(19,244),Point2f(119,244) ,Point2f(222,244) ,Point2f(321,244) ,Point2f(424,244),Point2f(527,244)};
	FightChara& m_Player;
	std::vector<Bullet*> m_Bullets;
	CollisionBox m_Collider;
	
};

