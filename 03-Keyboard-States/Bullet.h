#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_BULLET 30000
#define BULLET_SPEED 0.2f

class Bullet : public CGameObject {
public:
	Bullet(float x, float y) : CGameObject(x, y) {}
	void Render();
	void Update(DWORD dt);
};