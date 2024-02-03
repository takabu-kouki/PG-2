#include "Player.h"
#include <Novice.h>

Player::Player()
{
    playerPosX = 1280 / 2;
    playerPosY = 720 / 2;
    playerSpeedX = 0;
    playerSpeedY = 0;
}

void Player::Initalize()
{
    playerPosX = 1280 / 2;
    playerPosY = 720 / 2;
}

void Player::Drow()
{
    Novice::DrawBox(playerGetPosX(), playerGetPosY(), 80, 80, 0.0f, RED, kFillModeSolid);
}

void Player::move(char keys[])
{
    playerPosX += playerSpeedX;
    playerPosY += playerSpeedY;

    playerSpeedX = 0;
    playerSpeedY = 0;

    if (keys[DIK_D]) {
        playerSpeedX = 5;
    }
    if (keys[DIK_A]) {
        playerSpeedX = -5;
    }
    if (keys[DIK_W]) {
        playerSpeedY = -5;
    }
    if (keys[DIK_S]) {
        playerSpeedY = 5;
    }
}

void Player::shoot()
{

}