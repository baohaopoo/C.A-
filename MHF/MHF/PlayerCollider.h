#pragma once
#include "Object.h"

class PlayerCollider : public Object
{
public:
	PlayerCollider();
	virtual ~PlayerCollider();

public:
	virtual void Initialize();
	virtual int Update();
	virtual void LateUpdate();
	virtual void Render(HDC hdc);
	virtual void Release();


};

