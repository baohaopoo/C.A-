#pragma once
#include"Object.h"
class Mouse : public Object
{
public:
	Mouse();
	virtual ~Mouse();

public:
	virtual void Initialize();
	virtual int Update();
	virtual void LateUpdate();
	virtual void Render(HDC hdc);
	virtual void Release();

};

