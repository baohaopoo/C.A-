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
	void setid(OBJID objid) { id = objid; };
public:

	virtual void Initialize();
	virtual int Update();
	virtual void LateUpdate();
	virtual void Render(HDC hdc);
	virtual void Release();


public:
	int GetDrawID() { return drawID; }
	void SetDrawID(int iDrawID) { drawID = iDrawID; }

private:
	TCHAR* tileID;
	int drawID;

};

