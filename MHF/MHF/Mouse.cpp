#include "stdafx.h"
#include "Mouse.h"


Mouse::Mouse()
{
}


Mouse::~Mouse()
{
	Release();
}

void Mouse::Initialize()
{
	info.fCX = 10.f;
	info.fCY = 10.f;
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
	Ellipse(hdc, rect.left, rect.top, rect.right, rect.bottom);
}

void Mouse::Release()
{
}
