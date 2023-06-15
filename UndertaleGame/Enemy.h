#pragma once
#include <vector>

#include "CollisionBox.h"
#include "Vector2f.h"

class Bullet;
class FightPlayer;
class Texture;
class AnimatedSprite;
class ResourceManager;

enum class EnemyType
{
	froggit,
	loox,
	napstablook
};

class Enemy
{
public:
	Enemy(int health, int conversationAmount, AnimatedSprite* baseTexture, Texture* deathTexture, bool isFlying, FightPlayer& player, CollisionBox collider,EnemyType type); // constructor
	Enemy() = delete; // default constructor
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

	void Converse();

	void Damage(int damage);
	bool IsDead() const;
	bool AreBulletsActive() const;
	void DeleteBullets();
	EnemyType GetEnemyType() const;

	Texture* GetDeathTexture() const;
	Vector2f GetPos() const;
	bool GetMercyAble() const;
	void ReduceConversationAmount();
	int GetMaxHealth() const;
	int GetHealth() const;

protected:
	int m_Hp;
	const int m_MaxHp;
	int m_ConversationAmount; // amount of times you have to do correct conversation inputs with this enemy to make giving them mercy possible
	AnimatedSprite* m_pTexture;
	Texture* m_pEnemyDeathTexture;
	Vector2f m_Pos{};

	const bool m_IsFlying;
	const float m_FlightOffset{118};
	const Point2f m_PossibleSpawnLocations[6]{ Point2f(19,244),Point2f(119,244) ,Point2f(222,244) ,Point2f(321,244) ,Point2f(424,244),Point2f(527,244)};
	FightPlayer& m_Player;
	std::vector<Bullet*> m_Bullets;
	const CollisionBox m_FightRectCollider;
	const EnemyType m_EnemyType{};
	bool m_IsMercyable{};
	
};

