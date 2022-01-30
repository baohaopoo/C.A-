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


	//잔상 제거용
	BmpMgr::getInstance()->InsertBmp(L"Back", L"../Image/Back.bmp");

	//후면버퍼
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
	//후면 버퍼 얻어오기
	HDC BackBuffer = nullptr;
	if (nullptr == BackBuffer) {
		BackBuffer = BmpMgr::getInstance()->FindImage(L"BackBuffer");
	}

	//일단 전면버퍼가 아닌 후면 버퍼에 비트맵을 그려놓는다. 화면에 보이는 단계가 아님
	HDC MemDC = nullptr;
	if (nullptr == MemDC) {
		BmpMgr::getInstance()->FindImage(L"Back");
	}

	//비트맵 출력 BitBlt로 고속 복사한다.
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

	// 사용이 끝난 dc를 소멸
	ReleaseDC(g_hWnd, m_DC);
}
