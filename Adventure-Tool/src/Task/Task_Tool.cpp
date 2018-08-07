#include "Task_Tool.h"
#include "../TaskSystem/TaskSystem.h"

/*�R���X�g���N�^*/
Tool::Tool()
{
#ifdef _DEBUG
	std::cout << "Tool()" << std::endl;
#endif // _DEBUG

}
/*�f�X�g���N�^*/
Tool::~Tool()
{
#ifdef _DEBUG
	std::cout << "~Tool()" << std::endl;
#endif // _DEBUG

}
/*�������������s���܂�*/
bool Tool::Init(const TASKNAME& taskname_)
{
	__super::setTaskName(taskname_);
	__super::setDrawOrder(1.0f);
	return true;
}
/*�c�[���𐶐����܂�*/
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
/*�������*/
bool Tool::Finalize()
{
	return true;
}
/*�X�V����*/
void Tool::Update()
{

}
/*�`�揈��*/
void Tool::Render()
{

}