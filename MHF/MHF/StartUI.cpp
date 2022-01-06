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
	info.fCX = 500.f;
	info.fCY = 300.f;
}

int StartUI::Update()
{
	if (dwTime + 500 < GetTickCount())
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
	//GdiTransparentBlt(hdc, rect.left,rect.top, 500,300, suDC, rect.left, rect.top, 500, 300, RGB(255, 202, 24));
	BitBlt(hdc, 100, 180, 500, 300, suDC, 0, 0, SRCCOPY);

}

void StartUI::Release()
{
}
