#include "stdafx.h"
#include "ObjMgr.h"
#include "Object.h"
#include"Functional.h"
#include "CollisionMgr.h"
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
		}
	}


	CollisionMgr::CollisionObject(m_ObjList[TREE], m_ObjList[PLAYER]); //tree�� �и��� �ʴ� ������Ʈ��
	CollisionMgr::CollisionObject(m_ObjList[BACKGROUND], m_ObjList[PLAYER]); //������ �ϴµ� �ƹ��͵� ������ �ʴ�.
	CollisionMgr::CollisionObject(m_ObjList[ITEMBOX], m_ObjList[PLAYER]); //������ �ϴµ� �ƹ��͵� ������ �ʴ�.


	CollisionMgr::CollisionObject(m_ObjList[TREE], m_ObjList[COMPUTER]); //tree�� �и��� �ʴ� ������Ʈ��
	CollisionMgr::CollisionObject(m_ObjList[BACKGROUND], m_ObjList[COMPUTER]); //������ �ϴµ� �ƹ��͵� ������ �ʴ�.
	CollisionMgr::CollisionObject(m_ObjList[ITEMBOX], m_ObjList[COMPUTER]); //������ �ϴµ� �ƹ��͵� ������ �ʴ�.


	//�̰Ž� ���� ŷ�޴� ���̴�. 
	//CollisionMgr::CollisionObjectTree(m_ObjList[BOX], m_ObjList[BACKGROUND]); //������ �ϴµ� �ƹ��͵� ������ �ʴ�.
	//CollisionMgr::CollisionObjectTree(m_ObjList[BACKGROUND], m_ObjList[BOX]); //������ �ϴµ� �ƹ��͵� ������ �ʴ�.
	//CollisionMgr::CollisionObjectTree(m_ObjList[BOX], m_ObjList[BOX]); //������ �ϴµ� �ƹ��͵� ������ �ʴ�.


	CollisionMgr::CollisionRect(m_ObjList[BACKGROUND], m_ObjList[LEFTBULLET]); //������ �ϴµ� �ƹ��͵� ������ �ʴ�.
	CollisionMgr::CollisionRect(m_ObjList[BACKGROUND], m_ObjList[RIGHTBULLET]); //������ �ϴµ� �ƹ��͵� ������ �ʴ�.
	CollisionMgr::CollisionRect(m_ObjList[BACKGROUND], m_ObjList[UPBULLET]); //������ �ϴµ� �ƹ��͵� ������ �ʴ�.
	CollisionMgr::CollisionRect(m_ObjList[BACKGROUND], m_ObjList[DOWNBULLET]); //������ �ϴµ� �ƹ��͵� ������ �ʴ�.
	CollisionMgr::CollisionRect(m_ObjList[BACKGROUND], m_ObjList[MIDDLEBULLET]); //������ �ϴµ� �ƹ��͵� ������ �ʴ�.

	CollisionMgr::CollisionObject(m_ObjList[PLAYER], m_ObjList[BOX]); //�и��� ������Ʈ	
	CollisionMgr::CollisionObject(m_ObjList[COMPUTER], m_ObjList[BOX]);





	CollisionMgr::CollisionRect(m_ObjList[BOX], m_ObjList[DOWNBULLET]);
	CollisionMgr::CollisionRect(m_ObjList[BOX], m_ObjList[UPBULLET]);
	CollisionMgr::CollisionRect(m_ObjList[BOX], m_ObjList[LEFTBULLET]);
	CollisionMgr::CollisionRect(m_ObjList[BOX], m_ObjList[RIGHTBULLET]);
	CollisionMgr::CollisionRect(m_ObjList[BOX], m_ObjList[MIDDLEBULLET]);
	


	CollisionMgr::CollisionRect(m_ObjList[ITEMBOX], m_ObjList[DOWNBULLET]);
	CollisionMgr::CollisionRect(m_ObjList[ITEMBOX], m_ObjList[UPBULLET]);
	CollisionMgr::CollisionRect(m_ObjList[ITEMBOX], m_ObjList[LEFTBULLET]);
	CollisionMgr::CollisionRect(m_ObjList[ITEMBOX], m_ObjList[RIGHTBULLET]);
	CollisionMgr::CollisionRect(m_ObjList[ITEMBOX], m_ObjList[MIDDLEBULLET]);

	CollisionMgr::CollisionRect(m_ObjList[RIDE], m_ObjList[PLAYER]);
	CollisionMgr::CollisionRect(m_ObjList[RIDE], m_ObjList[COMPUTER]);

	CollisionMgr::CollisionRect(m_ObjList[BOSSMON], m_ObjList[DOWNBULLET]);
	CollisionMgr::CollisionRect(m_ObjList[BOSSMON], m_ObjList[UPBULLET]);
	CollisionMgr::CollisionRect(m_ObjList[BOSSMON], m_ObjList[LEFTBULLET]);
	CollisionMgr::CollisionRect(m_ObjList[BOSSMON], m_ObjList[RIGHTBULLET]);
	CollisionMgr::CollisionRect(m_ObjList[BOSSMON], m_ObjList[MIDDLEBULLET]);


	CollisionMgr::CollisionRect(m_ObjList[BOSSMON], m_ObjList[MONSTERU]);


	CollisionMgr::CollisionRect(m_ObjList[BOSSMON], m_ObjList[PLAYER]);


	CollisionMgr::CollisionRect(m_ObjList[PLAYER], m_ObjList[ITEM]);
	CollisionMgr::CollisionRect(m_ObjList[PLAYER], m_ObjList[SODA]);
	CollisionMgr::CollisionRect(m_ObjList[PLAYER], m_ObjList[JUSA]);
	CollisionMgr::CollisionRect(m_ObjList[COMPUTER], m_ObjList[ITEM]);
	CollisionMgr::CollisionRect(m_ObjList[COMPUTER], m_ObjList[SODA]);
	CollisionMgr::CollisionRect(m_ObjList[COMPUTER], m_ObjList[JUSA]);
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//���� ����������. 
	CollisionMgr::CollisionRect(m_ObjList[COBJECT], m_ObjList[DOWNBULLET]);
	CollisionMgr::CollisionRect(m_ObjList[COBJECT], m_ObjList[UPBULLET]);
	CollisionMgr::CollisionRect(m_ObjList[COBJECT], m_ObjList[LEFTBULLET]);
	CollisionMgr::CollisionRect(m_ObjList[COBJECT], m_ObjList[RIGHTBULLET]);

	//���� ���Ͷ� �Ѿ� �¾�����,

	CollisionMgr::CollisionRect(m_ObjList[MONSTER], m_ObjList[DOWNBULLET]);
	CollisionMgr::CollisionRect(m_ObjList[MONSTER], m_ObjList[UPBULLET]);
	CollisionMgr::CollisionRect(m_ObjList[MONSTER], m_ObjList[LEFTBULLET]);
	CollisionMgr::CollisionRect(m_ObjList[MONSTER], m_ObjList[RIGHTBULLET]);

	//��ũ ���Ͷ� �Ѿ� �¾�����,
	CollisionMgr::CollisionRect(m_ObjList[MONSTERU], m_ObjList[DOWNBULLET]);
	CollisionMgr::CollisionRect(m_ObjList[MONSTERU], m_ObjList[UPBULLET]);
	CollisionMgr::CollisionRect(m_ObjList[MONSTERU], m_ObjList[LEFTBULLET]);
	CollisionMgr::CollisionRect(m_ObjList[MONSTERU], m_ObjList[RIGHTBULLET]);
	//��ũ ���Ͷ� ���� ���� �浹�ҋ�, 
	CollisionMgr::CollisionRect(m_ObjList[MONSTERU], m_ObjList[MONSTER]);
	//���� ���Ͷ� ���� ���Ͷ� �浹�Ҷ�,
	//CollisionMgr::CollisionRect(m_ObjList[MONSTER], m_ObjList[MONSTER]);


	//�÷��̾�� ��ǳ�� �¾�����, 
	CollisionMgr::CollisionRect(m_ObjList[PLAYER], m_ObjList[DOWNBULLET]);
	CollisionMgr::CollisionRect(m_ObjList[PLAYER], m_ObjList[UPBULLET]);
	CollisionMgr::CollisionRect(m_ObjList[PLAYER], m_ObjList[LEFTBULLET]);
	CollisionMgr::CollisionRect(m_ObjList[PLAYER], m_ObjList[RIGHTBULLET]);


	CollisionMgr::CollisionRect(m_ObjList[COMPUTER], m_ObjList[DOWNBULLET]);
	CollisionMgr::CollisionRect(m_ObjList[COMPUTER], m_ObjList[UPBULLET]);
	CollisionMgr::CollisionRect(m_ObjList[COMPUTER], m_ObjList[LEFTBULLET]);
	CollisionMgr::CollisionRect(m_ObjList[COMPUTER], m_ObjList[RIGHTBULLET]);


	//��ũ ���Ͷ� ���� ���Ͷ� �÷��̾�� �浹������,
	CollisionMgr::CollisionRect(m_ObjList[PLAYER], m_ObjList[MONSTER]);
	CollisionMgr::CollisionRect(m_ObjList[PLAYER], m_ObjList[MONSTERU]);

	//Monster�� background�� ������,
	CollisionMgr::CollisionRect(m_ObjList[MONSTER], m_ObjList[BACKGROUND]);

	return 0;

}

void ObjMgr::Render(HDC hDC)
{
	for (int i = 0; i < END; ++i)
	{
			for (auto& iter = m_ObjList[i].begin(); iter != m_ObjList[i].end(); ++iter) {
				if((*iter) != NULL)	//���� �߰��Ѱ�..
				(*iter)->Render(hDC);
			}
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
