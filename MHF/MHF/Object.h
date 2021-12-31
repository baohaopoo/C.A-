#pragma once
#include"Struct.h"
#include "Enum.h"
#include "Define.h"
class Object
{
public:
	Object();
	virtual ~Object();


public:
	virtual void Initialize() = 0;
	virtual int Update() = 0;
	virtual	void LateUpdate() = 0;
	virtual void Render(HDC hdc) = 0;
	virtual void Release() = 0;


public:
	virtual void UpdateRect();
	
public:
	RECT& GetRect();
	INFO& GetInfo();
	void setDead();
protected:
	INFO info;
	RECT rect;
	bool isDead;

	Frame frame;

};

