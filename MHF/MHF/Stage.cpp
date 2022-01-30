#include "stdafx.h"
#include "Stage.h"
#include "BmpMgr.h"
#include "CollisionMgr.h"
#include "TileMgr.h"
#include "ObjMgr.h"
#include "Factory.h"
#include "PlayerCollider.h"
Stage::Stage()
	:player(nullptr),isEdit(false),skate(nullptr)
{
	
}


Stage::~Stage()
{
}

void Stage::Initialize()
{	
	//��������
	BmpMgr::getInstance()->InsertBmp(L"Stage", L"../Image/UIFrm2.bmp");
	//������Ʈ
	BmpMgr::getInstance()->InsertBmp(L"OBJ", L"../Image/object.bmp");

	//��¥ �ֿ� Ÿ��(�浹ó�� �ؾ���)
	BmpMgr::getInstance()->InsertBmp(L"fixbox", L"../Image/map/icetile.bmp");
	BmpMgr::getInstance()->InsertBmp(L"iceobj", L"../Image/map/iceobject.bmp");

	//������ Ÿ��
	BmpMgr::getInstance()->InsertBmp(L"jusa", L"../Image/Item/jusa.bmp");
	BmpMgr::getInstance()->InsertBmp(L"ballon", L"../Image/Item/ballon.bmp");
	BmpMgr::getInstance()->InsertBmp(L"skate", L"../Image/Item/skate.bmp");

	BmpMgr::getInstance()->InsertBmp(L"Box", L"../Image/Object/eglue.bmp");

	//����
	BmpMgr::getInstance()->InsertBmp(L"tree", L"../Image/Object/tree.bmp");
	//����
	BmpMgr::getInstance()->InsertBmp(L"dummy", L"../Image/Object/dummy.bmp");
	//�и��� ����
	BmpMgr::getInstance()->InsertBmp(L"iceobj", L"../Image/map/iceobject.bmp");
	//������ ����
	BmpMgr::getInstance()->InsertBmp(L"icetile", L"../Image/map/icetile.bmp");

	//�̱۷�
	Object* pObj = nullptr;
	pObj = Factory<Box>::CreateObj(L"Box",160,180,120,120);
	ObjList[BOX].push_back(pObj);
	pObj = Factory<Box>::CreateObj(L"Box",480, 180,120,120);
	ObjList[BOX].push_back(pObj);

	//start UI
	stui = new StartUI;
	stui->Initialize();

	//�����ʾ��� 
	for (int i = 0; i < 2; ++i) {
		pObj = Factory<Item>::CreateObj(L"iceobj", 40 + (i * 40), 220, 42, 48);
		ObjList[BOX].push_back(pObj);
	}
	//�����ʾ��� 
	for (int i = 0; i < 2; ++i) {
		pObj = Factory<Item>::CreateObj(L"iceobj", 280 + (i * 80), 220, 42, 48);
		ObjList[BOX].push_back(pObj);
	}
	//���ʾ��� 
	for (int i = 0; i < 2; ++i) {
		pObj = Factory<Item>::CreateObj(L"iceobj",560 + (i * 40), 220, 42, 48);
		ObjList[BOX].push_back(pObj);
	}
	//�� �� �ؾ��� 2
	for (int i = 0; i < 9; ++i) {
		pObj = Factory<Item>::CreateObj(L"iceobj", 160 + (i * 40), 420, 40, 40);
		ObjList[BOX].push_back(pObj);
	}
	//�� �� �ؾ��� 
	for (int i = 0; i < 9; ++i) {
		pObj = Factory<Item>::CreateObj(L"iceobj", 160 + (i * 40), 500, 40, 40);
		ObjList[BOX].push_back(pObj);
	}
	//�ؾ��� 
	for (int i = 0; i < 15; ++i) {
		pObj = Factory<Item>::CreateObj(L"iceobj", 40 + (i * 40), 540, 40, 40);
		ObjList[BOX].push_back(pObj);
	}
	//���̽� Ÿ�� 
	for (int i = 0; i < 2; ++i) {
		pObj = Factory<Item>::CreateObj(L"icetile", 160 + (i * 40), 300, 42, 54);
		ObjList[BOX].push_back(pObj);
	}
	//���̽� Ÿ�� 
	for (int i = 0; i < 2; ++i) {
		pObj = Factory<Item>::CreateObj(L"icetile", 440 + (i * 40), 300, 42, 54);
		ObjList[BOX].push_back(pObj);
	}
	//�� �� �ؾ���3 
	for (int i = 0; i < 9; ++i) {
		pObj = Factory<Item>::CreateObj(L"iceobj", 160 + (i * 40), 340, 40, 40);
		ObjList[BOX].push_back(pObj);
	}
	//���̽�Ÿ�� ���� ����
	for (int i = 0; i < 3; ++i) {
		pObj = Factory<Item>::CreateObj(L"iceobj", 160 + (i * 40), 260, 40, 40);
		ObjList[BOX].push_back(pObj);
	}
	//���̽�Ÿ�� ���� ����
	for (int i = 0; i < 3; ++i) {
		pObj = Factory<Item>::CreateObj(L"iceobj", 400 + (i * 40), 260, 40, 40);
		ObjList[BOX].push_back(pObj);
	}
	//���ʳ��� �ɱ�
	for (int i = 0; i < 6; ++i) {
		pObj = Factory<Box>::CreateObj(L"tree", 320, 40 + (i * 40), 40, 70);
		ObjList[BOX].push_back(pObj);
	}
	//���� �ɱ�
	for (int i = 0; i < 5; ++i) {
		pObj = Factory<Box>::CreateObj(L"tree", 240 + (i * 40), 280, 40, 70);
		ObjList[BOX].push_back(pObj);
	}
	//���ʳ��� �ɱ�
	for (int i = 0; i < 2; ++i) {
		pObj = Factory<Box>::CreateObj(L"tree", 80 + (i * 40), 280, 40, 70);
		ObjList[BOX].push_back(pObj);
	}
	//�����ʳ��� �ɱ�
	for (int i = 0; i < 2; ++i) {
		pObj = Factory<Box>::CreateObj(L"tree", 520 + (i * 40), 280, 40, 70);
		ObjList[BOX].push_back(pObj);
	}
	//dummy
	for (int i = 0; i < 7; ++i) {
		pObj = Factory<Box>::CreateObj(L"dummy", 80 + (i * 80), 450, 40, 60);
		ObjList[BOX].push_back(pObj);
	}

	for (int i = 0; i < 7; ++i) {
		pObj = Factory<Box>::CreateObj(L"dummy", 80 + (i * 80), 370, 40, 60);
		ObjList[BOX].push_back(pObj);
	}
	//Item
	for (int i = 0; i < 2; ++i) {
		pObj = Factory<Item>::CreateObj(L"ballon", 120 + (i * 400), 380, 40, 40);
		ObjList[SKATE].push_back(pObj);
	}

	for (int i = 0; i < 2; ++i) {
		pObj = Factory<Item>::CreateObj(L"skate", 120 + (i * 400), 460, 40, 40);
		ObjList[SKATE].push_back(pObj);
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
		player->setPos(100, 100);
	}


	//pObj = Factory < PlayerCollider > ::CreateObj(player->GetInfo().fX, player->GetInfo().fY);
	//ObjList[PLAYERC].push_back(pObj);

	//computer= Factory<Player>::CreateObj( 400,100);

	dynamic_cast<Player*>(player)->SetBulletList(&ObjList[BULLET]);


	//Ÿ��
	//TileMgr::GetInstance()->Initialize();
	//TileMgr::GetInstance()->LoadTile();

	
	pObj = Factory<Player>::CreateObj( 459,100);
	pObj->setID(COMPUTER);
	ObjList[COMPUTER].push_back(pObj);
	dynamic_cast<Player*>(pObj)->SetBulletList(&ObjList[BULLET]);
}

