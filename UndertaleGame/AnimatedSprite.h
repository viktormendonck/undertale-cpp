#pragma once
#include "Texture.h"
#include "Vector2f.h"
#include "Texture.h"
#include <vector>
#include <map>

struct AnimationData
{

	int rowIndex{};
	int spriteCount{};

};

class AnimatedSprite
{
public:
	AnimatedSprite(Texture* pTexture, std::map<std::string,AnimationData> animationData,int width, int height, std::string startAnim);
	~AnimatedSprite();

	void Draw();
	void Update(float deltaTime);
	void SetAnimation(const std::string& animationName);

	Vector2f m_pos{};

private:

	Texture* m_pTexture;
	std::map<std::string, AnimationData> m_AnimationData;

	int m_width;
	int m_height;
	std::string m_CurrentAnimation{};
	int m_CurrentFrame{};
	const float m_TimeBetweenFrames{.2f};
	float m_TimeUntilNextFrame{.2f};
};

