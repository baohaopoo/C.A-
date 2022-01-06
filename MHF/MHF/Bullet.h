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
	
public:
	void setDir(int dir);
	void setPos(float x, float y);
	void frameChange();

private:
	int direction;

	TCHAR* framekey;
	STANCE curstance;
	STANCE prestance;

	DWORD bombTime = GetTickCount();


};

