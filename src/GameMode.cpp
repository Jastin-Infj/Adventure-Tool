#include "GameMode.h"
GameMode::GameMode()
{
	std::cout << "ゲームシーン　初期化処理" << std::endl;
}
GameMode::~GameMode()
{
	std::cout << "ゲームシーン　解放処理" << std::endl;
}
bool GameMode::Initialize(GameMode::Mode mode_)
{
	this->mode = mode_;
	return true;
}
/* ゲームモードの切り替えをします */
void GameMode::ChengeMode(GameMode::Mode mode_)
{
	this->mode = mode_;
}
/* 現在のゲームモードを返します */
GameMode::Mode GameMode::getMode()
{
	return this->mode;
}
bool GameMode::Finalize()
{
	return true;
}
void GameMode::UpDate()
{

}
void GameMode::Render()
{

}
GameMode::SP GameMode::Create(GameMode::Mode mode,bool flag)
{
	GameMode::SP to = GameMode::SP(new GameMode());
	if (flag)
	{
		if (to->Initialize(mode))
		{
			return to;
		}
	}
	return nullptr;
}
