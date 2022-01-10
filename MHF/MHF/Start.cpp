#include "stdafx.h"
#include "Start.h"
#include "BmpMgr.h"
#include "Define.h"
#include "SceneMgr.h"
#include"Factory.h"
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
	BmpMgr::getInstance()->InsertBmp(L"START", L"../Image/Start.bmp");
	stBtn.Initialize();
	stBtnM.Initialize();

	

}

void Start::Update()
{

	stBtn.Update();

	stBtnM.Update();
	

}

void Start::LateUpdate()
{

	stBtn.LateUpdate();
	stBtnM.LateUpdate();
	//if (GetAsyncKeyState(VK_RETURN))
	//{
	//	SceneMgr::GetInstance()->SceneChange(SceneMgr::LOBBY);
	//	return;
	//}

}

void Start::Render(HDC hDC)
{
	HDC memDC = BmpMgr::getInstance()->FindImage(L"START");
	if (memDC == nullptr)return;

	
	BitBlt(hDC, 0, 0, WINCX, WINCY, memDC, 0, 0, SRCCOPY);
	//GdiTransparentBlt(hDC,rect.left, colliderBox.top, info.fCX, info.fCY, memDC, 0, 0, info.fCX, info.fCY, RGB(255, 201, 14));


	stBtn.Render(hDC);
	stBtnM.Render(hDC);
}

void Start::Release()
{
}
