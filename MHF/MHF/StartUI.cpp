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
	info.fX = 300.f;
	info.fY = 100.f;
	info.fCX = 300.f;
	info.fCY = 300.f;
}

int StartUI::Update()
{
	UpdateRect();
	return LIVE;
}

void StartUI::LateUpdate()
{
}

void StartUI::Render(HDC hdc)
{
	Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
	HDC suDC = BmpMgr::getInstance()->FindImage(L"StartUI");

	//배경 출력 
	if (suDC== nullptr) {
		return;
	}

	//GdiTransparentBlt(hdc, 300,300, 300,300, suDC, 0, 0, WINCX, WINCY, RGB(255, 202, 24));
	BitBlt(hdc, 300,100, 500, 300, suDC, 0, 0, SRCCOPY);

}

void StartUI::Release()
{
}
