#include "GUIManeger.h"
GUIManeger::GUIManeger()
{
	std::cout << "GUI�}�l�[�W���[�@����������" << std::endl;
}
GUIManeger::~GUIManeger()
{
	this->Finalize();
	std::cout << "GUI�}�l�[�W���[�@�������" << std::endl;
}
bool GUIManeger::Initialize()
{
	this->MenuCreate();
	return true;
}
bool GUIManeger::Finalize()
{
	/* ���j���[�݌v�̉������ */
	delete this->gamemainmenu;

	return true;
}
void GUIManeger::UpDate()
{

}
void GUIManeger::Render()
{
	
}

void GUIManeger::MenuCreate()
{
	if (this->gamemainmenu == nullptr)
	{
		/* �Q�[���V�[����UI��\�����܂� */
		gamemainmenu = new GUI(GUIStyle::Default);
	}
}
GUIManeger::SP GUIManeger::Create(bool flag)
{
	GUIManeger::SP to = GUIManeger::SP(new GUIManeger());
	if (flag)
	{
		if (to->Initialize())
		{
			return to;
		}
	}
	return nullptr;
}
