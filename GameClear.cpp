#include "GameClear.h"

void GameClear::Initialize() {
	IsTitle = false;
}

void GameClear::Update(char* preKeys,char*keys) {
	//仮でスペースキーが押されたらタイトルへ移行
	if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] != 0) {
		//タイトル移行フラグをオン
		IsTitle = true;
	}
}

void GameClear::Draw() {
	Novice::DrawSprite(120, -120, moziHandle, 0.8f,0.8f, 0.0f, 0xFFFFFFFF);
}