#pragma once

class Scene;
class SceneMgr
{
public:
	static SceneMgr* GetInstance();
	static void DestroyInstance()
	{
		if (instance)
		{
			delete instance;
			instance = nullptr;
		}
	}
public:
	enum SCENE { LOGO,START,LOBBY, STAGE,MONSTAGE, BOSS,END };

public:
	SceneMgr();
	~SceneMgr();

public:
	void SceneChange(SCENE sc);
	void Update();
	void LateUpdate();
	void Render(HDC hDC);
	void Release();

private:
	Scene* psc;
	SCENE curScene;
	SCENE preScene;

private:
	static SceneMgr* instance;
};

