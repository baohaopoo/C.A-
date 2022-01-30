#include "stdafx.h"
#include "Tree.h"


Tree::Tree()
{
}


Tree::~Tree()
{
	Release();
}

void Tree::Initialize()
{
	id = TREE;
	info.fCX = 10.f;
	info.fCY = 10.f;
}

int Tree::Update()
{
	if (true == isDead)
		return DEAD;
	framekey = info.name;

	UpdateRect();
	ColliderUpdateRect();
	return LIVE;
}

void Tree::LateUpdate()
{
}

void Tree::Render(HDC hdc)
{
	HDC memDC = BmpMgr::getInstance()->FindImage(framekey);
	if (nullptr == memDC)return;

	//Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);


	if (info.name == L"Eglue")
	{
		GdiTransparentBlt(hdc, rect.left, rect.top, info.fCX, info.fCY, memDC, 0, 0, 120, 120, RGB(255, 201, 14));
	}
	else {
		GdiTransparentBlt(hdc, rect.left, rect.top, info.fCX, info.fCY, memDC, 0, 0, info.fCX, info.fCY, RGB(255, 201, 14));
	}

	

}

void Tree::Release()
{
}

void Tree::Coliide(OBJID objid)
{
}
