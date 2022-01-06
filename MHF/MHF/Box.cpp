#include "stdafx.h"
#include "Box.h"


Box::Box()
{
}


Box::~Box()
{
}

void Box::Initialize()
{
	BmpMgr::getInstance()->InsertBmp(L"Box", L"../Image/map/box.bmp");

	info.fX = 400.f;
	info.fY = 400.f;

	info.fCX = 40.f;
	info.fCY = 47.f;

}

int Box::Update()
{
	UpdateRect();
	ColliderUpdateRect();
	return LIVE;
}

void Box::LateUpdate()
{
}

void Box::Render(HDC hdc)
{
	HDC memDC = BmpMgr::getInstance()->FindImage(L"Box");
	if (nullptr == memDC)return;

	//Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
	//GdiTransparentBlt(hdc, rect.left, rect.top, info.fCX, info.fCY, memDC, (int)info.fX, (int)info.fY,info.fCX, info.fCY, RGB(255, 255, 255));
	Rectangle(hdc, colliderBox.left, colliderBox.top, colliderBox.right, colliderBox.bottom);
	BitBlt(hdc, rect.left, rect.top, info.fCX, info.fCY, memDC, 0, 0, SRCCOPY);




}

void Box::Release()
{
}

void Box::Coliide()
{
	//info.fX
}
