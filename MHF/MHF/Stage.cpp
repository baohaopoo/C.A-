#include "stdafx.h"
#include "Stage.h"
#include "BmpMgr.h"
#include "CollisionMgr.h"
#include "TileMgr.h"
Stage::Stage()
	:player(nullptr)
{
}


Stage::~Stage()
{
}

void Stage::Initialize()
{	

	BmpMgr::getInstance()->InsertBmp(L"Stage", L"../Image/UIFrm.bmp");
	BmpMgr::getInstance()->InsertBmp(L"Tile", L"../Image/Tile.bmp");
	BmpMgr::getInstance()->InsertBmp(L"OBJ", L"../Image/object.bmp");


	stui.Initialize();
	if (nullptr == player) {
		player = new Player;
		ObjList[PLAYER].push_back(player);
		player->Initialize();
	}

	dynamic_cast<Player*>(player)->SetBulletList(&ObjList[BULLET]);

	TileMgr::GetInstance()->Initialize();

}

void Stage::Update()
{
	if (GetAsyncKeyState(VK_LBUTTON))
		isPicking();


	for (int i = 0; i < END; ++i)
	{

		for (auto& iter = ObjList[i].begin(); iter != ObjList[i].end(); ) {

			if (DEAD == (*iter)->Update())
			{
				delete *iter;
				*iter = nullptr;

				//	SafeDelete<Object*>(*iter);
				iter = ObjList[i].erase(iter);

			}
			else
				++iter;

		}
	}

	TileMgr::GetInstance()->Update();
	stui.Update();

}

void Stage::LateUpdate()
{
	for (int i = 0; i < END; ++i)
	{

		for (auto& iter = ObjList[i].begin(); iter != ObjList[i].end(); ++iter) {
			(*iter)->LateUpdate();
		}
	}


	CollisionMgr::CollisionRect(ObjList[PLAYER], ObjList[BULLET]);
	//CollisionMgr::CollisionShpere(ObjList[MONSTER], ObjList[BULLET]);
	TileMgr::GetInstance()->LateUpdate();
	stui.LateUpdate();
}

void Stage::Render(HDC hDC)
{



	

	TileMgr::GetInstance()->Render(hDC);


	HDC memDC = BmpMgr::getInstance()->FindImage(L"Stage");

	//배경 출력 
	if (memDC == nullptr) {
		return;
	}


	// GdiTransparentBlt: 사용자가 원하는 색상을 제거하여 비트맵을 출력.
	GdiTransparentBlt(hDC, 0, 0, WINCX, WINCY, memDC, 0, 0, WINCX, WINCY, RGB(255, 255, 255));

	for (int i = 0; i < END; ++i)
	{

		for (auto& iter = ObjList[i].begin(); iter != ObjList[i].end(); ++iter) {
			(*iter)->Render(hDC);
		}
	}
	stui.Render(hDC);
}

void Stage::Release()
{
	
	for (auto& objLst : ObjList[PLAYER])
		objLst->Release();
}

void Stage::isPicking()
{
	POINT pt = {};
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);

	int x = pt.x / TILECX;
	int y = pt.y / TILECY; 

	int index = x + TILECX* y;
	TileMgr::GetInstance()->PickTile(index, L"OBJ");
	
}
