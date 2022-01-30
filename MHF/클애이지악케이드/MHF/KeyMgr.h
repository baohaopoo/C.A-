#pragma once
class KeyMgr
{
public:
	KeyMgr();
	~KeyMgr();

public:
	bool		Key_Pressing(int iKey);
	bool		Key_Down(int iKey);
	bool		Key_Up(int iKey);

public:
	static KeyMgr*		Get_Instance(void)
	{
		if (nullptr == m_pInstance)
			m_pInstance = new KeyMgr;

		return m_pInstance;
	}
	static void			Destroy_Instance(void)
	{
		if (nullptr != m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

private:
	static		KeyMgr*	m_pInstance;
	bool		m_bKeyState[0xff];
};

