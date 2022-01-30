#pragma once
#include "Scene.h"
#include "LobbyStnBtn.h"

class Boss : public Scene
{
public:
	Boss();
	virtual ~Boss();

public:
	virtual void Initialize();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render(HDC hDC);
	virtual void Release();
	
private:
	Object* pObj;
};

