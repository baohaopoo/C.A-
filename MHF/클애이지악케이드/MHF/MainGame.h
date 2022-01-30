#pragma once
#include "Define.h"
#include "Enum.h"
#include "Functional.h"
#include "Mouse.h"
class MainGame
{
public:
	MainGame();
	~MainGame();


public:
	void Initialize();
	void Update();
	void LateUpdate();
	void Render();
	void Release();

private:
	HDC m_DC;
	int				m_iFPS;
	TCHAR			m_szFPS[32];
	DWORD			m_dwTime;
	Mouse mouse;
};

