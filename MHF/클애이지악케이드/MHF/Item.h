#pragma once
#include "Object.h"
#include "BmpMgr.h"
#include <random>
class Item : public Object
{
public:
	Item();
	virtual ~Item();

public:
	virtual void Initialize();
	virtual int Update();
	virtual void LateUpdate();
	virtual void Render(HDC hdc);
	virtual void Release();

public:
	virtual void Collide(OBJID objid);

	void setImageKey(TCHAR* key);

private:
	TCHAR* imageKey;
	int cnt;	//이거는 나름의 애니메이션 장치.
	int cnt2;

	DWORD dwTime = GetTickCount();
	bool isCollision = false;
	
};

