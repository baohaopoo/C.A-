#include "stdafx.h"
#include "StartBtn.h"
#include "SceneMgr.h"

StartBtn::StartBtn()
{
}


StartBtn::~StartBtn()
{
	Release();
}

void StartBtn::Initialize()
{
	info.fX = 580.f;
	info.fY = 470.f;
	info.fCX = 100.f;
	info.fCY = 100.f;
}

int StartBtn::Update()
{
	POINT pt = {};
	GetCursorPos(&pt);
	UpdateRect();
	ScreenToClient(g_hWnd, &pt);
	if (PtInRect(&rect, pt))
	{
		if (GetAsyncKeyState(VK_LBUTTON))
			SceneMgr::GetInstance()->SceneChange(SceneMgr::LOBBY);

	}

	return LIVE;
}

void StartBtn::LateUpdate()
{
	
}

void StartBtn::Render(HDC hDC)
{
	Rectangle(hDC, rect.left, rect.top, rect.right, rect.bottom);
}

void StartBtn::Release()
{
}
