#include "stdafx.h"
#include "Background.h"
#include "BmpMgr.h"
#include "Smoke.h"
#include"Factory.h"
#include"ObjMgr.h"
// 깨지긴 하는데 아무것도 나오지 않는. 

Background::Background()
{
}


Background::~Background()
{
	Release();
}

void Background::Initialize()
{
	id = BACKGROUND;





}

int Background::Update()
{
	if (true == isDead) {


		smoke = new Smoke();
		ObjMgr::Get_Instance()->Add_Object(SMOKE, smoke);
		smoke->setPos(info.fX -25, info.fY-25);
		smoke->Initialize();
		dwTime = GetTickCount();

		return DEAD;
	}

	framekey = info.name;


	UpdateRect();
	ColliderUpdateRect();

	return 0;
}

void Background::LateUpdate()
{
}

void Background::Render(HDC hdc)
{
	HDC memDC = BmpMgr::getInstance()->FindImage(framekey);
	

	if (nullptr == memDC)return;
	


	if (info.name == L"noItembox") {
		GdiTransparentBlt(hdc, rect.left, rect.top, info.fCX, info.fCY, memDC, 0, 0, info.fCX, info.fCY, RGB(255, 201, 14));
	}
	if(info.name == L"iceobj")
	GdiTransparentBlt(hdc, rect.left, rect.top, info.fCX, info.fCY, memDC, 0, 0, info.fCX, info.fCY, RGB(255, 201, 14));
	else
		GdiTransparentBlt(hdc, rect.left, rect.top, info.fCX, info.fCY, memDC, 0, 0, info.fCX, info.fCY, RGB(255, 201, 14));
}

void Background::Release()
{
}

void Background::Collide(OBJID objid)
{
	if (objid == MIDDLEBULLET) {
		setDead();
		
		
	}
	if (objid == LEFTBULLET) {
		setDead();
		

	}
	if (objid == RIGHTBULLET) {
		setDead();
	

	}
	if (objid == DOWNBULLET) {
		setDead();
		

	}
	if (objid == UPBULLET) {
		setDead();
	

	}

}


