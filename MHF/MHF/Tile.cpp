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
		BmpMgr::getInstance()->FindImage(tileID);
	
}

TCHAR * Tile::GetTileID()
{
	return tileID;
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


	// GdiTransparentBlt: 사용자가 원하는 색상을 제거하여 비트맵을 출력.
	//GdiTransparentBlt(memDC, rect.left, rect.top, TILECX, TILECY, memDC, 0, 0, WINCX, WINCY, RGB(255, 255, 255));



	//GdiTransparentBlt(hdc, 0, 0, WINCX, WINCY, memDC, 0, 0, WINCX, WINCY, RGB(255, 255, 255));

}

void Tile::Release()
{
}
