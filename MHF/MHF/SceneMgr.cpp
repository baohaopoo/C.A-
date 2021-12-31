#include "stdafx.h"
#include "SceneMgr.h"
#include "Functional.h"
#include "Logo.h"
#include "Stage.h"
#include "Lobby.h"
SceneMgr* SceneMgr::instance = nullptr;

SceneMgr * SceneMgr::GetInstance()
{
	if (nullptr == instance)
		instance = new SceneMgr;

	return instance;
}

void SceneMgr::DestroyInstance()
{
	if (instance)
	{
		delete instance;
		instance = nullptr;
	}
}

SceneMgr::SceneMgr()
	:psc(nullptr),curScene(END),preScene(END)
{
}


SceneMgr::~SceneMgr()
{
	Release();
}

void SceneMgr::SceneChange(SCENE sc)
{
	curScene = sc;

	if (preScene != curScene) {
	
		SafeDelete(psc);

		switch (curScene)
		{
		case LOGO:
			psc = new Logo;
			break;
		case LOBBY:
			psc = new Lobby;
			break;

		case STAGE:
			psc = new Stage;
			break;
		}

		psc->Initialize();
		preScene = curScene;
		 
	}
}

void SceneMgr::Update()
{
	psc->Update();
}

void SceneMgr::LateUpdate()
{
	psc->LateUpdate();
}
void SceneMgr::Render(HDC hDC)
{
	psc->Render(hDC);
}

void SceneMgr::Release()
{
	SafeDelete(psc);
}
