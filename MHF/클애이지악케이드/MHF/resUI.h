#pragma once
#include "Object.h"
class resUI : public Object
{
public:
	resUI();
	virtual ~resUI();

public:
	virtual void Initialize();
	virtual int Update();
	virtual void LateUpdate();
	virtual void Render(HDC hdc);
	virtual void Release();

private:
	DWORD dwTime = GetTickCount();
	TCHAR* framekey;

};

