#pragma once
#include"Scene.h"
#include"Player.h"
#include"Monster.h"
#include"Mouse.h"
#include"StartUI.h"
#include"Box.h"
#include"Item.h"
#include<random>
class MonStage : public Scene
{


	default_random_engine dre;
	uniform_int_distribution<> uidx{ 380,590 };
	uniform_int_distribution<> uidy{ 200,410 };

public:
	MonStage();
	virtual ~MonStage();

public:
	virtual void Initialize();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render(HDC hDC);
	virtual void Release();

	int pickcnt;
	int puplecnt ;
	Object* pObj;
	Object* puple;

	int wait = 0;
	DWORD dwTime = GetTickCount();
};

