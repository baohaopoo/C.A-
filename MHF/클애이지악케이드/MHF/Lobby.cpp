#include "stdafx.h"
#include "Lobby.h"
#include "BmpMgr.h"
#include "Define.h"
#include "SceneMgr.h"
#include "ObjMgr.h"
#include "Factory.h"
#include "SoundMgr.h"
Lobby::Lobby()
{

}


Lobby::~Lobby()
{
	Release();
}

void Lobby::Initialize()
{

	SoundMgr::Get_Instance()->PlaySoundW(L"Lobby.wav", SoundMgr::BGM, 8);
	BmpMgr::getInstance()->InsertBmp(L"Lobby", L"../Image/lobby.bmp");
	m_pBmgMgr->InsertBmp(L"OUI", L"../Image/OUI.bmp");
	m_pBmgMgr->InsertBmp(L"OUI2", L"../Image/OUI.bmp");
	m_pBmgMgr->InsertBmp(L"XUI", L"../Image/XUI.bmp");
	m_pBmgMgr->InsertBmp(L"XUI2", L"../Image/XUI.bmp");
	m_pBmgMgr->InsertBmp(L"ST", L"../Image/startbutton.bmp");
	m_pBmgMgr->InsertBmp(L"GB", L"../Image/goback.bmp");
	m_pBmgMgr->InsertBmp(L"mapb", L"../Image/mapbutton.bmp");
	Object* pObj = Factory<LobbyStnBtn>::CreateObj(290, 161, 105, 102);

	pObj->setImage(L"OUI");
	ObjMgr::Get_Instance()->Add_Object(LOBBYBUTTON, pObj);


	pObj = Factory<LobbyStnBtn>::CreateObj(392, 161, 105, 102);
	pObj->setImage(L"OUI2");
	ObjMgr::Get_Instance()->Add_Object(LOBBYBUTTON, pObj);


	pObj = Factory<LobbyStnBtn>::CreateObj(610, 525, 195, 68);
	pObj->setImage(L"ST");
	ObjMgr::Get_Instance()->Add_Object(LOBBYBUTTON, pObj);

	pObj = Factory<LobbyStnBtn>::CreateObj(120, 581, 90,80);
	pObj->setImage(L"GB");
	ObjMgr::Get_Instance()->Add_Object(LOBBYBUTTON, pObj);

	pObj = Factory<LobbyStnBtn>::CreateObj(710, 450, 130, 60);
	pObj->setImage(L"mapb");
	ObjMgr::Get_Instance()->Add_Object(LOBBYBUTTON, pObj);

	//pObj = Factory<LobbyStnBtn>::CreateObj(120, 600, 20, 20);
	//ObjMgr::Get_Instance()->Add_Object(LOBBYBUTTON, pObj);
}

void Lobby::Update()
{
	
	ObjMgr::Get_Instance()->Update();
}

void Lobby::LateUpdate()
{
	
	ObjMgr::Get_Instance()->Late_Update();
}

void Lobby::Render(HDC hDC)
{
	HDC memDC = BmpMgr::getInstance()->FindImage(L"Lobby");
	if (nullptr == memDC)
		return;

	BitBlt(hDC, 0, 0, WINCX, WINCY, memDC, 0, 0, SRCCOPY);
	
	
	ObjMgr::Get_Instance()->Render(hDC);

}

void Lobby::Release()
{
	ObjMgr::Get_Instance()->Delete_ID(LOBBYBUTTON);
	SoundMgr::Get_Instance()->StopAll();
}
