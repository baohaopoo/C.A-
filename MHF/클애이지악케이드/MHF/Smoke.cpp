#include "stdafx.h"
#include "Smoke.h"
#include "BmpMgr.h"
#include "Factory.h"
#include "Item.h"
#include "ObjMgr.h"

Smoke::Smoke()
{
}


Smoke::~Smoke()
{
	Release();
}

void Smoke::Initialize()
{
	id = SMOKE;
	BmpMgr::getInstance()->InsertBmp(L"BOXBYE", L"../Image/boxbye.bmp");
	
	frame.startX = 0;
	frame.EndX = 3;
	frame.startY = 0;
	frame.OldTime = GetTickCount();
	frame.Speed = 50;
	isDead = false;

}

int Smoke::Update()
{
	if (true == isDead) {
		return DEAD;
	}

	if (dwTime + 50 < GetTickCount())
		setDead();

	UpdateRect();
	ColliderUpdateRect();
	MoveFrame();

	return 0;
}

void Smoke::LateUpdate()
{
}

void Smoke::Render(HDC hdc)
{
	HDC effectDC = BmpMgr::getInstance()->FindImage(L"BOXBYE");
	if (nullptr == effectDC)return;


	//연기나는 effect

	GdiTransparentBlt(hdc, rect.left, rect.top, 58, 52, effectDC, frame.startX * 58, frame.startY * 52, 58, 52, RGB(255, 201, 14));



}

void Smoke::Release()
{
}

void Smoke::Collide(OBJID objid)
{
	isDead = true;
}
