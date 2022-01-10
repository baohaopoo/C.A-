#pragma once
#include "Object.h"
class Monster : public Object
{
public:
	enum STANCE { IDLE, WALK, BOMB, PANG, END };

public:
	Monster();
	~Monster();
public:
	virtual void Initialize();
	virtual int Update();
	virtual void LateUpdate();
	virtual void Render(HDC hdc);
	virtual void Release();


	void frameChange();
private:
	TCHAR* frameKey;

};

