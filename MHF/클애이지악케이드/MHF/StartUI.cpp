#include "stdafx.h"
#include "StartUI.h"
#include "BmpMgr.h"
#include"SceneMgr.h"
StartUI::StartUI()
{
}


StartUI::~StartUI()
{
	Release();
}

void StartUI::Initialize()
{

}

int StartUI::Update()
{

	if (info.name == L"bossUI") {
		info.fX -= 5;
		if (dwTime + 600 < GetTickCount()) {
		
		
			isDead = true;
		}
	

	}
	if (info.name == L"StartUI" || info.name == L"MStartUI"||info.name == L"LOSE") {
		if (dwTime + 900 < GetTickCount())
		{
			isDead = true;
		}
	}
	UpdateRect();

	if (isDead)
		return DEAD;

	return LIVE;
}

void StartUI::LateUpdate()
{
	POINT pt = {};
	GetCursorPos(&pt);
	UpdateRect();
	ScreenToClient(g_hWnd, &pt);

	if (PtInRect(&rect, pt))
	{
		if (info.name == L"Exit")
			info.fCX = 150; info.fCY = 80;

		if (GetAsyncKeyState(VK_LBUTTON)) {
			
			
				
					SceneMgr::GetInstance()->SceneChange(SceneMgr::LOBBY);
		
		}

	}

	else if (info.name == L"Exit") {
		info.fCX = 140; info.fCY = 70;
	}
	

}

void StartUI::Render(HDC hdc)
{
	//Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
	HDC suDC = BmpMgr::getInstance()->FindImage(info.name);

	//배경 출력 
	if (suDC == nullptr) {
		return;
	}
	if (info.name == L"jusa") {
		GdiTransparentBlt(hdc, rect.left, rect.top, info.fCX, info.fCY, suDC, 0, 0, 38, 38, RGB(255, 201, 14));
	}
	if(info.name == L"StartUI")
		GdiTransparentBlt(hdc, rect.left,rect.top, info.fCX, info.fCY, suDC,0, 0, 445,248, RGB(255, 202, 24));
	else if(info.name == L"MStartUI")
		GdiTransparentBlt(hdc, rect.left, rect.top, info.fCX, info.fCY, suDC, 0, 0, 326, 133, RGB(255, 201, 14));
	else if (info.name == L"LOSE") {
		GdiTransparentBlt(hdc, rect.left, rect.top, info.fCX, info.fCY, suDC, 0, 140, 312, 71, RGB(255, 201, 14));
	}
	else if (info.name == L"bossUI") {
		GdiTransparentBlt(hdc, rect.left, rect.top, info.fCX, info.fCY, suDC, 0, 0, 521, 206, RGB(255, 201, 14));
	
	}
	else
		GdiTransparentBlt(hdc, rect.left , rect.top , info.fCX, info.fCY , suDC, 0, 0, 101, 69, RGB(255, 201, 14));




}

void StartUI::Release()
{
}
