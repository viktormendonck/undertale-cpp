#include "pch.h"
#include "ResourceManager.h"
#include "AnimatedSprite.h"
#include <map>


ResourceManager::ResourceManager()
{
	m_pCharaTexture = new Texture{ "Sprites/chara.png" };
	m_pPlayerHeartTexture = new Texture{ "Sprites/PLayerHeart.png" };
	m_pPlayerHeartAnimTexture = new Texture{ "Sprites/PlayerHeartAnims.png" };
	m_pFightBackGrounds = new Texture{ "Static_Screens/FightBackGrounds.png" };
	m_pFroggitLeapAttackTexture = new Texture{ "Sprites/Froggit/JumpAttack.png" };
	m_pFroggitFlyAttackTexture = new Texture{ "Sprites/Froggit/flyAttack" };


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
	m_AnimatedSprites.push_back(new AnimatedSprite{ m_pCharaTexture,CharaData,19,29,"downIdle",0.2f});
	m_AnimatedSprites.push_back(new AnimatedSprite{ m_pPlayerHeartAnimTexture,playerHeartAnimData,20,24,"",0.2f});
	std::map<std::string, AnimationData> FroggitLeapAttackAnimData{
		{"charging",AnimationData{1,1}},
		{"jumping" ,AnimationData{2,1}}
	};
	std::map<std::string, AnimationData> FroggitFlyAttackAnimData{
		{"fly",AnimationData{1,2}}
	};
	m_BulletAnimatedSprites.push_back(new AnimatedSprite{ m_pFroggitLeapAttackTexture,FroggitLeapAttackAnimData,40,38,"charging", FLT_MAX });
	m_BulletAnimatedSprites.push_back(new AnimatedSprite{ m_pFroggitFlyAttackTexture,FroggitFlyAttackAnimData,6,8,"fly",0.1f });

	m_StaticTextures.push_back(m_pPlayerHeartTexture);
	m_StaticTextures.push_back(m_pFightBackGrounds);
}

ResourceManager::~ResourceManager()
{
	for (AnimatedSprite* pAnimatedSprite : m_AnimatedSprites)
	{
		delete pAnimatedSprite;
	}
	for (AnimatedSprite* pBulletAnimatedSprite : m_BulletAnimatedSprites)
	{
		delete pBulletAnimatedSprite;
	}
	for (Texture* pTexture : m_StaticTextures)
	{
		delete pTexture;
	}

}


void ResourceManager::Update(float deltaTime)
{
	for (AnimatedSprite* data : m_AnimatedSprites)
	{
		data->Update(deltaTime);
	}
}


