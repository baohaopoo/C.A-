#pragma once
#include "Scene.h"
#include "Object.h"
#include "StartBtn.h"
#include "StartMBtn.h"
class Start: public Scene
{
public:
	Start();
	~Start();

public:
	virtual void Initialize();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render(HDC hDC);
	virtual void Release();

private:
	Object* pObj;
	Object* pObj2;

};

