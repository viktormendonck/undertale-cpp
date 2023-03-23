#pragma once
#include <vector>
#include "Texture.h"

class AnimatedSprite;


class SpriteManager
{
public:
	SpriteManager();
	~SpriteManager();

	SpriteManager(const SpriteManager& other) = delete; // Copy constructor
	SpriteManager& operator=(const SpriteManager& other) = delete; // Copy assignment operator

	SpriteManager(SpriteManager&& other) = delete; // Move constructor
	SpriteManager& operator=(SpriteManager&& other) = delete; // Move assignment operator


	void Update(float deltaTime);

	std::vector<AnimatedSprite*> m_pAnimatedSprites{};
	std::vector<Texture*> m_pStaticTextures{};
private:
	Texture* m_pCharaTexture{};
	Texture* m_pPlayerHeartTexture{};
	Texture* m_pPlayerHeartAnimTexture{};
	Texture* m_pFightBackGrounds{};

};

