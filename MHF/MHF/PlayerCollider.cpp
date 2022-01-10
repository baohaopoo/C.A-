#include "stdafx.h"
#include "PlayerCollider.h"


PlayerCollider::PlayerCollider()
{
}


PlayerCollider::~PlayerCollider()
{
}

void PlayerCollider::Initialize()
{
	id = PLAYERC;
	info.fCX = 20.f;
	info.fCY = 20.f;

}

int PlayerCollider::Update()
{





	UpdateRect();
	return 0;
}

void PlayerCollider::LateUpdate()
{
}

void PlayerCollider::Render(HDC hdc)
{
	Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
}

void PlayerCollider::Release()
{
}
