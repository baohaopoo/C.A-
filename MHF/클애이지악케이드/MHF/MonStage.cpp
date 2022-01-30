#include "stdafx.h"
#include "MonStage.h"
#include "TileMgr.h"
#include "ObjMgr.h"
#include "Factory.h"
#include "SceneMgr.h"
#include "Player.h"
#include "Monster.h"
#include "CollisionMgr.h"
#include "SoundMgr.h"
#include "Box.h"
#include "Background.h"
#include "StartUI.h"
#include "PickMonster.h"
#include "resUI.h"
#include"ItemBox.h"
MonStage::MonStage()
{
}


MonStage::~MonStage()
{
	Release();
}

void MonStage::Initialize()
{

	//음악

	SoundMgr::Get_Instance()->PlaySoundW(L"gamest.wav", SoundMgr::EFFECT, 8);
	
	//통프레임
	BmpMgr::getInstance()->InsertBmp(L"MStage", L"../Image/Monster/mmmm.bmp");
	BmpMgr::getInstance()->InsertBmp(L"BOX", L"../Image/map/fixbox.bmp");
	BmpMgr::getInstance()->InsertBmp(L"montile", L"../Image/Monster/montile.bmp");
	BmpMgr::getInstance()->InsertBmp(L"MStartUI", L"../Image/gamestart.bmp"); 
	BmpMgr::getInstance()->InsertBmp(L"LOSE", L"../Image/lose.bmp");
	BmpMgr::getInstance()->InsertBmp(L"SMILE", L"../Image/map/smile.bmp");
	BmpMgr::getInstance()->InsertBmp(L"jusa", L"../Image/Item/jusa.bmp");
	BmpMgr::getInstance()->InsertBmp(L"ballon", L"../Image/Item/ballon.bmp");
	BmpMgr::getInstance()->InsertBmp(L"skate", L"../Image/Item/skate.bmp");


	
	//화면 시작 UI
	pObj = Factory<StartUI>::CreateObj(320, 260, 400, 140);
	pObj->setImage(L"MStartUI");
	ObjMgr::Get_Instance()->Add_Object(UI, pObj);


	pObj = Factory<Player>::CreateObj(123, 180,30,10);
	ObjMgr::Get_Instance()->Add_Object(PLAYER, pObj);
	dynamic_cast<Player*>(pObj)->SetBulletList(ObjMgr::Get_Instance()->Get_ObjList(BULLET));


	pObj = Factory<Background>::CreateObj(300,300);
	ObjMgr::Get_Instance()->Add_Object(BACKGROUND, pObj);
	pObj->setImage(L"montile");

	//나가기 유아이
	pObj = Factory<StartUI>::CreateObj(720, 600, 140, 70);
	pObj->setImage(L"Exit2");
	ObjMgr::Get_Instance()->Add_Object(STAGEBUTTON, pObj);




	//보라 몬스터
	for (int i = 0; i < 10; ++i) {
		puple = Factory<Monster>::CreateObj(uidx(dre), uidy(dre), -1);
		ObjMgr::Get_Instance()->Add_Object(MONSTER, puple);
		puple->setID(MONSTER);
		//pObj->setImage(L"lv1");
		puple->setImage(L"MUP");

		puplecnt -= 1;
	}


	for (int i = 0; i < 10; ++i) {
		puple = Factory<Monster>::CreateObj(uidx(dre), uidy(dre),1);
		ObjMgr::Get_Instance()->Add_Object(MONSTER, puple);
		puple->setID(MONSTER);
		//pObj->setImage(L"lv1");
		puple->setImage(L"MDW");

		puplecnt -= 1;
	}



	puple = Factory<Monster>::CreateObj(uidx(dre), uidy(dre));
	ObjMgr::Get_Instance()->Add_Object(MONSTER, puple);
	puple->setID(MONSTER);
	//pObj->setImage(L"lv1");
	puple->setImage(L"keymonster");

	////핑크몬스터

	for (int i = 0; i < 2; ++i) {
		pObj = Factory<PickMonster>::CreateObj(200, 135+(i*110));
		pObj->setID(MONSTERU);
		pObj->setImage(L"PL");
		ObjMgr::Get_Instance()->Add_Object(MONSTERU, pObj);

		pickcnt -= 2;
	}

	for (int i = 0; i < 2; ++i) {
		pObj = Factory<PickMonster>::CreateObj(200, 340 + (i * 110));
		pObj->setID(MONSTERU);
		pObj->setImage(L"PL");
		ObjMgr::Get_Instance()->Add_Object(MONSTERU, pObj);
		pickcnt -= 2;
	}


	//Item

	 pObj = Factory<Item>::CreateObj(L"skate", 100, 300, 38, 38);
	ObjMgr::Get_Instance()->Add_Object(ITEM, pObj);

	 pObj = Factory<Item>::CreateObj(L"ballon", 120, 160, 38, 38);
	ObjMgr::Get_Instance()->Add_Object(ITEM, pObj);

	 pObj = Factory<Item>::CreateObj(L"jusa", 50, 300, 38, 38);
	ObjMgr::Get_Instance()->Add_Object(JUSA, pObj);

	 pObj = Factory<Item>::CreateObj(L"soda", 220, 450, 38, 38);
	ObjMgr::Get_Instance()->Add_Object(SODA, pObj);


	//오브젝트 깔기.



	for (int i = 0; i < 4; ++i) {
		pObj = Factory<Background>::CreateObj(L"SMILE", 40 + (i * 40), 100, 40, 47);
		ObjMgr::Get_Instance()->Add_Object(BACKGROUND, pObj);
	}

	pObj = Factory<ItemBox>::CreateObj(L"SMILE", 160, 100 + (2 * 40), 40, 47);
	ObjMgr::Get_Instance()->Add_Object(ITEMBOX, pObj);
	pObj = Factory<Background>::CreateObj(L"SMILE", 160, 100 + (3 * 40), 40, 47);
	ObjMgr::Get_Instance()->Add_Object(BACKGROUND, pObj);
	pObj = Factory<ItemBox>::CreateObj(L"SMILE", 160, 100 + (5 * 40), 40, 47);
	ObjMgr::Get_Instance()->Add_Object(ITEMBOX, pObj);
	pObj = Factory<Background>::CreateObj(L"SMILE", 160, 100 + (7 * 40), 40, 47);
	ObjMgr::Get_Instance()->Add_Object(BACKGROUND, pObj);

	pObj = Factory<Background>::CreateObj(L"SMILE", 160, 100 + (8 * 40), 40, 47);
	ObjMgr::Get_Instance()->Add_Object(BACKGROUND, pObj);
	for (int i = 0; i < 4; ++i) {
		pObj = Factory<Background>::CreateObj(L"SMILE", 40 + (i * 40), 500, 40, 47);
		ObjMgr::Get_Instance()->Add_Object(BACKGROUND, pObj);
	}


	for (int i = 0; i < 7; ++i) {
		pObj = Factory<Background>::CreateObj(L"SMILE", 320 + (i * 40), 500, 40, 47);
		ObjMgr::Get_Instance()->Add_Object(BACKGROUND, pObj);
	}

	for (int i = 0; i < 7; ++i) {
		pObj = Factory<Background>::CreateObj(L"SMILE", 320 + (i * 40),100, 40, 47);
		ObjMgr::Get_Instance()->Add_Object(BACKGROUND, pObj);
	}
	 
	for (int i = 0; i < 11; ++i) {
		pObj = Factory<ItemBox>::CreateObj(L"SMILE", 600 , 100 + (i * 40), 40, 47);
		ObjMgr::Get_Instance()->Add_Object(ITEMBOX, pObj);
	}





}

