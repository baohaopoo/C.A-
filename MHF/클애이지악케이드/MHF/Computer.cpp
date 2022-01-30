#include "stdafx.h"
#include "Computer.h"
#include "Define.h"
#include "BmpMgr.h"
#include "ObjMgr.h"
#include "Factory.h"
#include "KeyMgr.h"
#include "downBullet.h"
#include "SoundMgr.h"
#include "resUI.h"

Computer::Computer()
{
	
}


Computer::~Computer()
{
	Release();
}

void Computer::Initialize()
{
	id = COMPUTER;
	info.fSpeed = 1.f;

	//그림자랑 머리위의 화살표
	BmpMgr::getInstance()->InsertBmp(L"PlayerArrow", L"../Image/playerArrow.bmp");
	BmpMgr::getInstance()->InsertBmp(L"Shadow", L"../Image/shadow.bmp");


	BmpMgr::getInstance()->InsertBmp(L"IDLE", L"../Image/ddd.bmp"); //64x74
	BmpMgr::getInstance()->InsertBmp(L"IDLE2", L"../Image/bazzi2.bmp"); //64x74


	BmpMgr::getInstance()->InsertBmp(L"WALKDOWN", L"../Image/WalkDown/wu2.bmp");
	BmpMgr::getInstance()->InsertBmp(L"WALKUP", L"../Image/WalkUp/wu.bmp");
	BmpMgr::getInstance()->InsertBmp(L"WALKRIGHT", L"../Image/WalkRight/wr.bmp");
	BmpMgr::getInstance()->InsertBmp(L"WALKLEFT", L"../Image/WalkLeft/wl.bmp");

	BmpMgr::getInstance()->InsertBmp(L"control", L"../Image/saveda.bmp");
	BmpMgr::getInstance()->InsertBmp(L"bubble1", L"../Image/bubblezzi1.bmp");
	BmpMgr::getInstance()->InsertBmp(L"bubble", L"../Image/bubblezzi.bmp");
	BmpMgr::getInstance()->InsertBmp(L"dead", L"../Image/deadd.bmp");
	BmpMgr::getInstance()->InsertBmp(L"HELPME", L"../Image/help.bmp");
	frameKey = L"IDLE";
	curstance = IDLE;
	prestance = curstance;

	frame.startX = 0;
	frame.EndX = 1;
	frame.startY = 0;
	frame.OldTime = GetTickCount();
	frame.Speed = 1000;
}

int Computer::Update()
{
	if (true == isDead) {
		//win,lose,

		if (id == PLAYER) {
			Object *resui;
			resui = Factory<resUI>::CreateObj(340, 120, 330, 80);
			resui->setImage(L"res");
			ObjMgr::Get_Instance()->Add_Object(UI, resui);

			//결과창.
			resui = Factory<resUI>::CreateObj(320, 330, 500, 350);
			resui->setImage(L"reszzi");
			ObjMgr::Get_Instance()->Add_Object(UI, resui);
		}

		if (id == COMPUTER) {
			Object *resui;
			resui = Factory<resUI>::CreateObj(340, 120, 330, 80); //win
			resui->setImage(L"win");
			ObjMgr::Get_Instance()->Add_Object(UI, resui);

			//결과창.
			resui = Factory<resUI>::CreateObj(320, 330, 500, 350);
			resui->setImage(L"winzzi");
			ObjMgr::Get_Instance()->Add_Object(UI, resui);


		}

		//음악
		SoundMgr::Get_Instance()->StopSound(SoundMgr::BGM);
		SoundMgr::Get_Instance()->PlaySoundW(L"resbefore.wav", SoundMgr::UI, 8);
		return DEAD;
	}
	KeyInput();

	//충돌시
	if (ispang)
	{

		frameKey = L"bubble";
		curstance = BOMB;

		if (wait2 > 6) {
			frameKey = L"dead";
			curstance = PANG;
			isDead = true;
		}
		if (dwTime + 4000 < GetTickCount()) {
			wait2++;
		}


	}


	frameChange();
	if (curstance == SAVE) {
		MoveFrame(1);
	}
	if (curstance == BOMB) {
		MoveFrame(2);
	}
	if (curstance == BOMB1) {
		MoveFrame(3);
	}
	if (curstance == PANG) {
		MoveFrame(4);
	}
	UpdateRect();

	return LIVE;
}

void Computer::LateUpdate()
{
	if (ismon) {

		//물풍선이랑 부딫혔을때
		frameKey = L"bubble";
		curstance = BOMB;
		frame.startX = 0;
		frame.EndX = 3;
		frame.Speed = 800;


		if (dwTime + 2900 < GetTickCount()); {
			wait++;
		}
		if (wait > 20) {
			frame.startX++;
			wait = 0;
		}

		if (frame.startX > 3) {
			frame.startX = 3;
		}

	}

	if (dwTime + 5000 < GetTickCount())
		ismon = false;
}