void Stage::Update()
{
	
	if (GetAsyncKeyState(VK_RBUTTON)) {
		isPicking();
	}


	if (GetAsyncKeyState('X'))
		CreateItem(L"Ballon", 200, 300);

	//if (GetAsyncKeyState('C'))

	CreateItem(L"Skate", 100, 400);



	//Ÿ��
	//if (GetAsyncKeyState('S')) {
	//	TileMgr::GetInstance()->SaveTile();
	//	isEdit = true;
	//}


	//������Ʈ
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

	//Ÿ��
	//TileMgr::GetInstance()->Update();



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
	CollisionMgr::CollisionRect(ObjList[COMPUTER], ObjList[SKATE]);
	CollisionMgr::CollisionRect(ObjList[PLAYER], ObjList[TILE]);

	CollisionMgr::CollisionObject(ObjList[PLAYER], ObjList[SKATE]);
	CollisionMgr::CollisionObject(ObjList[BOX], ObjList[PLAYER]);

	CollisionMgr::CollisionRect(ObjList[BULLET], ObjList[SKATE]);


	//Ÿ��
	//TileMgr::GetInstance()->LateUpdate();


	if (stui != nullptr)
		stui->LateUpdate();


}

void Stage::Render(HDC hDC)
{
	HDC memDC = BmpMgr::getInstance()->FindImage(L"Stage");

	//��� ��� 
	if (memDC == nullptr) {
		return;
	}


	//// GdiTransparentBlt: ����ڰ� ���ϴ� ������ �����Ͽ� ��Ʈ���� ���.
	GdiTransparentBlt(hDC, 0, 0, WINCX, WINCY, memDC, 0, 0, WINCX, WINCY, RGB(255, 255, 255));

	//Ÿ��
	//TileMgr::GetInstance()->Render(hDC);
		



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

	//TileMgr::GetInstance()->DestroyInstance();
}

