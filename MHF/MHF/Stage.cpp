#include "stdafx.h"
#include "Stage.h"
#include"BmpMgr.h"
#include "CollisionMgr.h"
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

	if (nullptr == player) {
		player = new Player;
		ObjList[PLAYER].push_back(player);
		player->Initialize();
	}

	dynamic_cast<Player*>(player)->SetBulletList(&ObjList[BULLET]);



}

void Stage::Update()
{
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

void Stage::LateUpdate()
{
	for (int i = 0; i < END; ++i)
	{

		for (auto& iter = ObjList[i].begin(); iter != ObjList[i].end(); ++iter) {
			(*iter)->LateUpdate();
		}
	}


	//CollisionMgr::CollisionRect(ObjList[MONSTER], ObjList[BULLET]);
	CollisionMgr::CollisionShpere(ObjList[MONSTER], ObjList[BULLET]);
}

void Stage::Render(HDC hDC)
{


	HDC memDC = nullptr;
	memDC = BmpMgr::getInstance()->FindImage(L"Stage");
	//배경 출력 
	if ( memDC == nullptr) {
		return;
	}

	BitBlt(hDC, 0, 0, WINCX, WINCY, memDC, 0, 0, SRCCOPY);



	for (int i = 0; i < END; ++i)
	{

		for (auto& iter = ObjList[i].begin(); iter != ObjList[i].end(); ++iter) {
			(*iter)->Render(hDC);
		}
	}



}

void Stage::Release()
{
	
	for (auto& objLst : ObjList[PLAYER])
		objLst->Release();
}
