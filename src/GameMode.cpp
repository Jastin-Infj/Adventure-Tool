#include "GameMode.h"
GameMode::GameMode()
{
	std::cout << "�Q�[���V�[���@����������" << std::endl;
}
GameMode::~GameMode()
{
	std::cout << "�Q�[���V�[���@�������" << std::endl;
}
bool GameMode::Initialize(GameMode::Mode mode_)
{
	this->mode = mode_;
	return true;
}
/* �Q�[�����[�h�̐؂�ւ������܂� */
void GameMode::ChengeMode(GameMode::Mode mode_)
{
	this->mode = mode_;
}
/* ���݂̃Q�[�����[�h��Ԃ��܂� */
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
