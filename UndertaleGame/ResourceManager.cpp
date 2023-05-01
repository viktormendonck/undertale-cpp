#include "pch.h"
#include "ResourceManager.h"
#include "AnimatedSprite.h"
#include <map>


ResourceManager::ResourceManager()
{
	//player
	m_pCharaTexture = new Texture{ "Sprites/chara.png" };
	m_pPlayerHeartTexture = new Texture{ "Sprites/PLayerHeart.png" };
	m_pPlayerHeartAnimTexture = new Texture{ "Sprites/PlayerHeartAnims.png" };
	m_pFightBackGrounds = new Texture{ "Static_Screens/FightBackGrounds.png" };
	//froggit
	m_pFroggitLeapAttackTexture = new Texture{ "Sprites/Froggit/JumpAttack.png" };
	m_pFroggitFlyAttackTexture = new Texture{ "Sprites/Froggit/flyAttack.png" };
	m_pFroggitHead = new Texture{ "Sprites/Froggit/head.png" };
	m_pFroggitBody = new Texture{ "Sprites/Froggit/body.png" };
	m_pFroggitDeath = new Texture{ "Sprites/Froggit/death.png" };
	//loox
	m_pLoox = new Texture{ "Sprites/Loox/loox.png" };
	m_pLooxDeath = new Texture{ "Sprites/loox/death.png" };
	m_pLooxAttack = new Texture{ "Sprites/loox/bullet.png" };
	//migosp
	m_pMigosp = new Texture{ "Sprites/migosp/migosp.png"};
	m_pMigospDeath = new Texture{ "Sprites/migosp/death.png"};
	m_pMigospAttack1 = new Texture{ "Sprites/migosp/bullet1.png"};
	m_pMigospAttack2 = new Texture{ "Sprites/migosp/bullet2.png"};
	//moldsmal
	m_pMoldsmal = new Texture{ "Sprites/Moldsmal/moldsmal.png" };
	m_pMoldsmalAttack = new Texture{ "Sprites/Moldsmal/bullet.png" };
	//Vegetoid
	m_pVegetoid = new Texture{ "Sprites/Vegetoid/vegetoid.png" };
	m_pVegetoidDeath = new Texture{ "Sprites/Vegetoid/death.png" };
	m_pVegetoidAttack = new Texture{ "Sprites/Vegetoid/bullet.png" };
	m_pVegetoidHeal = new Texture{ "Sprites/Vegetoid/heal.png" };
	//Whimsun
	m_pWhimsun = new Texture{ "Sprites/Whimsun/whimsun.png" };
	m_pWhimsunDeath = new Texture{ "Sprites/Whimsun/death.png" };
	m_pWhimsunAttack = new Texture{ "Sprites/Whimsun/attack.png" };

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
	std::map<std::string, AnimationData> froggitAnimData{
		{"live",AnimationData{1,2}}
	};
	std::map<std::string, AnimationData> LooxAnimData{
		{"live",AnimationData{1,5}}
	};
	std::map<std::string, AnimationData> migospAnimData{
		{"live",AnimationData{1,2}}
	};
	std::map<std::string, AnimationData> moldsmalAnimData{
		{"live",AnimationData{1,1}}
	};
	std::map<std::string, AnimationData> vegetoidAnimData{
		{"live",AnimationData{1,4}}
	};
	std::map<std::string, AnimationData> whimsunAnimData{
		{"live",AnimationData{1,2}}
	};


	m_AnimatedSprites.push_back(new AnimatedSprite{ m_pCharaTexture,CharaData,19,29,"downIdle",0.2f});
	m_AnimatedSprites.push_back(new AnimatedSprite{ m_pPlayerHeartAnimTexture,playerHeartAnimData,20,24,"",0.2f});
	m_AnimatedSprites.push_back(new AnimatedSprite{ m_pFroggitBody,froggitAnimData,92,48,"live",0.5f });
	m_AnimatedSprites.push_back(new AnimatedSprite(m_pLoox, LooxAnimData, 100, 116, "live", 0.2f));
	m_AnimatedSprites.push_back(new AnimatedSprite(m_pMigosp, migospAnimData,72, 96, "live", 0.2f));
	m_AnimatedSprites.push_back(new AnimatedSprite(m_pMoldsmal, moldsmalAnimData,102, 84, "live", FLT_MAX));
	m_AnimatedSprites.push_back(new AnimatedSprite(m_pVegetoid, vegetoidAnimData,72, 104, "live", 0.2f));
	m_AnimatedSprites.push_back(new AnimatedSprite(m_pWhimsun, whimsunAnimData,72, 104, "live", 0.2f));
	std::map<std::string, AnimationData> froggitLeapAttackAnimData{
		{"charging",AnimationData{1,1}},
		{"jumping" ,AnimationData{2,1}}
	};
	std::map<std::string, AnimationData> froggitFlyAttackAnimData{
		{"fly",AnimationData{1,2}}
	};
	std::map<std::string, AnimationData> looxAttackAnimData{
		{"big",AnimationData{3,1}},
		{"medium",AnimationData{2,1}},
		{"small",AnimationData{1,1}}
	};
	std::map<std::string, AnimationData> migospAttackAnimData{
		{"fly",AnimationData{1,2}}
	};
	std::map<std::string, AnimationData> migospAttack2AnimData{
		{"life",AnimationData{1,16}}
	};
	std::map<std::string, AnimationData> moldsmalAttackAnimData{
		{"big",AnimationData{2,1}},
		{"small",AnimationData{1,1}}
	};
	std::map<std::string, AnimationData> vegetoidAttackAnimData{
		{"veg",AnimationData{1,1}},
		{"veg1",AnimationData{2,1}},
		{"veg2",AnimationData{3,1}},
		{"veg3",AnimationData{4,1}},
		{"veg4",AnimationData{5,1}},
		{"veg5",AnimationData{6,1}},
		{"veg6",AnimationData{7,1}}

	};
	std::map<std::string, AnimationData> vegetoidHealAnimData{
		{"heal",AnimationData{1,7}}
	};
	std::map<std::string, AnimationData> whimsumAttackAnimData{
		{"attack",AnimationData{1,2}}
	};

	m_BulletAnimatedSprites.push_back(new AnimatedSprite{ m_pFroggitLeapAttackTexture,froggitLeapAttackAnimData,40,38,"charging", FLT_MAX});
	m_BulletAnimatedSprites.push_back(new AnimatedSprite{ m_pFroggitFlyAttackTexture,froggitFlyAttackAnimData,8,6,"fly",0.075f });
	m_BulletAnimatedSprites.push_back(new AnimatedSprite{ m_pLooxAttack, looxAttackAnimData ,14 ,14 , "big", 0.5f });
	m_BulletAnimatedSprites.push_back(new AnimatedSprite{ m_pMigospAttack1, migospAttackAnimData ,16 ,16 , "fly", 0.5f });
	m_BulletAnimatedSprites.push_back(new AnimatedSprite{ m_pMigospAttack2, migospAttack2AnimData ,32 ,32 , "live", 0.5f });
	m_BulletAnimatedSprites.push_back(new AnimatedSprite{ m_pMoldsmalAttack, moldsmalAttackAnimData ,12 ,12 , "big", 0.5f });
	m_BulletAnimatedSprites.push_back(new AnimatedSprite{ m_pVegetoidAttack, vegetoidAttackAnimData ,24 ,24 , "veg", 0.5f });
	m_BulletAnimatedSprites.push_back(new AnimatedSprite{ m_pVegetoidHeal, vegetoidHealAnimData ,24 ,24 , "heal", 0.5f });
	m_BulletAnimatedSprites.push_back(new AnimatedSprite{ m_pWhimsunAttack, whimsumAttackAnimData ,15 ,15 , "attack", 0.5f });

	m_StaticEnemyTextures.push_back(m_pFroggitHead);
	m_StaticEnemyTextures.push_back(m_pFroggitDeath);
	m_StaticEnemyTextures.push_back(m_pLooxDeath);
	m_StaticEnemyTextures.push_back(m_pMigospDeath);
	m_StaticEnemyTextures.push_back(m_pMoldsmal);
	m_StaticEnemyTextures.push_back(m_pVegetoidDeath);
	m_StaticEnemyTextures.push_back(m_pWhimsunDeath);

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
	for (Texture* pTexture : m_StaticEnemyTextures)
	{
		delete pTexture;
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
	for (AnimatedSprite* data : m_BulletAnimatedSprites)
	{
		data->Update(deltaTime);
	}

}


