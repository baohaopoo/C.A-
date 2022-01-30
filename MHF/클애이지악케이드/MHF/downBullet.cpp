#include "stdafx.h"
#include "downBullet.h"
#include "BmpMgr.h"
#include "Factory.h"
#include "Item.h"
#include "ObjMgr.h"

downBullet::downBullet()
{
}


downBullet::~downBullet()
{
	Release();
}

void downBullet::Initialize()
{
	id = DOWNBULLET;

	BmpMgr::getInstance()->InsertBmp(L"D", L"../Image/Bomb/upflow.bmp");


	frame.startX = 0;
	frame.EndX = 3;
	frame.startY = 1;
	frame.OldTime = GetTickCount();
	frame.Speed = 150;

	info.fCX = 30.f;
	info.fCY = 30.f;
	isDead = false;

}

int downBullet::Update()
{
	//일정부분 나가면 폭탄 나오지도마.
	if (info.fY >= WINCY - 70) {
		return DEAD;
	}

	if (dwTime + 500 < GetTickCount())
		setDead();

	if (true == isDead) {
		//Object* pObj = Factory<Item>::CreateObj(L"ballon", info.fX, info.fY, 40, 40);
		//ObjMgr::Get_Instance()->Add_Object(ITEM, pObj);
		return  DEAD;
	}


	UpdateRect();
	ColliderUpdateRect();
	MoveFrame();
	return 0;
}

void downBullet::LateUpdate()
{
	
	
}

void downBullet::Render(HDC hdc)
{


	HDC memDC = BmpMgr::getInstance()->FindImage(L"D");
	if (nullptr == memDC)return;
	

	GdiTransparentBlt(hdc, rect.left-20, rect.top-10, 60,60, memDC, frame.startX* 60,
		frame.startY * 65, 60, 65, RGB(255, 201, 14));

	//Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
}

void downBullet::Release()
{
	
}

void downBullet::Collide(OBJID objid)
{
	if (objid == ITEMBOX) {

		Object* pObj = Factory<Item>::CreateObj(L"soda", info.fX, info.fY, 38, 38);
		ObjMgr::Get_Instance()->Add_Object(SODA, pObj);


	}

	isDead = true;
}