void MonStage::Update()
{

	SoundMgr::Get_Instance()->PlaySoundW(L"작은거북.wav", SoundMgr::BGM, 8);

	if (GetAsyncKeyState('Z')) {
		pObj = Factory<StartUI>::CreateObj(690, 510, 38, 38);
		pObj->setImage(L"jusa");
		ObjMgr::Get_Instance()->Add_Object(UI, pObj);
	}
	if (GetAsyncKeyState(VK_F12)) {
	
		
			Object *resui;
			resui = Factory<resUI>::CreateObj(340, 120, 330, 80); //win
			resui->setImage(L"win");
			ObjMgr::Get_Instance()->Add_Object(UI, resui);
			////결과창.
			//resui = Factory<resUI>::CreateObj(320, 330, 500, 350);
			//resui->setImage(L"reszzi");
			//ObjMgr::Get_Instance()->Add_Object(UI, resui);

		
			
			SoundMgr::Get_Instance()->PlaySoundW(L"winres.wav", SoundMgr::UI, 10);	


		

		
	}

	if(GetAsyncKeyState(VK_F11))
		SceneMgr::GetInstance()->SceneChange(SceneMgr::BOSS);
	
	ObjMgr::Get_Instance()->Update();
}

void MonStage::LateUpdate()
{
	ObjMgr::Get_Instance()->Late_Update();
	
}

void MonStage::Render(HDC hDC)
{
	HDC memDC = BmpMgr::getInstance()->FindImage(L"MStage");

	//배경 출력 
	if (memDC == nullptr) {
		return;
	}



	//// GdiTransparentBlt: 사용자가 원하는 색상을 제거하여 비트맵을 출력.
	GdiTransparentBlt(hDC, 0, 0, WINCX, WINCY, memDC, 0, 0, WINCX, WINCY, RGB(255, 255, 255));

	ObjMgr::Get_Instance()->Render(hDC);



}

void MonStage::Release()
{
	SoundMgr::Get_Instance()->StopAll();
	ObjMgr::Get_Instance()->Delete_ID(UI);
	ObjMgr::Get_Instance()->Delete_ID(STAGEBUTTON);
	ObjMgr::Get_Instance()->Delete_ID(OBJECT);
	ObjMgr::Get_Instance()->Delete_ID(BACKGROUND);
	ObjMgr::Get_Instance()->Delete_ID(ITEM);
	ObjMgr::Get_Instance()->Delete_ID(PLAYER);
	ObjMgr::Get_Instance()->Delete_ID(MONSTER);
	ObjMgr::Get_Instance()->Delete_ID(MONSTERU);
	ObjMgr::Get_Instance()->Delete_ID(ITEMBOX);
	ObjMgr::Get_Instance()->Delete_ID(SODA);
	ObjMgr::Get_Instance()->Delete_ID(JUSA);

}


