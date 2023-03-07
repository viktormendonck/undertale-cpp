#pragma once
#include <vector>
#include "Texture.h"

class AnimatedSprite;


class SpriteManager
{
public:
	SpriteManager();
	~SpriteManager();

	void Draw();
	void Update(float deltaTime);

	std::vector<AnimatedSprite*> m_pAnimatedSprites{};
private:
	Texture* m_pCharaTexture{};
	Texture* m_pTorielTexture{};




};

