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
	AnimatedSprite(Texture* pTexture, std::map<std::string,AnimationData> animationData,int width, int height, std::string startAnim,float timeBetweenFrames);
	~AnimatedSprite();

	AnimatedSprite(const AnimatedSprite& other) = delete; // Copy constructor
	AnimatedSprite& operator=(const AnimatedSprite& other) = delete; // Copy assignment operator

	AnimatedSprite(AnimatedSprite&& other) = delete; // Move constructor
	AnimatedSprite& operator=(AnimatedSprite&& other) = delete; // Move assignment operator

	void Draw(Vector2f pos);
	void Update(float deltaTime);

	void SetAnimation(const std::string& animationName);
	std::string GetCurrentAnimation();
	float GetWidth();
	float GetHeight();


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

