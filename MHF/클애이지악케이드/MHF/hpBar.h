#pragma once
#include"Object.h"
#include"BmpMgr.h"
class hpBar :public Object
{
public:
	hpBar();
	virtual ~hpBar();


public:
	virtual void Initialize();
	virtual int Update();
	virtual void LateUpdate();
	virtual void Render(HDC hdc);
	virtual void Release();


private:
	DWORD bombTime = GetTickCount();
};

