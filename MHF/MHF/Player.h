#pragma once
#include "Object.h"
#include "Define.h"
#include "Bullet.h"
#include "PlayerCollider.h"
#include "UpFlow.h"
class Player : public Object
{
public:
	enum STANCE{IDLE, WALK,BOMB,PANG, END};

public:
	Player();
	virtual ~Player();

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

	

private:
	Bullet* bullet;
	Object* playerc;
	list<Object*>* bulletBucket;
	DWORD dwTime = GetTickCount();

private:
	POINT barrel;
	float angle;
	
private:
	TCHAR* frameKey;
	TCHAR* frameKey2;

	TCHAR* playeraArrow;
	TCHAR* Shdow;

	STANCE curstance;
	STANCE prestance;
private:
	bool isEglue = false;
	int pangcnt = 0;
};

