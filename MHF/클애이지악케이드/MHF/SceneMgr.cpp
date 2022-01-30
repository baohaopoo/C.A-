#include "stdafx.h"
#include "SceneMgr.h"
#include "Functional.h"
#include "Logo.h"
#include "Stage.h"
#include "Lobby.h"
#include "Start.h"
#include "MonStage.h"
#include "SoundMgr.h"
#include "Boss.h"
SceneMgr* SceneMgr::instance = nullptr;

SceneMgr * SceneMgr::GetInstance()
{
	if (nullptr == instance)
		instance = new SceneMgr;

	return instance;
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
		case START:
			
			psc = new Start;
			
			break;
		case LOBBY:
			psc = new Lobby;
			break;

		case STAGE:
			psc = new Stage;
			break;


		case MONSTAGE:
			psc = new MonStage;
			break;

		case BOSS:
			psc = new Boss;
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
