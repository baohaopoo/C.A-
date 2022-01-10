#include "stdafx.h"
#include "Tile.h"
#include"BmpMgr.h"
#include"Enum.h"
Tile::Tile()
	:tileID(0),drawID(1)
{
}

Tile::~Tile()
{
	Release();
}

void Tile::SetTileID(TCHAR * name)
{

		tileID= name; 
		BmpMgr::getInstance()->FindImage(tileID);
	
}

TCHAR * Tile::GetTileID()
{
	return tileID;
}

void Tile::Initialize()
{
	id= TILE;
	info.fCX = (float)TILECX;
	info.fCY = (float)TILECY;

	tileID = L"fixbox";

	drawID = 0;

	cnt = 0;
}

int Tile::Update()
{

	return LIVE;
	
}

void Tile::LateUpdate()
{
	//if (tileID == L"Tree") {
	//	SetSize(40, 70);
	//}
	

	//if (drawID == 2) {
	//	tileID = L"jusa";
	//}

} 

void Tile::Render(HDC hdc)
{
	Object::UpdateRect();


	if (drawID == 0) {
		tileID = L"iceobj";
	}
	HDC memDC = BmpMgr::getInstance()->FindImage(tileID);
	if (memDC == nullptr)return;
	

	GdiTransparentBlt(hdc, rect.left, rect.top, TILECX, TILECY, memDC, 0, 0, TILECX, TILECY, RGB(255, 255, 255));


}

void Tile::Release()
{
}
 
void Tile::SetSize(float x, float y)
{
	info.fCX = x; 
	info.fCY = y;
}
