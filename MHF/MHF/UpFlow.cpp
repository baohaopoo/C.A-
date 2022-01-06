#include "stdafx.h"
#include "UpFlow.h"
#include "BmpMgr.h"

UpFlow::UpFlow()
{
}


UpFlow::~UpFlow()
{
}
//480 x 131 장당 60 65 정도의 크기
void UpFlow::Initialize()
{
	BmpMgr::getInstance()->InsertBmp(L"UP", L"../Image/Bomb/upflow.bmp");
	info.fCX = 60.f;
	info.fCY = 65.f;

	frame.startX = 0;
	frame.EndX = 3;
	frame.startY = 0;
	frame.OldTime = GetTickCount();
	frame.Speed = 200;

}

int UpFlow::Update()
{
	UpdateRect();
	ColliderUpdateRect();

	return LIVE;
}

void UpFlow::LateUpdate()
{
}

void UpFlow::Render(HDC hdc)
{
	HDC memDC = BmpMgr::getInstance()->FindImage(L"upflow.bmp");
	if (nullptr == memDC)return;


	//충돌박스 
	Rectangle(hdc, colliderBox.left, colliderBox.top, colliderBox.right, colliderBox.bottom);


	GdiTransparentBlt(hdc, rect.left, rect.top, info.fCX, info.fCY, memDC, frame.startX * (int)info.fCX,
		frame.startY * (int)info.fCY, info.fCX, info.fCY, RGB(255, 201, 14));
}

void UpFlow::Release()
{
}
