#pragma once
#include"Object.h"

template<typename T>
class Factory
{
public:

	static Object* CreateObj()
	{
		Object* pObj = new T;
		pObj->Initialize();

		return pObj;
	}

	static Object* CreateObj(float x, float y) {
		
		Object* pobj = new T;
		pobj->Initialize();
		pobj->setPos(x, y);
	
		return pobj;
	}
	static Object* CreateObj(float x, float y,int dir) {

		Object* pobj = new T;
		pobj->Initialize();
		pobj->setPos(x, y);
		pobj->setdirection(dir);
		return pobj;
	}

	static Object* CreateObj(float x, float y,float cx, float cy) {

		Object* pobj = new T;
		pobj->Initialize();
		pobj->setPos(x, y);
		pobj->setSize(cx, cy);
		
		return pobj;
	}

	static Object* CreateObj(TCHAR* name, float x, float y, float cx, float cy) {

		Object* pobj = new T;
		pobj->Initialize();
		pobj->setPos(x, y);
		pobj->setSize(cx, cy);
		pobj->setImage(name);
		return pobj;
	}


};