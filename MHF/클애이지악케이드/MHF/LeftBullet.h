#pragma once
#include"Object.h"
class LeftBullet : public Object
{
public:
	LeftBullet();
	virtual~LeftBullet();

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

