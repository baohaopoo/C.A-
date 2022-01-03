#include "stdafx.h"
#include "TileMgr.h"
#include "Define.h"
#include "Object.h"
#include "Tile.h"
#include "Functional.h"

TileMgr* TileMgr::instance = nullptr;

TileMgr* TileMgr::GetInstance()
{
	if (nullptr == instance) {
		instance = new TileMgr;
	
	}

	return instance;
}

void TileMgr::DestroyInstance()
{
	if (instance)
	{
		delete instance;
		instance = nullptr;
	}
}

TileMgr::TileMgr()
{
}

TileMgr::~TileMgr()
{
	Release();
}

void TileMgr::Initialize()
{
	float x = 0.f;
	float y = 0.f;

	for (int i = 0; i < 14; ++i) {
		for (int j = 0; j < 15; ++j) {
			x = TILECX + TILECX *j;
			y = TILECY + TILECY * i;
			 
		
			Object* tileobj = new Tile;
			tileobj->Initialize();
			tileobj->setPos(x, y);
			TileVec.push_back(tileobj);
		

		}
	}
}

void TileMgr::Update()
{
	for (auto& ptile : TileVec)
		ptile->Update();
}

void TileMgr::LateUpdate()
{
	for (auto& ptile : TileVec)
		ptile->LateUpdate();
}

void TileMgr::Render(HDC hdc)
{
	for (auto& ptile : TileVec)
		ptile->Render(hdc);
}

void TileMgr::Release()
{
	for_each(TileVec.begin(), TileVec.end(), SafeDelete<Object*>);
	TileVec.clear();
	TileVec.shrink_to_fit();
}

void TileMgr::PickTile(int index, TCHAR* TileName)
{
	if (0 > index || index >= TileVec.size()) return;

	dynamic_cast<Tile*>(TileVec[index])->SetTileID(TileName);

}

void TileMgr::SaveTile()
{
}

void TileMgr::LoadTile()
{
}
