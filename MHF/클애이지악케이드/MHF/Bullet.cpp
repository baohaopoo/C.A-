#include "stdafx.h"
#include "Bullet.h"
#include "BmpMgr.h"
#include "Factory.h"
#include "ObjMgr.h"
#include "downBullet.h"
#include "SoundMgr.h"
Bullet::Bullet()
	:direction(0)
{

}


Bullet::~Bullet()
{
	Release();
}

void Bullet::Initialize()
{

	id = BULLET;

	BmpMgr::getInstance()->InsertBmp(L"IDLEBOMB", L"../Image/ab.bmp"); //두둥실

	framekey = L"IDLEBOMB";
	curstance = IDLEBOMB;
	prestance = curstance;


	frame.startX = 0;
	frame.EndX = 2;
	frame.startY = 0;
	frame.OldTime = GetTickCount();
	frame.Speed = 2000;

	info.fCX = 30.f; //53
	info.fCY = 30.f; //55
	isDead = false;
	info.fSpeed = 10.f;

}



int Bullet::Update() 
{

	
	if (true == isDead) {
		SoundMgr::Get_Instance()->PlaySoundW(L"bomb.wav", SoundMgr::BOMB, 7);
		return  DEAD;
	}


	if (GetAsyncKeyState('J')) //발로 까기
	{
		SoundMgr::Get_Instance()->PlaySoundW(L"bombMove.wav", SoundMgr::PLAYER, 7);
		info.fX += 20;

	}
	UpdateRect();
	ColliderUpdateRect();

	framekey = L"IDLEBOMB";
	curstance = IDLEBOMB;

	return LIVE;

	
}

void Bullet::LateUpdate()
{

	MoveFrame();
	frameChange();

	
	if (bombTime + 2300 < GetTickCount()) {
		CreateBullet(sodacnt);
		isDead = true;
	}


}


void Bullet::Render(HDC hdc)
{


	HDC memDC = BmpMgr::getInstance()->FindImage(framekey);
	if (nullptr == memDC)return;

	//충돌박스 
	//Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
	if (curstance == IDLEBOMB) {
		GdiTransparentBlt(hdc, rect.left, rect.top - 10, 53, 55, memDC, frame.startX * 53,
			frame.startY * 55, 53, 55, RGB(255, 201, 14));
	}
}

void Bullet::Release()
{

}

void Bullet::Collide(OBJID objid)
{
	
	if (objid == BOX) {

	
	}
}

void Bullet::setDir(int dir)
{
	direction = dir;
}

void Bullet::setPos(float x, float y)
{
	info.fX = x;
	info.fY = y;
}

void Bullet::frameChange()
{
	if (prestance != curstance)
	{
		switch (curstance)
		{
		case IDLEBOMB:
			frame.startX = 0;
			frame.EndX = 2;
			frame.startY = 0;
			frame.OldTime = GetTickCount();
			frame.Speed = 5000;
			break;

		case ALONEBOMB:
		
			frame.startX = 0;
			frame.EndX = 3;
			frame.startY = 0;
			frame.OldTime = GetTickCount();
			frame.Speed = 5000;
			break;

		default:
			break;
		}
		prestance = curstance;
	}
}

void Bullet::sodago(int cnt)
{
	
}


void Bullet::CreateBullet(int cnt)
{

	if (dwTime + 260 < GetTickCount())
	{
		middle = new middleBullet();
		ObjMgr::Get_Instance()->Add_Object(MIDDLEBULLET, middle);
		middle->setPos(info.fX, info.fY);
		middle->Initialize();
		dwTime = GetTickCount();

		for (int i = 1; i <= cnt; ++i) {

			down = new downBullet();
			ObjMgr::Get_Instance()->Add_Object(DOWNBULLET, down);
			down->setPos(info.fX, info.fY + (30*i));
			down->Initialize();
			dwTime = GetTickCount();


			up = new UpBullet();
			ObjMgr::Get_Instance()->Add_Object(UPBULLET, up);
			up->setPos(info.fX, info.fY - (30*i));
			up->Initialize();
			dwTime = GetTickCount();

			right = new RightBullet();
			ObjMgr::Get_Instance()->Add_Object(RIGHTBULLET, right);
			right->setPos(info.fX + (30*i), info.fY);
			right->Initialize();
			dwTime = GetTickCount();

			left = new LeftBullet();
			ObjMgr::Get_Instance()->Add_Object(LEFTBULLET, left);
			left->setPos(info.fX - (30*i), info.fY);
			left->Initialize();
			dwTime = GetTickCount();
		}
	}


}
