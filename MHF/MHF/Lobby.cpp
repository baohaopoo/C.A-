#include "stdafx.h"
#include "Lobby.h"
#include "BmpMgr.h"
#include "Define.h"
#include "SceneMgr.h"
Lobby::Lobby()
{
}


Lobby::~Lobby()
{
	Release();
}

void Lobby::Initialize()
{
	/*BmpMgr::getInstance()->InsertBmp(L"Lobby", "../Image/");*/
}

void Lobby::Update()
{
}

void Lobby::LateUpdate()
{
	if (GetAsyncKeyState(VK_RETURN))
	{
		SceneMgr::GetInstance()->SceneChange(SceneMgr::STAGE);
		return;
	}
	
}

void Lobby::Render(HDC hDC)
{
	Rectangle(hDC, 0, 0, WINCX, WINCY);
}

void Lobby::Release()
{
}
