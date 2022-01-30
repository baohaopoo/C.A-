#include "stdafx.h"
#include "TileMgr.h"
#include "Define.h"
#include "Object.h"
#include "Tile.h"
#include "Functional.h"
#include "ObjMgr.h"

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
			y = 20+TILECY + TILECY * i;
			 
		
			
			Object* tileobj = new Tile;
			tileobj->Initialize();
			tileobj->setPos(x, y);

			if (dynamic_cast<Tile*>(tileobj)->GetTileID() == L"fixbox") {
				ObjMgr::Get_Instance()->Add_Object(TILE, tileobj);
				dynamic_cast<Tile*>(tileobj)->setid(TILE);
				
			}

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

	//TCHAR str2[124];

	//for (auto& ptile : TileVec)
	//	wsprintf(str2, TEXT("%d %d"), ptile->GetInfo().fX, ptile->GetInfo().fY);

	for (auto& ptile : TileVec)
		ptile->Render(hdc);

	//for (auto& ptile : TileVec)
	//{
	//
	//	TextOut(hdc, ptile->GetInfo().fX, ptile->GetInfo().fY, str2, lstrlen(str2));

	//}



}

void TileMgr::Release()
{
	for_each(TileVec.begin(), TileVec.end(), SafeDelete<Object*>);
	TileVec.clear();
	TileVec.shrink_to_fit();
}

void TileMgr::PickTile(int index, int TileName)
{
	if (0 > index || index >= TileVec.size()) return;

	

	//if (GetAsyncKeyState(VK_RBUTTON)) {
	//	dynamic_cast<Tile*>(TileVec[index])->SetDrawID(2);

	//}
	//if (dynamic_cast<Tile*>(TileVec[index])->GetDrawID() == L"tree") {
	//	//dynamic_cast<Tile*>(TileVec[index])->SetSize(40, 70);
	//}

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
	int		iDrawID = NULL;
	
	DWORD	dwByte = 0;

	for (auto& pTile : TileVec)
	{
		tInfo = pTile->GetInfo();
		iDrawID = dynamic_cast<Tile*>(pTile)->GetDrawID();
		
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
	int	iDrawID = 0;
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

		dynamic_cast<Tile*>(pTile)->SetDrawID(iDrawID);
		TileVec.push_back(pTile);
	}

	CloseHandle(hFile);
}



