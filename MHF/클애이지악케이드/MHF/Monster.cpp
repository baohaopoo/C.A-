#include "stdafx.h"
#include "Monster.h"
#include "BmpMgr.h"
#include "SoundMgr.h"
#include "resUI.h"
#include "ObjMgr.h"
#include "Factory.h"
#include "Item.h"
Monster::Monster()
{
}
Monster::~Monster()
{
	Release();
}

void Monster::Initialize()
{



	info.fCX = 30.f;
	info.fCY = 30.f;



	deadcnt = 0;

	BmpMgr::getInstance()->InsertBmp(L"keymonster", L"../Image/Monster/lv1-up.bmp"); //73 x 116
	BmpMgr::getInstance()->InsertBmp(L"MUP", L"../Image/Monster/lv1-up.bmp"); //73 x 116
	BmpMgr::getInstance()->InsertBmp(L"MDW", L"../Image/Monster/lv1down.bmp"); //73 x 116

	BmpMgr::getInstance()->InsertBmp(L"DUMP", L"../Image/Monster/pinkb.bmp"); //73 x 116

	BmpMgr::getInstance()->InsertBmp(L"RUN", L"../Image/Monster/run.bmp");
	BmpMgr::getInstance()->InsertBmp(L"Rundie", L"../Image/Monster/rundie.bmp");
	BmpMgr::getInstance()->InsertBmp(L"boradie", L"../Image/Monster/boradie.bmp");

	BmpMgr::getInstance()->InsertBmp(L"effect", L"../Image/Moster/effect1.bmp");
	effectKey = L"effect";
	curstance = IDLE;
	prestance = curstance;

	info.fSpeed = 1.f;


	frame.startX = 0;
	frame.EndX = 1;
	frame.startY = 0;
	frame.Speed = 500;
	frame.OldTime = GetTickCount();

	m_fPower = 15.f;
}

int Monster::Update()
{

	//if (isalldie) {
	//
	//		Object *resui;
	//		resui = Factory<resUI>::CreateObj(340, 120, 330, 80); //win
	//		resui->setImage(L"win");
	//		ObjMgr::Get_Instance()->Add_Object(UI, resui);
	//		//°á°úÃ¢.
	//		resui = Factory<resUI>::CreateObj(320, 330, 500, 350);
	//		resui->setImage(L"reszzi");
	//		ObjMgr::Get_Instance()->Add_Object(UI, resui);

	//		//À½¾Ç
	//		SoundMgr::Get_Instance()->StopSound(SoundMgr::BGM);
	//		SoundMgr::Get_Instance()->PlaySoundW(L"resbefore.wav", SoundMgr::UI, 8);

	//	
	//}
	//if (deadcnt >= 2)
	//{
	//	isalldie = true;
	//}
	//

	if (true == isDead) {

		if (dwTime + 5000 < GetTickCount()) {
			itemkey = L"gold3";
			dwTime = GetTickCount();
		}
		if (dwTime + 3000 < GetTickCount()) {
			itemkey = L"gold4";
			dwTime = GetTickCount();
		}
		if (dwTime + 200 < GetTickCount()) {
			itemkey = L"gold5";
			dwTime = GetTickCount();
		}
		
		Object* gold = Factory<Item>::CreateObj(itemkey, info.fX, info.fY, 38, 38);
		ObjMgr::Get_Instance()->Add_Object(ITEM, gold);
		
		
		return DEAD;
	
	}


	info.fY += info.fSpeed*info.dir;

	if (info.fX >= 600) {
		frameKey = L"Rundie";
		info.fX = 600;

	
		isDead = true;
	}


	if (info.fY < 140) {
		frameKey = L"MDW";
		info.fSpeed *= -1;
	}

	if (info.fY > 440) {
		frameKey = L"MDW";

		info.fSpeed *= -1;

	}
	if (gorun) {
		frameKey = L"RUN";
		curstance = RUN;
		info.fX += 3;
	}
	if (gopang) {

	


		/*if (delay > 10) {
			setDead();
		}
		if (dwTime + 50 < GetTickCount()) {
			delay++;
		}*/

	}

	if (isCollision) {



		frameKey = L"DUMP";
		iseffect = true;

		curstance = DAMAGE;
		info.fSpeed = 0;

	}




	frameChange();
	Object::MoveFrame();
	UpdateRect();

	return LIVE;
}

void Monster::LateUpdate()
{

}

void Monster::Render(HDC hdc)
{
	HDC memDC = BmpMgr::getInstance()->FindImage(frameKey);
	if (nullptr == memDC)return;

	HDC memDC2 = BmpMgr::getInstance()->FindImage(L"effect");
	if (nullptr == memDC2)return;


	if ( curstance == DAMAGE) {
		GdiTransparentBlt(hdc, rect.left, rect.top, 55, 44, memDC, frame.startX * info.fCX, frame.startY * info.fCY, 55, 44, RGB(255, 201, 14));
		
	}

	if (curstance == RUN) {
		GdiTransparentBlt(hdc, rect.left, rect.top, 111, 53, memDC, frame.startX * info.fCX, frame.startY * info.fCY, 111, 53, RGB(255, 201, 14));
	}
	if (frameKey == L"Rundie") {
		GdiTransparentBlt(hdc, rect.left - 100, rect.top - 300, 55, 44, memDC2, 0, 0, 101, 89, RGB(255, 201, 14));
		GdiTransparentBlt(hdc, rect.left, rect.top, 84, 79, memDC, frame.startX * 84, frame.startY * 79, 83, 79, RGB(255, 201, 14));
	}

	GdiTransparentBlt(hdc, rect.left, rect.top, 54, 55, memDC, frame.startX * 54, frame.startY * 55, 54, 55, RGB(255, 201, 14));
	
	

	GdiTransparentBlt(hdc, rect.left-100, rect.top-300, 55,44, memDC2, frame.startX * 59, frame.startY * 48, 59, 48, RGB(255, 201, 14));
	//Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);

}

void Monster::Release()
{
}

void Monster::frameChange()
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

		case EFFECT:
			frame.startX = 0;
			frame.EndX = 1;
			frame.startY = 0;
			frame.Speed = 5500;
			frame.OldTime = GetTickCount();
			break;

		}
		prestance = curstance;

	}
}

void Monster::Collide2()
{
	
	
	isCollision = true;

	iseffect = true;
}

void Monster::Collide(OBJID objid)
{
	if (objid == BACKGROUND)
	{
		SoundMgr::Get_Instance()->PlaySoundW(L"bombMove.wav", SoundMgr::EFFECT, 8);
		frameKey = L"Rundie";
		curstance = PANG;



	}
	if (objid == PLAYER) {
		if (curstance == DAMAGE) {
			gorun = true;
		}
	}

	if (objid == MONSTER) {
		if (curstance == DAMAGE) {
			isCollision = true;
		}
		else
			isCollision = false;
	}

	if (objid == MONSTER) {


		gopang = true;
	}

	if (objid == MONSTERU)
	{
		//info.fY -= sinf(0.3* (PI / 180.f));

	}
}
