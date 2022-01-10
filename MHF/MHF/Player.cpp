#include "stdafx.h"
#include "Player.h"
#include "Define.h"
#include "BmpMgr.h"
#include "UpFlow.h"
#include "ObjMgr.h"
#include "Factory.h"
Player::Player()
{
}


Player::~Player()

{
}

void Player::Initialize()
{

	id = PLAYER;
	info.fX = 300.f;
	info.fY = 400.f;
	info.fCX = 60.f; //down용49  53
	info.fCY = 70.f;

	//info.fCX = 65.f;	//right 용
	//info.fCY = 72.f;
	info.fSpeed = 15.f;


	//ObjMgr::Get_Instance()->Add_Object(PLAYERC,Factory<PlayerCollider>::CreateObj(info.fX, info.fY));

	BmpMgr::getInstance()->InsertBmp(L"IDLE", L"../Image/ddd.bmp"); //64x74
	BmpMgr::getInstance()->InsertBmp(L"WALKDOWN", L"../Image/WalkDown/wu2.bmp");
	BmpMgr::getInstance()->InsertBmp(L"WALKUP", L"../Image/WalkUp/wu.bmp");
	BmpMgr::getInstance()->InsertBmp(L"WALKRIGHT", L"../Image/WalkRight/wr.bmp");
	BmpMgr::getInstance()->InsertBmp(L"WALKLEFT", L"../Image/WalkLeft/wl.bmp");
	BmpMgr::getInstance()->InsertBmp(L"BOMB", L"../Image/dead.bmp");
	BmpMgr::getInstance()->InsertBmp(L"DEAD", L"../Image/pang.bmp");
	BmpMgr::getInstance()->InsertBmp(L"SAVE", L"../Image/happy.bmp");





	BmpMgr::getInstance()->InsertBmp(L"WALKDOWN", L"../Image/WalkDown/wu2.bmp");
	BmpMgr::getInstance()->InsertBmp(L"WALKUP", L"../Image/WalkUp/wu.bmp");
	BmpMgr::getInstance()->InsertBmp(L"WALKRIGHT", L"../Image/WalkRight/wr.bmp");
	BmpMgr::getInstance()->InsertBmp(L"WALKLEFT", L"../Image/WalkLeft/wl.bmp");

	//computer 
	BmpMgr::getInstance()->InsertBmp(L"COMUP", L"../Image/WalkUp/computerwu.bmp");



	//IDLE 키보드 떼는 순간 .
	//frameKey = L"WALKDOWN";

	frameKey = L"WALKDOWN";
	curstance = IDLE;
	prestance = curstance; 

	frame.OldTime = GetTickCount();
	frame.Speed = 2000;

	//frame.startX = 0;
	//frame.EndX = 3;
	//frame.startY = 0;


	//ObjMgr::Get_Instance()->Add_Object(PLAYERC, Factory<PlayerCollider>::CreateObj(info.fX,info.fY));
	playerc = new PlayerCollider();

	playerc->Initialize();
	playerc->setPos(info.fX, info.fY );

}

  
int Player::Update()
{
	

	if (true == isDead) {


		return DEAD;
	}


	KeyInput();


	playerc->setPos(info.fX, info.fY);

	UpdateRect();
	ColliderUpdateRect();


	return LIVE;

}

void Player::LateUpdate()
{
	frameChange();



	if (isEglue) {
	/*	info.fSpeed = 0;
		isEglue = false;*/
	}

	//충돌시
	if (isCollision)
	{
		//약간 딜레이 되는 척..
		if (dwTime + 2300 < GetTickCount()) {
		/*	frameKey = L"BOMB";
			curstance = BOMB;*/
				frame.startY++;
				if (frame.startY > 3) {
		
					frame.startY = 0;
					++pangcnt;
				}
				if (pangcnt > 3) isCollision = false;

				if (frame.startY > 5)
					isCollision = false;

				/*if (frame.startY > 3) {
					frameKey = L"DEAD";
					curstance = PANG;
				}*/

				//frameKey = L"DEAD";
			
		}



	}	
	playerc->LateUpdate();
}

