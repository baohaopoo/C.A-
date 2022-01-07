#pragma once
#include"Define.h"
#include "Enum.h"
class Object;
class ObjMgr
{
public:
	ObjMgr();
	~ObjMgr();


public:
	Object*			Get_Player() { return m_ObjList[PLAYER].front(); }
	Object*			Get_Target(OBJID eID, Object* pObj);
	list<Object*>*	Get_ObjList(OBJID eID);

public:
	void			Add_Object(OBJID eID, Object* pObj);

	int				Update(void);
	int				Late_Update(void);
	void			Render(HDC hDC);
	void			Release(void);
	void			Delete_ID(OBJID eID);

public:
	static ObjMgr*		Get_Instance(void)
	{
		if (nullptr == m_pInstance)
			m_pInstance = new ObjMgr;

		return m_pInstance;
	}
	static void			Destroy_Instance(void)
	{
		if (nullptr != m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

private:
	list<Object*>				m_ObjList[END];
	//list<Object*>				m_RenderList[GROUP_END];

	static		ObjMgr*	m_pInstance;

};

