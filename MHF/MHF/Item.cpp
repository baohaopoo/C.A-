#include "stdafx.h"
#include "Item.h"

//롤러스케이트
Item::Item()
{
}


Item::~Item()
{
}

void Item::Initialize()
{
	BmpMgr::getInstance()->InsertBmp(L"Skate", L"../Image/Item/skate.bmp");

	info.fX = 400.f;
	info.fY = 200.f;

	info.fCX = 38.f;
	info.fCY = 38.f;
}

int Item::Update()
{
	if (isDead)
		return DEAD;
	UpdateRect();
	ColliderUpdateRect();

	return LIVE;
}

void Item::LateUpdate()
{
}

void Item::Render(HDC hdc)
{
	HDC memDC = BmpMgr::getInstance()->FindImage(L"Skate");
	if (nullptr == memDC)return;

	//Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
	//GdiTransparentBlt(hdc, rect.left, rect.top, info.fCX, info.fCY, memDC, (int)info.fX, (int)info.fY,info.fCX, info.fCY, RGB(255, 255, 255));
	Rectangle(hdc, colliderBox.left, colliderBox.top, colliderBox.right, colliderBox.bottom);
	BitBlt(hdc, rect.left, rect.top, info.fCX, info.fCY, memDC, 0, 0, SRCCOPY);


}

void Item::Release()
{
}

void Item::Collide()
{
	isDead = true;
}
