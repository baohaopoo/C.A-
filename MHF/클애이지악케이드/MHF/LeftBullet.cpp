#include "stdafx.h"
#include "LeftBullet.h"
#include "BmpMgr.h"
#include"Factory.h"
#include "Item.h"
#include"ObjMgr.h"

LeftBullet::LeftBullet()
{
}


LeftBullet::~LeftBullet()
{
	Release();
}

void LeftBullet::Initialize()
{
	id = LEFTBULLET;
	BmpMgr::getInstance()->InsertBmp(L"L", L"../Image/leftflow.bmp");
	BmpMgr::getInstance()->InsertBmp(L"fake", L"../Image/bb.bmp"); //정사각형 터짐.
	frame.startX = 4;
	frame.EndX = 7;
	frame.startY = 1;
	frame.OldTime = GetTickCount();
	frame.Speed = 150;

	info.fCX = 30.f;
	info.fCY = 30.f;
	isDead = false;
}

int LeftBullet::Update()
{

	if (info.fX <= 40) {
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

void LeftBullet::LateUpdate()
{
}

void LeftBullet::Render(HDC hdc)
{

	HDC memDC = BmpMgr::getInstance()->FindImage(L"D");
	if (nullptr == memDC)return;


	GdiTransparentBlt(hdc, rect.left - 22, rect.top - 18, 60, 60, memDC, frame.startX * 61,
		frame.startY * 65, 60, 65, RGB(255, 201, 14));

}
void LeftBullet::Release()
{
}

void LeftBullet::Collide(OBJID objid)
{
	if (objid == ITEMBOX) {
	
		Object* pObj = Factory<Item>::CreateObj(L"skate", info.fX,info.fY, 38, 38);
		ObjMgr::Get_Instance()->Add_Object(ITEM, pObj);

	
	}
	
	isDead = true;
}
