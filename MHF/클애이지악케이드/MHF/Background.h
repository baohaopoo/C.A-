#pragma once
#include "Object.h"
#include "BmpMgr.h"
class Background : public Object
{
public:
	Background();
	virtual ~Background();

public:
	virtual void Initialize();
	virtual int Update();
	virtual void LateUpdate();
	virtual void Render(HDC hdc);
	virtual void Release();
	virtual void Collide(OBJID objid);
private:

	Object* smoke;
	bool isCollision = false;
	TCHAR* framekey;
};

