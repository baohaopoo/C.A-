#include "stdafx.h"
#include "Item.h"

//롤러스케이트
Item::Item()
{
}


Item::~Item()
{
}

void Item::Initialize()
{
	id = SKATE;

	info.fX = uidx(dre);
	info.fY = uidy(dre);

	info.fCX = 38.f;
	info.fCY = 38.f;

	cnt = 0;
	
}

int Item::Update()
{
	if (isCollision) {
		if (isDead)
			return DEAD;

	}


	imageKey = info.name;
	if (imageKey == L"ballon" || imageKey == L"skate") {
		//아이템 나름 움직이라고 넣은 것..
		if (cnt < 3) {
			++cnt;
			info.fY -= 1;
		}
		if (cnt >= 3) {
			++cnt;
			info.fY += 1;
		}
		if (cnt == 6)
			cnt = 0;


		if (isDead)
			return DEAD;
	}
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

		//충돌박스 
		Rectangle(hdc, colliderBox.left, colliderBox.top, colliderBox.right, colliderBox.bottom);

		


		GdiTransparentBlt(hdc, colliderBox.left, colliderBox.top, info.fCX, info.fCY, memDC, 0, 0, info.fCX, info.fCY, RGB(255, 201, 14));



}

void Item::Release()
{
}

void Item::Collide(OBJID objid)
{
	isDead = true;

	if (objid == BULLET)
	{

		isCollision = true;
	
	}
}

void Item::setImageKey(TCHAR * key)
{
	imageKey = key;
}
