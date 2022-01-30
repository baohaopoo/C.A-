#include "stdafx.h"
#include "Start.h"
#include "BmpMgr.h"
#include "Define.h"
#include "SceneMgr.h"
#include"Factory.h"
#include"ObjMgr.h"
#include "SoundMgr.h"
//2p ´­·¶À»¶§ btn


Start::Start()
{
}


Start::~Start()
{
	Release();
}

void Start::Initialize()
{

	m_pBmgMgr->InsertBmp(L"START", L"../Image/Start.bmp");
	m_pBmgMgr->InsertBmp(L"1P", L"../Image/button.bmp");
	m_pBmgMgr->InsertBmp(L"2P", L"../Image/button2.bmp");
	m_pBmgMgr->InsertBmp(L"Exit", L"../Image/Exit.bmp");
	Object* pObj = Factory<StartBtn>::CreateObj(220,470,100,100);
	pObj->setImage(L"1P");
	ObjMgr::Get_Instance()->Add_Object(BUTTON, pObj);


	pObj = Factory<StartBtn>::CreateObj(580, 470, 90, 100);
	pObj->setImage(L"2P");
	ObjMgr::Get_Instance()->Add_Object(BUTTON, pObj);


	pObj = Factory<StartBtn>::CreateObj(500, 605, 100, 100);
	pObj->setImage(L"Exit");
	ObjMgr::Get_Instance()->Add_Object(BUTTON, pObj);



	


}

void Start::Update()
{

	SoundMgr::Get_Instance()->PlaySoundW(L"Logo.wav", SoundMgr::BGM,8);
	ObjMgr::Get_Instance()->Update();
	

}

void Start::LateUpdate()
{


	ObjMgr::Get_Instance()->Late_Update();
	
}

void Start::Render(HDC hDC)
{

	HDC memDC = m_pBmgMgr->FindImage(L"START");
	if (memDC == nullptr)return;

	
	BitBlt(hDC, 0, 0, WINCX, WINCY, memDC, 0, 0, SRCCOPY);
	//GdiTransparentBlt(hDC,rect.left, colliderBox.top, info.fCX, info.fCY, memDC, 0, 0, info.fCX, info.fCY, RGB(255, 201, 14));


	ObjMgr::Get_Instance()->Render(hDC);

}

void Start::Release()
{
	ObjMgr::Get_Instance()->Delete_ID(BUTTON);
	SoundMgr::Get_Instance()->StopAll();
}
