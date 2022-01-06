#pragma once
#include "Object.h"
#include "BmpMgr.h"
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

	virtual void Collide();


};

