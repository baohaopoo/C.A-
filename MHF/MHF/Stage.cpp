#include "stdafx.h"
#include "Stage.h"
#include "BmpMgr.h"
#include "CollisionMgr.h"
#include "TileMgr.h"
#include "ObjMgr.h"
#include "Factory.h"
Stage::Stage()
	:player(nullptr),box(nullptr),isEdit(false),skate(nullptr)
{
	
}


Stage::~Stage()
{
}

void Stage::Initialize()
{	

	BmpMgr::getInstance()->InsertBmp(L"Stage", L"../Image/UIFrm.bmp");
	BmpMgr::getInstance()->InsertBmp(L"Tile", L"../Image/map/ice.bmp");
	BmpMgr::getInstance()->InsertBmp(L"OBJ", L"../Image/object.bmp");

	//stage에 깔 오브젝트 bmp
	//BmpMgr::getInstance()->InsertBmp(L"fixbox", L"../Image/map/iceobject.bmp");
	BmpMgr::getInstance()->InsertBmp(L"fixbox", L"../Image/map/icetile.bmp");


	//

	if (isEdit== true) {
		TileMgr::GetInstance()->LoadTile();
	}

	stui = new StartUI;
	stui->Initialize();


	if (nullptr == box) {
		box = new Box;
		ObjList[BOX].push_back(box);
		box->Initialize();
	}
	if (nullptr == skate) {
		skate = new Item;
		ObjList[SKATE].push_back(skate);
		skate->Initialize();
	}
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
	
	if (GetAsyncKeyState(VK_LBUTTON)) {
		isPicking();
	}


	if (GetAsyncKeyState('X'))
		CreateItem(L"Ballon", 200, 300);

	//if (GetAsyncKeyState('C'))

	CreateItem(L"Skate", 100, 400);




	if (GetAsyncKeyState('S')) {
		TileMgr::GetInstance()->SaveTile();
		isEdit = true;
	}

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

	if (box != nullptr) {
		box->Update();
	}

	if (stui != nullptr) {
		if (DEAD == stui->Update())
		{
			delete stui;
			stui = nullptr;

		}
	}

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
	CollisionMgr::CollisionRect(ObjList[PLAYER], ObjList[SKATE]);
	CollisionMgr::CollisionRect(ObjList[PLAYER], ObjList[TILE]);
	CollisionMgr::CollisionRect(ObjList[PLAYER], ObjList[BOX]);

	TileMgr::GetInstance()->LateUpdate();
	if (stui != nullptr)
		stui->LateUpdate();

	if (box != nullptr) {
		box->LateUpdate();
	}

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
	
	//박스
	if (box != nullptr) {
		box->Render(hDC);
	}

	for (int i = 0; i < END; ++i)
	{

		for (auto& iter = ObjList[i].begin(); iter != ObjList[i].end(); ++iter) {
			(*iter)->Render(hDC);
		}
	}


	if (stui != nullptr)
		stui->Render(hDC);

	
}

void Stage::Release()
{
	
	for (auto& objLst : ObjList[PLAYER])
		objLst->Release();

	TileMgr::GetInstance()->DestroyInstance();
}

void Stage::isPicking()
{
	POINT pt = {};
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);

	int x = (int)pt.x / TILECX;
	int y = (int)pt.y / TILECY; 

	int index = x + (TILEX* y);
	TileMgr::GetInstance()->PickTile(index,L"fixbox");
	
}

void Stage::CreateItem(TCHAR * key, float x, float y)
{
	if (dwTime + 260<GetTickCount())
	{
		skate = new Item();
		//skate->setPos(uidx(dre),uidy(dre));


		skate->Initialize();
		skate->setImageKey(key);
		skate->setPos(x, y);

		ObjList[SKATE].push_back(skate);

		dwTime = GetTickCount();

	}
}
