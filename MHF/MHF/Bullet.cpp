#include "stdafx.h"
#include "Bullet.h"


Bullet::Bullet()
	:direction(0)
{
}


Bullet::~Bullet()
{
}

void Bullet::Initialize()
{
	info.fCX = 20.f;
	info.fCY = 20.f;
	isDead = false;
	info.fSpeed = 10.f;
}



int Bullet::Update() 
{
	

		if (true == isDead)
			return  DEAD;


		enum { 위 = 1, 아래, 오른쪽, 왼쪽 };


			if (direction == 위) {
				info.fY -= info.fSpeed;
			}
			if (direction == 아래) {
				info.fY += info.fSpeed;
			}
			if (direction == 오른쪽) {
				info.fX += info.fSpeed;
			}
			if (direction == 왼쪽) {
				info.fX -= info.fSpeed;
			}

			UpdateRect();
		
	

	return LIVE;

	
}

void Bullet::LateUpdate()
{



	if (50 >= rect.left || WINCX - 50 <= rect.right||
		50 >= rect.top || WINCY - 50 <= rect.bottom) {
		isDead = true;
	}


}

void Bullet::Render(HDC hdc)
{

	

	Ellipse(hdc, rect.left, rect.top, rect.right, rect.bottom);

}

void Bullet::Release()
{
}

void Bullet::setDir(int dir)
{
	direction = dir;
}

void Bullet::setPos(float x, float y)
{
	info.fX = x;
	info.fY = y;
}
