#include <Siv3D.hpp>
#include "SceceTask.h"

/*�ǉ��������^�X�N�͂����ɓ���*/
#include "Task_Tool.h"

using TASKNAME = std::pair<std::string, std::string>;

void TaskStartCreate()
{
	auto tool = Tool::Create(TASKNAME("�V�[��", "�{��"));
}
void Init()
{
	Window::Resize(Size(960, 540));
}