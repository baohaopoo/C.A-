#include "stdafx.h"
#include "ObjMgr.h"
#include "Object.h"
#include"Functional.h"

ObjMgr* ObjMgr::m_pInstance = nullptr;


ObjMgr::ObjMgr()
{
	Release();
}


ObjMgr::~ObjMgr()
{
}

Object * ObjMgr::Get_Target(OBJID eID, Object * pObj)
{
	if (m_ObjList[eID].empty())
		return nullptr;

	Object*		pTarget = nullptr;

	float		fDistance = 0.f;

	for (auto& iter : m_ObjList[eID])
	{
		if (iter->GetDead())
			continue;

		float	fWidth = abs(pObj->GetInfo().fX - iter->GetInfo().fX);
		float	fHeight = abs(pObj->GetInfo().fY - iter->GetInfo().fY);

		float   fDistance2 = sqrtf(fWidth * fWidth + fHeight * fHeight);

		if (fDistance > fDistance2 || !pTarget)
		{
			pTarget = iter;
			fDistance = fDistance2;
		}
	}

	return pTarget;
}

list<Object*>* ObjMgr::Get_ObjList(OBJID eID)
{
	return &m_ObjList[eID];
}

void ObjMgr::Add_Object(OBJID eID, Object * pObj)
{
	if (END <= eID || nullptr == pObj)
		return;

	m_ObjList[eID].push_back(pObj);
}

int ObjMgr::Update(void)
{
	int iEvent = 0;

	for (int i = 0; i < END; ++i)
	{
		auto& iter = m_ObjList[i].begin();

		for (; iter != m_ObjList[i].end(); )
		{
			iEvent = (*iter)->Update();

			if (DEAD == iEvent)
			{
				SafeDelete<Object*>(*iter);
				iter = m_ObjList[i].erase(iter);
			}
			else
				++iter;
		}
	}

	return iEvent;
}

int ObjMgr::Late_Update(void)
{
	for (int i = 0; i < END; ++i)
	{
		for (auto& iter : m_ObjList[i])
		{
			iter->LateUpdate();

			if (m_ObjList[i].empty())
				break;

		/*	GROUPID		eID = iter->Get_GroupID();
			m_RenderList[eID].push_back(iter);*/

		}
	}
	return 0;
	//CCollisionMgr::Collision_Sphere(m_ObjList[BULLET], m_ObjList[MONSTER]);
	//CCollisionMgr::Collision_Rect(m_ObjList[BULLET], m_ObjList[MONSTER]);
	//CCollisionMgr::Collision_RectEx(m_ObjList[MONSTER], m_ObjList[PLAYER]);
}

void ObjMgr::Render(HDC hDC)
{
	for (int i = 0; i < END; ++i)
	{
	/*	m_RenderList[i].sort(CompareY<CObj*>);*/

		//for (auto& iter : m_RenderList[i])
		//	iter->Render(hDC);

		//m_RenderList[i].clear();		// 정렬은 실시간으로 계속 바뀜
	}

}

void ObjMgr::Release(void)
{
	for (int i = 0; i < END; ++i)
	{
		for_each(m_ObjList[i].begin(), m_ObjList[i].end(), SafeDelete<Object*>);
		m_ObjList[i].clear();
	}
}

void ObjMgr::Delete_ID(OBJID eID)
{
	for (auto& iter : m_ObjList[eID])
		SafeDelete(iter);

	m_ObjList[eID].clear();
}
