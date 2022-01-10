#include "stdafx.h"
#include "Mouse.h"
#include "BmpMgr.h"


Mouse::Mouse()
{
}


Mouse::~Mouse()
{
	Release();
}

void Mouse::Initialize()
{
	info.fCX = 37.f;
	info.fCY = 37.f;

	BmpMgr::getInstance()->InsertBmp(L"Mouse", L"../Image/mouse.bmp");
}

int Mouse::Update()
{
	return LIVE;
}

void Mouse::LateUpdate()
{
	POINT pt{};
	
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);

	info.fX = (float)pt.x;
	info.fY = (float)pt.y;

	UpdateRect();
	ShowCursor(false);

}

void Mouse::Render(HDC hdc)
{
	HDC memDC = BmpMgr::getInstance()->FindImage(L"Mouse");
	if (nullptr ==    memDC)return;



	GdiTransparentBlt(hdc, info.fX, info.fCY, info.fCX, info.fCY, memDC, 0, 0, info.fCX, info.fCY, RGB(255, 201, 14));
}

void Mouse::Release()
{
}
