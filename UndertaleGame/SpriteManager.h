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
	std::vector<Texture*> m_pStaticTextures{};
private:
	Texture* m_pCharaTexture{};
	Texture* m_pPlayerHeartTexture{};
	Texture* m_pPlayerHeartAnimTexture{};
	Texture* m_pFightBackGrounds{};





};

