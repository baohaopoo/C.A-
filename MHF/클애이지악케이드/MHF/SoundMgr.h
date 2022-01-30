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

public: // �ִ� 32 ä�α��� ���� ����� ����
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

	// ���� ���ҽ� ������ ���� ��ü 
	map<TCHAR*, FMOD_SOUND*> m_mapSound;

	// FMOD_CHANNEL : ����ϰ� �ִ� ���带 ������ ��ü 
	FMOD_CHANNEL* m_pChannelArr[MAXCHANNEL];

	// ���� ,ä�� ��ü �� ��ġ�� �����ϴ� ��ü 
	FMOD_SYSTEM* m_pSystem;

};

