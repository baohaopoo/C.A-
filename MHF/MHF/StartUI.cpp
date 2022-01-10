#include "stdafx.h"
#include "StartUI.h"
#include "BmpMgr.h"

StartUI::StartUI()
{
}


StartUI::~StartUI()
{
	Release();
}

void StartUI::Initialize()
{
	BmpMgr::getInstance()->InsertBmp(L"StartUI", L"../Image/startui.bmp");
	info.fX = 320.f;
	info.fY = 290.f;
	info.fCX = 445.f;
	info.fCY = 248.f;
}

int StartUI::Update()
{
	if (dwTime + 700 < GetTickCount())
	{
		isDead = true;


	}
	UpdateRect();

	if (isDead)
		return DEAD;

	return LIVE;
}

void StartUI::LateUpdate()
{
}

void StartUI::Render(HDC hdc)
{
	//Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
	HDC suDC = BmpMgr::getInstance()->FindImage(L"StartUI");

	//배경 출력 
	if (suDC == nullptr) {
		return;
	}

	
	GdiTransparentBlt(hdc, rect.left,rect.top, info.fCX, info.fCY, suDC,0, 0, info.fCX, info.fCY, RGB(255, 202, 24));

}

void StartUI::Release()
{
}
