#pragma once
#include"Object.h"
class StartUI :public Object
{
public:
	StartUI();
	virtual ~StartUI();//�� �ٿ�

public:
	virtual void Initialize();
	virtual int Update();
	virtual void LateUpdate();
	virtual void Render(HDC hdc);
	virtual void Release();
private:
	DWORD dwTime = GetTickCount();
};

