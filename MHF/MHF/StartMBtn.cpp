#include "stdafx.h"
#include "StartMBtn.h"
#include "SceneMgr.h"
#include "BmpMgr.h"
StartMBtn::StartMBtn()
{
}


StartMBtn::~StartMBtn()
{
	Release();

}

void StartMBtn::Initialize()
{
	info.fX = 220.f;
	info.fY = 470.f;
	info.fCX = 90.f;
	info.fCY = 100.f;
	BmpMgr::getInstance()->InsertBmp(L"click", L"../Image/button.bmp");


}

int StartMBtn::Update()
{
	POINT pt2 = {};
	GetCursorPos(&pt2);
	UpdateRect();
	ScreenToClient(g_hWnd, &pt2);


	if (PtInRect(&rect, pt2))
	{

		if (GetAsyncKeyState(VK_LBUTTON)) {
			if (PtInRect(&rect, pt2))
			{


				SceneMgr::GetInstance()->SceneChange(SceneMgr::MONSTAGE);

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

void StartMBtn::LateUpdate()
{
}

void StartMBtn::Render(HDC hDC)
{
	//Rectangle(hDC, rect.left, rect.top, rect.right, rect.bottom);
	HDC memDC = BmpMgr::getInstance()->FindImage(L"click");
	if (nullptr == memDC)return;
	GdiTransparentBlt(hDC, rect.left, rect.top, info.fCX, info.fCY, memDC, 0, 0, 68, 86, RGB(255, 201, 14));




}

void StartMBtn::Release()
{
}
