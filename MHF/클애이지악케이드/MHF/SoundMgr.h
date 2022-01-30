#pragma once
class SoundMgr
{
public:
	static SoundMgr* Get_Instance()
	{
		if (nullptr == m_pInstance)
			m_pInstance = new SoundMgr;

		return m_pInstance;
	}
	static void Destroy_Instance()
	{
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

public: // 최대 32 채널까지 동시 재생이 가능
	enum CHANNELID { BGM, PLAYER, MONSTER, BOMB,ITEM,EFFECT, UI, MAXCHANNEL };

private:
	SoundMgr();
	~SoundMgr();

public:
	void Initialize();

	void Release();
public:
	void PlaySound(TCHAR* pSoundKey, CHANNELID eID, float fVolume);
	void PlayBGM(TCHAR* pSoundKey, float fVolume);
	void StopSound(CHANNELID eID);
	void StopAll();
	void SetChannelVolume(CHANNELID eID, float fVolume);
private:
	void LoadSoundFile();

private:
	static SoundMgr* m_pInstance;

	// 사운드 리소스 정보를 갖는 객체 
	map<TCHAR*, FMOD_SOUND*> m_mapSound;

	// FMOD_CHANNEL : 재생하고 있는 사운드를 관리할 객체 
	FMOD_CHANNEL* m_pChannelArr[MAXCHANNEL];

	// 사운드 ,채널 객체 및 장치를 관리하는 객체 
	FMOD_SYSTEM* m_pSystem;

};

