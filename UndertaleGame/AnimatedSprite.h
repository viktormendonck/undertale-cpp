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
	float timeBetweenFrames{};

};

class AnimatedSprite
{
public:
	AnimatedSprite(Texture* pTexture, std::map<std::string,AnimationData> animationData,int width, int height, std::string startAnim,float timeBetweenFrames);
	~AnimatedSprite();

	void Draw();
	void Update(float deltaTime);
	void SetAnimation(const std::string& animationName);
	std::string GetCurrentAnimation();

	Vector2f m_pos{};

private:

	Texture* m_pTexture;
	std::map<std::string, AnimationData> m_AnimationData;

	int m_width;
	int m_height;
	std::string m_CurrentAnimation{};
	int m_CurrentFrame{};
	const float m_TimeBetweenFrames{};
	float m_TimeUntilNextFrame{};
};

