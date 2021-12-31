#pragma once
#include "Object.h"
class Monster : public Object
{
public:
	Monster();
	~Monster();
public:
	virtual void Initialize();
	virtual int Update();
	virtual void LateUpdate();
	virtual void Render(HDC hdc);
	virtual void Release();



};

