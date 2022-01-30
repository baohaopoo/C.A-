#pragma once
#include "BmpMgr.h"
class Scene
{
public:
	Scene();
	virtual ~Scene();

public:
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void LateUpdate() = 0;
	virtual void Render(HDC hDC) = 0;
	virtual void Release() = 0;

protected:
	BmpMgr* m_pBmgMgr;
};

