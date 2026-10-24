#include "Enemy.h"

void Enemy::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_ENEMY)->Render(x, y);
}
void Enemy::AddDestination(float desX, float desY) {
	pair<float, float> des(desX, desY);
	destination.push_back(des);
}
void Enemy::Update(DWORD dt) {
	// move to next destination
	if (!destination.empty()) {
		float temX = x;
		float temY = y;
		float desX = destination.front().first;
		float desY = destination.front().second;
		if (desX > temX) {
			temX += ENEMY_MOVE_SPEED * dt;
			x = (temX >= desX) ? desX : temX;
		}
		else if (desX < temX) {
			temX -= ENEMY_MOVE_SPEED * dt;
			x = (temX <= desX) ? desX : temX;

		}
		if (desY > temY) {
			temY += ENEMY_MOVE_SPEED * dt;
			y = (temY >= desY) ? desY : temY;
		}
		else if (desY < temY) {
			temY -= ENEMY_MOVE_SPEED * dt;
			y = (temY <= desY) ? desY : temY;
		}
		if (x == desX && y == desY) {
			destination.erase(destination.begin());
		}
	}
}