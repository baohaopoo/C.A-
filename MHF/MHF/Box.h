#pragma once
#include "Object.h"
#include "BmpMgr.h"
class Box : public Object
{
	//¿Ã±€∑Á
public:
	Box();
	virtual ~Box();

public:
	virtual void Initialize();
	virtual int Update();
	virtual void LateUpdate();
	virtual void Render(HDC hdc);
	virtual void Release();

	virtual void Coliide(OBJID objid);

private:
	TCHAR* framekey;
};

