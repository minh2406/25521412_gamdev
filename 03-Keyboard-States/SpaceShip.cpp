#include "SpaceShip.h"
#include "Bullet.h"
extern vector<LPGAMEOBJECT> objects;
void SpaceShip::Update(DWORD dt)
{
	if(state == SPACESHIP_STATE_UP)
	{
		y -= SPACESHIP_SPEED * dt;
	}
	else if (state == SPACESHIP_STATE_DOWN)
	{
		y += SPACESHIP_SPEED * dt;
	}
	else if (state == SPACESHIP_STATE_LEFT)
	{
		x -= SPACESHIP_SPEED * dt;
	}
	else if (state == SPACESHIP_STATE_RIGHT)
	{
		x += SPACESHIP_SPEED * dt;
	}
	lastFireTime += dt;
}
void SpaceShip::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	switch (state)
	{
	case SPACESHIP_STATE_UP:
		aniId = ANI_ID_SPACESHIP_UP;
		break;
	case SPACESHIP_STATE_DOWN:
		aniId = ANI_ID_SPACESHIP_DOWN;
		break;
	default:
		aniId = ANI_ID_SPACESHIP_FLYING;
		break;
	}
	animations->Get(aniId)->Render(x, y);
}
void SpaceShip::fireBullet()
{
	if (lastFireTime >= FIRE_RATE)
	{
		Bullet* bullet = new Bullet(x + 14.0f, y);
		objects.push_back(bullet);
		lastFireTime = 0;
	}
}
void SpaceShip::SetState(int state)
{
	this->state = state;
}