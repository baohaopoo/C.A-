#pragma once
#include "Object.h"
#include "Define.h"
#include "Bullet.h"

class Player : public Object
{
public:
	enum STANCE{IDLE, WALK,BOMB,END};
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
	virtual void Collide();

private:
	void KeyInput();
	void CreateBullet();
	void eatSkate();
	

private:
	Bullet* bullet;
	list<Object*>* bulletBucket;
	DWORD dwTime = GetTickCount();

private:
	POINT barrel;
	float angle;
	
private:
	TCHAR* frameKey;
	STANCE curstance;
	STANCE prestance;

};

