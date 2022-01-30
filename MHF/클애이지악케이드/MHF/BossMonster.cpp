#include "stdafx.h"
#include "BossMonster.h"
#include "ObjMgr.h"
#include "Factory.h"
#include "SceneMgr.h"
#include "Player.h"
#include "Monster.h"
#include "CollisionMgr.h"
#include "SoundMgr.h"
#include "Box.h"
#include "Background.h"
#include "StartUI.h"
#include "hpBar.h"
#include "PickMonster.h"
#include "resUI.h"
#include"Item.h"
BossMonster::BossMonster()
{
}


BossMonster::~BossMonster()
{
	Release();
}

void BossMonster::Initialize()
{
	id = BOSSMON;
	BmpMgr::getInstance()->InsertBmp(L"boss", L"../Image/Monster/bossdown.bmp");
//	BmpMgr::getInstance()->InsertBmp(L"boss", L"../Image/Monster/king.bmp");
	BmpMgr::getInstance()->InsertBmp(L"bossr", L"../Image/Monster/bossright.bmp");
	BmpMgr::getInstance()->InsertBmp(L"bossl", L"../Image/Monster/bossleft.bmp");
	BmpMgr::getInstance()->InsertBmp(L"bossa", L"../Image/Monster/bossang.bmp");
	BmpMgr::getInstance()->InsertBmp(L"bosssh", L"../Image/Monster/bosssh.bmp");

	BmpMgr::getInstance()->InsertBmp(L"die", L"../Image/Monster/dieboss.bmp");
	BmpMgr::getInstance()->InsertBmp(L"dieturtle", L"../Image/deadturtle.bmp");

	Object* pObj;
	pObj = Factory<hpBar>::CreateObj(323,80, 400, 140);
	pObj->setImage(L"hp");
	ObjMgr::Get_Instance()->Add_Object(UI, pObj);

	frameKey = L"boss";
	curstance = IDLE;
	prestance = curstance;
	
	info.fCX = 100;
	info.fCY = 100;


	frame.startX = 0;
	frame.EndX = 1;
	frame.startY = 0;
	frame.Speed = 500;
	frame.OldTime = GetTickCount();
	info.fSpeed = 0.1f;

}

