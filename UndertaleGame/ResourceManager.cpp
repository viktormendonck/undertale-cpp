#include "pch.h"
#include "ResourceManager.h"
#include "AnimatedSprite.h"
#include <map>


ResourceManager::ResourceManager(std::string playerName)
{
	//player
	Texture* charaTexture = new Texture{ "Sprites/chara.png" };
	Texture* playerHeartTexture = new Texture{ "Sprites/PLayerHeart.png" };
	Texture* playerHeartAnimTexture = new Texture{ "Sprites/PlayerHeartAnims.png" };
	Texture* fightBackGrounds = new Texture{ "Static_Screens/FightBackGrounds.png" };
	//froggit
	Texture* froggitLeapAttackTexture = new Texture{ "Sprites/Froggit/JumpAttack.png" };
	Texture* froggitFlyAttackTexture = new Texture{ "Sprites/Froggit/flyAttack.png" };
	Texture* froggitHead = new Texture{ "Sprites/Froggit/head.png" };
	Texture* froggitBody = new Texture{ "Sprites/Froggit/body.png" };
	Texture* froggitDeath = new Texture{ "Sprites/Froggit/death.png" };
	//loox
	Texture* loox = new Texture{ "Sprites/Loox/loox.png" };
	Texture* looxDeath = new Texture{ "Sprites/loox/death.png" };
	Texture* looxAttackBig = new Texture{ "Sprites/loox/bullet.png" };
	//migosp
	//Texture* migosp = new Texture{ "Sprites/migosp/migosp.png"};
	//Texture* migospDeath = new Texture{ "Sprites/migosp/death.png"};
	//Texture* migospAttack1 = new Texture{ "Sprites/migosp/bullet1.png"};
	//Texture* migospAttack2 = new Texture{ "Sprites/migosp/bullet2.png"};
	////moldsmal
	//Texture* moldsmal = new Texture{ "Sprites/Moldsmal/moldsmal.png" };
	//Texture* moldsmalDeath = new Texture{ "Sprites/Moldsmal/moldsmal.png" };
	//Texture* moldsmalAttack = new Texture{ "Sprites/Moldsmal/bullet.png" };
	////Vegetoid
	//Texture* vegetoid = new Texture{ "Sprites/Vegetoid/vegetoid.png" };
	//Texture* vegetoidDeath = new Texture{ "Sprites/Vegetoid/death.png" };
	//Texture* vegetoidAttack = new Texture{ "Sprites/Vegetoid/bullet.png" };
	//Texture* vegetoidHeal = new Texture{ "Sprites/Vegetoid/heal.png" };
	////Whimsun
	//Texture* whimsun = new Texture{ "Sprites/Whimsun/whimsun.png" };
	//Texture* whimsunDeath = new Texture{ "Sprites/Whimsun/death.png" };
	//Texture* whimsunAttack = new Texture{ "Sprites/Whimsun/bullet.png" };
	Texture* fightButtonTexture = new Texture{ "UI/fightButton.png" };
	Texture* actButtonTexture = new Texture{ "UI/actButton.png" };
	Texture* itemButtonTexture = new Texture{ "UI/itemButton.png" };
	Texture* mercyButtonTexture = new Texture{ "UI/mercyButton.png" };

	Texture* fightMenuScreenTexture = new Texture{ "UI/fightTarget.png" };
	Texture* fightMenuPlayerBarTexture = new Texture{ "Sprites/Player/attackSelector.png" };
	Texture* playerAttackTexture = new Texture{ "Sprites/Player/attackAnim.png" };

	//text Textures

	Texture* playerNameTexture = new Texture{ playerName,"UI/determinationFont.ttf",30,Color4f{1,1,1,1} };
	Texture* playerHealthTexture = new Texture{ "20/20 Hp","UI/determinationFont.ttf",30,Color4f{1,1,1,1} };

	Texture* actCheckTexture = new Texture{ "* Check","UI/determinationFont.ttf",30,Color4f{1,1,1,1} };
	Texture* froggitActTexture1 = new Texture{ "* Compliment","UI/determinationFont.ttf",30,Color4f{1,1,1,1} };
	Texture* froggitActTexture2 = new Texture{ "* Threaten","UI/determinationFont.ttf",30,Color4f{1,1,1,1} };
	Texture* froggitCheckResponseTexture0 = new Texture{ "text/froggit/checkResponse.png" };
	Texture* froggitResponseTexture1 = new Texture{ "text/froggit/flatterResponse.png"};
	Texture* froggitResponseTexture2 = new Texture{  "text/froggit/insultResponse.png"};


	Texture* looxActTexture1 = new Texture{ "* Pick on","UI/determinationFont.ttf",30,Color4f{1,1,1,1} };
	Texture* looxActTexture2 = new Texture{ "* Don't pick on","UI/determinationFont.ttf",30,Color4f{1,1,1,1} };
	Texture* looxCheckResponseTexture0 = new Texture{ "text/loox/checkResponse.png" };
	Texture* looxResponseTexture1 = new Texture{ "You rude little snipe","UI/determinationFont.ttf",30,Color4f{1,1,1,1} };
	Texture* looxResponseTexture2 = new Texture{ "Finaly, someone gets it","UI/determinationFont.ttf",30,Color4f{1,1,1,1} };

	Texture* mercyTextTexture = new Texture{ "* Mercy","UI/determinationFont.ttf",30,Color4f{1,1,1,1} };
	Texture* fleeTextTexture = new Texture{ "* Flee","UI/determinationFont.ttf",30,Color4f{1,1,1,1} };

	//map locations and tiles
	Texture* room1Tex = new Texture{ "map/Room1.png" };
	Texture* room1_5Tex = new Texture{ "map/Room1.5.png" };
	Texture* room2Tex = new Texture{ "map/Room2.png" };
	Texture* room2_5Tex = new Texture{ "map/Room2.5.png" };
	Texture* room3Tex = new Texture{ "map/Room3.png" };
	Texture* room4Tex = new Texture{ "map/Room4.png" };
	Texture* room4_5Tex = new Texture{ "map/Room4.5.png" };
	Texture* room5Tex = new Texture{ "map/Room5.png" };

	Texture* stickTextTexture = new Texture{ "* Stick","UI/determinationFont.ttf",30,Color4f{1,1,1,1} };
	Texture* toyKnifeTextTexture = new Texture{ "* Toy Knife","UI/determinationFont.ttf",30,Color4f{1,1,1,1} };
	Texture* bandageTextTexture = new Texture{ "* Bandage","UI/determinationFont.ttf",30,Color4f{1,1,1,1} };
	Texture* fadedRibbonTextTexture = new Texture{ "* FadedRibbon","UI/determinationFont.ttf",30,Color4f{1,1,1,1} };
	Texture* monsterCandyTexture = new Texture{ "* Monster Candy","UI/determinationFont.ttf",30,Color4f{1,1,1,1} };
	Texture*  emptyTextTexture = new Texture{ "  -","UI/determinationFont.ttf",30,Color4f{1,1,1,1} };

	Texture*  holeTexture = new Texture{"map/tiles/hole.png"};
	Texture*  rockTexture = new Texture{"map/tiles/rock.png"};
	Texture*  room3SpikesTexture = new Texture{"map/tiles/room3spikes.png"};

	Texture* interactionBackgroundTexture = new Texture{ "text/interact/baseTextBox.png" };

	Texture* froggitInteractionTexture1 = new Texture{ "text/interact/froggitText1.png" };
	Texture* froggitInteractionTexture2 = new Texture{ "text/interact/froggitText2.png" };
	Texture* froggitInteractionTexture3 = new Texture{ "text/interact/froggitText3.png" };
	Texture* froggitInteractionTexture4 = new Texture{ "text/interact/froggitText4.png" };
	Texture* froggitInteractionTexture5 = new Texture{ "text/interact/froggitText5.png" };
	Texture* froggitInteractionTexture6 = new Texture{ "text/interact/froggitText6.png" };

	Texture* scriptureInteractionTexture1 = new Texture{ "text/interact/scripture1.png" };
	Texture* scriptureInteractionTexture2 = new Texture{ "text/interact/scripture2.png" };
	Texture* scriptureInteractionTexture3 = new Texture{ "text/interact/scripture3.png" };
	Texture* saveInteractionTexture = new Texture{ "text/interact/saveText.png" };

	Texture* itemYesInteractionTexture = new Texture{ "text/interact/yes.png" };
	Texture* itemNoInteractionTexture = new Texture{ "text/interact/no.png" };
	Texture* itemInteractionTexture1 = new Texture{ "text/interact/itemText1.png" };


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
	/*std::map<std::string, AnimationData> migospAnimData{
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
	};*/

	m_AnimatedSprites.push_back(new AnimatedSprite{ charaTexture,CharaData,38,58,"downIdle",0.2f});
	m_AnimatedSprites.push_back(new AnimatedSprite{ playerHeartAnimTexture,playerHeartAnimData,20,24,"",0.2f});
	m_AnimatedSprites.push_back(new AnimatedSprite{ froggitBody,froggitAnimData,92,48,"live",0.5f });
	m_AnimatedSprites.push_back(new AnimatedSprite(loox, LooxAnimData, 100, 116, "live", 0.2f));
	//m_AnimatedSprites.push_back(new AnimatedSprite(migosp, migospAnimData,72, 96, "live", 0.2f));
	//m_AnimatedSprites.push_back(new AnimatedSprite(moldsmal, moldsmalAnimData,102, 84, "live", FLT_MAX));
	//m_AnimatedSprites.push_back(new AnimatedSprite(vegetoid, vegetoidAnimData,72, 104, "live", 0.2f));
	//m_AnimatedSprites.push_back(new AnimatedSprite(whimsun, whimsunAnimData,72, 104, "live", 0.2f));
	std::map<std::string, AnimationData> froggitLeapAttackAnimData{
		{"charging",AnimationData{1,1}},
		{"jumping" ,AnimationData{2,1}}
	};
	std::map<std::string, AnimationData> froggitFlyAttackAnimData{
		{"fly",AnimationData{1,2}}
	};
	std::map<std::string, AnimationData> looxAttackAnimData{
		{"big",AnimationData{1,1}},
		{"med",AnimationData{2,1}},
		{"small",AnimationData{3,1}}
	};
	/*std::map<std::string, AnimationData> migospAttackAnimData{
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
	};*/

	m_BulletAnimatedSprites.push_back(new AnimatedSprite{ froggitLeapAttackTexture,froggitLeapAttackAnimData,40,38,"charging", FLT_MAX});
	m_BulletAnimatedSprites.push_back(new AnimatedSprite{ froggitFlyAttackTexture,froggitFlyAttackAnimData,8,6,"fly",0.075f });
	m_BulletAnimatedSprites.push_back(new AnimatedSprite{ looxAttackBig, looxAttackAnimData ,14 ,14 , "big", FLT_MAX });
	/*m_BulletAnimatedSprites.push_back(new AnimatedSprite{ migospAttack1, migospAttackAnimData ,16 ,16 , "fly", 0.5f });
	m_BulletAnimatedSprites.push_back(new AnimatedSprite{ migospAttack2, migospAttack2AnimData ,32 ,32 , "live", 0.5f });
	m_BulletAnimatedSprites.push_back(new AnimatedSprite{ moldsmalAttack, moldsmalAttackAnimData ,12 ,12 , "big", FLT_MAX });
	m_BulletAnimatedSprites.push_back(new AnimatedSprite{ vegetoidAttack, vegetoidAttackAnimData ,24 ,24 , "veg", FLT_MAX });
	m_BulletAnimatedSprites.push_back(new AnimatedSprite{ vegetoidHeal, vegetoidHealAnimData ,24 ,24 , "heal", FLT_MAX });
	m_BulletAnimatedSprites.push_back(new AnimatedSprite{ whimsunAttack, whimsumAttackAnimData ,15 ,15 , "attack", 0.5f });*/

	std::map<std::string, AnimationData> buttonAnimData{
		{"inactive",AnimationData{0,1}},
		{"active",AnimationData{1,1}}
	};

	m_UiElementSprites.push_back(new AnimatedSprite{ fightButtonTexture,buttonAnimData,110,42,"inactive",FLT_MAX });
	m_UiElementSprites.push_back(new AnimatedSprite{ actButtonTexture  ,buttonAnimData,110,42,"inactive",FLT_MAX });
	m_UiElementSprites.push_back(new AnimatedSprite{ itemButtonTexture ,buttonAnimData,110,42,"inactive",FLT_MAX });
	m_UiElementSprites.push_back(new AnimatedSprite{ mercyButtonTexture,buttonAnimData,110,42,"inactive",FLT_MAX });

	std::map<std::string, AnimationData> playerAttackBarAnimData{
		{"inactive",AnimationData{0,1}},
		{"active",AnimationData{1,1}}
	};
	std::map<std::string, AnimationData> playerAttackAnimData{
		{"swing",AnimationData{0,6}},
	};

	m_MiscAnimatedSprites.push_back(new AnimatedSprite{ fightMenuPlayerBarTexture,playerAttackBarAnimData,8,124,"active",FLT_MAX });
	m_MiscAnimatedSprites.push_back(new AnimatedSprite{ playerAttackTexture,playerAttackAnimData,26,110,"swing",0.15f });

	m_StaticEnemyTextures.push_back(froggitHead);
	m_StaticEnemyTextures.push_back(froggitDeath);
	m_StaticEnemyTextures.push_back(looxDeath);
	/*m_StaticEnemyTextures.push_back(migospDeath);
	m_StaticEnemyTextures.push_back(moldsmalDeath);
	m_StaticEnemyTextures.push_back(vegetoidDeath);
	m_StaticEnemyTextures.push_back(whimsunDeath);*/

	m_StaticTextures.push_back(playerHeartTexture);
	m_StaticTextures.push_back(fightBackGrounds);
	m_StaticTextures.push_back(fightMenuScreenTexture);

	m_TextTextures.push_back(playerNameTexture);
	m_TextTextures.push_back(playerHealthTexture);
	m_TextTextures.push_back(mercyTextTexture);
	m_TextTextures.push_back(fleeTextTexture);

	m_FroggitTextTextures.push_back(actCheckTexture);
	m_FroggitTextTextures.push_back(froggitActTexture1);
	m_FroggitTextTextures.push_back(froggitActTexture2);
	m_FroggitTextTextures.push_back(froggitCheckResponseTexture0);
	m_FroggitTextTextures.push_back(froggitResponseTexture1);
	m_FroggitTextTextures.push_back(froggitResponseTexture2);

	m_LooxTextTextures.push_back(actCheckTexture);
	m_LooxTextTextures.push_back(looxActTexture1);
	m_LooxTextTextures.push_back(looxActTexture2);
	m_LooxTextTextures.push_back(looxCheckResponseTexture0);
	m_LooxTextTextures.push_back(looxResponseTexture1);
	m_LooxTextTextures.push_back(looxResponseTexture2);

	m_RoomTextures.push_back(room1Tex);
	m_RoomTextures.push_back(room1_5Tex);
	m_RoomTextures.push_back(room2Tex);
	m_RoomTextures.push_back(room2_5Tex);
	m_RoomTextures.push_back(room3Tex);
	m_RoomTextures.push_back(room4Tex);
	m_RoomTextures.push_back(room4_5Tex);
	m_RoomTextures.push_back(room5Tex);

	m_ItemTextTextures.push_back(stickTextTexture);
	m_ItemTextTextures.push_back(toyKnifeTextTexture);
	m_ItemTextTextures.push_back(bandageTextTexture);
	m_ItemTextTextures.push_back(fadedRibbonTextTexture);
	m_ItemTextTextures.push_back(monsterCandyTexture);
	m_ItemTextTextures.push_back(emptyTextTexture);

	m_RoomCorrectionTiles.push_back(holeTexture);
	m_RoomCorrectionTiles.push_back(rockTexture);
	m_RoomCorrectionTiles.push_back(room3SpikesTexture);

	m_InteractableTextTextures.push_back(interactionBackgroundTexture);

	m_InteractableTextTextures.push_back(froggitInteractionTexture1);
	m_InteractableTextTextures.push_back(froggitInteractionTexture2);
	m_InteractableTextTextures.push_back(froggitInteractionTexture3);
	m_InteractableTextTextures.push_back(froggitInteractionTexture4);
	m_InteractableTextTextures.push_back(froggitInteractionTexture5);
	m_InteractableTextTextures.push_back(froggitInteractionTexture6);

	m_InteractableTextTextures.push_back(scriptureInteractionTexture1);
	m_InteractableTextTextures.push_back(scriptureInteractionTexture2);
	m_InteractableTextTextures.push_back(scriptureInteractionTexture3);
	m_InteractableTextTextures.push_back(saveInteractionTexture);

	m_InteractableTextTextures.push_back(itemYesInteractionTexture);
	m_InteractableTextTextures.push_back(itemNoInteractionTexture);
	m_InteractableTextTextures.push_back(itemInteractionTexture1);
}

