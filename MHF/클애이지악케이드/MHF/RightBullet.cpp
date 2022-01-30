#include "stdafx.h"
#include "RightBullet.h"
#include "BmpMgr.h"
#include "Factory.h"
#include "Item.h"
#include "ObjMgr.h"

RightBullet::RightBullet()
{
	Release();
}


RightBullet::~RightBullet()
{
}

void RightBullet::Initialize()
{
	id = RIGHTBULLET;
	BmpMgr::getInstance()->InsertBmp(L"R", L"../Image/leftflow.bmp");


	frame.startX = 4;
	frame.EndX = 7;
	frame.startY = 0;
	frame.OldTime = GetTickCount();
	frame.Speed = 150;

	info.fCX = 30.f;
	info.fCY = 30.f;
	isDead = false;
}

int RightBullet::Update()
{
	if (info.fX >= WINCX -200) {
		return DEAD;
	}

	if (dwTime + 500 < GetTickCount())
		setDead();
	if (true == isDead) {
		//Object* pObj = Factory<Item>::CreateObj(L"jusa", info.fX, info.fY, 40, 40);
		//ObjMgr::Get_Instance()->Add_Object(ITEM, pObj);
		return  DEAD;
	}


	UpdateRect();
	ColliderUpdateRect();
	MoveFrame();

	return 0;
}

void RightBullet::LateUpdate()
{
}

void RightBullet::Render(HDC hdc)
{

	HDC memDC = BmpMgr::getInstance()->FindImage(L"D");
	if (nullptr == memDC)return;


	GdiTransparentBlt(hdc, rect.left - 20, rect.top - 8, 60, 60, memDC, frame.startX * 60,
		frame.startY * 65, 60, 65, RGB(255, 201, 14));
}

void RightBullet::Release()
{
}

void RightBullet::Collide(OBJID objid)
{

	if (objid == ITEMBOX) {

		Object* pObj = Factory<Item>::CreateObj(L"ballon", info.fX, info.fY, 38, 38);
		ObjMgr::Get_Instance()->Add_Object(ITEM, pObj);


	}

	isDead = true;
}
