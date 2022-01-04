#include "stdafx.h"
#include "Bullet.h"
#include "BmpMgr.h"

Bullet::Bullet()
	:direction(0)
{
}


Bullet::~Bullet()
{
}

void Bullet::Initialize()
{


	BmpMgr::getInstance()->InsertBmp(L"IDLEBOMB", L"../Image/bomb.bmp");

	framekey = L"IDLEBOMB";
	curstance = IDLEBOMB;
	prestance = curstance;


	frame.startX = 0;
	frame.EndX = 2;
	frame.startY = 0;
	frame.OldTime = GetTickCount();
	frame.Speed = 10;

	info.fCX = 57.f;
	info.fCY = 51.f;
	isDead = false;
	info.fSpeed = 10.f;

}



int Bullet::Update() 
{
	

	if (true == isDead)
		return  DEAD;


			
	UpdateRect();
		
	framekey = L"IDLEBOMB";
	curstance = IDLEBOMB;

	return LIVE;

	
}

void Bullet::LateUpdate()
{

	/*if (50 >= rect.left || WINCX - 50 <= rect.right||
		50 >= rect.top || WINCY - 50 <= rect.bottom) {
		isDead = true;
	}*/
	MoveFrame();
	frameChange();

}

void Bullet::Render(HDC hdc)
{

	HDC memDC = BmpMgr::getInstance()->FindImage(L"IDLEBOMB");
	if (nullptr == memDC)return;


	GdiTransparentBlt(hdc, rect.left, rect.top, info.fCX, info.fCY, memDC, 0, 0, info.fCX, info.fCY, RGB(255, 201, 14));





}

void Bullet::Release()
{
}

void Bullet::setDir(int dir)
{
	direction = dir;
}

void Bullet::setPos(float x, float y)
{
	info.fX = x;
	info.fY = y;
}

void Bullet::frameChange()
{
	if (prestance != curstance)
	{
		switch (curstance)
		{
		case IDLEBOMB:
			frame.startX = 0;
			frame.EndX = 2;
			frame.startY = 0;
			frame.OldTime = GetTickCount();
			frame.Speed = 10;
			break;


		default:
			break;
		}
		prestance = curstance;
	}
}
