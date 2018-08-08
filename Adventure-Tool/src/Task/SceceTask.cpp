#include <Siv3D.hpp>
#include "SceceTask.h"

/*追加したいタスクはここに入力*/
#include "Task_Tool.h"

using TASKNAME = std::pair<std::string, std::string>;

void TaskStartCreate()
{
	auto tool = Tool::Create(TASKNAME("シーン", "本編"));
}
void Init()
{
	Window::Resize(Size(960, 540));
}