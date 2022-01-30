#include "stdafx.h"
#include "PickMonster.h"
#include "BmpMgr.h"
#include "SoundMgr.h"

PickMonster::PickMonster()
{
}


PickMonster::~PickMonster()
{
	Release();
}

void PickMonster::Initialize()
{


	info.fCX = 20.f;
	info.fCY = 20.f;




	BmpMgr::getInstance()->InsertBmp(L"PL", L"../Image/Monster/lv2right.bmp"); //73 x 116
	BmpMgr::getInstance()->InsertBmp(L"PR", L"../Image/Monster/lv2left.bmp"); //73 x 116

	BmpMgr::getInstance()->InsertBmp(L"DUMP", L"../Image/Monster/pinkb.bmp"); //73 x 116

	BmpMgr::getInstance()->InsertBmp(L"RUN", L"../Image/Monster/run.bmp");
	BmpMgr::getInstance()->InsertBmp(L"Rundie", L"../Image/Monster/rundie.bmp");
	BmpMgr::getInstance()->InsertBmp(L"effect", L"../Image/Monster/effectda.bmp");

	curstance = IDLE;
	prestance = curstance;

	info.fSpeed = 0.7f;


	frame.startX = 0;
	frame.EndX = 1;
	frame.startY = 0;
	frame.Speed = 500;
	frame.OldTime = GetTickCount();
}

int PickMonster::Update()
{
	if (true == isDead) {
	
		
		return DEAD;
	}
	if (frameKey == L"Rundie")
		curstance = PANG;


	info.fX += info.fSpeed;
	if (info.fX >= 600) {
		frameKey = L"Rundie";

		info.fX = 600;
		isDead = true;
	}


	
	if (info.fX < 180) {
	
		frameKey = L"PR";
		info.fSpeed *= -1;
	}

	if (info.fX > 300) {
		
		frameKey = L"PL";
		info.fSpeed *= -1;
	}


	if (isCollision) {



		frameKey = L"DUMP";
		curstance = DAMAGE;
		info.fSpeed = 0;

	/*	if (dwTime + 10000 < GetTickCount())
		{
			frameKey = L"PR";
			curstance = IDLE;
			info.fSpeed = -1;
		}*/



	}

	if (gorun) {
		frameKey = L"RUN";
		curstance = RUN;
		info.fX += 7;

	}

	if (gopang) {
		

		
			frameKey = L"Rundie";
			curstance = PANG;


			if (delay > 10) {
				setDead();
			}
			if (dwTime + 50 < GetTickCount()) {
				delay++;
			}

		
		
		
	}

	frameChange();
	Object::MoveFrame();
	UpdateRect();

}

void PickMonster::LateUpdate()
{
}

void PickMonster::Render(HDC hdc)
{
	HDC memDC = BmpMgr::getInstance()->FindImage(frameKey);
	HDC effDC = BmpMgr::getInstance()->FindImage(frameKey);

	if (nullptr == effDC) return;
	if (nullptr == memDC)return;

	if (frameKey == L"lv1")
	{
		curstance = BIRTH;
		GdiTransparentBlt(hdc, rect.left, rect.top + 20, 52, 45, memDC, frame.startX * 52, frame.startY * 45, 52, 45, RGB(255, 201, 14));
	}

	if (curstance == DAMAGE) {
		GdiTransparentBlt(hdc, rect.left, rect.top, info.fCX, info.fCY, memDC, frame.startX * info.fCX, frame.startY * info.fCY, 100, 44, RGB(255, 201, 14));
		//GdiTransparentBlt(hdc, rect.left, rect.top, 0, 0, memDC, frame.startX * 54, frame.startY * 55, 99, 44, RGB(255, 201, 14));
	}
	if (curstance == RUN) {
		GdiTransparentBlt(hdc, rect.left, rect.top, info.fCX, info.fCY, memDC, frame.startX * info.fCX, frame.startY * info.fCY, 111, 53, RGB(255, 201, 14));
	}
	if (frameKey == L"Rundie") {

		GdiTransparentBlt(hdc, rect.left, rect.top, 101, 89, effDC, 0, 0, 101, 89, RGB(255, 201, 14));
		GdiTransparentBlt(hdc, rect.left, rect.top, 100, 100, memDC, frame.startX * 84, frame.startY * 79, 83, 79, RGB(255, 201, 14));
	}
	
	
	GdiTransparentBlt(hdc, rect.left, rect.top, 55, 44, memDC, frame.startX * 55, frame.startY * 44, 55, 44, RGB(255, 201, 14));

	//Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
}

void PickMonster::Release()
{
}

void PickMonster::frameChange()
{
	if (prestance != curstance)
	{
		switch (curstance)
		{
		case BIRTH:
			frame.startX = 0;
			frame.EndX = 4;
			frame.startY = 0;
			frame.Speed = 200;
			frame.OldTime = GetTickCount();
			break;

		case IDLE:
			frame.startX = 0;
			frame.EndX = 1;
			frame.startY = 0;
			frame.Speed = 200;
			frame.OldTime = GetTickCount();
			break;

		case DAMAGE:
			frame.startX = 0;
			frame.EndX = 0;
			frame.startY = 0;
			frame.Speed = 200;
			frame.OldTime = GetTickCount();
			break;

		case RUN:
			frame.startX = 0;
			frame.EndX = 1;
			frame.startY = 0;
			frame.Speed = 5500;
			frame.OldTime = GetTickCount();
			break;

		case PANG:
			frame.startX = 0;
			frame.EndX = 2;
			frame.startY = 0;
			frame.Speed = 20;
			frame.OldTime = GetTickCount();
			break;


		}
		prestance = curstance;

	}
}

void PickMonster::Collide(OBJID objid)
{
	if (objid == PLAYER) {
		if (curstance == DAMAGE) {

			info.fX += 50;
			gorun = true;
		}
	}

	if (objid == MONSTER) {
		SoundMgr::Get_Instance()->PlaySoundW(L"bombMove.wav", SoundMgr::EFFECT, 8);
		gopang = true;
	}
}

void PickMonster::Collide2()
{
	isCollision = true;
}
