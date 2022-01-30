#include "stdafx.h"
#include "Item.h"
#include "SoundMgr.h"
#include"Factory.h"
#include"ObjMgr.h"
#include"StartUI.h"
Item::Item()
{
}


Item::~Item()
{
	Release();
}

void Item::Initialize()
{
	id = ITEM;
	BmpMgr::getInstance()->InsertBmp(L"dShadow", L"../Image/itemsh.bmp");
	BmpMgr::getInstance()->InsertBmp(L"jusa", L"../Image/Item/jusa.bmp");
	BmpMgr::getInstance()->InsertBmp(L"ballon", L"../Image/Item/ballon.bmp");
	BmpMgr::getInstance()->InsertBmp(L"skate", L"../Image/Item/skate.bmp");
	BmpMgr::getInstance()->InsertBmp(L"ride", L"../Image/Item/ride2.bmp");
	BmpMgr::getInstance()->InsertBmp(L"soda", L"../Image/Item/soda.bmp");
	BmpMgr::getInstance()->InsertBmp(L"gold1", L"../Image/Item/gold.bmp");
	BmpMgr::getInstance()->InsertBmp(L"gold2", L"../Image/Item/gold2.bmp");
	BmpMgr::getInstance()->InsertBmp(L"gold3", L"../Image/Item/gold3.bmp");
	BmpMgr::getInstance()->InsertBmp(L"gold4", L"../Image/Item/gold4.bmp");
	BmpMgr::getInstance()->InsertBmp(L"gold5", L"../Image/Item/gold5.bmp");
	BmpMgr::getInstance()->InsertBmp(L"gold6", L"../Image/Item/gold6.bmp");
	cnt = 0;
	cnt2 = 0;
}

int Item::Update()
{
	if (isCollision) {
	
		if (isDead) {

			return DEAD;
		}
	}


	if ((40 >= info.fX))
		return DEAD;

	if (WINCX - 200 < info.fX)
		return DEAD;


	if (70 >= info.fY)
		return DEAD;

	if ((WINCY - 70 <= info.fY))
		return DEAD;
	
	
	imageKey = info.name;
	
	

	//
	//if (cnt > 10) {
	//	
	//	info.fY += 0.1;

	//}
	//if (cnt > 20) {
	//	info.fY -= 0.1;
	//	cnt = 0;
	//}
	//if (dwTime + 500 < GetTickCount()) {
	//	cnt+=1;
	//	
	//}




	UpdateRect();
	ColliderUpdateRect();

	return LIVE;
}

void Item::LateUpdate()
{
	if (isCollision) {
		
		isDead = true;
	}
}

void Item::Render(HDC hdc)
{
	HDC memDC = BmpMgr::getInstance()->FindImage(imageKey);
	if (nullptr == memDC)return;


		HDC memDC3 = BmpMgr::getInstance()->FindImage(L"dShadow");
		if (nullptr == memDC3)return;
		GdiTransparentBlt(hdc, rect.left+13, rect.top +32, 20, 10, memDC3, 0, 0, 16, 10, RGB(255, 201, 14));


	GdiTransparentBlt(hdc, rect.left, rect.top, info.fCX, info.fCY, memDC, 0, 0, info.fCX, info.fCY, RGB(255, 201, 14));




}

void Item::Release()
{

}

void Item::Collide(OBJID objid)
{
	if (objid == PLAYER) {
		isDead = true;
	}
	info.fX = 1000.f;
}



void Item::setImageKey(TCHAR * key)
{
	imageKey = key;
}