void Computer::Render(HDC hdc)
{
	HDC memDC = BmpMgr::getInstance()->FindImage(frameKey);
	if (nullptr == memDC)return;
	HDC memDC2 = BmpMgr::getInstance()->FindImage(L"PlayerArrow");
	if (nullptr == memDC2)return;
	HDC memDC3 = BmpMgr::getInstance()->FindImage(L"Shadow");
	if (nullptr == memDC3)return;
	GdiTransparentBlt(hdc, rect.left - 3, rect.top - 10, 45, 35, memDC3, 0, 0, 48, 34, RGB(255, 201, 14));

	HDC helpDC = BmpMgr::getInstance()->FindImage(L"HELPME");
	if (nullptr == helpDC) return;

	//충돌박스 
	//Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);


	{
		if (curstance == BOMB) {

			//플레이어 머리 위에 있는 화살표
			GdiTransparentBlt(hdc, rect.left - 2, rect.top - 75, 30, 30, memDC2, 0, 0, 49, 61, RGB(255, 201, 14));

			//헬프 표시
			GdiTransparentBlt(hdc, rect.left - 30, rect.top - 90, 106, 56, helpDC, 0, 0, 123, 63, RGB(255, 201, 14));

			//물방울에 갇힘
			GdiTransparentBlt(hdc, rect.left - 14, rect.top - 50, 70, 70, memDC, frame.startX * 71, frame.startY * 66, 71, 66, RGB(255, 201, 14));
		}

		if (frameKey == L"bazzi") {
			//플레이어 머리 위에 있는 화살표
			GdiTransparentBlt(hdc, rect.left - 2, rect.top - 75, 30, 30, memDC2, 0, 0, 49, 61, RGB(255, 201, 14));
			GdiTransparentBlt(hdc, rect.left, rect.top - 50, 60, 70, memDC, frame.startX * 70, frame.startY * 70, 69, 69, RGB(255, 201, 14));
		}
		else if (frameKey == L"control")
		{
			//플레이어 머리 위에 있는 화살표
			GdiTransparentBlt(hdc, rect.left - 2, rect.top - 75, 30, 30, memDC2, 0, 0, 49, 61, RGB(255, 201, 14));
			GdiTransparentBlt(hdc, rect.left - 24, rect.top - 50, 70, 70, memDC, frame.startX * 70, frame.startY * 71, 70, 71, RGB(255, 201, 14));
			//GdiTransparentBlt(hdc, rect.left-14, rect.top-50, 60, 70, memDC, frame.startX * 70, frame.startY * 72, 70, 72, RGB(255, 201, 14));
		}
		else if (frameKey == L"dead") {
			GdiTransparentBlt(hdc, rect.left - 16, rect.top - 50, 70, 70, memDC, frame.startX * 69, frame.startY * 70, 69, 72, RGB(255, 201, 14));
		}
		else {
			//플레이어 머리 위에 있는 화살표
			GdiTransparentBlt(hdc, rect.left - 2, rect.top - 75, 30, 30, memDC2, 0, 0, 49, 61, RGB(255, 201, 14));
			GdiTransparentBlt(hdc, rect.left - 14, rect.top - 50, 60, 70, memDC, frame.startX * 60, frame.startY * 70, 60, 69, RGB(255, 201, 14));
		}
	}




	if (ismon) {
		HDC memDC6 = BmpMgr::getInstance()->FindImage(L"sad");
		if (nullptr == memDC6)return;
		GdiTransparentBlt(hdc, rect.left + 3, rect.top - 95, 30, 30, memDC6, 0, 0, 49, 48, RGB(255, 201, 14));
	}


}

void Computer::Release()
{
}

void Computer::SetBulletList(list<Object*>* bulletLst)
{
	bulletBucket = bulletLst;
}

void Computer::frameChange()
{
	if (prestance != curstance)
	{
		switch (curstance)
		{
		case IDLE: //down, 기본, 왼쪽, 오른쪽
			frame.startX = 0;
			frame.EndX = 2;
			frame.startY = 0;
			break;

		case IDLE2: //up용 
			frame.startX = 0;
			frame.EndX = 3;
			frame.startY = 0;
			break;

		case WALK:

			frame.startY = 0;
			frame.EndY = 3;
			frame.OldTime = GetTickCount();
			frame.Speed = 5000;

		case SAVE:


			frame.startX = 0;
			frame.EndX = 3;
			frame.startY = 0;
			frame.OldTime = GetTickCount();
			frame.Speed = 50;
			break;

		case BOMB1:
			frame.startX = 0;
			frame.EndX = 1;
			frame.startY = 0;
			frame.OldTime = GetTickCount();
			frame.Speed = 500;
			break;

		case BOMB:
			frame.startX = 0;
			frame.EndX = 3;
			frame.startY = 0;
			frame.OldTime = GetTickCount();
			frame.Speed = 500;
			break;

		case PANG:
			frame.startX = 0;
			frame.EndX = 4;
			frame.startY = 0;
			frame.OldTime = GetTickCount();
			frame.Speed = 50;
			break;


		default:
			break;
		}
		prestance = curstance;
	}
}

