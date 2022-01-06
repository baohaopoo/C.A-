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
	info.fCX = 53.f; //down용49
	info.fCY = 70.f;

	//info.fCX = 65.f;	//right 용
	//info.fCY = 72.f;

	info.fSpeed = 15.f;  
	BmpMgr::getInstance()->InsertBmp(L"IDLE", L"../Image/ddd.bmp");
	BmpMgr::getInstance()->InsertBmp(L"WALKDOWN", L"../Image/WalkDown/WalkDown.bmp");
	BmpMgr::getInstance()->InsertBmp(L"WALKUP", L"../Image/WalkUp/wu.bmp");
	BmpMgr::getInstance()->InsertBmp(L"WALKRIGHT", L"../Image/WalkRight/wr.bmp");
	BmpMgr::getInstance()->InsertBmp(L"WALKLEFT", L"../Image/WalkLeft/wl.bmp");
	BmpMgr::getInstance()->InsertBmp(L"BOMB", L"../Image/dead.bmp");

	//IDLE 키보드 떼는 순간 .
	//frameKey = L"WALKDOWN";

	frameKey = L"IDLE";
	curstance = IDLE;
	prestance = curstance; 

	frame.OldTime = GetTickCount();
	frame.Speed = 200;

	//frame.startX = 0;
	//frame.EndX = 3;
	//frame.startY = 0;


}

  
int Player::Update()
{
	if (true == isDead) {


		return DEAD;
	}


	KeyInput();

	UpdateRect();
	ColliderUpdateRect();


	return LIVE;

}

void Player::LateUpdate()
{
	//barrel.x = info.fX + 50 * cosf(angle*(PI / 180));
	//barrel.y = info.fY - 50 * sinf(angle*(PI / 180));

	//MoveFrame();
	//if (down < 3) {
	//	frame.startX++;

	//}
	//else if (down > 3) down = 0;
	frameChange();


	//충돌시
	if (isCollision)
	{
		////약간 딜레이 되는 척..
		//if (dwTime + 2300 < GetTickCount()) {
		//	frameKey = L"BOMB";
		//	curstance = BOMB;
		//}



	}
}

void Player::Render(HDC hdc)
{
	HDC memDC = BmpMgr::getInstance()->FindImage(frameKey);
	if (nullptr == memDC)return;


	//GdiTransparentBlt(hdc, rect.left, rect.top, info.fCX, info.fCY, memDC,0, 0, info.fCX, info.fCY, RGB(255, 201, 14));
	GdiTransparentBlt(hdc, rect.left, rect.top, info.fCX, info.fCY, memDC, frame.startX * (int)info.fCX,
		frame.startY * (int)info.fCY, info.fCX, info.fCY, RGB(255, 201, 14));

	//충돌박스 
	//Rectangle(hdc, colliderBox.left, colliderBox.top, colliderBox.right, colliderBox.bottom);


}

void Player::Release()
{
}



void Player::KeyInput()
{

	
	if (GetAsyncKeyState(VK_LEFT)&0x8000) {
		frameKey = L"WALKLEFT";

		frame.startY++;
		if (frame.startY > 3)
			frame.startY = 0;

		if (!(50 >= info.fX))
			info.fX -= info.fSpeed;
		else
			info.fX = 50;
	}

	if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
		frameKey = L"WALKRIGHT";

		frame.startY++;
		if (frame.startY > 3)
			frame.startY = 0;

		if (!(WINCX - 200 <= info.fX))
			info.fX += info.fSpeed;
		else
			info.fX = WINCX - 200;
	}

	if (GetAsyncKeyState(VK_UP) & 0x8000) {
		frameKey = L"WALKUP";

		frame.startY++;
		if (frame.startY > 3)
			frame.startY = 0;

		if (!(70 >= info.fY))
			info.fY -= info.fSpeed;
		else
			info.fY = 70;
	}

	if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
		frameKey = L"WALKDOWN";
		
		frame.startY++;
		if (frame.startY > 3)
			frame.startY = 0;

		if (!(WINCY - 70 <= info.fY))
			info.fY += info.fSpeed;
		else
			info.fY = WINCY - 70;
	}




	//if (!(GetAsyncKeyState(VK_UP) & 0x8000))
	//	frameKey = L"IDLE";

	//if (!(GetAsyncKeyState(VK_DOWN) & 0x8000))
	//	frameKey = L"IDLE";

	//if (!(GetAsyncKeyState(VK_DOWN) & 0x8000))
	//	frameKey = L"IDLE";


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

void Player::eatSkate()
{
	if (dwTime + 300 < GetTickCount()) {
		info.fSpeed =20.f;	//기존스피드 15
	}

}



void Player::SetBulletList(list<Object*>* bulletLst)
{
	bulletBucket = bulletLst;
}

void Player::frameChange()
{
	if (prestance != curstance)
	{
		switch (curstance)
		{
		//case IDLE:
		//	frame.startX = 0;
		//	frame.EndX = 3;
		//	frame.startY = 0;
		//	break;

		case BOMB:
			frame.startX = 0;
			frame.EndX = 3;
			frame.startY = 0;
			frame.OldTime = GetTickCount();
			frame.Speed = 10;
			break;

		default:
			break;
		}
		prestance = curstance;
	}
}

void Player::Collide()
{
	eatSkate();
}

