#pragma once
#include"Object.h"
class middleBullet : public Object
{
public:
	middleBullet();
	virtual ~middleBullet();
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

