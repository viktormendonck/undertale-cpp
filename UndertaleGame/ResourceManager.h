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
private:
	Texture* m_pCharaTexture{};
	Texture* m_pPlayerHeartTexture{};
	Texture* m_pPlayerHeartAnimTexture{};
	Texture* m_pFroggitLeapAttackTexture{};
	Texture* m_pFroggitFlyAttackTexture{};
	Texture* m_pFightBackGrounds{};
	Texture* m_pFont{};
};

