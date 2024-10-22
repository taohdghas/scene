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

}