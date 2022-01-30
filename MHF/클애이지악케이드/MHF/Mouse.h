#pragma once
#include"Object.h"
class Mouse : public Object
{
public:
	Mouse();
	virtual ~Mouse();

	enum STANCE{IDLE,END};
public:
	virtual void Initialize();
	virtual int Update();
	virtual void LateUpdate();
	virtual void Render(HDC hdc);
	virtual void Release();

private:
	TCHAR* framekey;
	STANCE curstnace;
	STANCE prestance;
};

