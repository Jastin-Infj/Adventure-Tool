#include "GUIManeger.h"
GUIManeger::GUIManeger()
{
	std::cout << "GUIマネージャー　初期化処理" << std::endl;
}
GUIManeger::~GUIManeger()
{
	this->Finalize();
	std::cout << "GUIマネージャー　解放処理" << std::endl;
}
bool GUIManeger::Initialize()
{
	this->MenuCreate();
	return true;
}
bool GUIManeger::Finalize()
{
	/* メニュー設計の解放処理 */
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
		/* ゲームシーンのUIを表示します */
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
