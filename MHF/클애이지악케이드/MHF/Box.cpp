#include "stdafx.h"
#include "Box.h"
#include "Smoke.h"
#include"Factory.h"
#include"ObjMgr.h"


Box::Box()
{
}


Box::~Box()
{
	Release();
}

void Box::Initialize()
{
	id = BOX;
	//info.fCX = 10.f;
	//info.fCY = 10.f;

}

int Box::Update()
{
	if (true == isDead) {

		smoke = new Smoke();
		ObjMgr::Get_Instance()->Add_Object(SMOKE, smoke);
		smoke->setPos(info.fX - 25, info.fY - 25);
		smoke->Initialize();
		dwTime = GetTickCount();

		return DEAD;
	}

	if ((40 >= info.fX))
		info.fX = 40;
	if ((WINCX - 200 <= info.fX))
		info.fX = WINCX - 200;
	if ((70 >= info.fY))
		info.fY = 70;
	if ((WINCY - 70 <= info.fY))
		info.fY = WINCY - 70;

	framekey = info.name;

	UpdateRect();
	ColliderUpdateRect();
	return LIVE;
}

void Box::LateUpdate()
{
}

void Box::Render(HDC hdc)
{
	HDC memDC = BmpMgr::getInstance()->FindImage(framekey);
	if (nullptr == memDC)return;


	if (info.name == L"BOX")
	{
		GdiTransparentBlt(hdc, rect.left, rect.top, info.fCX, info.fCY, memDC, 0, 0, 40,47, RGB(255, 201, 14));
	}
	if (info.name == L"realbox") {
		GdiTransparentBlt(hdc, rect.left, rect.top, info.fCX, info.fCY, memDC, 0, 0, info.fCX, info.fCY, RGB(255, 201, 14));
	
	}
	GdiTransparentBlt(hdc, rect.left, rect.top, info.fCX, info.fCY, memDC,0,0, info.fCX, info.fCY, RGB(255, 201, 14));
	//Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
	
}

void Box::Release()
{

}

void Box::Coliide(OBJID objid)
{

	if (objid == BULLET)
	{
		if (dwTime + 3000 < GetTickCount()) {
			isDead = true;
		}
	}

	if (objid == DOWNBULLET )
		isDead = true;


	if (objid == COBJECT)
		isDead = true;

	if (objid == LEFTBULLET)
		info.fY = 100000;


}
