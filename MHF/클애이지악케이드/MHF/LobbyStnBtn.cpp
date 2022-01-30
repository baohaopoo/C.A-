#include "stdafx.h"
#include "LobbyStnBtn.h"
#include "SceneMgr.h"
#include "BmpMgr.h"
#include"SoundMgr.h"
LobbyStnBtn::LobbyStnBtn()
{
}


LobbyStnBtn::~LobbyStnBtn()
{
	
}

void LobbyStnBtn::Initialize()
{
	BmpMgr::getInstance()->InsertBmp(L"chmap", L"../Image/choosemap.bmp");
}

int LobbyStnBtn::Update()
{

	UpdateRect();
	return LIVE;
}

void LobbyStnBtn::LateUpdate()
{
	if(GetAsyncKeyState('T'))
	{
		isgo = false;
	}
	POINT pt{};
	GetCursorPos(&pt);
	UpdateRect();
	ScreenToClient(g_hWnd, &pt);

	if (PtInRect(&rect, pt))
	{
		if (info.name == L"ST") {
			info.fCX = 210; info.fCY = 80;
		}
		if (info.name == L"mapb") {
			info.fCX = 160; info.fCY = 60;
		}
		if (GetAsyncKeyState(VK_LBUTTON))
		{
			SoundMgr::Get_Instance()->PlaySoundW(L"Button.wav", SoundMgr::UI, 8);
			if (info.name == L"OUI" && ispick == false) {
				info.name = L"XUI";
			}
			else if (info.name == L"OUI2") {
				info.name = L"XUI2";
			}
			else if (info.name == L"ST" ){
				info.name = L"ST";
			
				SceneMgr::GetInstance()->SceneChange(SceneMgr::STAGE); 
			}
			else if (info.name == L"GB") {
				info.name = L"GB";
				SceneMgr::GetInstance()->SceneChange(SceneMgr::START);
			}
			else if (info.name == L"mapb") {
				info.name = L"mapb";
				isgo = true;

			}
		}
	}
	else if (info.name == L"ST") {
		info.fCX = 195; info.fCY = 68;
	}

	else if (info.name == L"mapb") {
		info.fCX = 130; info.fCY = 60;
	}
	
}

void LobbyStnBtn::Render(HDC hDC)
{
	HDC memDC = BmpMgr::getInstance()->FindImage(info.name);
	HDC chDC = BmpMgr::getInstance()->FindImage(L"chmap");

	if (nullptr == memDC)return;

	if (info.name == L"mapb") {
		GdiTransparentBlt(hDC, rect.left, rect.top, info.fCX, info.fCY, memDC, 0, 0, 129, 53, RGB(255, 201, 14));
	
	
	}

	if (info.name == L"XUI") {
		GdiTransparentBlt(hDC, rect.left, rect.top, info.fCX, info.fCY, memDC, 0, 0, 120, 113, RGB(255, 201, 14));
	}
	if (info.name == L"XUI2") {
		GdiTransparentBlt(hDC, rect.left, rect.top, info.fCX, info.fCY, memDC, 0, 0, 120, 113, RGB(255, 201, 14));
	}
	if (info.name == L"ST") {
		GdiTransparentBlt(hDC, rect.left, rect.top, info.fCX, info.fCY, memDC, 0, 0, 200, 69, RGB(255, 201, 14));
	}
	if (info.name == L"GB") {
		GdiTransparentBlt(hDC, rect.left, rect.top, info.fCX, info.fCY, memDC, 0, 0, 94, 69, RGB(255, 201, 14));
	}

	if (isgo) {
		GdiTransparentBlt(hDC, 160, 100, 500, 400, chDC, 0, 0, 685, 618, RGB(255, 201, 14));
	
	}
	
}

void LobbyStnBtn::Release()
{
}
