#include "stdafx.h"
#include "MonStage.h"
#include "TileMgr.h"
#include "ObjMgr.h"
#include "Factory.h"
#include "SceneMgr.h"
#include "Player.h"
#include "Monster.h"
#include "CollisionMgr.h"
MonStage::MonStage()
{
}


MonStage::~MonStage()
{
}

void MonStage::Initialize()
{
	Object* pObj;
	pObj = Factory<Player>::CreateObj(459, 200);
	ObjList[PLAYER].push_back(pObj);
	dynamic_cast<Player*>(pObj)->SetBulletList(&ObjList[BULLET]);



	pObj = Factory<Monster>::CreateObj(159, 300);
	ObjList[MONSTER].push_back(pObj);


	//통프레임
	BmpMgr::getInstance()->InsertBmp(L"Stage", L"../Image/UIFrm2.bmp");

	BmpMgr::getInstance()->InsertBmp(L"iceobj", L"../Image/map/iceobject.bmp");

	for (int i = 0; i < 15; ++i) {
		pObj = Factory<Item>::CreateObj(L"iceobj", 40 + (i * 40), 540, 40, 40);
		ObjList[SKATE].push_back(pObj);
	}

	for (int i = 0; i < 15; ++i) {
		pObj = Factory<Item>::CreateObj(L"iceobj", 40 + (i * 40), 60, 40, 40);
		ObjList[SKATE].push_back(pObj);
	}

	for (int i = 0; i < 11; ++i) {
		pObj = Factory<Item>::CreateObj(L"iceobj", 40 , 100 +(i * 40), 40, 40);
		ObjList[SKATE].push_back(pObj);
	}

	for (int i = 0; i < 11; ++i) {
		pObj = Factory<Item>::CreateObj(L"iceobj", 600 ,100 + (i * 40), 40, 40);
		ObjList[SKATE].push_back(pObj);
	}

}

void MonStage::Update()
{
	TileMgr::GetInstance()->Update();
	//오브젝트
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

}

void MonStage::LateUpdate()
{
	//타일
	TileMgr::GetInstance()->LateUpdate();
	for (int i = 0; i < END; ++i)
	{

		for (auto& iter = ObjList[i].begin(); iter != ObjList[i].end(); ++iter) {
			(*iter)->LateUpdate();
		}
	}



	CollisionMgr::CollisionObject(ObjList[PLAYER], ObjList[SKATE]);
}

void MonStage::Render(HDC hDC)
{
	HDC memDC = BmpMgr::getInstance()->FindImage(L"Stage");

	//배경 출력 
	if (memDC == nullptr) {
		return;
	}


	//// GdiTransparentBlt: 사용자가 원하는 색상을 제거하여 비트맵을 출력.
	GdiTransparentBlt(hDC, 0, 0, WINCX, WINCY, memDC, 0, 0, WINCX, WINCY, RGB(255, 255, 255));

	for (int i = 0; i < END; ++i)
	{

		for (auto& iter = ObjList[i].begin(); iter != ObjList[i].end(); ++iter) {
			(*iter)->Render(hDC);
		}
	}


}

void MonStage::Release()
{
}

void MonStage::isPicking()
{
	POINT pt = {};
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);

	int x = (int)pt.x / TILECX;
	int y = (int)pt.y / TILECY; 

	int index = x + (TILEX* y);
}
