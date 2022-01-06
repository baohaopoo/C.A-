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

	for (int i = 0; i < TILEY; ++i) {
		for (int j = 0; j < TILEX; ++j) {
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
	HANDLE hFile = CreateFile(L"../Data/Tile.dat", GENERIC_WRITE, 0, 0, CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL, 0);

	if (INVALID_HANDLE_VALUE == hFile)
	{
		MessageBox(g_hWnd, L"Tile Save Failed!", L"Fail!!!!", MB_OK);
		return;
	}

	INFO	tInfo = {};
	TCHAR*		iDrawID ;
	DWORD	dwByte = 0;

	for (auto& pTile : TileVec)
	{
		tInfo = pTile->GetInfo();
		iDrawID = dynamic_cast<Tile*>(pTile)->GetTileID();

		WriteFile(hFile, &tInfo, sizeof(INFO), &dwByte, 0);
		WriteFile(hFile, &iDrawID, sizeof(int), &dwByte, 0);
	}

	CloseHandle(hFile);
	MessageBox(g_hWnd, L"Tile Save Success!", L"Success!!!!", MB_OK);
}

void TileMgr::LoadTile()
{

	HANDLE hFile = CreateFile(L"../Data/Tile.dat", GENERIC_READ, 0, 0, OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL, 0);

	if (INVALID_HANDLE_VALUE == hFile)
	{
		MessageBox(g_hWnd, L"Tile Load Failed!", L"Fail!!!!", MB_OK);
		return;
	}

	INFO	tInfo = {};
	TCHAR*	iDrawID;
	DWORD	dwByte = 0;

	while (true)
	{
		ReadFile(hFile, &tInfo, sizeof(INFO), &dwByte, 0);
		ReadFile(hFile, &iDrawID, sizeof(int), &dwByte, 0);

		if (0 == dwByte)
			break;


		Object* pTile = new Tile;
		pTile->Initialize();
		pTile->setPos(tInfo.fX, tInfo.fY);

		TileVec.push_back(pTile);
	}

	CloseHandle(hFile);
}
