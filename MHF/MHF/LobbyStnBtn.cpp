#include "stdafx.h"
#include "LobbyStnBtn.h"
#include "SceneMgr.h"

LobbyStnBtn::LobbyStnBtn()
{
}


LobbyStnBtn::~LobbyStnBtn()
{
	Release();
}

void LobbyStnBtn::Initialize()
{
	info.fX = 610.f;
	info.fY = 520.f;
	info.fCX = 190.f;
	info.fCY = 50.f;


}

int LobbyStnBtn::Update()
{
	POINT pt{};
	GetCursorPos(&pt);
	UpdateRect();
	ScreenToClient(g_hWnd,&pt);
	
	if (PtInRect(&rect, pt))
	{
		if (GetAsyncKeyState(VK_LBUTTON))
			SceneMgr::GetInstance()->SceneChange(SceneMgr::STAGE);
	}

	return LIVE;
}

void LobbyStnBtn::LateUpdate()
{
}

void LobbyStnBtn::Render(HDC hDC)
{
	//Rectangle(hD C, rect.left, rect.top, rect.right, rect.bottom);
}

void LobbyStnBtn::Release()
{
}
