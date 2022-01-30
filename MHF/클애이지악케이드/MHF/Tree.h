#pragma once
#include "Object.h"
#include "BmpMgr.h"
class Tree : public Object
{
public:
	Tree();
	virtual ~Tree();

public:
	virtual void Initialize();
	virtual int Update();
	virtual void LateUpdate();
	virtual void Render(HDC hdc);
	virtual void Release();
	virtual void Coliide(OBJID objid);

private:
	bool isCollision = false;
	TCHAR* framekey;
	DWORD dwTime = GetTickCount();
};

