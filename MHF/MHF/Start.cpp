#include "stdafx.h"
#include "Start.h"
#include "BmpMgr.h"
#include "Define.h"
#include "SceneMgr.h"
#include "Factory.h"
#include "ObjMgr.h"
#include "StartMBtn.h"
#include "StartBtn.h"
//2p ´­·¶À»¶§ btn

Start::Start()
	:pObj(nullptr), pObj2(nullptr)

{
}


Start::~Start()
{
	Release();
}

void Start::Initialize()
{
	BmpMgr::getInstance()->InsertBmp(L"START", L"../Image/Start.bmp");
	BmpMgr::getInstance()->InsertBmp(L"click2", L"../Image/button2.bmp");

	if (pObj == nullptr) {
		pObj = new StartBtn;
		pObj->Initialize();
	}


	

}

void Start::Update()
{

	if(pObj !=nullptr)
	pObj->Update();
	

}

void Start::LateUpdate()
{
	if (pObj != nullptr)
	pObj->LateUpdate();


}

void Start::Render(HDC hDC)
{
	HDC memDC = BmpMgr::getInstance()->FindImage(L"START");
	if (memDC == nullptr)return;

	
	BitBlt(hDC, 0, 0, WINCX, WINCY, memDC, 0, 0, SRCCOPY);
	if (pObj != nullptr)
	pObj->Render(hDC);


}

void Start::Release()
{

}
