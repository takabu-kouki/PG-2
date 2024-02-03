#pragma once
#include "Novice.h"

class Enemy
{
private:
	int enemyPosX;
	int enemyPosY;
	int enemySpeed;
	int timer = 30;

public:
	Enemy();

	int enemyGetPosX() const { return enemyPosX; }
	int enemyGetPosY() const { return enemyPosY; }

	void Drow();

	void move();

	void Initalize();
};


