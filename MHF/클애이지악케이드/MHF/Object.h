#pragma once
#include"Struct.h"
#include "Enum.h"
#include "Define.h"
class Object
{
public:
	Object();
	virtual ~Object();


public:
	virtual void Initialize() = 0;
	virtual int Update() = 0;
	virtual	void LateUpdate() = 0;
	virtual void Render(HDC hdc) = 0;
	virtual void Release() = 0;


public:
	virtual void UpdateRect();
	virtual void ColliderUpdateRect();
	virtual void Collide(OBJID objid);
	virtual void Collide2();
	
public:
	RECT& GetRect();
	INFO& GetInfo();

	void setPos(float x, float y);
	void setPosY(float y) { info.fY = y; };
	void setPosX(float x) { info.fX = x; };
	void setSpeed(float s) { info.fSpeed = s; };
	void setSize(float x, float y) { info.fCX = x; info.fCY = y; };
	void setImage(TCHAR* _name) { info.name = _name; };
	void setdirection(int dir) { info.dir = dir; }
	TCHAR* getImage() { return info.name; };
	void setDead();
	bool GetDead();
	OBJID getID();
	void setID(OBJID obj) { id = obj; };
protected:
	void MoveFrame(int state);
	void MoveFrame();
	void MoveFrameY();

protected:
	INFO info;
	RECT rect;
	RECT colliderBox;
	Frame frame;
	
	DWORD dwTime = GetTickCount();
	bool isDead;
	bool isCollision;
	OBJID id;
};

