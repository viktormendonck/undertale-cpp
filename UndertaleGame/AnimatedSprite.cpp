#include "pch.h"
#include "AnimatedSprite.h"


AnimatedSprite::AnimatedSprite(Texture* pTexture, std::map<std::string, AnimationData> animationData, int width, int height, std::string startAnim, float timeBetweenFrames)
	: m_pTexture{ pTexture },
	m_AnimationData{ animationData },
	m_width{ width },
	m_height{ height },
	m_CurrentAnimation{ startAnim },
	m_TimeBetweenFrames{timeBetweenFrames}
{
	m_TimeUntilNextFrame = m_TimeBetweenFrames;
}



AnimatedSprite::~AnimatedSprite()
{
	delete m_pTexture;
}

void AnimatedSprite::Draw(Vector2f pos)
{
	Rectf srcRect
	{
		static_cast<float>(m_CurrentFrame * m_width),
		static_cast<float>(m_AnimationData[m_CurrentAnimation].rowIndex * m_height),
		static_cast<float>(m_width),static_cast<float>(m_height)
	};
	m_pTexture->Draw(pos.ToPoint2f(), srcRect);

}

void AnimatedSprite::Update(float deltaTime)
{
	if (m_AnimationData[m_CurrentAnimation].spriteCount > 0) {
		if (m_TimeUntilNextFrame <= 0)
		{
			m_TimeUntilNextFrame = m_TimeBetweenFrames;
			m_CurrentFrame = (m_CurrentFrame + 1) % m_AnimationData[m_CurrentAnimation].spriteCount;
		}
		else
		{
			m_TimeUntilNextFrame -= deltaTime;
		}
	}
}

void AnimatedSprite::SetAnimation(const std::string& animationName)
{
	if (m_AnimationData.find(animationName) == m_AnimationData.end())
	{
		return;
	}
	m_CurrentAnimation = animationName;
	m_CurrentFrame = 0;
	m_TimeUntilNextFrame = m_TimeBetweenFrames;
}

std::string AnimatedSprite::GetCurrentAnimation()
{
	return m_CurrentAnimation;
}
