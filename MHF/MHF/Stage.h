#pragma once
#include"Scene.h"
#include"Player.h"
#include"Monster.h"
#include"Mouse.h"
#include"StartUI.h"
#include"Box.h"
#include"Item.h"
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

public:
	void isPicking();

private:
	Object* player;
	Object* monster;
	Object* mouse;

	DWORD dwTime = GetTickCount();
	list<Object*> ObjList[END];

	StartUI* stui;

	Box* box;
	Item* skate;

	bool isEdit;

};

