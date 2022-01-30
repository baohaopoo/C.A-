#include "stdafx.h"
#include "StartBtn.h"
#include "SceneMgr.h"
#include "BmpMgr.h"
#include "SoundMgr.h"
StartBtn::StartBtn()
{
}


StartBtn::~StartBtn()
{
	
}

void StartBtn::Initialize()
{

}

int StartBtn::Update()
{
	UpdateRect();
	return LIVE;
}

void StartBtn::LateUpdate()
{

	POINT pt = {};
	GetCursorPos(&pt);
	UpdateRect();
	ScreenToClient(g_hWnd, &pt);
	
	if (PtInRect(&rect, pt))
	{
	
		//SoundMgr::Get_Instance()->PlayBGM(L"Button.wav", 2);

		if (GetAsyncKeyState(VK_LBUTTON)) {

			{
				
				if (info.name == L"2P") {
					
					SceneMgr::GetInstance()->SceneChange(SceneMgr::LOBBY);
					
				}
				else if(info.name == L"1P") {
					SoundMgr::Get_Instance()->StopAll();
					SceneMgr::GetInstance()->SceneChange(SceneMgr::MONSTAGE);
				}
				else {
					DestroyWindow(g_hWnd);
				}
			}
		}



		else {
			info.fCX = 120;
			info.fCY = 120;
		}

	}

	else
	{
		info.fCX = 90;
		info.fCY = 100;
	}


	
}

void StartBtn::Render(HDC hDC)
{
	HDC memDC = BmpMgr::getInstance()->FindImage(info.name);
	if (nullptr == memDC)return;

	if(info.name == L"2P")
	GdiTransparentBlt(hDC, rect.left, rect.top, info.fCX, info.fCY, memDC, 0, 0, 68, 86, RGB(255, 201, 14));
	else if (info.name == L"Exit") {
		GdiTransparentBlt(hDC, rect.left+5, rect.top+5, info.fCX+10, info.fCY-30, memDC, 0, 0, 101, 69, RGB(255, 201, 14));
	}
	else {

		GdiTransparentBlt(hDC, rect.left, rect.top, info.fCX, info.fCY, memDC, 0, 0, 115, 143, RGB(255, 201, 14));

	}

}

void StartBtn::Release()
{
}
