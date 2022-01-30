#pragma once
#include "Object.h"
class Smoke : public Object
{
public:
	Smoke();
	virtual ~Smoke();

	virtual void Initialize();
	virtual int Update();
	virtual void LateUpdate();
	virtual void Render(HDC hdc);
	virtual void Release();
	virtual void Collide(OBJID objid);

private:

	DWORD smokeTime = GetTickCount();
};

