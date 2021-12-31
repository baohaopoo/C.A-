#pragma once
#include"Scene.h"

class Logo : public Scene
{
public:
	Logo();
	virtual ~Logo();

public:
	virtual void Initialize();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render(HDC hDC);
	virtual void Release();
};

