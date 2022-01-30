#include "stdafx.h"
#include "hpBar.h"
#include "BmpMgr.h"
#include "Factory.h"
#include "Item.h"
#include "ObjMgr.h"


hpBar::hpBar()
{
}


hpBar::~hpBar()
{
	Release();
}

void hpBar::Initialize()
{
	id = UI;
	BmpMgr::getInstance()->InsertBmp(L"hp", L"../Image/hpbar.bmp");


	frame.startX = 0;
	frame.EndX = 0;
	frame.startY = 0;
	frame.EndY = 3;
	frame.OldTime = GetTickCount();
	frame.Speed = 150;

	info.fCX = 100.f;
	info.fCY = 100.f;
	isDead = false;
}

int hpBar::Update()
{
	UpdateRect();
	MoveFrameY();
	return 0;

}

void hpBar::LateUpdate()
{
}

void hpBar::Render(HDC hdc)
{
	HDC memDC = BmpMgr::getInstance()->FindImage(L"D");
	if (nullptr == memDC)return;


	GdiTransparentBlt(hdc, rect.left - 20, rect.top - 10, 60, 60, memDC, frame.startX * 493,
		frame.startY * 62, 493, 62, RGB(255, 201, 14));
}

void hpBar::Release()
{
}
