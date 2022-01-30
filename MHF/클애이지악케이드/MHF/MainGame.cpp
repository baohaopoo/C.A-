#include "stdafx.h"
#include "MainGame.h"
#include "CollisionMgr.h"
#include "BmpMgr.h"
#include "Mouse.h"
#include "SceneMgr.h"
#include "ObjMgr.h"
#include "KeyMgr.h"
#include "Factory.h"
#include "SoundMgr.h"


MainGame::MainGame()
	: m_iFPS(0)
	, m_dwTime(GetTickCount())
{
	
	ZeroMemory(m_szFPS, sizeof(TCHAR) * 32);
}


MainGame::~MainGame()
{
	Release();
}

void MainGame::Initialize()
{
	m_DC = GetDC(g_hWnd);


	//�ܻ� ���ſ�
	BmpMgr::getInstance()->InsertBmp(L"Back", L"../Image/Back.bmp");

	//�ĸ����
	BmpMgr::getInstance()->InsertBmp(L"BackBuffer", L"../Image/BackBuffer.bmp");

	SceneMgr::GetInstance()->SceneChange(SceneMgr::LOGO);

	Object* pObj = nullptr;
	pObj = Factory<Mouse>::CreateObj(100, 100);
	ObjMgr::Get_Instance()->Add_Object(MOUSE, pObj);
	SoundMgr::Get_Instance()->Initialize();

}


void MainGame::Update()
{


	SceneMgr::GetInstance()->Update();
	ObjMgr::Get_Instance()->Update();
	
}

void MainGame::LateUpdate()
{


	
	SceneMgr::GetInstance()->LateUpdate();
	ObjMgr::Get_Instance()->Late_Update();
}

void MainGame::Render()
{
	//�ĸ� ���� ������
	HDC BackBuffer = nullptr;
	if (nullptr == BackBuffer) {
		BackBuffer = BmpMgr::getInstance()->FindImage(L"BackBuffer");
	}

	//�ϴ� ������۰� �ƴ� �ĸ� ���ۿ� ��Ʈ���� �׷����´�. ȭ�鿡 ���̴� �ܰ谡 �ƴ�
	HDC MemDC = nullptr;
	if (nullptr == MemDC) {
		BmpMgr::getInstance()->FindImage(L"Back");
	}

	//��Ʈ�� ��� BitBlt�� ��� �����Ѵ�.
	BitBlt(BackBuffer, 0, 0, WINCX, WINCY, MemDC, 0, 0, SRCCOPY);

	SceneMgr::GetInstance()->Render(BackBuffer);


	TCHAR		szBuff[32] = L"";
	++m_iFPS;

	/*if (m_dwTime + 1000 < GetTickCount())
	{
		swprintf_s(m_szFPS, L"FPS : %d", m_iFPS);
		SetWindowText(g_hWnd, m_szFPS);

		m_iFPS = 0;
		m_dwTime = GetTickCount();
	}
*/


	BitBlt(m_DC, 0, 0, WINCX, WINCY, BackBuffer, 0, 0, SRCCOPY);

}


void MainGame::Release()
{
	SoundMgr::Get_Instance()->Destroy_Instance();
	SceneMgr::GetInstance()->DestroyInstance();
	ObjMgr::Get_Instance()->Destroy_Instance();
	BmpMgr::getInstance()->DestroyInstance();
	KeyMgr::Get_Instance()->Destroy_Instance();

	// ����� ���� dc�� �Ҹ�
	ReleaseDC(g_hWnd, m_DC);
}
