#include "stdafx.h"
#include "UpBullet.h"
#include "BmpMgr.h"
#include "Factory.h"
#include "BmpMgr.h"
#include "Item.h"
#include "ObjMgr.h"

UpBullet::UpBullet()
{
}


UpBullet::~UpBullet()
{
	Release();
}

void UpBullet::Initialize()
{
	id = UPBULLET;

	BmpMgr::getInstance()->InsertBmp(L"U", L"../Image/Bomb/upflow.bmp");

	frame.startX = 0;
	frame.EndX = 3;
	frame.startY = 0;
	frame.OldTime = GetTickCount();
	frame.Speed = 150;

	info.fCX = 30.f;
	info.fCY = 30.f;
	isDead = false;
}

int UpBullet::Update()
{
	if (info.fY <= 40) {
		return DEAD;

	}
	if (dwTime + 500 < GetTickCount())
		setDead();
	
	if (true == isDead) {
		//Object* pObj = Factory<Item>::CreateObj(L"skate", info.fX,info.fY, 38, 38);
		//ObjMgr::Get_Instance()->Add_Object(ITEM, pObj);

		return  DEAD;
	}


	UpdateRect();
	ColliderUpdateRect();
	MoveFrame();
	return 0;
}

void UpBullet::LateUpdate()
{
}

void UpBullet::Render(HDC hdc)
{
	HDC memDC = BmpMgr::getInstance()->FindImage(L"D");
	if (nullptr == memDC)return;


	GdiTransparentBlt(hdc, rect.left - 20, rect.top - 10, 60, 60, memDC, frame.startX * 60,
		frame.startY * 65, 60, 65, RGB(255, 201, 14));
}

void UpBullet::Release()
{
}

void UpBullet::Collide(OBJID objid)
{
	if (objid == ITEMBOX) {

		Object* pObj = Factory<Item>::CreateObj(L"ballon", info.fX, info.fY, 38, 38);
		ObjMgr::Get_Instance()->Add_Object(ITEM, pObj);


	}


	isDead = true;
}
