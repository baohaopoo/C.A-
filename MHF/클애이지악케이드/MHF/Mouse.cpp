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
	POINT pt3{};
	
	GetCursorPos(&pt3);
	ScreenToClient(g_hWnd, &pt3);

	info.fX = (float)pt3.x;
	info.fY = (float)pt3.y;

	UpdateRect();
	ShowCursor(false);

}

void Mouse::Render(HDC hdc)
{
	HDC memDC = BmpMgr::getInstance()->FindImage(L"Mouse");
	if (nullptr ==    memDC)return;



	GdiTransparentBlt(hdc, rect.left, rect.top, info.fCX, info.fCY, memDC, 0, 0, 37, 39, RGB(255, 201, 14));
}

void Mouse::Release()
{
}
