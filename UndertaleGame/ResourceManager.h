#pragma once
#include <vector>
#include "Texture.h"

class AnimatedSprite;


class ResourceManager final
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
	
};

