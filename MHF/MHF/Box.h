#pragma once
#include "Object.h"
#include "BmpMgr.h"
class Box : public Object
{
	//�̱۷�
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