ResourceManager::~ResourceManager()
{
	for (int i{}; i < m_AnimatedSprites.size(); ++i)
	{
		delete m_AnimatedSprites[i];
	}

	for (int i{}; i < m_BulletAnimatedSprites.size(); ++i)
	{
		delete m_BulletAnimatedSprites[i];
	}
	for (int i{}; i < m_MiscAnimatedSprites.size(); ++i)
	{
		delete m_MiscAnimatedSprites[i];
	}

	for (int i{}; i < m_UiElementSprites.size(); ++i )
	{
		delete m_UiElementSprites[i];
	}

	for (int i{}; i < m_StaticEnemyTextures.size(); ++i)
	{
		delete m_StaticEnemyTextures[i];
	}

	for (int i{}; i < m_StaticTextures.size(); ++i)
	{
		delete m_StaticTextures[i];
	}

	for (int i{}; i < m_TextTextures.size(); ++i)
	{
		delete m_TextTextures[i];
	}
	for (int i{}; i < m_FroggitTextTextures.size(); ++i)
	{
		delete m_FroggitTextTextures[i];
	}
	for (int i{1}; i < m_LooxTextTextures.size(); ++i)
	{
		delete m_LooxTextTextures[i];
	}
	for (int i{}; i < m_RoomTextures.size(); ++i)
	{
		delete m_RoomTextures[i];
	}
	for (int i{}; i < m_ItemTextTextures.size(); ++i)
	{
		delete m_ItemTextTextures[i];
	}
	for (int i{}; i < m_RoomCorrectionTiles.size(); ++i)
	{
		delete m_RoomCorrectionTiles[i];
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
	for (AnimatedSprite* data : m_MiscAnimatedSprites)
	{
		data->Update(deltaTime);
	}

}