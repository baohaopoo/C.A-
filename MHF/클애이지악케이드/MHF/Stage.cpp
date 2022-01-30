#include "stdafx.h"
#include "Stage.h"
#include "BmpMgr.h"
#include "CollisionMgr.h"
#include "TileMgr.h"
#include "ObjMgr.h"
#include "Functional.h"
#include "Factory.h"
#include "SoundMgr.h"
#include "StartUI.h"
#include "Tree.h"
#include "ItemBox.h"
#include "Background.h"
#include"Computer.h"

Stage::Stage()
{
}

Stage::~Stage()
{
	Release();
}

void Stage::Initialize()
{
	SoundMgr::Get_Instance()->PlaySoundW(L"game.wav", SoundMgr::BGM, 8);
	SoundMgr::Get_Instance()->PlaySoundW(L"gamest.wav", SoundMgr::EFFECT, 8);

	//통프레임
	BmpMgr::getInstance()->InsertBmp(L"Stage", L"../Image/UIFrm2.bmp");
	//오브젝트
	BmpMgr::getInstance()->InsertBmp(L"OBJ", L"../Image/object.bmp");
	//나가기 버튼.
	m_pBmgMgr->InsertBmp(L"Exit", L"../Image/Exit.bmp");
	BmpMgr::getInstance()->InsertBmp(L"LOSE", L"../Image/lose.bmp");
	BmpMgr::getInstance()->InsertBmp(L"StartUI", L"../Image/startui.bmp"); 
	//진짜 주요 타일(충돌처리 해야함)
	BmpMgr::getInstance()->InsertBmp(L"fixbox", L"../Image/map/icetile.bmp");
	//BmpMgr::getInstance()->InsertBmp(L"iceobj", L"../Image/map/iceobject.bmp");
	BmpMgr::getInstance()->InsertBmp(L"MStartUI", L"../Image/gamestart.bmp");
	//아이템 타일
	BmpMgr::getInstance()->InsertBmp(L"jusa", L"../Image/Item/jusa.bmp");
	BmpMgr::getInstance()->InsertBmp(L"ballon", L"../Image/Item/ballon.bmp");
	BmpMgr::getInstance()->InsertBmp(L"skate", L"../Image/Item/skate.bmp");

	BmpMgr::getInstance()->InsertBmp(L"Eglue", L"../Image/Object/eglue.bmp");
	BmpMgr::getInstance()->InsertBmp(L"realbox", L"../Image/map/box.bmp");
	//나무
	BmpMgr::getInstance()->InsertBmp(L"tree", L"../Image/Object/tree.bmp");
	//더미
	BmpMgr::getInstance()->InsertBmp(L"dummy", L"../Image/Object/dummy.bmp");
	//밀리는 얼음
	BmpMgr::getInstance()->InsertBmp(L"iceobj", L"../Image/map/iceobject.bmp");
	//깨지는 얼음
	BmpMgr::getInstance()->InsertBmp(L"noItembox", L"../Image/map/icetile.bmp");

	Object* pObj = nullptr;
	
	//나가기 유아이
	pObj = Factory<StartUI>::CreateObj(720, 600, 140, 70);
	pObj->setImage(L"Exit");
	ObjMgr::Get_Instance()->Add_Object(STAGEBUTTON, pObj);

	//	//start UI
	pObj = Factory<StartUI>::CreateObj(320,290,445,248);
	pObj->setImage(L"StartUI");
	ObjMgr::Get_Instance()->Add_Object(UI, pObj);


	///////////////////////////////////////////////////////////////////////////////////
	//이글루, 나무나 더미같이 깨지지 않는 고정 단단.

	pObj = Factory<Tree>::CreateObj(L"Eglue",160,180,120,120);
	ObjMgr::Get_Instance()->Add_Object(TREE, pObj);

	pObj = Factory<Tree>::CreateObj(L"Eglue",480, 180,120,120);
	ObjMgr::Get_Instance()->Add_Object(TREE, pObj);


		//위쪽나무 심기
		for (int i = 0; i < 6; ++i) {
			pObj = Factory<ItemBox>::CreateObj(L"iceobj", 320, 40 + (i * 40), 40, 40);
			ObjMgr::Get_Instance()->Add_Object(ITEMBOX, pObj);
		}
		//나무 심기
		for (int i = 0; i < 5; ++i) {
			pObj = Factory<Tree>::CreateObj(L"tree", 240 + (i * 40), 280, 40, 70);
			ObjMgr::Get_Instance()->Add_Object(TREE, pObj);
		}
		//왼쪽나무 심기
		for (int i = 0; i < 2; ++i) {
			pObj = Factory<Tree>::CreateObj(L"tree", 80 + (i * 40), 280, 40, 70);
			ObjMgr::Get_Instance()->Add_Object(TREE, pObj);
		}
		//오른쪽나무 심기
		for (int i = 0; i < 2; ++i) {
			pObj = Factory<Tree>::CreateObj(L"tree", 520 + (i * 40), 280, 40, 70);
			ObjMgr::Get_Instance()->Add_Object(TREE, pObj);
		}
		//dummy
		for (int i = 0; i < 7; ++i) {
			pObj = Factory<Tree>::CreateObj(L"dummy", 80 + (i * 80), 450, 40, 60);
			ObjMgr::Get_Instance()->Add_Object(TREE, pObj);
		}
	
		for (int i = 0; i < 7; ++i) {
			pObj = Factory<Tree>::CreateObj(L"dummy", 80 + (i * 80), 370, 40, 60);
			ObjMgr::Get_Instance()->Add_Object(TREE, pObj);
		}
	


	//깨지긴 하는데 아무것도 나오지 않는 박스

	for (int i = 0; i < 2; ++i) {
		pObj = Factory<Background>::CreateObj(L"noItembox", 100 + (i * 40), 300, 40, 40);
		ObjMgr::Get_Instance()->Add_Object(BACKGROUND, pObj);
	}

	for (int i = 0; i < 2; ++i) {
		pObj = Factory<Background>::CreateObj(L"noItembox", 440 + (i * 40), 300, 40, 40);
		ObjMgr::Get_Instance()->Add_Object(BACKGROUND, pObj);

	}


	for (int i = 0; i < 2; ++i) {
		pObj = Factory<Background>::CreateObj(L"noItembox", 440 + (i * 40), 300, 40, 40);
		ObjMgr::Get_Instance()->Add_Object(BACKGROUND, pObj);

	}

	for (int i = 0; i < 15; ++i) {
		pObj = Factory<Background>::CreateObj(L"noItembox", 40 + (i * 40), 300, 40, 40);
		ObjMgr::Get_Instance()->Add_Object(BACKGROUND, pObj);

	}

	for (int i = 0; i < 15; ++i) {
		pObj = Factory<Background>::CreateObj(L"noItembox", 40 + (i * 40), 340, 40, 40);
		ObjMgr::Get_Instance()->Add_Object(BACKGROUND, pObj);

	}

//	///////////////////////////////////////////////////////////////////////////////////
// 밀리는 박스  


	pObj = Factory<Box>::CreateObj(L"realbox", 120, 100, 40, 47);
	ObjMgr::Get_Instance()->Add_Object(BOX, pObj);

	//pObj = Factory<Box>::CreateObj(L"skate", 40, 220, 42, 48);
	//ObjMgr::Get_Instance()->Add_Object(ITEM, pObj);

//	///////////////////////////////////////////////////////////////////////////////////

	pObj = Factory<ItemBox>::CreateObj(L"iceobj", 40, 220, 42, 48);
	ObjMgr::Get_Instance()->Add_Object(BACKGROUND, pObj);

	pObj = Factory<Background>::CreateObj(L"iceobj", 80, 220, 42, 48);
	ObjMgr::Get_Instance()->Add_Object(BACKGROUND, pObj);


//	//가운쪽얼음 
	for (int i = 0; i < 2; ++i) {
		pObj = Factory<ItemBox>::CreateObj(L"iceobj", 280 + (i * 80), 220, 42, 48);
		ObjMgr::Get_Instance()->Add_Object(ITEMBOX, pObj);
	}
	//왼쪽얼음 
	for (int i = 0; i < 2; ++i) {
		pObj = Factory<ItemBox>::CreateObj(L"iceobj",560 + (i * 40), 220, 42, 48);
		ObjMgr::Get_Instance()->Add_Object(ITEMBOX, pObj);
	}
	//그 위 밑얼음 2
	for (int i = 0; i < 9; ++i) {
		pObj = Factory<Background>::CreateObj(L"iceobj", 160 + (i * 40), 420, 40, 40);
		ObjMgr::Get_Instance()->Add_Object(BACKGROUND, pObj);
	}
	//그 위 밑얼음 
	for (int i = 0; i < 9; ++i) {
		pObj = Factory<Background>::CreateObj(L"iceobj", 160 + (i * 40), 500, 40, 40);
		ObjMgr::Get_Instance()->Add_Object(BACKGROUND, pObj);
	}
	//밑얼음 
	for (int i = 0; i < 15; ++i) {
		pObj = Factory<Background>::CreateObj(L"iceobj", 40 + (i * 40), 540, 40, 40);
		ObjMgr::Get_Instance()->Add_Object(BACKGROUND, pObj);
	}


	//아이스타일 위쪽 얼음
	for (int i = 0; i < 2; ++i) {
		pObj = Factory<Background>::CreateObj(L"iceobj", 160 + (i * 40), 260, 40, 40);
		ObjMgr::Get_Instance()->Add_Object(BACKGROUND, pObj);
	}
	//아이스타일 위쪽 얼음
	for (int i = 0; i < 2; ++i) {
		pObj = Factory<Background>::CreateObj(L"iceobj", 400 + (i * 40), 260, 40, 40);
		ObjMgr::Get_Instance()->Add_Object(BACKGROUND, pObj);
	}
/////////////////////////////////////////////////////////////////////////////////////////////

//	///////////////////////////////////////////////////////////////////////////////////


	pObj = Factory<Player>::CreateObj(123, 180, 30, 10);
	pObj->setID(PLAYER);
	ObjMgr::Get_Instance()->Add_Object(PLAYER, pObj);
	//ObjList[PLAYER].push_back(pObj);
	//dynamic_cast<Player*>(pObj)->SetBulletList(&ObjList[BULLET]);
	dynamic_cast<Player*>(pObj)->SetBulletList(ObjMgr::Get_Instance()->Get_ObjList(BULLET));


	pObj = Factory < Player > ::CreateObj(409, 180, 30, 10);
	pObj->setID(COMPUTER);
	ObjMgr::Get_Instance()->Add_Object(COMPUTER, pObj);

	dynamic_cast<Player*>(pObj)->SetBulletList(ObjMgr::Get_Instance()->Get_ObjList(BULLET));
}

