#pragma once
#include "Object.h"
#include "BmpMgr.h"
class ItemBox : public Object
{
public:
	ItemBox();
	virtual ~ItemBox();

public:
	virtual void Initialize();
	virtual int Update();
	virtual void LateUpdate();
	virtual void Render(HDC hdc);
	virtual void Release();
	virtual void Coliide(OBJID objid);
private:
	bool isCollision = false;
	TCHAR* itemkey;
	TCHAR* framekey;
	DWORD dwTime = GetTickCount();

};

