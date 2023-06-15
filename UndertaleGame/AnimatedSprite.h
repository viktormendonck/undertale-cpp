#pragma once
#include "Texture.h"
#include "Vector2f.h"
#include <map>

struct AnimationData
{

	int rowIndex{};
	int spriteCount{};

};

class AnimatedSprite final
{
public:
	AnimatedSprite(Texture* pTexture, std::map<std::string,AnimationData> animationData,int width, int height, std::string startAnim,float timeBetweenFrames);
	~AnimatedSprite();

	AnimatedSprite(const AnimatedSprite& other) = delete; // Copy constructor
	AnimatedSprite& operator=(const AnimatedSprite& other) = delete; // Copy assignment operator

	AnimatedSprite(AnimatedSprite&& other) = delete; // Move constructor
	AnimatedSprite& operator=(AnimatedSprite&& other) = delete; // Move assignment operator

	void Draw(const Vector2f& pos);
	void Update(float deltaTime);

	void SetAnimation(const std::string& animationName);
	const std::string& GetCurrentAnimation() const;
	float GetWidth() const;
	float GetHeight() const;
	Rectf GetRect() const;
	void ResetAnim();


private:

	Texture* m_pTexture;
	std::map<std::string, AnimationData> m_AnimationData;

	const int m_Width;
	const int m_Height;
	std::string m_CurrentAnimation{};
	int m_CurrentFrame{};
	const float m_TimeBetweenFrames{};
	float m_TimeUntilNextFrame{};
};

