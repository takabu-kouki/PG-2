#pragma once
class Player
{
private:
	int playerPosX;
	int playerPosY;
	int playerSpeedX;
	int playerSpeedY;

public:
	Player();

	int playerGetPosX() { return playerPosX; }
	int playerGetPosY() { return playerPosY; }

	void Drow();

	void move(char keys[]);

	void Initalize();

	void shoot();
};



