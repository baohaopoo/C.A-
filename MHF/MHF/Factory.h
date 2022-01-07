#pragma once
#include"Object.h"

template<typename T>
class Factory
{
public:
	static Object* CreateObj(float x, float y) {
		
		Object* pobj = new T;
		pobj->Initialize();
		pobj->setPos(x, y);
	
		return pobj;
	}

};