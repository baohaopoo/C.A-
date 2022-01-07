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
				//box�ϋ�
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
