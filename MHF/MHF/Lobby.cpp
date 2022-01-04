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
	BmpMgr::getInstance()->InsertBmp(L"Lobby", L"../Image/lobby.bmp");
	lsBtn.Initialize();
}

void Lobby::Update()
{
	lsBtn.Update();
}

void Lobby::LateUpdate()
{
	lsBtn.LateUpdate();
	
}

void Lobby::Render(HDC hDC)
{
	HDC memDC = BmpMgr::getInstance()->FindImage(L"Lobby");
	if (nullptr == memDC)
		return;

	BitBlt(hDC, 0, 0, WINCX, WINCY, memDC, 0, 0, SRCCOPY);
	
	lsBtn.Render(hDC);

}

void Lobby::Release()
{
}
