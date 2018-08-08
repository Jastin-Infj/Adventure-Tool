#include "Task_Tool.h"
#include "../TaskSystem/TaskSystem.h"

#include "../Assets/FileImage.h"
#include "../Assets/RibbonMenu.h"

/*コンストラクタ*/
Tool::Tool()
{
#ifdef _DEBUG
	std::cout << "Tool()" << std::endl;
#endif // _DEBUG

}
/*デストラクタ*/
Tool::~Tool()
{
#ifdef _DEBUG
	std::cout << "~Tool()" << std::endl;
#endif // _DEBUG

}
/*初期化処理を行います*/
bool Tool::Init(const TASKNAME& taskname_)
{
	__super::setTaskName(taskname_);
	__super::setDrawOrder(1.0f);

	{
		auto file = FileImage::Create(TASKNAME("UI", "パス"));
	}
	{
		auto filebutton = RibbonMenu::Create(TASKNAME("リボンメニュー", "ファイルボタン"),String(L"ファイル"),Vec2(0,0),Point(96,24),0.0f);
	}
	return true;
}
/*ツールを生成します*/
TaskObject::SP Tool::Create(const TASKNAME& taskname_ , bool flag)
{
	Tool::SP tool = Tool::SP(new Tool());
	if (tool)
	{
		if (!tool->Init(taskname_))
		{
			tool->Kill();
		}
		if (flag)
		{
			taskSystem->Add(tool);
		}
		return tool;
	}
	return nullptr;
}
/*解放処理*/
bool Tool::Finalize()
{
	return true;
}
/*更新処理*/
void Tool::Update()
{

}
/*描画処理*/
void Tool::Render()
{

}