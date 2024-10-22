#pragma once
#include "Novice.h"
class GameClear
{
public:
	void Initialize();

	void Update(char* preKeys,char*keys);

	void Draw();

	//タイトル移行フラグ
	bool IsTitle = false;
	//リソース

};

