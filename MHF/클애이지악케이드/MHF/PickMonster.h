#pragma once
#include "Object.h"
class PickMonster : public Object
{
public:
	enum STANCE { BIRTH, IDLE, DAMAGE, RUN, PANG, END };

public:
	PickMonster();
	virtual ~PickMonster();

public:
	virtual void Initialize();
	virtual int Update();
	virtual void LateUpdate();
	virtual void Render(HDC hdc);
	virtual void Release();
	void frameChange();
	virtual void Collide(OBJID objid);
	virtual void Collide2();

private:
	TCHAR* frameKey;
	STANCE curstance;
	STANCE prestance;
	bool gorun = false;
	bool gopang = false;
	int delay = 0;

};

