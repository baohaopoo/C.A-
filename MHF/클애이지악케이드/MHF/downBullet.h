#pragma once
#include"Object.h"
class downBullet: public Object
{
public:
	downBullet();
	virtual ~downBullet();

public:
	virtual void Initialize();
	virtual int Update();
	virtual void LateUpdate();
	virtual void Render(HDC hdc);
	virtual void Release();
	virtual void Collide(OBJID objid);

private:
	DWORD bombTime = GetTickCount();
};

