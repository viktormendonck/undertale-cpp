#include "pch.h"
#include "ResourceManager.h"
#include "AnimatedSprite.h"
#include <map>


ResourceManager::ResourceManager(std::string playerName)
{
	//player
	Texture* charaTexture = new Texture{ "Sprites/chara.png" };
	Texture* playerHeartTexture = new Texture{ "Sprites/PlayerHeart.png" };
	Texture* playerHeartAnimTexture = new Texture{ "Sprites/PlayerHeartAnims.png" };
	Texture* fightBackGrounds = new Texture{ "Static_Screens/FightBackGrounds.png" };
	//menu
	Texture* controlMenuBackGroundTexture = new Texture{ "Static_Screens/Controls.png" };
	Texture* nameMenuBackGroundTexture = new Texture{ "Static_Screens/menu/NamingMenu.png" };
	Texture* optionsMenuBackGroundTexture = new Texture{ "Static_Screens/menu/optionsMenu.png" };
	Texture* standardMenuBackGroundTexture = new Texture{ "Static_Screens/menu/baseStartMenuBackground.png" };

	//froggit
	Texture* froggitLeapAttackTexture = new Texture{ "Sprites/Froggit/JumpAttack.png" };
	Texture* froggitFlyAttackTexture = new Texture{ "Sprites/Froggit/flyAttack.png" };
	Texture* froggitHead = new Texture{ "Sprites/Froggit/head.png" };
	Texture* froggitBody = new Texture{ "Sprites/Froggit/body.png" };
	Texture* froggitDeath = new Texture{ "Sprites/Froggit/death.png" };
	//loox
	Texture* loox = new Texture{ "Sprites/Loox/loox.png" };
	Texture* looxDeath = new Texture{ "Sprites/loox/death.png" };
	Texture* looxAttack = new Texture{ "Sprites/loox/bullet.png" };
	//napstablook
	Texture* napsta = new Texture{ "Sprites/napstablook/napstablook.png" };
	Texture* napstaDeath = new Texture{ "Sprites/napstablook/death.png" };
	Texture* napstaAttack = new Texture{ "Sprites/napstablook/tear.png" };
	Texture* napstaAttack1 = new Texture{ "Sprites/napstablook/notUpToIt.png" };

	Texture* fightButtonTexture = new Texture{ "UI/fightButton.png" };
	Texture* actButtonTexture = new Texture{ "UI/actButton.png" };
	Texture* itemButtonTexture = new Texture{ "UI/itemButton.png" };
	Texture* mercyButtonTexture = new Texture{ "UI/mercyButton.png" };

	Texture* fightMenuScreenTexture = new Texture{ "UI/fightTarget.png" };
	Texture* fightMenuPlayerBarTexture = new Texture{ "Sprites/Player/attackSelector.png" };
	Texture* playerAttackTexture = new Texture{ "Sprites/Player/attackAnim.png" };

	//text Textures

	Texture* playerNameTexture = new Texture{ playerName,"UI/determinationFont.ttf",30,Color4f{1,1,1,1} };
	Texture* playerHealthTexture = new Texture{ "20/20HP","UI/determinationFont.ttf",30,Color4f{1,1,1,1} };

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
	Texture* paralax = new Texture{ "map/paralax.png" };

	Texture* stickTextTexture = new Texture{ "* Stick","UI/determinationFont.ttf",30,Color4f{1,1,1,1} };
	Texture* toyKnifeTextTexture = new Texture{ "* Toy Knife","UI/determinationFont.ttf",30,Color4f{1,1,1,1} };
	Texture* bandageTextTexture = new Texture{ "* Bandage","UI/determinationFont.ttf",30,Color4f{1,1,1,1} };
	Texture* fadedRibbonTextTexture = new Texture{ "* FadedRibbon","UI/determinationFont.ttf",30,Color4f{1,1,1,1} };
	Texture* monsterCandyTexture = new Texture{ "* Monster Candy","UI/determinationFont.ttf",30,Color4f{1,1,1,1} };
	Texture*  emptyTextTexture = new Texture{ "  -","UI/determinationFont.ttf",30,Color4f{1,1,1,1} };

	Texture*  holeTexture = new Texture{"map/tiles/hole.png"};
	Texture*  rockTexture = new Texture{"map/tiles/rock.png"};
	Texture*  room3SpikesTexture = new Texture{"map/tiles/room3spikes.png"};
	Texture*  napstaTexture = new Texture{"map/tiles/napstablook.png"};

	Texture* interactionBackgroundTexture = new Texture{ "text/interact/baseTextBox.png" };
	Texture* menuBackgroundTexture = new Texture{ "text/menu/menuTextBox.png" };

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
	std::map<std::string, AnimationData> looxAnimData{
		{"live",AnimationData{1,5}}
	};
	std::map<std::string, AnimationData> napstaAnimData{
		{"live", AnimationData{ 1,2 }}
	};

	m_AnimatedSprites.push_back(new AnimatedSprite{ charaTexture,CharaData,38,58,"downIdle",0.2f});
	m_AnimatedSprites.push_back(new AnimatedSprite{ playerHeartAnimTexture,playerHeartAnimData,20,24,"",0.2f});
	m_AnimatedSprites.push_back(new AnimatedSprite{ froggitBody,froggitAnimData,92,48,"live",0.5f });
	m_AnimatedSprites.push_back(new AnimatedSprite(loox, looxAnimData, 100, 116, "live", 0.2f));
	m_AnimatedSprites.push_back(new AnimatedSprite(napsta, napstaAnimData, 104, 166, "live", 0.2f));

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
	std::map<std::string, AnimationData> napstaAttackAnimData{
		{"std", AnimationData{ 1,1 }}
	};


	m_BulletAnimatedSprites.push_back(new AnimatedSprite{ froggitLeapAttackTexture,froggitLeapAttackAnimData,40,38,"charging", FLT_MAX});
	m_BulletAnimatedSprites.push_back(new AnimatedSprite{ froggitFlyAttackTexture,froggitFlyAttackAnimData,8,6,"fly",0.075f });
	m_BulletAnimatedSprites.push_back(new AnimatedSprite{ looxAttack, looxAttackAnimData ,14 ,14 , "big", FLT_MAX });
	m_BulletAnimatedSprites.push_back(new AnimatedSprite{ napstaAttack, napstaAttackAnimData ,12 ,13 , "std", FLT_MAX });
	m_BulletAnimatedSprites.push_back(new AnimatedSprite{ napstaAttack1, napstaAttackAnimData ,98 ,41 , "std", FLT_MAX });


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
	m_MiscAnimatedSprites.push_back(new AnimatedSprite{ playerAttackTexture,playerAttackAnimData,26,110,"swing",0.3f });

	m_StaticEnemyTextures.push_back(froggitHead);
	m_StaticEnemyTextures.push_back(froggitDeath);
	m_StaticEnemyTextures.push_back(looxDeath);
	m_StaticEnemyTextures.push_back(napstaDeath);

	m_MiscTextures.push_back(playerHeartTexture);
	m_MiscTextures.push_back(fightBackGrounds);
	m_MiscTextures.push_back(fightMenuScreenTexture);
	m_MiscTextures.push_back(menuBackgroundTexture);
	m_MiscTextures.push_back(standardMenuBackGroundTexture);
	m_MiscTextures.push_back(controlMenuBackGroundTexture);
	m_MiscTextures.push_back(nameMenuBackGroundTexture);
	m_MiscTextures.push_back(optionsMenuBackGroundTexture);


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
	m_RoomTextures.push_back(paralax);

	m_ItemTextTextures.push_back(stickTextTexture);
	m_ItemTextTextures.push_back(toyKnifeTextTexture);
	m_ItemTextTextures.push_back(bandageTextTexture);
	m_ItemTextTextures.push_back(fadedRibbonTextTexture);
	m_ItemTextTextures.push_back(monsterCandyTexture);
	m_ItemTextTextures.push_back(emptyTextTexture);

	m_RoomCorrectionTiles.push_back(holeTexture);
	m_RoomCorrectionTiles.push_back(rockTexture);
	m_RoomCorrectionTiles.push_back(room3SpikesTexture);
	m_RoomCorrectionTiles.push_back(napstaTexture);

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

	for (int i{}; i < m_MiscTextures.size(); ++i)
	{
		delete m_MiscTextures[i];
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
	for (int i{}; i < m_InteractableTextTextures.size(); ++i)
	{
		delete m_InteractableTextTextures[i];
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