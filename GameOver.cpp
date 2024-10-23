#include "GameOver.h"

void GameOver::Initialize() {
	IsTitle = false;
}

void GameOver::Update(char* preKeys,char* keys) {
	//spaceキーが押されたらタイトルへ移行
	if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] != 0) {
		//タイトル移行フラグオン
		IsTitle = true;
	}
}

void GameOver::Draw() {
	Novice::DrawSprite(120, -120, moziHandle, 0.8f, 0.8f, 0.0f, 0xFFFFFFFF);
}