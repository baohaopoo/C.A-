#pragma once
#include"Object.h"
#include "UpFlow.h"

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

private:
	int direction;

	TCHAR* framekey;
	TCHAR* framekey2;
	TCHAR* framekey3;
	TCHAR* framekey4;
	TCHAR* framekey5;

	STANCE curstance;
	STANCE prestance;

	DWORD bombTime = GetTickCount();


};

