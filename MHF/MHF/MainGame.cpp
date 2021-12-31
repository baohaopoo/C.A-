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


	//�ܻ� ���ſ�
	BmpMgr::getInstance()->InsertBmp(L"Back", L"../Image/Back.bmp");

	//�ĸ����
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

	BitBlt(m_DC, 0, 0, WINCX, WINCY, BackBuffer, 0, 0, SRCCOPY);

}


void MainGame::Release()
{


	BmpMgr::getInstance()->DestroyInstance();
}
