#pragma once
#include"Object.h"
class RightBullet : public Object
{
public:
	RightBullet();
	virtual~RightBullet();


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

