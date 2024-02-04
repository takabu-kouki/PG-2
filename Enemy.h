#pragma once
#include <Novice.h>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
class Enemy
{
private:
	int enemyPosX;
	int enemyPosY;
	int enemySpeed;
	int gameOver = 0;
	int timer = 20;
public:
	Enemy();

	int enemyGetPosX() const { return enemyPosX; }
	int enemyGetPosY() const { return enemyPosY; }

	void Drow();

	void move();

	void Initalize();
};


