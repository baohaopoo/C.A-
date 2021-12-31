#include "stdafx.h"
#include "MainGame.h"
#include "CollisionMgr.h"
#include"BmpMgr.h"
#include"SceneMgr.h"
MainGame::MainGame()
{
	m_DC = GetDC(g_hWnd);
}


MainGame::~MainGame()
{
}

void MainGame::Initialize()
{


	//잔상 제거용
	BmpMgr::getInstance()->InsertBmp(L"Back", L"../Image/Back.bmp");

	//후면버퍼
	BmpMgr::getInstance()->InsertBmp(L"BackBuffer", L"../Image/BackBuffer.bmp");

	SceneMgr::GetInstance()->SceneChange(SceneMgr::LOGO);
}


void MainGame::Update()
{


	SceneMgr::GetInstance()->Update();

	
}

void MainGame::LateUpdate()
{



	SceneMgr::GetInstance()->LateUpdate();

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

	BitBlt(m_DC, 0, 0, WINCX, WINCY, BackBuffer, 0, 0, SRCCOPY);

}


void MainGame::Release()
{


	BmpMgr::getInstance()->DestroyInstance();
}
