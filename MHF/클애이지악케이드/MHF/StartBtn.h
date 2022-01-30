#pragma once
#include "Object.h"
class StartBtn : public Object
{
public:
	StartBtn();
	virtual ~StartBtn();

public:
	virtual void Initialize();
	virtual int Update();
	virtual void LateUpdate();
	virtual void Render(HDC hDC);
	virtual void Release();

};

