#include "pch.h"
#include "SpriteManager.h"
#include "AnimatedSprite.h"
#include <map>


SpriteManager::SpriteManager()
{
	m_pCharaTexture = new Texture{ "Sprites/chara.png" };
	std::map<std::string, AnimationData> animData{
		{"down"	  ,AnimationData{1,4}},
		{"downIdle" ,AnimationData{1,1}},
		{"left"	  ,AnimationData{2,2}},
		{"leftIdle" ,AnimationData{2,1}},
		{"right"	  ,AnimationData{3,2}},
		{"rightIdle",AnimationData{3,1}},
		{"up"		  ,AnimationData{4,4}},
		{"upIdle"   ,AnimationData{4,1}}
	};
	m_pAnimatedSprites.push_back(new AnimatedSprite{ m_pCharaTexture,animData,19,29,"downIdle",0.2f});
	
}

SpriteManager::~SpriteManager()
{

}

void SpriteManager::Draw()
{
	for (AnimatedSprite* data :m_pAnimatedSprites)
	{
		data->Draw();
	}
}

void SpriteManager::Update(float deltaTime)
{
	for (AnimatedSprite* data : m_pAnimatedSprites)
	{
		data->Update(deltaTime);
	}
}


