#pragma once

#include "GameObject.h"
#include "Animation.h"
#include <vector>
#include "Animations.h"

#define ID_ANI_ENEMY 40000
#define ENEMY_MOVE_SPEED 0.05
using namespace std;
class Enemy : public CGameObject {
	vector<pair<float, float>> destination;
public:
	Enemy(float x, float y) : CGameObject(x, y) {}
	void Render();
	void Update(DWORD dt);
	void AddDestination(float desX, float dexY);
};