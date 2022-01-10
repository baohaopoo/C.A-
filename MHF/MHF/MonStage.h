#pragma once
#include"Scene.h"
#include"Player.h"
#include"Monster.h"
#include"Mouse.h"
#include"StartUI.h"
#include"Box.h"
#include"Item.h"
#include "UpFlow.h"
#include<random>
class MonStage : public Scene
{
public:
	MonStage();
	virtual ~MonStage();

public:
	virtual void Initialize();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render(HDC hDC);
	virtual void Release();


	void isPicking();

private:
	list<Object*> ObjList[END];
	Object* player;
	Object* bmonster;
};

