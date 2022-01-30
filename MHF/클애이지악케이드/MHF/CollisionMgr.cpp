#include "stdafx.h"
#include "CollisionMgr.h"
#include "Object.h"
#include"Item.h"
CollisionMgr::CollisionMgr()
{
}


CollisionMgr::~CollisionMgr()
{

}

bool CollisionMgr::checkSphereCollision(Object* dst, Object* src)
{
	float width = fabs(src->GetInfo().fX - dst->GetInfo().fX);
	float height = fabs(dst->GetInfo().fY - src->GetInfo().fY);

	float distance = sqrtf((width*width) + (height*height));

	float radiusSum = 0.5*(dst->GetInfo().fCX + src->GetInfo().fCX);

	return radiusSum > distance;
}

void CollisionMgr::CollisionRect(list<Object*>& dst, list<Object*>& src)
{
	RECT rc{};

	for (auto& dstIter : dst) {
		for (auto& srcIter : src) {
			
			if (IntersectRect(&rc, &(dstIter->GetRect()), &(srcIter->GetRect())))
			{

				if (dstIter->getID() == RIDE && srcIter->getID() == PLAYER) {
					dstIter->setDead();
					srcIter->Collide(RIDE);
				}

				if (dstIter->getID() == RIDE && srcIter->getID() == COMPUTER) {
					dstIter->setDead();
					srcIter->setDead();
				}


				if (dstIter->getID() == BOSSMON && srcIter->getID() == PLAYER)
				{

					dstIter->Collide(PLAYER);
				}

				if (dstIter->getID() == MONSTER && srcIter->getID() == BACKGROUND) {
					dstIter->Collide(BACKGROUND);
				}

				if (dstIter->getID() == BACKGROUND && srcIter->getID() == LEFTBULLET) {
					dstIter->Collide(LEFTBULLET);
				}
				if (dstIter->getID() == BACKGROUND && srcIter->getID() == RIGHTBULLET) {
					dstIter->Collide(RIGHTBULLET);
				}
				if (dstIter->getID() == BACKGROUND && srcIter->getID() == UPBULLET) {
					dstIter->Collide(UPBULLET);
				}
				if (dstIter->getID() == BACKGROUND && srcIter->getID() == DOWNBULLET) {
					dstIter->Collide(DOWNBULLET);
				}
				if (dstIter->getID() == BACKGROUND && srcIter->getID() == MIDDLEBULLET) {
					dstIter->Collide(MIDDLEBULLET);
				}



				if (dstIter->getID() == ITEMBOX && srcIter->getID() == LEFTBULLET) {
					dstIter->Collide(LEFTBULLET);
					srcIter->Collide(ITEMBOX);
				}
				if (dstIter->getID() == ITEMBOX && srcIter->getID() == RIGHTBULLET) {
					dstIter->Collide(RIGHTBULLET);
					srcIter->Collide(ITEMBOX);
				}
				if (dstIter->getID() == ITEMBOX && srcIter->getID() == UPBULLET) {
					dstIter->Collide(UPBULLET);
					srcIter->Collide(ITEMBOX);
				}
				if (dstIter->getID() == ITEMBOX && srcIter->getID() == DOWNBULLET) {
					dstIter->Collide(DOWNBULLET);
					srcIter->Collide(ITEMBOX);
				}
				if (dstIter->getID() == ITEMBOX && srcIter->getID() == MIDDLEBULLET) {
					dstIter->Collide(MIDDLEBULLET);
					srcIter->Collide(ITEMBOX);
				}



				//보스몬.
				if (dstIter->getID() == BOSSMON && srcIter->getID() == LEFTBULLET) {
					dstIter->Collide(LEFTBULLET);
				}
				if (dstIter->getID() == BOSSMON&& srcIter->getID() == RIGHTBULLET) {
					dstIter->Collide(RIGHTBULLET);
				}
				if (dstIter->getID() == BOSSMON&& srcIter->getID() == UPBULLET) {
					dstIter->Collide(UPBULLET);
				}
				if (dstIter->getID() == BOSSMON && srcIter->getID() == DOWNBULLET) {
					dstIter->Collide(DOWNBULLET);
				}
				if (dstIter->getID() == BOSSMON && srcIter->getID() == MIDDLEBULLET) {
					dstIter->Collide(MIDDLEBULLET);
				}


				if (dstIter->getID() == BOSSMON && srcIter->getID() == MONSTERU) {
					dstIter->Collide(MONSTERU);
					srcIter->setDead();
				}









				if (dstIter->getID() == OBJECT && srcIter->getID() == LEFTBULLET) {
				
					dstIter->Collide(LEFTBULLET);
					srcIter->setDead();
				}

				if (dstIter->getID() == BOX && srcIter->getID() == PLAYER) {
					
					dstIter->Collide(PLAYER);
					srcIter->Collide(BOX);

				}
			

				//플레이어 아이템일때,
				if (dstIter->getID() == PLAYER && srcIter->getID() == ITEM) {
		
	/*				dynamic_cast<Item*>(dstIter)->Collide(ITEM);
					dynamic_cast<Item*>(dstIter)->Collide(PLAYER);*/
					dstIter->Collide(ITEM);
					srcIter->Collide(ITEM);
				}

				//플레이어 아이템일때,
				if (dstIter->getID() == COMPUTER && srcIter->getID() == ITEM) {

					/*				dynamic_cast<Item*>(dstIter)->Collide(ITEM);
					dynamic_cast<Item*>(dstIter)->Collide(PLAYER);*/
					dstIter->Collide(ITEM);
					srcIter->Collide(ITEM);
				}


				if (dstIter->getID() == PLAYER && srcIter->getID() == SODA) {

					/*				dynamic_cast<Item*>(dstIter)->Collide(ITEM);
					dynamic_cast<Item*>(dstIter)->Collide(PLAYER);*/
					dstIter->Collide(SODA);
					srcIter->setDead();
				}
				//주사일떄
				if (dstIter->getID() == PLAYER && srcIter->getID() ==JUSA) {

					/*				dynamic_cast<Item*>(dstIter)->Collide(ITEM);
					dynamic_cast<Item*>(dstIter)->Collide(PLAYER);*/
					dstIter->Collide(JUSA);
					srcIter->setDead();
				}

				///////////////////////////////////////////////////
				/*if (dstIter->getID()==PLAYER && srcIter->getID() == BULLET) {
					dstIter->Collide(BULLET);
					srcIter->Collide(PLAYER);
				}
				*/


				//플레이어랑 물폭탄 맞았을때 처리  (완료)
				if (dstIter->getID() == PLAYER && srcIter->getID() == LEFTBULLET) {
					dstIter->Collide(LEFTBULLET);
					srcIter->Collide(PLAYER);
				}

				if (dstIter->getID() == PLAYER && srcIter->getID() == RIGHTBULLET) {
					dstIter->Collide(RIGHTBULLET);
					srcIter->Collide(PLAYER);
				}

				if (dstIter->getID() == PLAYER && srcIter->getID() == UPBULLET) {
					dstIter->Collide(UPBULLET);
					srcIter->Collide(PLAYER);
				}
				if (dstIter->getID() == PLAYER && srcIter->getID() == DOWNBULLET) {
					dstIter->Collide(DOWNBULLET);
					srcIter->Collide(PLAYER);
				}


				//컴퓨터 플레이어랑 물폭탄 맞았을때 처리  (완료)
				if (dstIter->getID() == COMPUTER && srcIter->getID() == LEFTBULLET) {
					dstIter->Collide(LEFTBULLET);
					srcIter->Collide(COMPUTER);
				}

				if (dstIter->getID() == COMPUTER&& srcIter->getID() == RIGHTBULLET) {
					dstIter->Collide(RIGHTBULLET);
					srcIter->Collide(COMPUTER);
				}

				if (dstIter->getID() == COMPUTER && srcIter->getID() == UPBULLET) {
					dstIter->Collide(UPBULLET);
					srcIter->Collide(COMPUTER);
				}
				if (dstIter->getID() == COMPUTER && srcIter->getID() == DOWNBULLET) {
					dstIter->Collide(DOWNBULLET);
					srcIter->Collide(COMPUTER);
				}


				//밤과 타일.
				if ((dstIter->getID() == BOX) && (srcIter->getID()==BULLET)) {

					srcIter->Collide(BOX);
 					dstIter->Collide(BULLET);

				}

				if ((dstIter->getID() == BOX) && (srcIter->getID() == DOWNBULLET)) {

					//srcIter->Collide(BOX);
					dstIter->Collide(DOWNBULLET);

				}
				if ((dstIter->getID() == BOX) && (srcIter->getID() == UPBULLET)) {

					//srcIter->Collide(BOX);
					dstIter->Collide(UPBULLET);

				}
				if ((dstIter->getID() == BOX) && (srcIter->getID() == LEFTBULLET)) {

					//srcIter->Collide(BOX);
					dstIter->Collide(LEFTBULLET);

				}
				if ((dstIter->getID() == BOX) && (srcIter->getID() == RIGHTBULLET)) {

					//srcIter->Collide(BOX);
					dstIter->Collide(RIGHTBULLET);

				}

				/////////// 이건 몬가 안쓸거같음..

				/*if ((dstIter->getID() == PLAYER) && (srcIter->getID() == DOWNBULLET)) {

					srcIter->Collide(PLAYER);
					dstIter->Collide(DOWNBULLET);

				}
				if ((dstIter->getID() == PLAYER) && (srcIter->getID() == UPBULLET)) {

					srcIter->Collide(PLAYER);
					dstIter->Collide(UPBULLET);

				}
				if ((dstIter->getID() == PLAYER) && (srcIter->getID() == LEFTBULLET)) {

					srcIter->Collide(PLAYER);
					dstIter->Collide(LEFTBULLET);

				}
				if ((dstIter->getID() == BOX) && (srcIter->getID() == RIGHTBULLET)) {

					srcIter->Collide(PLAYER);
					dstIter->Collide(RIGHTBULLET);

				}*/

			/////////////////////////////////////////몬스터 스테이지용. COBJECT
				if ((dstIter->getID() == COBJECT) && (srcIter->getID() == DOWNBULLET)) {

					srcIter->Collide(COBJECT);
					dstIter->Collide(DOWNBULLET);

				}
				if ((dstIter->getID() == COBJECT) && (srcIter->getID() == UPBULLET)) {

					srcIter->Collide(COBJECT);
					dstIter->Collide(UPBULLET);

				}
				if ((dstIter->getID() == COBJECT) && (srcIter->getID() == LEFTBULLET)) {

					srcIter->Collide(COBJECT);
					dstIter->Collide(LEFTBULLET);

				}
				if ((dstIter->getID() == COBJECT) && (srcIter->getID() == RIGHTBULLET)) {

					srcIter->Collide(COBJECT);
					dstIter->Collide(RIGHTBULLET);

				}
				//이거때문에 퍼플과 퍼플 시에 문제 생감.
				if (dstIter->getID() == MONSTER )
				{
			
						dstIter->setImage(L"DUMP");
						dstIter->Collide2();
				
				}

				if (dstIter->getID() == MONSTERU ) {
					dstIter->setImage(L"DUMP");
					dstIter->Collide2();

				}


				//퍼플 몬스터랑 핑크 몬스터 충돌 했을떄, 
				if (dstIter->getID() == MONSTERU && srcIter->getID() == MONSTER)
				{
					dstIter->Collide(MONSTER);
					//dstIter->setDead();
					srcIter->Collide(MONSTERU);
					srcIter->setDead();
				}



				//퍼플 몬스터랑 플레이어랑 충돌했을때, 

				if (dstIter->getID() == PLAYER && srcIter->getID() == MONSTER) {
					dstIter->Collide(MONSTER);
					srcIter->Collide(PLAYER);
				}
				if (dstIter->getID() == PLAYER && srcIter->getID() == MONSTERU) {
					dstIter->Collide(MONSTER);
					srcIter->Collide(PLAYER);
				}


				//퍼플몬스터랑 퍼플몬스터가 충돌할떄,
				if (dstIter->getID() == MONSTER && srcIter->getID() == MONSTER)
				{
					/*dstIter->Collide(MONSTER);

					srcIter->Collide(MONSTER);*/
				}
















				//monster일때 죽여..
				/*dstIter->setDead();
				srcIter->setDead();*/

			}
		
		}
	}

}

