#pragma once
#include"Object.h"
#include"downBullet.h"
#include "UpBullet.h"
#include"LeftBullet.h"
#include"RightBullet.h"
#include "middleBullet.h"
class Bullet : public Object
{
public:
	enum STANCE { IDLEBOMB, ALONEBOMB, FLOWBOMB ,END};
public:
	Bullet();
	virtual ~Bullet();

public:
	virtual void Initialize();
	virtual int Update();
	virtual void LateUpdate();
	virtual void Render(HDC hdc);
	virtual void Release();
	virtual void Collide(OBJID objid);
public:
	void setDir(int dir);
	void setPos(float x, float y);
	void frameChange();
	void sodago(int cnt);
	void setsoda(int cnt) { sodacnt = cnt; };
	void CreateBullet(int cnt);
private:
	int sodacnt = 0;
	int direction;

	TCHAR* framekey;
	TCHAR* framekey2;
	TCHAR* framekey3;
	TCHAR* framekey4;
	TCHAR* framekey5;

	STANCE curstance;
	STANCE prestance;
	
	DWORD bombTime = GetTickCount();



	Object* middle;
	list<Object*>* middleBucket;

	Object* down;
	list<Object*>* downBucket;

	Object* up;
	list<Object*>* upBucket;

	Object* right;
	list<Object*>* rightBucket;

	Object* left;
	list<Object*>* leftBucket;
};

