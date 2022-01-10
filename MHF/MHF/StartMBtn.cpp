#include "stdafx.h"
#include "StartMBtn.h"
#include "SceneMgr.h"

StartMBtn::StartMBtn()
{
}


StartMBtn::~StartMBtn()
{
	Release();

}

void StartMBtn::Initialize()
{
	info.fX = 220.f;
	info.fY = 470.f;
	info.fCX = 100.f;
	info.fCY = 100.f;
}

int StartMBtn::Update()
{
	POINT pt = {};
	GetCursorPos(&pt);
	UpdateRect();
	ScreenToClient(g_hWnd, &pt);

	if (GetAsyncKeyState(VK_RBUTTON)) {
		if (PtInRect(&rect, pt))
		{

			SceneMgr::GetInstance()->SceneChange(SceneMgr::MONSTAGE);

		}
	}

	return LIVE;
}

void StartMBtn::LateUpdate()
{
}

void StartMBtn::Render(HDC hDC)
{
	Rectangle(hDC, rect.left, rect.top, rect.right, rect.bottom);
}

void StartMBtn::Release()
{
}
