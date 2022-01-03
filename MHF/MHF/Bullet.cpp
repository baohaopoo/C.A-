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
	info.fCX = 44.f;
	info.fCY = 41.f;
	isDead = false;
	info.fSpeed = 10.f;

	BmpMgr::getInstance()->InsertBmp(L"IDLE", L"../Image/Idle0.bmp");
}



int Bullet::Update() 
{
	

	if (true == isDead)
		return  DEAD;


			
	UpdateRect();
		
	

	return LIVE;

	
}

void Bullet::LateUpdate()
{



	/*if (50 >= rect.left || WINCX - 50 <= rect.right||
		50 >= rect.top || WINCY - 50 <= rect.bottom) {
		isDead = true;
	}*/


}

void Bullet::Render(HDC hdc)
{

	HDC memDC = BmpMgr::getInstance()->FindImage(L"IDLE");
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
