#pragma once
class Bmp
{
public:
	Bmp();
	~Bmp();


public:
	HDC GetmemDC() {return memDC;}
public:
	void LoadBmp(const TCHAR* FilePath);
	void Release();
private:
	HDC memDC; //읽어온 비트맵 미리 그리기

	HBITMAP bitMap;
	HBITMAP tmp;

};

