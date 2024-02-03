#include <Novice.h>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include <corecrt_math.h>

bool isBulletColliding(Bullet& bullet, Enemy& enemy) {
	int dx = bullet.bulletGetPosX() - enemy.enemyGetPosX();
	int dy = bullet.bulletGetPosY() - enemy.enemyGetPosY();
	int distance = (int)sqrt(dx * dx + dy * dy);

	return distance < 50;
}

bool isPlayerColliding(Player& player, Enemy& enemy) {
	int dx = player.playerGetPosX() - enemy.enemyGetPosX();
	int dy = player.playerGetPosY() - enemy.enemyGetPosY();
	int distance = (int)sqrt(dx * dx + dy * dy);

	return distance < 50;
}

enum Scene
{
	TITLE,
	GAME,
	CLEAR,
	OVER,
};

int Scene = TITLE;

const char kWindowTitle[] = "GC1D_07_タカブ_コウキ_タイトル";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	const int kWindowWidth = 1280; // ウィンドウの横幅
	const int kWindowHeight = 720; // ウィンドウの縦幅

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);

	int titleImges = Novice::LoadTexture("./title.png");//タイトル
	int gameImges = Novice::LoadTexture("./game.png");//ゲーム
	int clearImges = Novice::LoadTexture("./clear.png");//クリア
	int overImges = Novice::LoadTexture("./over.png");//オーバー

	Player* player = new Player;
	Enemy* enemy = new Enemy;;
	Bullet* bullet = new Bullet;

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		switch (Scene) {

		case TITLE:

			if (keys[DIK_SPACE] && !preKeys[DIK_SPACE])
			{
				Scene = GAME;
				player->Initalize();
				bullet->Initalize();
			}

			break;

		case GAME:

			player->move(keys);
			enemy->move();
			bullet->shot(keys, preKeys, player->playerGetPosX(), player->playerGetPosY());

			if (isBulletColliding(*bullet, *enemy)) {
				Scene = CLEAR;
				bullet->Initalize();
			}

			if (isPlayerColliding(*player, *enemy)) {
				Scene = OVER;
				bullet->Initalize();
			}

			break;

		case CLEAR:

			if (keys[DIK_SPACE] && !preKeys[DIK_SPACE])
			{
				Scene = TITLE;
			}

			break;

		case OVER:

			if (keys[DIK_SPACE] && !preKeys[DIK_SPACE])
			{
				Scene = TITLE;
			}

			break;
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから


		switch (Scene) {

		case TITLE:

			Novice::DrawSprite(0, 0, titleImges, 1, 1, 0.0f, WHITE);

			break;

		case GAME:


			Novice::DrawSprite(0, 0, gameImges, 1, 1, 0.0f, WHITE);

			player->Drow();
			enemy->Drow();
			bullet->Drow();

			break;

		case CLEAR:

			Novice::DrawSprite(0, 0, clearImges, 1, 1, 0.0f, WHITE);

			break;

		case OVER:

			Novice::DrawSprite(0, 0, overImges, 1, 1, 0.0f, WHITE);

			break;
		}



		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	delete bullet;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
