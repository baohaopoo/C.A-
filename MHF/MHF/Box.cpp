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
	id = BOX;
	BmpMgr::getInstance()->InsertBmp(L"Box", L"../Image/map/iceobj.bmp");

	info.fX = 100.f;
	info.fY = 520.f;

	info.fCX = 440.f;
	info.fCY = 120.f;

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



	GdiTransparentBlt(hdc, info.fX, info.fCY, info.fCX, info.fCY, memDC, 0, 0, info.fCX, info.fCY, RGB(255, 201, 14));
}

void Box::Release()
{
}

void Box::Coliide(OBJID objid)
{
	//info.fX
}