void Stage::Update()
{
	SoundMgr::Get_Instance()->PlaySoundW(L"game.wav", SoundMgr::BGM, 8);
	ObjMgr::Get_Instance()->Update();

	
}

void Stage::LateUpdate()
{
	ObjMgr::Get_Instance()->Late_Update();


}

void Stage::Render(HDC hDC)
{
	HDC memDC = BmpMgr::getInstance()->FindImage(L"Stage");

	//배경 출력 
	if (memDC == nullptr) {
		return;
	}

	GdiTransparentBlt(hDC, 0, 0, WINCX, WINCY, memDC, 0, 0, WINCX, WINCY, RGB(255, 255, 255));

	


	ObjMgr::Get_Instance()->Render(hDC);



	
}

void Stage::Release()
{

	SoundMgr::Get_Instance()->StopAll();
	ObjMgr::Get_Instance()->Delete_ID(UI);
	
	ObjMgr::Get_Instance()->Delete_ID(STAGEBUTTON);

	ObjMgr::Get_Instance()->Delete_ID(OBJECT);

	ObjMgr::Get_Instance()->Delete_ID(BOX);

	ObjMgr::Get_Instance()->Delete_ID(ITEM);

	ObjMgr::Get_Instance()->Delete_ID(PLAYER);
	ObjMgr::Get_Instance()->Delete_ID(SODA);
	ObjMgr::Get_Instance()->Delete_ID(COMPUTER);
	ObjMgr::Get_Instance()->Delete_ID(TREE);
	ObjMgr::Get_Instance()->Delete_ID(BACKGROUND);
	ObjMgr::Get_Instance()->Delete_ID(ITEMBOX);



}

