#pragma once

class Scene;
class SceneMgr
{
public:
	static SceneMgr* GetInstance();
	void DestroyInstance();
public:
	enum SCENE { LOGO,START,LOBBY, STAGE,MONSTAGE, END };

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

