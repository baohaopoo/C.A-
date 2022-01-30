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
	// 이전에 눌림이 없고, 현재 눌림이 있는 경우

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
	// 이전에 눌림이 있고, 현재 눌리지 않았을 경우
	if (m_bKeyState[iKey] && !(GetAsyncKeyState(iKey) & 0x8000))
	{
		m_bKeyState[iKey] = !m_bKeyState[iKey];
		return true;
	}

	if (!m_bKeyState[iKey] && (GetAsyncKeyState(iKey) & 0x8000))
		m_bKeyState[iKey] = !m_bKeyState[iKey];

	return false;
}
