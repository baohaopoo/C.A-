#include "stdafx.h"
#include "resUI.h"
#include "BmpMgr.h"
#include "SceneMgr.h"

resUI::resUI()
{
}


resUI::~resUI()
{
	Release();
}

void resUI::Initialize()
{
	BmpMgr::getInstance()->InsertBmp(L"res", L"../Image/lose.bmp");
	BmpMgr::getInstance()->InsertBmp(L"reszzi", L"../Image/losezzi.bmp");
	BmpMgr::getInstance()->InsertBmp(L"winzzi", L"../Image/winzzi.bmp");
	BmpMgr::getInstance()->InsertBmp(L"win", L"../Image/lose.bmp");
}

int resUI::Update()
{
	UpdateRect();
	framekey = info.name;
	if (isDead)
		return DEAD;

	return LIVE;
}

void resUI::LateUpdate()
{
}

void resUI::Render(HDC hdc)
{
	HDC resUI = BmpMgr::getInstance()->FindImage(L"res");
	if (resUI == nullptr) {
		return;
	}

	HDC resUI2 = BmpMgr::getInstance()->FindImage(framekey);
	if (resUI2 == nullptr) {
		return;
	}

	if (info.name == L"res") {
		GdiTransparentBlt(hdc, rect.left, rect.top, info.fCX, info.fCY, resUI, 0, 80, 312, 71, RGB(255, 201, 14));
	}
	if (info.name == L"winzzi")
	{
		GdiTransparentBlt(hdc, rect.left, rect.top, info.fCX, info.fCY, resUI2, 0, 0, 269, 170, RGB(255, 201, 14));
	}
	else if (info.name == L"reszzi") {
		GdiTransparentBlt(hdc, rect.left, rect.top, info.fCX, info.fCY, resUI2, 0, 0, 269,170, RGB(255, 201, 14));
	
	}else if (info.name == L"win") {
		GdiTransparentBlt(hdc, rect.left, rect.top, info.fCX, info.fCY, resUI, 0, 140, 312, 71, RGB(255, 201, 14));

	}

}

void resUI::Release()
{
}
