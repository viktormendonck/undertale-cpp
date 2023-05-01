#pragma once
#include <vector>
#include "Texture.h"

class AnimatedSprite;


class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();

	ResourceManager(const ResourceManager& other) = delete; // Copy constructor
	ResourceManager& operator=(const ResourceManager& other) = delete; // Copy assignment operator

	ResourceManager(ResourceManager&& other) = delete; // Move constructor
	ResourceManager& operator=(ResourceManager&& other) = delete; // Move assignment operator


	void Update(float deltaTime);

	std::vector<AnimatedSprite*> m_AnimatedSprites{};
	std::vector<AnimatedSprite*> m_BulletAnimatedSprites{};
	std::vector<Texture*> m_StaticTextures{};
	std::vector<Texture*> m_StaticEnemyTextures{};
private:
	//player
	Texture* m_pCharaTexture{};
	Texture* m_pPlayerHeartTexture{};
	Texture* m_pPlayerHeartAnimTexture{};
	//froggit
	Texture* m_pFroggitLeapAttackTexture{};
	Texture* m_pFroggitFlyAttackTexture{};
	Texture* m_pFroggitBody{};
	Texture* m_pFroggitHead{};
	Texture* m_pFroggitDeath{};
	//loox
	Texture* m_pLoox{};
	Texture* m_pLooxDeath{};
	Texture* m_pLooxAttack{};
	//migosp
	Texture* m_pMigosp{};
	Texture* m_pMigospDeath{};
	Texture* m_pMigospAttack1{};
	Texture* m_pMigospAttack2{};
	//moldsmal
	Texture* m_pMoldsmal{};
	Texture* m_pMoldsmalAttack{};
	//Vegetoid
	Texture* m_pVegetoid{};
	Texture* m_pVegetoidDeath{};
	Texture* m_pVegetoidAttack{};
	Texture* m_pVegetoidHeal{};
	//Whimsun
	Texture* m_pWhimsun{};
	Texture* m_pWhimsunDeath{};
	Texture* m_pWhimsunAttack{};
	//extra
	Texture* m_pFightBackGrounds{};
	Texture* m_pFont{};
};