int BossMonster::Update()
{

	//if (isCollision) {
	//
	//	//info.fY = info.fY - 30;
	//	frameKey = L"bosspunch";
	//	curstance = DAMAGE;
	//
	//}
	//

	frameKey = info.name;

	if (true == isDead) {



		Object *resui;
		resui = Factory<resUI>::CreateObj(340, 120, 330, 80); //win
		resui->setImage(L"win");
		ObjMgr::Get_Instance()->Add_Object(UI, resui);
		//°á°úÃ¢.
		resui = Factory<resUI>::CreateObj(320, 330, 500, 350);
		resui->setImage(L"reszzi");
		ObjMgr::Get_Instance()->Add_Object(UI, resui);

		//À½¾Ç
		SoundMgr::Get_Instance()->StopSound(SoundMgr::BGM);
		SoundMgr::Get_Instance()->PlaySoundW(L"resbefore.wav", SoundMgr::UI, 8);
		return DEAD;

	}





	if (info.fY >= 250)
	{
		info.fY = 250;
		info.fX -= info.fSpeed;
		frameKey = L"bossl";
		curstance = LEFT;
	}
	
	 if (info.fX < 240)
	{
		info.fSpeed *= -1;
		frameKey = L"bossr";
		curstance = RIGHT;
	}
	 

	 if (info.fX > 540) {
		 info.fSpeed *= -1;
		 frameKey = L"bossl";
		 curstance = LEFT;
	 }


/////////////////////////////////////////////////////////////////////////////////////////
	//if (frameKey == L"boss" &&  info.fY >= 250) {
	//

	//	info.fY = 250;
	//	frameKey = L"bossl";
	//	curstance = LEFT;
	//	//info.fX -= info.fSpeed;
	//}

	//if (frameKey == L"bossl") {
	//
	//	if (delay >100) {
	//		frameKey = L"bossr";
	//		curstance = RIGHT;
	//		info.fX += info.fSpeed;
	//	}
	//	if (dwTime + 500 < GetTickCount()) {
	//		delay++;
	//	}
	//}

	//if (frameKey == L"bossr") {
	//	frameKey = L"bossr";
	//	curstance = RIGHT;
	//	info.fX += info.fSpeed;
	//}



	//if (info.fX > 540) {
	//	info.fSpeed *= -1;
	//	frameKey = L"bossl";
	//	curstance = LEFT;

	//}
	///////////////////////////////////////////////////////////////
	//if (info.fX < 240)
	//{
	//	info.fSpeed *= -1;
	//	frameKey = L"bossr";
	//	curstance = RIGHT;
	//}
	//if (frameKey == L"bossr") {

	//	if (delay > 1000)
	//	{
	//		frameKey = L"bossl";
	//		curstance = LEFT;
	//		info.fX -= 0.1;
	//	}

	//	if (dwTime + 5000 < GetTickCount()) {
	//		wait2++;
	//	}
	//}



	//if (frameKey == L"bossl" && info.fX < 150) {
	//
	//
	//	frameKey = L"bossr";
	//	curstance = RIGHT;
	//	info.fX += 301;
	//}


	if (GetAsyncKeyState(VK_F9)) {
		SoundMgr::Get_Instance()->PlaySoundW(L"bomb.wav", SoundMgr::PLAYER, 8);
		for (int i = 0; i < 6; ++i) {
			for (int j = 0; j < 6; ++j) {
				Object* pObj = Factory<Item>::CreateObj(L"gold5", 120 + (80 * i), 200 + (40 * j), 38, 38);
				ObjMgr::Get_Instance()->Add_Object(ITEM, pObj);
			}

		}
		Object *resui;
		resui = Factory<resUI>::CreateObj(340, 120, 330, 80); //win
		resui->setImage(L"win");
		ObjMgr::Get_Instance()->Add_Object(UI, resui);
		//°á°úÃ¢.
	

		//À½¾Ç
		SoundMgr::Get_Instance()->StopSound(SoundMgr::BGM);
		SoundMgr::Get_Instance()->PlaySoundW(L"resbefore.wav", SoundMgr::UI, 8);
		return DEAD;
	}
	

	info.fY += 0.1;

	if (hp <= 0){

		frameKey = L"die";
		curstance = PANG;


	}
	if (isCollision) {

		hp -= 0.1;

			
	

		SoundMgr::Get_Instance()->PlaySoundW(L"°ÅºÏ¾ÆÆÄ.wav", SoundMgr::MONSTER, 8);
		if (frameKey != L"bossa") {

			frameKey = L"bossa";
			curstance = ROLL;

			if (dwTime + 2000 < GetTickCount()) { wait++; }

			if (wait > 500) {
				frameKey = L"boss";
				curstance = IDLE;
				isCollision = false;
				
				wait = 0;
			}
		}

		
		
	}
	//if (isDead)
	//{

	//	Object *resui;
	//	resui = Factory<resUI>::CreateObj(340, 120, 330, 80);
	//	resui->setImage(L"win");
	//	ObjMgr::Get_Instance()->Add_Object(UI, resui);

	//	//°á°úÃ¢.
	//	resui = Factory<resUI>::CreateObj(320, 330, 500, 350);
	//	resui->setImage(L"reszzi");
	//	ObjMgr::Get_Instance()->Add_Object(UI, resui);

	//	//À½¾Ç
	//	SoundMgr::Get_Instance()->StopSound(SoundMgr::BGM);
	//	SoundMgr::Get_Instance()->PlaySoundW(L"resbefore.wav", SoundMgr::UI, 8);

	//	return DEAD;
	//}

	//if (dwTime + 500 > GetTickCount()) {
	//	delay++;
	//}
	//if (delay > 10) {

	//	frameKey = L"boss";
	//	curstance = IDLE;
	//}


	//if (info.fX >= 400) {

	//	frameKey = L"bossl";
	//	curstance = LEFT;
	//	frame.startX = 0;

	//	info.fX -= 0.1;
	//}

	//if (info.fY >= 300) {

	//	info.fY = 300;
	//	info.fX += 0.1;
	//	frameKey = L"bossl";
	//	curstance = LEFT;
	//	frame.startX = 0;
	//}



	//frameKey = info.name;
	frameChange();
	MoveFrame();

	UpdateRect();

	return LIVE;
}

void BossMonster::LateUpdate()
{
}

