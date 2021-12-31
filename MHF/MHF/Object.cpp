#include "stdafx.h"
#include "Object.h"


Object::Object()
{
	ZeroMemory(&info, sizeof(INFO));
	ZeroMemory(&rect, sizeof(RECT));
	isDead = false;
}


Object::~Object()
{
}

void Object::UpdateRect()
{
	rect.left = LONG(info.fX - (info.fCX * 0.5));
	rect.top = LONG(info.fY - (info.fCY *0.5));
	rect.right = LONG(info.fX + (info.fCX * 0.5));
	rect.bottom = LONG(info.fY + (info.fCY *0.5));

}

RECT & Object::GetRect()
{
	return rect;
}

INFO & Object::GetInfo()
{
	return info;
}

void Object::setDead()
{
	isDead = true;
}