void CollisionMgr::CollisionShpere(list<Object*>& dst, list<Object*>& src)
{
	for (auto& dstIter : dst) {
		for (auto& srcIter : src) {
		
			if(checkSphereCollision(dstIter, srcIter)) {
				dstIter->setDead();
				srcIter->setDead();
			
			}
		
		}
	
	}
}

void CollisionMgr::CollisionObject(list<Object*>& dst, list<Object*>& src)
{
	RECT	rc{};

	float		fWidth, fHeight;

	for (auto& DestIter : dst)
	{
		for (auto& SrcIter : src)
		{
			if (Check_Rect(DestIter, SrcIter, &fWidth, &fHeight))
			{
				 {
						
					// 상하 충돌
					if (fWidth > fHeight)
					{
						// 하 충돌
						if (DestIter->GetInfo().fY < SrcIter->GetInfo().fY) {
						/*	if (DestIter->getID() == OBJECT  && SrcIter->getID() == DOWNBULLET) {
								SrcIter->setDead();
							}else*/
								SrcIter->setPosY(SrcIter->GetInfo().fY + fHeight);
						}
						// 상 충돌
						else {
					/*		if (DestIter->getID() == OBJECT  && SrcIter->getID() == UPBULLET) {
								SrcIter->setDead();
							}else */
								SrcIter->setPosY(SrcIter->GetInfo().fY - fHeight);
						}
					}
					// 좌우 충돌
					else
					{

						// 우 충돌
						if (DestIter->GetInfo().fX < SrcIter->GetInfo().fX) {
				/*			if (DestIter->getID() == OBJECT  && SrcIter->getID() == LEFTBULLET) {
								SrcIter->Collide(OBJECT);
							}else */
								SrcIter->setPosX(SrcIter->GetInfo().fX + fWidth);
						}
						// 좌 충돌
						else {
							/*if (DestIter->getID() == OBJECT  && SrcIter->getID() == RIGHTBULLET) {

							}else*/
								SrcIter->setPosX(SrcIter->GetInfo().fX + -fWidth);
						}
					}

					
				}
			}
		}
	}
}
void CollisionMgr::CollisionObjectTree(list<Object*>& dst, list<Object*>& src)
{
	//box background
	//backgournd box
	//box box


	RECT	rc{};

	float		fWidth, fHeight;

	for (auto& DestIter : dst)
	{
		for (auto& SrcIter : src)
		{
			if (Check_Rect(DestIter, SrcIter, &fWidth, &fHeight))
			{
				{

					// 상하 충돌
					if (fWidth > fHeight)
					{
						// 하 충돌
						if (DestIter->GetInfo().fY < SrcIter->GetInfo().fY) {
						
							DestIter->setPosY(DestIter->GetInfo().fY + fHeight);
						}
						// 상 충돌
						else {
						
							DestIter->setPosY(DestIter->GetInfo().fY + fHeight);
						}
					}
					// 좌우 충돌
					else
					{

						// 우 충돌
						if (DestIter->GetInfo().fX < SrcIter->GetInfo().fX) {
						
							DestIter->setPosY(DestIter->GetInfo().fX);
						}
						// 좌 충돌
						else {
						
							DestIter->setPosY(DestIter->GetInfo().fX);
						}
					}


				}
			}
		}
	}













}
void CollisionMgr::CollisionV(list<Object*>& dst, list<Object*>& src)
{
	RECT	rc{};

	float		fWidth, fHeight;

	for (auto& DestIter : dst)
	{
		for (auto& SrcIter : src)
		{
			if (Check_Rect(DestIter, SrcIter, &fWidth, &fHeight))
			{
				{

				
					{
						// 우 충돌
						if (DestIter->GetInfo().fX < SrcIter->GetInfo().fX)
							SrcIter->setPosX(SrcIter->GetInfo().fX + fWidth);
						// 좌 충돌
						else
							SrcIter->setPosX(SrcIter->GetInfo().fX + -fWidth);
					}


				}
			}
		}
	}

}
//object, player
bool CollisionMgr::Check_Rect(Object * pDest, Object * pSrc, float * _pX, float * _pY)
{
	float		fWidth = abs(pDest->GetInfo().fX - pSrc->GetInfo().fX);
	float		fHeight = abs(pDest->GetInfo().fY - pSrc->GetInfo().fY);

	// float		fCX = pDest->Get_Info().fCX / 2.f + pSrc->Get_Info().fCX / 2.f;
	// 위의 식을 아래 식으로 변경했을 뿐
	float		fCX = (pDest->GetInfo().fCX + pSrc->GetInfo().fCX) * 0.5f;
	float		fCY = (pDest->GetInfo().fCY + pSrc->GetInfo().fCY) * 0.5f;

	if (fCX > fWidth && fCY > fHeight)
	{
		*_pX = fCX - fWidth;
		*_pY = fCY - fHeight;

		return true;
	}
	return false;
}