void Player::Render(HDC hdc)
{
	HDC memDC = BmpMgr::getInstance()->FindImage(frameKey);
	if (nullptr == memDC)return;

	
	//충돌박스 
	//Rectangle(hdc, colliderBox.left+10, colliderBox.top+30, colliderBox.right-10, colliderBox.bottom-30);

	//충돌박스 
	//Rectangle(hdc, rect.left , rect.top , rect.right , rect.bottom );



	GdiTransparentBlt(hdc, rect.left, rect.top, info.fCX, info.fCY, memDC,0, 0, info.fCX, info.fCY, RGB(255, 201, 14));
	//GdiTransparentBlt(hdc, rect.left, rect.top, info.fCX, info.fCY, memDC, frame.startX * (int)info.fCX,frame.startY * (int)info.fCY, info.fCX, info.fCY, RGB(255, 201, 14));

		playerc->Render(hdc);



}

void Player::Release()
{
}



void Player::KeyInput()
{
	//계속 누르고 있을때, 
	if (id == PLAYER) {
		if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
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



		if (GetAsyncKeyState(VK_CONTROL)) {
			frameKey = L"SAVE";
			//curstance = PANG;
			frame.startY++;
			if (frame.startY > 1)
				frame.startY = 1;


		}


		if (GetAsyncKeyState(VK_SPACE)) {
			CreateBullet();
		}
	}

	if (id == COMPUTER) {
		if (GetAsyncKeyState('A') & 0x8000) {
			frameKey = L"WALKLEFT";

			frame.startY++;
			if (frame.startY > 3)
				frame.startY = 0;

			if (!(50 >= info.fX))
				info.fX -= info.fSpeed;
			else
				info.fX = 50;
		}

		if (GetAsyncKeyState('D') & 0x8000) {
			frameKey = L"WALKRIGHT";

			frame.startY++;
			if (frame.startY > 3)
				frame.startY = 0;

			if (!(WINCX - 200 <= info.fX))
				info.fX += info.fSpeed;
			else
				info.fX = WINCX - 200;
		}

		if (GetAsyncKeyState('W') & 0x8000) {
			frameKey = L"WALKUP";

			frame.startY++;
			if (frame.startY > 3)
				frame.startY = 0;

			if (!(70 >= info.fY))
				info.fY -= info.fSpeed;
			else
				info.fY = 70;
		}

		if (GetAsyncKeyState('S') & 0x8000) {
			frameKey = L"WALKDOWN";

			frame.startY++;
			if (frame.startY > 3)
				frame.startY = 0;

			if (!(WINCY - 70 <= info.fY))
				info.fY += info.fSpeed;
			else
				info.fY = WINCY - 70;
		}



		if (GetAsyncKeyState(VK_CONTROL)) {
			frameKey = L"SAVE";
			//curstance = PANG;
			frame.startY++;
			if (frame.startY > 1)
				frame.startY = 1;


		}


		if (GetAsyncKeyState(VK_SPACE)) {
			CreateBullet();
		}
	}
}


void Player::CreateBullet()
{
	if (dwTime + 260<GetTickCount())
	{
		bullet = new Bullet();
	//	playerc = new PlayerCollider();

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
		info.fSpeed =30.f;	//기존스피드 15
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
		case IDLE:
			frame.startX = 0;
			frame.EndX = 3;
			frame.startY = 0;
			break;

		case BOMB:
			frame.startX = 0;
			frame.EndX = 3;
			frame.startY = 0;
			frame.OldTime = GetTickCount();
			frame.Speed = 200;
			break;

		case PANG:

			if (dwTime + 220 < GetTickCount()) {
				frame.startX = 0;
				frame.EndX = 0;
				frame.startY = 2;
			}
			break;

		default:
			break;
		}
		prestance = curstance;
	}
}

void Player::Collide(OBJID objid)
{
	//isCollision = true;
	//frameKey = L"BOMB";

	if (BULLET == objid)
	isCollision = true;

	if(SKATE == objid)
	eatSkate();

	if (objid == BOX)
	{
		isEglue = true;
		//info.fY = 285;
	}


}

