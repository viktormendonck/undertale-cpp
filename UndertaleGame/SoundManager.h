#pragma once
#include <map>
#include <vector>

class SoundEffect;
class SoundStream;

class SoundManager
{
public:
	static SoundManager& GetInstance();

	void Initialize();
	void SetMusic(const std::string& songName);
	void PlaySoundEffect(const std::string& name);
	void CleanUp();
private:
	SoundManager();
	~SoundManager();
	bool m_HasInitialized{ false };
	std::map<std::string, SoundStream*> m_Music{};
	std::map<std::string, SoundEffect*> m_SFX{};
};


