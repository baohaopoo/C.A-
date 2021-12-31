#include "stdafx.h"
#include "Monster.h"


Monster::Monster()
{
}
Monster::~Monster()
{
}

void Monster::Initialize()
{

	info.fX = 300.f;
	info.fY = 200.f;


	info.fCX = 60.f;
	info.fCY = 60.f;

	info.fSpeed = 10.f;
}

int Monster::Update()
{
	if (true == isDead)
		return DEAD;

	info.fX += info.fSpeed;

	UpdateRect();
	return LIVE;
}

void Monster::LateUpdate()
{
	if(WINCX - 80 <= rect.right || 80 >= rect.left)
		info.fSpeed *= -1.f;

	
}

void Monster::Render(HDC hdc)
{
	Ellipse(hdc, rect.left, rect.top, rect.right, rect.bottom);
}

void Monster::Release()
{
}
