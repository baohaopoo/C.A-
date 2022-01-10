#pragma once
#include "Object.h"
class StartMBtn: public Object
{
public:
	StartMBtn();
	virtual ~StartMBtn();

public:
	virtual void Initialize();
	virtual int Update();
	virtual void LateUpdate();
	virtual void Render(HDC hDC);
	virtual void Release();
};

