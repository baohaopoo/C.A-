#include "stdafx.h"
#include "middleBullet.h"
#include "BmpMgr.h"
#include "Factory.h"
#include "Item.h"
#include "ObjMgr.h"

middleBullet::middleBullet()
{
	Release();
}


middleBullet::~middleBullet()
{
	
}

void middleBullet::Initialize()
{
	id = MIDDLEBULLET;

	BmpMgr::getInstance()->InsertBmp(L"middle", L"../Image/bb.bmp"); 
	frame.startX = 0;
	frame.EndX = 3;
	frame.startY = 0;
	frame.OldTime = GetTickCount();
	frame.Speed = 150;

	info.fCX = 30.f;
	info.fCY = 30.f;
	isDead = false;
}

int middleBullet::Update()
{
	if (dwTime + 500 < GetTickCount())
		setDead();
	if (true == isDead) {

		return  DEAD;
	}


	UpdateRect();
	ColliderUpdateRect();
	MoveFrame();

	return 0;
}

void middleBullet::LateUpdate()
{
}

void middleBullet::Render(HDC hdc)
{
	HDC memDC = BmpMgr::getInstance()->FindImage(L"middle");
	if (nullptr == memDC)return;

	GdiTransparentBlt(hdc, rect.left - 12, rect.top - 10, 50, 55, memDC, frame.startX * 50,
		frame.startY * 55, 50, 55, RGB(255, 201, 14));

}

void middleBullet::Release()
{
}

void middleBullet::Collide(OBJID objid)
{
	if (objid == ITEMBOX) {

		Object* pObj = Factory<Item>::CreateObj(L"skate", info.fX, info.fY, 38, 38);
		ObjMgr::Get_Instance()->Add_Object(ITEM, pObj);


	}

	isDead = true;
}
