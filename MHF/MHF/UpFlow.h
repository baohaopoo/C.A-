#pragma once
#include"Object.h"
class UpFlow : public Object
{
public:
	UpFlow();
	virtual ~UpFlow();

public:
	virtual void Initialize();
	virtual int Update();
	virtual void LateUpdate();
	virtual void Render(HDC hdc);
	virtual void Release();

};

