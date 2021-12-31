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
	info.fCX = 56.f;
	info.fCY = 56.f;

	info.fSpeed = 15.f;

	BmpMgr::getInstance()->InsertBmp(L"WALK_LEFT", L"../Image/WalkLeft/WalkLeft(0).bmp");
	//frameKey = L"WALK_LEFT";
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
	barrel.x = info.fX + 50 * cosf(angle*(PI / 180));
	barrel.y = info.fY - 50 * sinf(angle*(PI / 180));
}

void Player::Render(HDC hdc)
{
	HDC memDC = BmpMgr::getInstance()->FindImage(L"WALK_LEFT");
	//if (nullptr == memDC)return;
	BitBlt(hdc, 0, 0, WINCX, WINCY, memDC, 0, 0, SRCCOPY);
	//BitBlt(hdc, rect.left, rect.top, rect.right, rect.bottom, memDC, 0, 0, SRCCOPY);
	Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
	//GdiTransparentBlt(hdc, rect.left, rect.top, (int)info.fCX, info.fCY,
	//	memDC, m_tFrame.iFrameStart * (int)m_tInfo.fCX, m_tFrame.iScene * (int)m_tInfo.fCY,
	//	info.fCX, info.fCY, RGB(0, 0, 0));
	//
	////포신
	//MoveToEx(hdc, info.fX, info.fY, nullptr);
	//LineTo(hdc, barrel.x, barrel.y);


}

void Player::Release()
{
}

void Player::KeyInput()
{
	if (GetAsyncKeyState(VK_LEFT)) {
		if (!(80 >= info.fX))
			info.fX -= info.fSpeed;
		else
			info.fX = 80;
	}

	if (GetAsyncKeyState(VK_RIGHT)) {
		if (!(WINCX-80 < info.fX))
			info.fX += info.fSpeed;
		else
			info.fX = WINCX - 80;
	}

	if (GetAsyncKeyState(VK_UP)) {
		if (!(80 > info.fY))
			info.fY -= info.fSpeed;
		else
			info.fY = 80;
	}

	if (GetAsyncKeyState(VK_DOWN)) {
		if (!(WINCY-80 < info.fY))
			info.fY += info.fSpeed;
		else
			info.fY = WINCY - 80;
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


	if (GetAsyncKeyState('W'))
		CreateBullet(1);

	if (GetAsyncKeyState('S')) 
		CreateBullet(2);

	if (GetAsyncKeyState('D'))
		angle += 5;

	if (GetAsyncKeyState('A'))
		angle -= 5;
}


void Player::CreateBullet(int dir)
{
	if (dwTime + 260<GetTickCount())
	{
		bullet = new Bullet();
		bullet->setPos(info.fX, info.fY);

	//dynamic_cast<Bullet*>(bullet)->setPos(info.fX, info.fY);
	//dynamic_cast<Bullet*>(bullet)->Initialize();	//이거 한줄..때문에 애 먹었다.
	//dynamic_cast<Bullet*>(bullet)->setDir(dir);

		bullet->Initialize();

		bullet->setDir(dir);
		bulletBucket->push_back(bullet);

		dwTime = GetTickCount();
	}
}

void Player::SetBulletList(list<Object*>* bulletLst)
{
	bulletBucket = bulletLst;
}

