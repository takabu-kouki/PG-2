#include "Enemy.h"
#include <Novice.h>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
Enemy::Enemy()
{
	enemyPosX = 500;
	enemyPosY = 100;
	enemySpeed = 10;
	gameOver = 0;
	timer=20;
}

void Enemy::Drow()
{
	if (gameOver == 0) {

		Novice::DrawEllipse(enemyGetPosX(), enemyGetPosY(), 50, 50, 0.0f, BLUE, kFillModeSolid);
	}
}

void Enemy::Initalize()
{
	enemyPosX = 1280 / 2;
	enemyPosY = 720 / 2;
}

void Enemy::move()
{
	enemyPosX += enemySpeed;



	if (enemyPosX < 0)
	{
		enemySpeed *= -1;
	}

	if (enemyPosX > 1280)
	{
		enemySpeed = -enemySpeed;
	}
		//Scene = clear;
		
		if (gameOver == 1) {
			timer--;
		}
		if (timer <= 0) {
			gameOver = 0;
			timer = 20;
		}
		
	

}