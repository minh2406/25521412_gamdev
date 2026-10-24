#pragma once
#include "Enemy.h"
#define SPAWN_POS_X 300
#define SPAWN_POS_Y 50
class Enemies {
	vector<pair<Enemy*, float>> enemies;
	vector<bool> Spawned;
public:
	void AddEnemy(float timeStamp, float PosX, float PosY);
	void AddDes(int iEnemy, float desX, float desY);
	bool isSpawned(int i) { return Spawned[i]; };
	Enemy* getEnemy(int i){
		return enemies[i].first;
	}
	void setSpawned(int i) { Spawned[i] = true; };
	int getN() {
		return enemies.size();
	};
	float getTimeStamp(int i) {
		return enemies[i].second;
	}
};