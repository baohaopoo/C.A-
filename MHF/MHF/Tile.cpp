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

	BmpMgr::getInstance()->InsertBmp(L"test", L"../Image/camp.bmp");
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

	/*HDC memDC = BmpMgr::getInstance()->FindImage(tileID);
	if (memDC == nullptr)return;

	BitBlt(hdc, rect.left, rect.top, TILECX, TILECY, memDC, 0, 0, SRCCOPY);
*/


	HDC memDC = BmpMgr::getInstance()->FindImage(L"test");
	if (memDC == nullptr)return;

	BitBlt(hdc, rect.left, rect.top, TILECX, TILECY, memDC, 0, 0, SRCCOPY);
	//GdiTransparentBlt(hdc, 0, 0, WINCX, WINCY, memDC, 0, 0, WINCX, WINCY, RGB(255, 255, 255));

}

void Tile::Release()
{
}
