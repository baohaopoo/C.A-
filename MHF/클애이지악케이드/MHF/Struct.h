#pragma once
typedef struct OBJINFO {
	float fX;
	float fY;
	float fCX;
	float fCY;

	float fSpeed;
	int dir;
	TCHAR* name;
}INFO;


typedef struct FRAME
{
	int startX;
	int EndX;
	int startY;
	int EndY;
	DWORD OldTime;
	DWORD Speed;
	

}Frame;