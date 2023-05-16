#pragma once
#include <vector>
#include "Texture.h"

class AnimatedSprite;


class ResourceManager final
{
public:
	ResourceManager(std::string playerName);
	~ResourceManager();

	ResourceManager(const ResourceManager& other) = delete; // Copy constructor
	ResourceManager& operator=(const ResourceManager& other) = delete; // Copy assignment operator

	ResourceManager(ResourceManager&& other) = delete; // Move constructor
	ResourceManager& operator=(ResourceManager&& other) = delete; // Move assignment operator


	void Update(float deltaTime);

	std::vector<AnimatedSprite*> m_AnimatedSprites{};
	std::vector<AnimatedSprite*> m_BulletAnimatedSprites{};
	std::vector<AnimatedSprite*> m_UiElementSprites{};
	std::vector<AnimatedSprite*> m_MiscAnimatedSprites{};
	std::vector<Texture*> m_StaticTextures{};
	std::vector<Texture*> m_StaticEnemyTextures{};
	std::vector<Texture*> m_TextTextures{};
	std::vector<Texture*> m_FroggitTextTextures{};
	std::vector<Texture*> m_LooxTextTextures{};
	std::vector<Texture*> m_RoomTextures{};
	std::vector<Texture*> m_RoomCorrectionTiles{};
	std::vector<Texture*> m_ItemTextTextures{};

private:
	
};

