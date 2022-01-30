#pragma once
#include "Object.h"
class Monster : public Object
{
public:
	enum STANCE { BIRTH,IDLE, DAMAGE, RUN, PANG, EFFECT,END };

public:
	Monster();
	virtual ~Monster();
public:
	virtual void Initialize();
	virtual int Update();
	virtual void LateUpdate();
	virtual void Render(HDC hdc);
	virtual void Release();
	void frameChange();
	virtual void Collide2();
	virtual void Collide(OBJID objid);

public:
	int getcnt() { return deadcnt; }
private:
	TCHAR* frameKey;
	TCHAR* itemkey;
	TCHAR* effectKey;
	STANCE curstance;
	STANCE prestance;

	bool iseffect = false;
	bool					m_bJump;
	float					m_fPower;
	float					m_fOriginY;

	bool m_bStretch = true;

	bool isCollision = false;
	bool gorun = false;
	bool gopang = false;
	bool isalldie = false;
	int delay = 0;
	int deadcnt;
};

