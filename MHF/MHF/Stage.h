#pragma once
#include"Scene.h"
#include"Player.h"
#include"Monster.h"
#include"Mouse.h"
#include"StartUI.h"
#include"Box.h"
#include"Item.h"
#include<random>
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
	void CreateItem(TCHAR* key, float x, float y);
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

	default_random_engine dre;
	uniform_int_distribution<> uidx{ 100,300 };
	uniform_int_distribution<> uidy{ 200,600 };
};

