#pragma once
#include "Scene.h"
#include "LobbyStnBtn.h"
class Lobby : public Scene
{
public:
	Lobby();
	virtual ~Lobby();

public:
	virtual void Initialize();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render(HDC hDC);
	virtual void Release();


};

