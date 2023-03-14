#include "pch.h"
#include "SpriteManager.h"
#include "AnimatedSprite.h"
#include <map>


SpriteManager::SpriteManager()
{
	m_pCharaTexture = new Texture{ "Sprites/chara.png" };
	m_pPlayerHeartTexture = new Texture{ "Sprites/PLayerHeart.png" };
	m_pPlayerHeartAnimTexture = new Texture{ "Sprites/PlayerHeartAnims.png" };
	m_pFightBackGrounds = new Texture{ "Static_Screens/FightBackGrounds.png" };


	std::map<std::string, AnimationData> CharaData{
		{"down"	  ,AnimationData{1,4}},
		{"downIdle" ,AnimationData{1,1}},
		{"left"	  ,AnimationData{2,2}},
		{"leftIdle" ,AnimationData{2,1}},
		{"right"	  ,AnimationData{3,2}},
		{"rightIdle",AnimationData{3,1}},
		{"up"		  ,AnimationData{4,4}},
		{"upIdle"   ,AnimationData{4,1}}
	};
	std::map<std::string, AnimationData> playerHeartAnimData{
		{"death",AnimationData{1,1}},
		{"flee" ,AnimationData{3,2}}
	};
	m_pAnimatedSprites.push_back(new AnimatedSprite{ m_pCharaTexture,CharaData,19,29,"downIdle",0.2f});
	m_pAnimatedSprites.push_back(new AnimatedSprite{ m_pPlayerHeartAnimTexture,playerHeartAnimData,20,24,"",0.2f});

	m_pStaticTextures.push_back(m_pPlayerHeartTexture);
	m_pStaticTextures.push_back(m_pFightBackGrounds);
}

SpriteManager::~SpriteManager()
{
	for (int index{}; index < m_pAnimatedSprites.size(); index++)
	{
		delete m_pAnimatedSprites[index];
	}
}

void SpriteManager::Draw()
{
	//for (AnimatedSprite* data :m_pAnimatedSprites)
	//{
		//data->Draw();
	//}
}

void SpriteManager::Update(float deltaTime)
{
	for (AnimatedSprite* data : m_pAnimatedSprites)
	{
		data->Update(deltaTime);
	}
}


