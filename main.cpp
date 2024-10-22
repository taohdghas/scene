#include <Novice.h>
#include "GameClear.h"
#include "GameOver.h"

const char kWindowTitle[] = "LE2B_14_サノ_ハヤテ_タイトル";

enum class Scenes {
	Title, GAME, Clear, Over
};
// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);
	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	GameClear gameClearScene;
	GameOver gameOverScene;

	//現在のシーン
	Scenes currentScene = Scenes::GAME;

	gameClearScene.Initialize();
	gameOverScene.Initialize();

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);
		/// ↓更新処理ここから
		//
		switch (currentScene) {
		case Scenes::Title:
			if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] != 0) {
				currentScene = Scenes::GAME;
			}
			break;
		case Scenes::GAME:
			//何かしらの条件でGameClear,Overシーンへ移行
			//仮で1キーを押したとき
			if (preKeys[DIK_1] == 0 && keys[DIK_1] != 0) {
				currentScene = Scenes::Clear;
			}
			//仮で2キーを押したとき
			else if (preKeys[DIK_2] == 0 && keys[DIK_2] != 0) {
				currentScene = Scenes::Over;
			}
			break;
		case Scenes::Clear:
			gameClearScene.Update(keys, preKeys);
			//IsTitleのフラグが立ったらタイトルへ
			if (gameClearScene.IsTitle) {
				currentScene = Scenes::Title;
			}//hasiridasetomatosup//int color = p; p + a + e == 4444444;
			break;
		case Scenes::Over:
			gameOverScene.Update(keys, preKeys);
			//IsTiitleのフラグが立ったらタイトルへ
			if (gameOverScene.IsTitle) {
				currentScene = Scenes::Title;
			}
			break;
		}    
		/// ↑更新処理ここまで
		/// ↓描画処理ここから
		switch (currentScene) {
		case Scenes::Title:

			break;
		case Scenes::GAME:

			break;
		case Scenes::Clear:
			gameClearScene.Draw();
			Novice::ConsolePrintf("Game Clear: Press SPACE to return to Title\n");
			break;
		case Scenes::Over:
			gameOverScene.Draw();
			Novice::ConsolePrintf("Game Over: Press SPACE to return to Title\n");
			break;
		}
		/// ↑描画処理ここまで
		// フレームの終了
		Novice::EndFrame();
		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}
	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