void Stage::isPicking()
{
	POINT pt = {};
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);

	int x = (int)pt.x / TILECX;
	int y = (int)pt.y / TILECY; 

	int index = x + (TILEX* y);
	 
	//if(GetAsyncKeyState(VK_LBUTTON))
	//TileMgr::GetInstance()->PickTile(index,L"fixbox");

	//if (GetAsyncKeyState(VK_F1)) {
	//	TileMgr::GetInstance()->PickTile(index, L"iceobj");
	//}
	//
	////jusa������
	//if (GetAsyncKeyState(VK_F2)) {
	//	TileMgr::GetInstance()->PickTile(index, L"jusa");
	//}
	////ballon������
	//if (GetAsyncKeyState(VK_F3)) {
	//	TileMgr::GetInstance()->PickTile(index, L"ballon");
	//}
	////ballon������
	//if (GetAsyncKeyState(VK_F4)) {
	//	TileMgr::GetInstance()->PickTile(index, L"skate");
	//}

	////����
	//if (GetAsyncKeyState(VK_F5)) {
	//	TileMgr::GetInstance()->PickTile(index, L"jusa");
	//}




	//if (GetAsyncKeyState(VK_RBUTTON))
	//	TileMgr::GetInstance()->PickTile(index, 1);

	//if (GetAsyncKeyState(VK_F1)) {
	//	TileMgr::GetInstance()->PickTile(index,2);
	//}

	////jusa������
	//if (GetAsyncKeyState(VK_F2)) {
	//	TileMgr::GetInstance()->PickTile(index,3);
	//}
	////ballon������
	//if (GetAsyncKeyState(VK_F3)) {
	//	TileMgr::GetInstance()->PickTile(index, 4);
	//}
	////ballon������
	//if (GetAsyncKeyState(VK_F4)) {
	//	TileMgr::GetInstance()->PickTile(index,5);
	//}

	////����
	//if (GetAsyncKeyState(VK_F5)) {
	//	TileMgr::GetInstance()->PickTile(index,6);
	//}
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
