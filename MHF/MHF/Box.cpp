#include "stdafx.h"
#include "Box.h"


Box::Box()
{
}


Box::~Box()
{
}

void Box::Initialize()
{
	id = BOX;
	info.fCX = 10.f;
	info.fCY = 10.f;

	/*info.fCX = 120.f;
	info.fCY = 120.f;*/
	//framekey = L"";
}

int Box::Update()
{

	if (isDead)
		return DEAD;

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

	//Rectangle(hdc, colliderBox.left, colliderBox.top, colliderBox.right, colliderBox.bottom);
	GdiTransparentBlt(hdc, colliderBox.left, colliderBox.top, info.fCX, info.fCY, memDC, 0, 0, info.fCX, info.fCY, RGB(255, 201, 14));

	//GdiTransparentBlt(hdc, info.fX-60 , info.fCY+40, info.fCX, info.fCY, memDC, 0, 0, info.fCX, info.fCY, RGB(255, 201, 14));

	
}

void Box::Release()
{
}

void Box::Coliide(OBJID objid)
{

		isDead = true;




}
