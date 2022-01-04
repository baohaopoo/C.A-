#pragma once
#include "Object.h"

class LobbyStnBtn : public Object
{
public:
	LobbyStnBtn();
	virtual ~LobbyStnBtn();

public:
	virtual void Initialize();
	virtual int Update();
	virtual void LateUpdate();
	virtual void Render(HDC hDC);
	virtual void Release();



};

