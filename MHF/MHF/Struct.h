#pragma once
typedef struct OBJINFO {
	float fX;
	float fY;
	float fCX;
	float fCY;

	float fSpeed;
}INFO;


typedef struct FRAME
{
	int startX;
	int EndX;
	int startY;

	DWORD OldTime;
	DWORD Speed;

}Frame;