void Computer::Collide(OBJID objid)
{
	if (id == COMPUTER) {

		if (BULLET == objid)
			ispang = true;

		if (UPBULLET == objid)
			ispang = true;

		if (DOWNBULLET == objid)
			ispang = true;

		if (LEFTBULLET == objid)
			ispang = true;

		if (RIGHTBULLET == objid)
			ispang = true;

		if (ITEM == objid) {
			SoundMgr::Get_Instance()->PlaySoundW(L"itemEat.wav", SoundMgr::ITEM, 7);
			eatSkate();
		}
		if (MONSTER == objid) {
			ismon = true;
		}
	}
}

void Computer::KeyInput()
{
	if (id == COMPUTER) {


		if (KeyMgr::Get_Instance()->Key_Up('U')) {
			ispang = false;
			frameKey = L"control";
			curstance = SAVE;

			if (dwTime + 500 < GetTickCount()); {
				wait++;
			}
			if (wait > 20) {
				frame.startX++;
				wait = 0;
			}

			if (frame.startX > 2) {
				frame.startX = 2;
			}

		}


		if (KeyMgr::Get_Instance()->Key_Up('S')) {
			frameKey = L"IDLE";
			curstance = IDLE;
			frame.startX = 0;

		}
		if (KeyMgr::Get_Instance()->Key_Up('A')) {
			frameKey = L"WALKLEFT";
			curstance = IDLE;
			frame.startX = 0;
		}

		if (KeyMgr::Get_Instance()->Key_Up('D')) {
			frameKey = L"WALKRIGHT";
			curstance = IDLE;
			frame.startX = 0;
		}
		if (KeyMgr::Get_Instance()->Key_Up('W')) {
			frameKey = L"IDLE2"; //뒤돌아보고 있는 그림상태.
			curstance = IDLE2;
			frame.startX = 0;
		}


		//////////////////////////////////////////////////////////////////////////////////여기서부터 움직임.

		if (GetAsyncKeyState('A') & 0x8000) {
			//속도
			if (!(40 >= info.fX))
				info.fX -= info.fSpeed;
			else
				info.fX = 40;

			frameKey = L"WALKLEFT";
			curstance = WALK;

			if (dwTime + 500 < GetTickCount()); {
				wait++;
			}
			if (wait > 10) {
				frame.startY++;
				wait = 0;
			}

			if (frame.startY > 2) {
				frame.startY = 0;
			}
		}

		if (GetAsyncKeyState('D') & 0x8000) {

			if (!(WINCX - 200 <= info.fX))
				info.fX += info.fSpeed;
			else
				info.fX = WINCX - 200;

			frameKey = L"WALKRIGHT";
			curstance = WALK;

			if (dwTime + 500 < GetTickCount()); {
				wait++;
			}
			if (wait > 10) {
				frame.startY++;
				wait = 0;
			}

			if (frame.startY > 2) {
				frame.startY = 0;
			}

		}

		if (GetAsyncKeyState('W') & 0x8000) {

			if (!(70 >= info.fY))
				info.fY -= info.fSpeed;
			else
				info.fY = 70;

			frameKey = L"WALKUP";
			curstance = WALK;

			if (dwTime + 500 < GetTickCount()); {
				wait++;
			}
			if (wait > 20) {
				frame.startY++;
				wait = 0;
			}

			if (frame.startY > 2) {
				frame.startY = 0;
			}
		}




		if (GetAsyncKeyState('S') & 0x8000) {
			if (!(WINCY - 70 <= info.fY))
				info.fY += info.fSpeed;
			else
				info.fY = WINCY - 70;

			frameKey = L"WALKDOWN";
			curstance = WALK;

			if (dwTime + 500 < GetTickCount()); {
				wait++;
			}
			if (wait > 20) {
				frame.startY++;
				wait = 0;
			}

			if (frame.startY > 2) {
				frame.startY = 0;
			}
		}



		if (GetAsyncKeyState(VK_SHIFT)) {
			SoundMgr::Get_Instance()->PlaySoundW(L"bombput.wav", SoundMgr::PLAYER, 7);
			CreateBullet();
		}
	}
}

void Computer::CreateBullet()
{
	if (dwTime + 260<GetTickCount())
	{
		bullet = new Bullet();
		if (issoda) {
			//bullet->CreateBullet()
		}

		bullet->setPos(info.fX, info.fY);
		bullet->Initialize();
		bulletBucket->push_back(bullet);
		dwTime = GetTickCount();
	}
}

void Computer::eatSkate()
{
	info.fSpeed = 2.f;	//기존스피드 15
}

void Computer::bombpang()
{
	frameKey = L"bubble";
	curstance = BOMB;

	if (wait2 > 6) {
		frameKey = L"dead";
		curstance = PANG;
	}
	if (dwTime + 4000 < GetTickCount()) {
		wait2++;
	}
}
