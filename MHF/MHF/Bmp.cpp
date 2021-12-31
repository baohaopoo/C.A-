#include "stdafx.h"
#include "Bmp.h"
#include "Define.h"

Bmp::Bmp()
{
}


Bmp::~Bmp()
{
}

void Bmp::LoadBmp(const TCHAR * FilePath)
{
	bitMap = (HBITMAP)LoadImage(nullptr, FilePath, IMAGE_BITMAP, 0, 0,
		LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	HDC hDC = GetDC(g_hWnd);
	
	memDC = CreateCompatibleDC(hDC);
	ReleaseDC(g_hWnd, hDC);

	tmp = (HBITMAP)SelectObject(memDC, bitMap);
}

void Bmp::Release()
{
	SelectObject(memDC, tmp);
	DeleteObject(bitMap);
	DeleteDC(memDC);
}
