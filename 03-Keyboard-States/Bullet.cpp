#include "Bullet.h"

void Bullet::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_BULLET)->Render(x, y);
}
void Bullet::Update(DWORD dt)
{
	x += BULLET_SPEED * dt;
}