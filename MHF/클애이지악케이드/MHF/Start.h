#pragma once
#include "Scene.h"
#include "StartBtn.h"

#include "mouse.h"
class Start: public Scene
{
public:
	Start();
	virtual ~Start();

public:
	virtual void Initialize();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render(HDC hDC);
	virtual void Release();


};

