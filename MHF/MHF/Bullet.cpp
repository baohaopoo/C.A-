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


	BmpMgr::getInstance()->InsertBmp(L"IDLEBOMB", L"../Image/ab.bmp"); //bomb
	BmpMgr::getInstance()->InsertBmp(L"ALONEBOMB", L"../Image/bb.bmp");
	BmpMgr::getInstance()->InsertBmp(L"FLOWBOMB", L"../Image/flow.bmp");

	framekey = L"IDLEBOMB";
	curstance = IDLEBOMB;
	prestance = curstance;


	frame.startX = 0;
	frame.EndX = 2;
	frame.startY = 0;
	frame.OldTime = GetTickCount();
	frame.Speed = 200;

	info.fCX = 53.f;
	info.fCY = 55.f;
	isDead = false;
	info.fSpeed = 10.f;

}



int Bullet::Update() 
{
	

	if (true == isDead)
		return  DEAD;


		
	UpdateRect();
	ColliderUpdateRect();

	framekey = L"IDLEBOMB";
	curstance = IDLEBOMB;

	return LIVE;

	
}

void Bullet::LateUpdate()
{

	MoveFrame();
	frameChange();

	if (bombTime + 2300 < GetTickCount())
	{
		
		framekey = L"ALONEBOMB";
		curstance = ALONEBOMB;
		isDead = true;
	}
}


void Bullet::Render(HDC hdc)
{


	HDC memDC = BmpMgr::getInstance()->FindImage(framekey);
	if (nullptr == memDC)return;


	//충돌박스 
	Rectangle(hdc, colliderBox.left, colliderBox.top, colliderBox.right, colliderBox.bottom);


	GdiTransparentBlt(hdc, rect.left, rect.top, info.fCX, info.fCY, memDC, frame.startX * (int)info.fCX,
		frame.startY * (int)info.fCY, info.fCX, info.fCY, RGB(255, 201, 14));

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

		case ALONEBOMB:
		
			frame.startX = 0;
			frame.EndX = 3;
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
