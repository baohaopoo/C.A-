#include "stdafx.h"
#include "CollisionMgr.h"
#include "Object.h"

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
				//bullet box�϶�

				if ((dstIter->getID() == BULLET) && (srcIter->getID() == SKATE)) {
					srcIter->Collide(BULLET);

				}

				//�÷��̾� �������϶�,
				if (srcIter->getID() == SKATE) {
					dstIter->Collide(SKATE);
					srcIter->Collide(SKATE);
				}
				if (srcIter->getID() == BULLET) {
					dstIter->Collide(BULLET);
					srcIter->Collide(BULLET);
				}


				//Ÿ���϶�
				if (srcIter->getID() == TILE) {
					dstIter->Collide(TILE);
					srcIter->Collide(TILE);
				}

				////�̱۷��϶�,
				if (srcIter->getID() == BOX) {
					dstIter->Collide(BOX);
					
					srcIter->Collide(BOX);
				}


				//monster�϶� �׿�..
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
				if (DestIter->getID() == PLAYER) {
					// ���� �浹
					if (fWidth > fHeight)
					{
						// �� �浹
						if (DestIter->GetInfo().fY < SrcIter->GetInfo().fY)
					DestIter->setPosY(SrcIter->GetInfo().fY + SrcIter->GetInfo().fCY);// DestIter->GetInfo().fY -20
						// �� �浹
						else
							DestIter->setPosY(SrcIter->GetInfo().fY - SrcIter->GetInfo().fCY);
					}
					// �¿� �浹
					else
					{
						// �� �浹
						if (DestIter->GetInfo().fX < SrcIter->GetInfo().fX)
							DestIter->setPosX(SrcIter->GetInfo().fX - (SrcIter->GetInfo().fCX));// DestIter->GetInfo().fX - 10
						// �� �浹
						else
							DestIter->setPosX(SrcIter->GetInfo().fX + (SrcIter->GetInfo().fCX));
					}
				}
			}
		}
	}
}

bool CollisionMgr::Check_Rect(Object * pDest, Object * pSrc, float * _pX, float * _pY)
{
	float		fWidth = fabs(pDest->GetInfo().fX - pSrc->GetInfo().fX);
	float		fHeight = fabs(pDest->GetInfo().fY - pSrc->GetInfo().fY);

	float		fDistance = sqrtf(fWidth * fWidth + fHeight * fHeight);

	float		fRadius = (pDest->GetInfo().fCX + pSrc->GetInfo().fCX) * 0.5f;

	return fRadius > fDistance;		// �浹 �ߴ�
}
