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
	colliderBox.left = LONG(info.fX - (info.fCX * 0.5));
	colliderBox.top = LONG(info.fY - (info.fCY *0.5))  ;
	colliderBox.right = LONG(info.fX + (info.fCX * 0.5));
	colliderBox.bottom = LONG(info.fY + (info.fCY *0.5)) ;

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

bool Object::GetDead()
{
	return isDead;
}

OBJID Object::getID()
{
	return id;
}

void Object::MoveFrame(int state)
{
	//1 상태가 save일때
	if (state == 1) {
		if (frame.OldTime + frame.Speed < GetTickCount()) {
			++frame.startX;
			frame.OldTime = GetTickCount();
		}

		if (frame.startX > 3)
			frame.startX = 3;
	}
	//상태가 bomb일떄
	if (state == 2) {
		if (frame.OldTime + frame.Speed < GetTickCount()) {
			++frame.startX;
			frame.OldTime = GetTickCount();
		}


		if (frame.startX > 3)
			frame.startX = 3;
	}

	//상태가 bomb1일떄
	if (state == 3) {
		if (frame.OldTime + frame.Speed < GetTickCount()) {
			++frame.startX;
			frame.OldTime = GetTickCount();
		}

		if (frame.startX > 1)
			frame.startX = 1;
	}

	//상태가 Pang일떄
	if (state == 4) {
		if (frame.OldTime + frame.Speed < GetTickCount()) {
			++frame.startX;
			frame.OldTime = GetTickCount();
		}

		if (frame.startX > 4)
			frame.startX = 4;
	}


}

void Object::MoveFrame()
{
	if (frame.OldTime + frame.Speed < GetTickCount()) {
		++frame.startX;
		frame.OldTime = GetTickCount();
	}

	if (frame.startX > frame.EndX)
		frame.startX = 0;

}

void Object::MoveFrameY()
{
	if (frame.OldTime + frame.Speed < GetTickCount()) {
		++frame.startY;
		frame.OldTime = GetTickCount();
	}

	if (frame.startY > frame.EndY)
		frame.startY = 0;

}

void Object::Collide(OBJID objid)
{
	if (dwTime + 3000 < GetTickCount()) {
		isDead = true;
	}
}
void Object::Collide2()
{

}
	//isCollision = true;

