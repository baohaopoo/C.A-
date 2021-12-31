#pragma once
#include"Scene.h"
#include"Player.h"
#include"Monster.h"
#include"Mouse.h"

class Stage : public Scene
{
public:
	Stage();
	virtual ~Stage();


public:
	virtual void Initialize();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render(HDC hDC);
	virtual void Release();

	Object* player;
	Object* monster;
	Object* mouse;

	list<Object*> ObjList[END];

};

