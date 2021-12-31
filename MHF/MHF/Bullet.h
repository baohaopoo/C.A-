#pragma once
#include"Object.h"
class Bullet : public Object
{
public:
	Bullet();
	virtual ~Bullet();

public:
	virtual void Initialize();
	virtual int Update();
	virtual void LateUpdate();
	virtual void Render(HDC hdc);
	virtual void Release();
	
public:
	void setDir(int dir);
	void setPos(float x, float y);
private:
	int direction;
};

