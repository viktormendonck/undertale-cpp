#include "pch.h"
#include "SoundManager.h"
#include "SoundEffect.h"
#include "SoundStream.h"

SoundManager& SoundManager::GetInstance()
{
	static SoundManager instance;
	return instance;
}


void SoundManager::SetMusic(const std::string& songName)
{
	for (std::pair<std::string, SoundStream*> music : m_Music)
	{
		music.second->Stop();
	}
	m_Music[songName]->Play(true);
}

void SoundManager::PlaySoundEffect(const std::string& name)
{
	m_SFX[name]->Play(0);
}

void SoundManager::CleanUp()
{
	for (std::pair<std::string,SoundStream*> music: m_Music)
	{
		delete music.second;
	}
	for (std::pair<std::string, SoundEffect*> sfx : m_SFX)
	{
		delete sfx.second;
	}
}

void SoundManager::Initialize()
{
	if (!m_HasInitialized)
	{
		m_HasInitialized = !m_HasInitialized;

		m_Music["ruins"] = new SoundStream("sound/music/ruins.wav");
		m_Music["battle"] = new SoundStream("sound/music/battle.wav");
		m_Music["ghostFight"] = new SoundStream("sound/music/ghostFight.wav");

		m_SFX["damage"] = new SoundEffect("sound/sfx/damage.wav");
		m_SFX["escape"] = new SoundEffect("sound/sfx/escape.wav");
		m_SFX["fall"] = new SoundEffect("sound/sfx/fall.wav");
		m_SFX["heal"] = new SoundEffect("sound/sfx/heal.wav");
		m_SFX["hit"] = new SoundEffect("sound/sfx/hit.wav");
		m_SFX["select"] = new SoundEffect("sound/sfx/select.wav");
		m_SFX["slash"] = new SoundEffect("sound/sfx/slash.wav");
		m_SFX["changeSelection"] = new SoundEffect("sound/sfx/changeSelection.wav");
	}
}

SoundManager::SoundManager()
{
}

SoundManager::~SoundManager()
{
}