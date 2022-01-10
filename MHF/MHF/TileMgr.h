#pragma once
class Object;
class TileMgr
{

public:
	static TileMgr* GetInstance();
	void DestroyInstance();

public:
	TileMgr();
	~TileMgr();

public:
	void Initialize();
	void Update();
	void LateUpdate();
	void Render(HDC hdc);
	void Release();

public:
	void PickTile(int index, int TileName);
	void SaveTile();
	void LoadTile();


private:

	static TileMgr* instance;
	vector<Object*> TileVec;
	
};

