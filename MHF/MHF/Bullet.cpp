#include "stdafx.h"
#include "Bullet.h"
#include "BmpMgr.h"
#include "Factory.h"
#include "ObjMgr.h"
Bullet::Bullet()
	:direction(0)
{

}


Bullet::~Bullet()
{
}

void Bullet::Initialize()
{
	


	id = BULLET;

	BmpMgr::getInstance()->InsertBmp(L"IDLEBOMB", L"../Image/ab.bmp"); //bomb
	BmpMgr::getInstance()->InsertBmp(L"ALONEBOMB", L"../Image/bb.bmp");
	BmpMgr::getInstance()->InsertBmp(L"FLOWBOMB", L"../Image/flow.bmp");

	BmpMgr::getInstance()->InsertBmp(L"UP", L"../Image/Bomb/upflow.bmp");

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
		framekey2 = L"UP";
		framekey3 = L"UP";
		framekey4 = L"UP";
		framekey5 = L"UP";

		curstance = ALONEBOMB;
		isDead = true;
	}
}


void Bullet::Render(HDC hdc)
{


	HDC memDC = BmpMgr::getInstance()->FindImage(framekey);
	if (nullptr == memDC)return;

	GdiTransparentBlt(hdc, rect.left, rect.top, info.fCX, info.fCY, memDC, frame.startX * (int)info.fCX,
		frame.startY * (int)info.fCY, info.fCX, info.fCY, RGB(255, 201, 14));

	//up
	HDC memDC2= BmpMgr::getInstance()->FindImage(framekey2);
	if (nullptr == memDC2)return;

	GdiTransparentBlt(hdc, rect.left-13, rect.top-40, info.fCX, info.fCY, memDC2, frame.startX * (int)info.fCX,
		frame.startY * (int)info.fCY, info.fCX, info.fCY, RGB(255, 201, 14));

	//right
	HDC memDC3 = BmpMgr::getInstance()->FindImage(framekey3);
	if (nullptr == memDC3)return;

	GdiTransparentBlt(hdc, rect.left+43, rect.top, info.fCX, info.fCY, memDC3, 5 * (int)info.fCX,
		frame.startY * (int)info.fCY, info.fCX, info.fCY, RGB(255, 201, 14));

	//down
	HDC memDC4 = BmpMgr::getInstance()->FindImage(framekey4);
	if (nullptr == memDC4)return;

	GdiTransparentBlt(hdc, rect.left-13, rect.top+23, info.fCX, info.fCY, memDC3, frame.startX* (int)info.fCX,
		1 * (int)info.fCY, info.fCX, info.fCY, RGB(255, 201, 14));

	//left
	HDC memDC5 = BmpMgr::getInstance()->FindImage(framekey5);
	if (nullptr == memDC5)return;

	GdiTransparentBlt(hdc, rect.left-28, rect.top-18, info.fCX, info.fCY, memDC3, 5* (int)info.fCX,
		1 * (int)info.fCY, info.fCX, info.fCY, RGB(255, 201, 14));



	//충돌박스 
//	Rectangle(hdc, colliderBox.left, colliderBox.top, colliderBox.right, colliderBox.bottom);

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