void BossMonster::Render(HDC hdc)
{
	HDC memDC = BmpMgr::getInstance()->FindImage(frameKey);
	if (memDC == nullptr) return;
	
	//±×¸²ÀÚ
	HDC memDC3 = BmpMgr::getInstance()->FindImage(L"bosssh");
	if (nullptr == memDC3)return;
	GdiTransparentBlt(hdc, rect.left-20, rect.top-130, 200, 280, memDC3, 0, 0, 82, 91, RGB(255, 201, 14));


	HDC memDC4 = BmpMgr::getInstance()->FindImage(L"hp");
	if (nullptr == memDC4)return;




	//GdiTransparentBlt(hdc, rect.left - 20, rect.top - 50, 180,30, memDC4, 0, frame.startY *62, 493,62 , RGB(255, 201, 14));

	//if (frameKey = L"bosspunch")
	//{
	//	GdiTransparentBlt(hdc, rect.left, rect.top, 121, 110, memDC, 0, 0 ,121, 110, RGB(255, 201, 14));
	//}
	////if (frameKey == L"boss") {
	////	Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
	////	GdiTransparentBlt(hdc, rect.left , rect.top , 100, 100, memDC, frame.startX * 93, frame.startY * 92, 93, 92, RGB(255, 201, 14));
	////}
	// if (frameKey == L"bossr") {
	//	Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
	//	GdiTransparentBlt(hdc, rect.left - 70, rect.top - 40, 230, 200, memDC, frame.startX * 143, frame.startY * 81, 143, 81, RGB(255, 201, 14));
	//} 
	// if (/*frameKey == L"bossl"*/curstance == LEFT) {
	//	 Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
	//	// GdiTransparentBlt(hdc, rect.left, rect.top, 143, 81, memDC, frame.startX * 143, frame.startY * 81, 143, 81, RGB(255, 201, 14));
	// }
	// if (frameKey == L"bossdie") {

	//	 GdiTransparentBlt(hdc, rect.left, rect.top , 73, 84, memDC, frame.startX * 73, frame.startY * 84, 73, 84, RGB(255, 201, 14));
	//	 Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
	// }
	// if (curstance == ROLL) {
	//	 GdiTransparentBlt(hdc, rect.left, rect.top, 230, 200, memDC, frame.startX * 105, frame.startY * 110, 105, 110, RGB(255, 201, 14));
	//	 Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
	// }

	if (frameKey == L"dieturtle") {
		GdiTransparentBlt(hdc, rect.left, rect.top, 95, 200, memDC, frame.startX * 95, frame.startY * 110, 94, 110, RGB(255, 201, 14));
	}

	if (frameKey == L"die") {
		GdiTransparentBlt(hdc, rect.left-70, rect.top-40, 300, 300, memDC, frame.startX * 73, frame.startY * 84, 73, 84, RGB(255, 201, 14));
	}
	if (frameKey == L"bossl") {
		GdiTransparentBlt(hdc, rect.left - 50, rect.top - 40, 200, 160, memDC, frame.startX * 143, frame.startY * 81, 143, 81, RGB(255, 201, 14));
		//Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
	}
	if (frameKey == L"bossr") {
		GdiTransparentBlt(hdc, rect.left - 70, rect.top - 40, 200, 160, memDC, frame.startX * 143, frame.startY * 81, 143, 81, RGB(255, 201, 14));
		//Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
	}
	if (frameKey == L"bossa") {
		GdiTransparentBlt(hdc, rect.left, rect.top, 230, 200, memDC, frame.startX * 105, frame.startY * 110, 105, 110, RGB(255, 201, 14));
		//Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
	}


	else
	{
		//Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
		GdiTransparentBlt(hdc, rect.left, rect.top, 150, 150, memDC, frame.startX * 93, frame.startY * 92, 93, 92, RGB(255, 201, 14));
	}
	// Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
	 //GdiTransparentBlt(hdc, rect.left, rect.top, 150, 150, memDC, frame.startX * 200, frame.startY * 112, 128, 112, RGB(255, 201, 14));

}

void BossMonster::Release()
{
	

	
}

void BossMonster::frameChange()
{

	if (prestance != curstance)
	{
		switch (curstance)
		{
		case IDLE: //down
			frame.startX = 0;
			frame.EndX = 1;
			frame.startY = 0;
		
			frame.Speed = 500;
			frame.OldTime = GetTickCount();
			break;
		
		case RIGHT:
			frame.startX = 0;
			frame.EndX =1 ;
			frame.startY = 0;
			frame.OldTime = GetTickCount();
			frame.Speed = 500;

		case LEFT:
			frame.startX = 0;
			frame.EndX = 1;
			frame.startY = 0;
			frame.OldTime = GetTickCount();
			frame.Speed = 500;
			break;

		case DAMAGE:
			frame.startX = 0;
			frame.EndX = 0;
			frame.startY = 0;
	
			break;
		case ROLL:
			frame.startX = 0;
			frame.EndX = 4;
			frame.startY = 0;
			frame.OldTime = GetTickCount();
			frame.Speed = 200;
			break;
		case PANG:
			frame.startX = 0;
			frame.EndX = 2;
			frame.startY = 0;
			frame.OldTime = GetTickCount();
			frame.Speed = 200;
			break;
		case DIE:

			frame.startX = 0;
			frame.EndX = 3;
			frame.startY = 0;
			frame.OldTime = GetTickCount();
			frame.Speed = 200;
			break;

		default:
			break;
		}
		prestance = curstance;
	}
}

void BossMonster::Collide(OBJID objid)
{

	if (objid == PLAYER)
	{

	/*	frameKey = L"dieturtle";
		curstance = DIE;*/
	
	}

	if (objid == MONSTERU)
		isCollision = true;
	if (objid == LEFTBULLET)
	{
		
		isCollision = true;
	}
	if (objid == RIGHTBULLET)
	{
		isCollision = true;
	}
	if (objid == UPBULLET)
	{
		isCollision = true;
	}
	if (objid == DOWNBULLET)
	{
		isCollision = true;
		
	}

	if (objid == MIDDLEBULLET)
	{
		isCollision = true;

	}


}

void BossMonster::Collide2()
{
}
