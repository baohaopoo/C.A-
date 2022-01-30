#include "stdafx.h"
#include "Boss.h"
#include "stdafx.h"
#include "MonStage.h"
#include "TileMgr.h"
#include "ObjMgr.h"
#include "Factory.h"
#include "SceneMgr.h"
#include "Player.h"
#include "Monster.h"
#include "CollisionMgr.h"
#include "Box.h"
#include "Background.h"
#include "StartUI.h"
#include "PickMonster.h"
#include "SoundMgr.h"
#include "BossMonster.h"
#include "Item.h"
#include "ItemBox.h"
Boss::Boss()
{
}


Boss::~Boss()
{
	Release();
}

void Boss::Initialize()
{
	//음악
	
	SoundMgr::Get_Instance()->PlaySoundW(L"gamest.wav", SoundMgr::EFFECT, 8);

	//통프레임
	BmpMgr::getInstance()->InsertBmp(L"beach", L"../Image/map/beach222.bmp");
	BmpMgr::getInstance()->InsertBmp(L"MStartUI", L"../Image/gamestart.bmp");
	BmpMgr::getInstance()->InsertBmp(L"bossUI", L"../Image/bossmapUI.bmp");
	BmpMgr::getInstance()->InsertBmp(L"shell", L"../Image/shell.bmp");
	BmpMgr::getInstance()->InsertBmp(L"noItembox", L"../Image/map/icetile.bmp");

	//아이템.

	pObj = Factory<Item>::CreateObj(210, 420, 38, 38);
	pObj->setImage(L"soda");
	ObjMgr::Get_Instance()->Add_Object(SODA, pObj);

	pObj = Factory<Item>::CreateObj(240, 420, 38, 38);
	pObj->setImage(L"soda");
	ObjMgr::Get_Instance()->Add_Object(SODA, pObj);



	//화면 시작 UI
	pObj = Factory<StartUI>::CreateObj(320, 260, 400, 240);
	pObj->setImage(L"bossUI");
	ObjMgr::Get_Instance()->Add_Object(UI, pObj);



	//화면 시작 UI
	pObj = Factory<StartUI>::CreateObj(320, 260, 400, 140);
	pObj->setImage(L"MStartUI");
	ObjMgr::Get_Instance()->Add_Object(UI, pObj);



	//나가기 유아이
	pObj = Factory<StartUI>::CreateObj(720, 600, 140, 70);
	pObj->setImage(L"Exit2");
	ObjMgr::Get_Instance()->Add_Object(STAGEBUTTON, pObj);


	//플레이어
	pObj = Factory<Player>::CreateObj(100, 510, 30, 10);
	pObj->setID(PLAYER);
	ObjMgr::Get_Instance()->Add_Object(PLAYER, pObj);
	dynamic_cast<Player*>(pObj)->SetBulletList(ObjMgr::Get_Instance()->Get_ObjList(BULLET));

	//보스 몬스터
	pObj = Factory<BossMonster>::CreateObj(323, 180);
	pObj->setID(BOSSMON);
	pObj->setImage(L"boss");
	ObjMgr::Get_Instance()->Add_Object(BOSSMON, pObj);

	//////핑크몬스터

	//for (int i = 0; i < 2; ++i) {
	//	pObj = Factory<PickMonster>::CreateObj(200, 235 + (i * 110));
	//	pObj->setID(MONSTERU);
	//	pObj->setImage(L"PL");
	//	ObjMgr::Get_Instance()->Add_Object(MONSTERU, pObj);


	//}

	for (int i = 0; i < 2; ++i) {
		pObj = Factory<ItemBox>::CreateObj(L"shell", 40 + (i * 80), 540, 40, 40);
		ObjMgr::Get_Instance()->Add_Object(ITEMBOX, pObj);
	}

	for (int i = 0; i < 2; ++i) {
		pObj = Factory<Background>::CreateObj(L"shell", 520 + (i * 80), 540, 40, 40);
		ObjMgr::Get_Instance()->Add_Object(BACKGROUND, pObj);
	}


	for (int i = 0; i < 9; ++i) {
		pObj = Factory<ItemBox>::CreateObj(L"noItembox", 160 + (i * 40), 460, 40, 40);
		ObjMgr::Get_Instance()->Add_Object(ITEMBOX, pObj);

	}
	for (int i = 0; i < 9; ++i) {
		pObj = Factory<Background>::CreateObj(L"noItembox", 160 + (i * 40), 500, 40, 40);
		ObjMgr::Get_Instance()->Add_Object(BACKGROUND, pObj);


	}
	for (int i = 0; i < 5; ++i) {
		pObj = Factory<ItemBox>::CreateObj(L"noItembox", 160 + (i * 80), 540, 40, 40);
		ObjMgr::Get_Instance()->Add_Object(ITEMBOX, pObj);


	}



	for (int i = 0; i < 2; ++i) {
		pObj = Factory<ItemBox>::CreateObj(L"shell", 40 + (i * 80), 60, 40, 40);
		ObjMgr::Get_Instance()->Add_Object(ITEMBOX, pObj);
	}

	for (int i = 0; i < 2; ++i) {
		pObj = Factory<Background>::CreateObj(L"shell", 520 + (i * 80), 60, 40, 40);
		ObjMgr::Get_Instance()->Add_Object(BACKGROUND, pObj);
	}



	for (int i = 0; i < 5; ++i) {
		pObj = Factory<ItemBox>::CreateObj(L"noItembox", 160 + (i * 80), 100, 40, 40);
		ObjMgr::Get_Instance()->Add_Object(ITEMBOX, pObj);

	}
	for (int i = 0; i < 4; ++i) {
		pObj = Factory<Background>::CreateObj(L"noItembox", 200 + (i * 80), 140, 40, 40);
		ObjMgr::Get_Instance()->Add_Object(BACKGROUND, pObj);
	}



}

void Boss::Update()
{
	SoundMgr::Get_Instance()->PlaySoundW(L"거북맵.wav", SoundMgr::BGM, 8);
	ObjMgr::Get_Instance()->Update();
}

void Boss::LateUpdate()
{
	ObjMgr::Get_Instance()->Late_Update();
}

void Boss::Render(HDC hDC)
{
	HDC memDC = BmpMgr::getInstance()->FindImage(L"beach");

	//배경 출력 
	if (memDC == nullptr) {
		return;
	}



	//// GdiTransparentBlt: 사용자가 원하는 색상을 제거하여 비트맵을 출력.
	GdiTransparentBlt(hDC, 0, 0, WINCX, WINCY, memDC, 0, 0, WINCX, WINCY, RGB(255, 255, 255));
	ObjMgr::Get_Instance()->Render(hDC);
}

void Boss::Release()
{
	SoundMgr::Get_Instance()->StopAll();
	ObjMgr::Get_Instance()->Delete_ID(UI);
	ObjMgr::Get_Instance()->Delete_ID(STAGEBUTTON);
	ObjMgr::Get_Instance()->Delete_ID(OBJECT);
	ObjMgr::Get_Instance()->Delete_ID(BACKGROUND);
	ObjMgr::Get_Instance()->Delete_ID(ITEM);
	ObjMgr::Get_Instance()->Delete_ID(PLAYER);
	ObjMgr::Get_Instance()->Delete_ID(TREE);
	ObjMgr::Get_Instance()->Delete_ID(MONSTER);
	ObjMgr::Get_Instance()->Delete_ID(ITEMBOX);
	ObjMgr::Get_Instance()->Delete_ID(MONSTERU);
	ObjMgr::Get_Instance()->Delete_ID(BOSSMON);
	ObjMgr::Get_Instance()->Delete_ID(SODA);
}
