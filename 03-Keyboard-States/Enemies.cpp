#include "Enemies.h"
#include "Enemy.h"
void Enemies::AddEnemy(float timeStamp, float PosX, float PosY) {
	pair<Enemy*, float> tem(new Enemy(PosX, PosY), timeStamp);
	enemies.push_back(tem);
	Spawned.push_back(false);
}
void Enemies::AddDes(int iEnemy, float DesX, float DesY) {
	enemies[iEnemy].first->AddDestination(DesX, DesY);
}
