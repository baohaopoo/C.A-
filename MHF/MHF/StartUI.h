#pragma once
#include"Object.h"
class StartUI :public Object
{
public:
	StartUI();
	~StartUI();

public:
	virtual void Initialize();
	virtual int Update();
	virtual void LateUpdate();
	virtual void Render(HDC hdc);
	virtual void Release();

};

