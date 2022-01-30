#include "stdafx.h"
#include "ItemBox.h"
#include"Factory.h"
#include "Item.h"
#include"ObjMgr.h"
#include "Smoke.h"
#include "BmpMgr.h"
ItemBox::ItemBox()
{
}


ItemBox::~ItemBox()
{
	Release();
}

void ItemBox::Initialize()
{
	id = ITEMBOX;
	info.fCX = 10.f;
	info.fCY = 10.f;
\

}

int ItemBox::Update()
{
	if (isCollision) {
		
	}
	if (true == isDead) {


		Object* smoke = new Smoke();
		ObjMgr::Get_Instance()->Add_Object(SMOKE, smoke);
		smoke->setPos(info.fX - 25, info.fY - 25);
		smoke->Initialize();
		dwTime = GetTickCount();


	


		

		return DEAD;
	}

	framekey = info.name;

	UpdateRect();
	ColliderUpdateRect();
	return LIVE;
}

void ItemBox::LateUpdate()
{
}

void ItemBox::Render(HDC hdc)
{
	HDC memDC = BmpMgr::getInstance()->FindImage(framekey);
	if (nullptr == memDC)return;
	GdiTransparentBlt(hdc, rect.left, rect.top, info.fCX, info.fCY, memDC, 0, 0, info.fCX, info.fCY, RGB(255, 201, 14));
	//Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
}

void ItemBox::Release()
{
}

void ItemBox::Coliide(OBJID objid)
{
	if (objid == LEFTBULLET) {
		
		isCollision = true;
		setDead();
	}
	if (objid == RIGHTBULLET) {
		Object* pObj = Factory<Item>::CreateObj(L"jusa", info.fX,info.fY, 38, 38);
		ObjMgr::Get_Instance()->Add_Object(ITEM, pObj);
		setDead();
	}
	if (objid == UPBULLET) {
		Object* pObj = Factory<Item>::CreateObj(L"jusa", info.fX, info.fY, 38, 38);
		ObjMgr::Get_Instance()->Add_Object(ITEM, pObj);
		setDead();
	}
	if (objid == DOWNBULLET) {
		Object* pObj = Factory<Item>::CreateObj(L"balllon", info.fX, info.fY, 38, 38);
		ObjMgr::Get_Instance()->Add_Object(ITEM, pObj);
		setDead();
	}
	if (objid == MIDDLEBULLET) {
		Object* pObj = Factory<Item>::CreateObj(L"skate", info.fX, info.fY, 38, 38);
		setDead();
	}
}
