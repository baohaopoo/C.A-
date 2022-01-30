#include "stdafx.h"
#include "StartBtn.h"
#include "SceneMgr.h"
#include "BmpMgr.h"
StartBtn::StartBtn()
{
}


StartBtn::~StartBtn()
{
	Release();
}

void StartBtn::Initialize()
{
	info.fX = 580.f;
	info.fY = 470.f;
	info.fCX = 90.f;
	info.fCY = 100.f;

	
	BmpMgr::getInstance()->InsertBmp(L"click2", L"../Image/button2.bmp");

}

int StartBtn::Update()
{
	POINT pt = {};
	GetCursorPos(&pt);
	UpdateRect();
	ScreenToClient(g_hWnd, &pt);

	if (PtInRect(&rect, pt))
	{

		if (GetAsyncKeyState(VK_LBUTTON)) {
			if (PtInRect(&rect, pt))
			{

					SceneMgr::GetInstance()->SceneChange(SceneMgr::LOBBY);
				
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
	

	return LIVE;
}

void StartBtn::LateUpdate()
{
	
}

void StartBtn::Render(HDC hDC)
{
	
	HDC memDC = BmpMgr::getInstance()->FindImage(L"click2");
	if (nullptr == memDC)return;


	Rectangle(hDC,rect.left, rect.top, rect.right, rect.bottom);
	GdiTransparentBlt(hDC,rect.left, rect.top, info.fCX, info.fCY, memDC, 0, 0, 68, 86, RGB(255, 201, 14));


}

void StartBtn::Release()
{
}
