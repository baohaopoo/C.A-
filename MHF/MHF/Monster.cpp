#include "stdafx.h"
#include "Monster.h"
#include "BmpMgr.h"


Monster::Monster()
{
}
Monster::~Monster()
{
}

void Monster::Initialize()
{

	info.fX = 300.f;
	info.fY = 200.f;


	info.fCX = 96.f;
	info.fCY = 96.f;

	info.fSpeed = 10.f;
	frame.startX = 2;
	frame.EndX = 4;
	frame.startY = 0;

	BmpMgr::getInstance()->InsertBmp(L"MIDLE", L"../Image/Monster/babymonster.bmp"); //64x74
	frameKey = L"MIDLE";
}

int Monster::Update()
{
	if (true == isDead)
		return DEAD;

	info.fX += info.fSpeed;
	frame.startX++;


	UpdateRect();
	return LIVE;
}

void Monster::LateUpdate()
{
	if (WINCX - 380 <= rect.right || 80 >= rect.left) {
		
		info.fSpeed *= -1.f;
	}

	
}

void Monster::Render(HDC hdc)
{
	HDC memDC = BmpMgr::getInstance()->FindImage(frameKey);
	if (nullptr == memDC)return;

	GdiTransparentBlt(hdc, rect.left, rect.top, info.fCX, info.fCY, memDC, 0, 0, info.fCX, info.fCY, RGB(255, 201, 14));
}

void Monster::Release()
{
}

void Monster::frameChange()
{
}
