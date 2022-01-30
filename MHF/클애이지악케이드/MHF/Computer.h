#pragma once
#include "Define.h"
#include "Bullet.h"
#include "downBullet.h"
class Computer:public Object
{

public:
	enum STANCE { IDLE, IDLE2, WALK, BOMB1, BOMB, PANG, SAVE, END };

public:
	Computer();
	virtual ~Computer();

public:
	virtual void Initialize();
	virtual int Update();
	virtual void LateUpdate();
	virtual void Render(HDC hdc);
	virtual void Release();

public:
	void SetBulletList(list<Object*>* bulletLst);

	void frameChange();
	virtual void Collide(OBJID objid);

private:
	void KeyInput();
	void CreateBullet();
	void eatSkate();
	void bombpang();



private:
	Bullet* bullet;
	bool					m_bStretch = true;
	int wait = 0;
	int wait2 = 0;
	int before = wait;
	Object* playerc;
	list<Object*>* bulletBucket;
	list<Object*>* downBucket;
	DWORD dwTime = GetTickCount();

private:
	POINT barrel;
	float angle;

private:
	TCHAR* frameKey;
	TCHAR* frameKey2;

	STANCE curstance;
	STANCE prestance;
private:
	bool isEglue = false;
	bool ispang = false;
	int pangcnt = 0;
	bool ismon = false;
	bool issoda = false;

};

