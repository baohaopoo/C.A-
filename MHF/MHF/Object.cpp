#include "stdafx.h"
#include "Object.h"


Object::Object()
{
	ZeroMemory(&info, sizeof(INFO));
	ZeroMemory(&rect, sizeof(RECT));
	ZeroMemory(&frame, sizeof(FRAME));
	ZeroMemory(&colliderBox, sizeof(RECT));
	isDead = false;
	isCollision = false;
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

void Object::ColliderUpdateRect()
{
	colliderBox.left = LONG(info.fX - (info.fCX * 0.5)) + 10;
	colliderBox.top = LONG(info.fY - (info.fCY *0.5)) + 10 ;
	colliderBox.right = LONG(info.fX + (info.fCX * 0.5))- 10;
	colliderBox.bottom = LONG(info.fY + (info.fCY *0.5)) - 10;

}

RECT & Object::GetRect()
{
	return rect;
}

INFO & Object::GetInfo()
{
	return info;
}

void Object::setPos(float x, float y)
{
	info.fX = x;
	info.fY = y;
}

void Object::setDead()
{
	isDead = true;
}

void Object::MoveFrame()
{
	if (frame.OldTime + frame.Speed < GetTickCount()) {
		frame.startX++;
		frame.OldTime = GetTickCount();
	}

	if (frame.startX > frame.EndX)
		frame.startX = 0;

}

void Object::Collide()
{
	isCollision = true;
}
