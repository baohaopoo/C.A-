#include "stdafx.h"
#include "Logo.h"
#include "BmpMgr.h"
#include"SceneMgr.h"
#include"Define.h"
Logo::Logo()
{
}


Logo::~Logo()
{
	Release();
}

void Logo::Initialize()
{
	BmpMgr::getInstance()->InsertBmp(L"Logo", L"../Image/Logo.bmp");

}

void Logo::Update()
{
}

void Logo::LateUpdate()
{
	if (GetAsyncKeyState(VK_RETURN))
	{
		SceneMgr::GetInstance()->SceneChange(SceneMgr::START);
		return;
	}
}

void Logo::Render(HDC hDC)
{
	HDC memDC = nullptr;
	if (memDC == nullptr) {
		memDC = BmpMgr::getInstance()->FindImage(L"Logo");
	}

	BitBlt(hDC, 0, 0, WINCX, WINCY, memDC, 0, 0, SRCCOPY);
}

void Logo::Release()
{
}
