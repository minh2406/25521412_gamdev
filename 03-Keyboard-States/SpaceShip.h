#pragma once
#include "GameObject.h"

#include "Animation.h"
#include "Animations.h"

#include "debug.h"

#define ANI_ID_SPACESHIP_FLYING	20000
#define ANI_ID_SPACESHIP_UP	20001
#define ANI_ID_SPACESHIP_DOWN 20002

#define SPACESHIP_STATE_FLYING 0
#define SPACESHIP_STATE_LEFT 1
#define SPACESHIP_STATE_RIGHT 2
#define SPACESHIP_STATE_UP 3
#define SPACESHIP_STATE_DOWN 4

#define SPACESHIP_SPEED	0.1f
#define FIRE_RATE 200 // milliseconds

class SpaceShip : public CGameObject
{
	int aniId;
	int lastFireTime = 0;
public:
	SpaceShip(float x, float y) : CGameObject(x, y)
	{
		aniId = ANI_ID_SPACESHIP_FLYING;
	}
	float GetX() { return x; }
	float GetY() { return y; }
	void fireBullet();
	void Update(DWORD dt);
	void Render();
	void SetState(int state);
};