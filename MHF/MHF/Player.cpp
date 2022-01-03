#include "stdafx.h"
#include "Player.h"
#include "Define.h"
#include "BmpMgr.h"
Player::Player()
{
}


Player::~Player()

{
}

void Player::Initialize()
{

	
	info.fX = 300.f;
	info.fY = 400.f;
	info.fCX = 49.f;
	info.fCY = 70.f;

	info.fSpeed = 15.f;
	BmpMgr::getInstance()->InsertBmp(L"WALKDOWN", L"../Image/WalkDown/WalkDown.bmp");
	BmpMgr::getInstance()->InsertBmp(L"WALKUP", L"../Image/WalkUp/WalkUp.bmp");
	BmpMgr::getInstance()->InsertBmp(L"WALKRIGHT", L"../Image/WalkRight/WalkRight.bmp");
	BmpMgr::getInstance()->InsertBmp(L"WALKLEFT", L"../Image/WalkLeft/WalkLeft.bmp");

	frameKey = L"WALKUP";

	//curstance = IDLE;
	//prestance = curstance;

	//frame.startX = 0;
	//frame.EndX = 56;
	//frame.

}

  
int Player::Update()
{
	if (true == isDead)
		return DEAD;

	KeyInput();
	UpdateRect();

	return LIVE;

}

void Player::LateUpdate()
{
	//barrel.x = info.fX + 50 * cosf(angle*(PI / 180));
	//barrel.y = info.fY - 50 * sinf(angle*(PI / 180));
}

void Player::Render(HDC hdc)
{
	HDC memDC = BmpMgr::getInstance()->FindImage(frameKey);
	if (nullptr == memDC)return;


	GdiTransparentBlt(hdc, rect.left, rect.top, info.fCX, info.fCY, memDC,0, 0, info.fCX, info.fCY, RGB(255, 201, 14));
	



}

void Player::Release()
{
}

void Player::KeyInput()
{
	if (GetAsyncKeyState(VK_LEFT)) {
		frameKey = L"WALKLEFT";

		if (!(50 >= info.fX))
			info.fX -= info.fSpeed;
		else
			info.fX = 50;
	}

	if (GetAsyncKeyState(VK_RIGHT)) {
		frameKey = L"WALKRIGHT";
		if (!(WINCX - 200 <= info.fX))
			info.fX += info.fSpeed;
		else
			info.fX = WINCX - 200;
	}

	if (GetAsyncKeyState(VK_UP)) {
		frameKey = L"WALKUP";
		if (!(70 >= info.fY))
			info.fY -= info.fSpeed;
		else
			info.fY = 70;
	}

	if (GetAsyncKeyState(VK_DOWN)) {
		frameKey = L"WALKDOWN";
		if (!(WINCY - 70 <= info.fY))
			info.fY += info.fSpeed;
		else
			info.fY = WINCY - 70;
	}

	//기존 총알 쏘는 키
	//if (GetAsyncKeyState('W'))
	//	CreateBullet(1);

	//if (GetAsyncKeyState('S')) 
	//	CreateBullet(2);

	//if (GetAsyncKeyState('D'))	
	//	CreateBullet(3);

	//if (GetAsyncKeyState('A')) 
	//	CreateBullet(4);


	/*if (GetAsyncKeyState('W'))
		CreateBullet(1);

	if (GetAsyncKeyState('S'))
		CreateBullet(2);

	if (GetAsyncKeyState('D'))
		angle += 5;

	if (GetAsyncKeyState('A'))
		angle -= 5;*/

	if (GetAsyncKeyState(VK_SPACE)){
		CreateBullet();
	}
}


void Player::CreateBullet()
{
	if (dwTime + 260<GetTickCount())
	{
		bullet = new Bullet();
		bullet->setPos(info.fX, info.fY);

	//dynamic_cast<Bullet*>(bullet)->setPos(info.fX, info.fY);
	//dynamic_cast<Bullet*>(bullet)->Initialize();	//이거 한줄..때문에 애 먹었다.
	//dynamic_cast<Bullet*>(bullet)->setDir(dir);

		bullet->Initialize();

		//bullet->setDir(dir);
		bulletBucket->push_back(bullet);

		dwTime = GetTickCount();
	}
}

void Player::SetBulletList(list<Object*>* bulletLst)
{
	bulletBucket = bulletLst;
}

