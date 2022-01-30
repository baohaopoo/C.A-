#include "stdafx.h"
#include "KeyMgr.h"


KeyMgr*	KeyMgr::m_pInstance = nullptr;
KeyMgr::KeyMgr()
{
	ZeroMemory(m_bKeyState, sizeof(m_bKeyState));
}



KeyMgr::~KeyMgr()
{
}

bool KeyMgr::Key_Pressing(int iKey)
{
	if (GetAsyncKeyState(iKey) & 0x8000)
		return true;

	return false;
}

bool KeyMgr::Key_Down(int iKey)
{
	// ������ ������ ����, ���� ������ �ִ� ���

	if (!m_bKeyState[iKey] && (GetAsyncKeyState(iKey) & 0x8000))
	{
		m_bKeyState[iKey] = !m_bKeyState[iKey];
		return true;
	}

	if (m_bKeyState[iKey] && !(GetAsyncKeyState(iKey) & 0x8000))
		m_bKeyState[iKey] = !m_bKeyState[iKey];

	return false;
}

bool KeyMgr::Key_Up(int iKey)
{
	// ������ ������ �ְ�, ���� ������ �ʾ��� ���
	if (m_bKeyState[iKey] && !(GetAsyncKeyState(iKey) & 0x8000))
	{
		m_bKeyState[iKey] = !m_bKeyState[iKey];
		return true;
	}

	if (!m_bKeyState[iKey] && (GetAsyncKeyState(iKey) & 0x8000))
		m_bKeyState[iKey] = !m_bKeyState[iKey];

	return false;
}
