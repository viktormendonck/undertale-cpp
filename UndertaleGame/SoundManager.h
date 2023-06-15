#pragma once
#include <map>
#include <vector>

class SoundEffect;
class SoundStream;

class SoundManager final
{
public:
	static SoundManager& GetInstance();

	void Initialize();
	void SetMusic(const std::string& songName);
	void PlaySoundEffect(const std::string& name);
	void UpdateAudioLevel();
	void CleanUp();
	int& GetAudioVolumeRef();
	const std::string& GetCurrentSong()const;
private:
	SoundManager() = default;
	bool m_HasInitialized{ false };
	int m_AudioVolume{ 50 };
	std::map<std::string, SoundStream*> m_Music{};
	std::map<std::string, SoundEffect*> m_SFX{};
	std::string m_CurrentSong{};
};


