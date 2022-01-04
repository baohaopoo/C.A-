#pragma once
#include "Scene.h"
#include "StartBtn.h"
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
	StartBtn stBtn;
};

