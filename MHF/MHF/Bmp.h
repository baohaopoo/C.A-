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
	HDC memDC; //�о�� ��Ʈ�� �̸� �׸���

	HBITMAP bitMap;
	HBITMAP tmp;

};

