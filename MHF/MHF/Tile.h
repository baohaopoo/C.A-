#pragma once
#include "Object.h"
#include"BmpMgr.h"

class Tile : public Object
{
public:
	Tile();
	virtual ~Tile();

//public:
//	int GetTileID() { return tileID; }
public:
	void SetTileID(TCHAR* name);
	TCHAR* GetTileID();
public:

	virtual void Initialize();
	virtual int Update();
	virtual void LateUpdate();
	virtual void Render(HDC hdc);
	virtual void Release();

private:
	TCHAR* tileID;
};

