#include "stdafx.h"
#include "Tile.h"
#include"BmpMgr.h"
Tile::Tile()
	:tileID(0)
{
}

Tile::~Tile()
{
	Release();
}

void Tile::SetTileID(TCHAR * name)
{

		tileID = name; 
		//BmpMgr::getInstance()->FindImage(tileID);
	
}

void Tile::Initialize()
{
	info.fCX = (float)TILECX;
	info.fCY = (float)TILECY;

	tileID = L"Tile";
}

int Tile::Update()
{
	return LIVE;
}

void Tile::LateUpdate()
{
}

void Tile::Render(HDC hdc)
{
	Object::UpdateRect();

	HDC memDC = BmpMgr::getInstance()->FindImage(tileID);
	if (memDC == nullptr)return;

	BitBlt(hdc, rect.left, rect.top, TILECX, TILECY, memDC, 0, 0, SRCCOPY);

}

void Tile::Release()
{
}
