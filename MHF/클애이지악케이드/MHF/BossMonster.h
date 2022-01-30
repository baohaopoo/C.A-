#pragma once
#include "Object.h"
class BossMonster : public Object
{
public:
	enum STANCE {  IDLE,LEFT,RIGHT, DAMAGE, ROLL, PANG,DIE, END };

public:
	BossMonster();
	virtual ~BossMonster();

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
	int delay = 0;
	int wait = 0;
	int wait2 = 0;
	int delay2 = 0;
	int hp = 1920;
};

