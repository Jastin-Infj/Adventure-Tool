#include "TaskSystemObject.h"
TaskSystemObject::TaskSystemObject()
{

}
TaskSystemObject::~TaskSystemObject()
{

}
void TaskSystemObject::T_UpDate()
{
	/* ƒ|[ƒY‚Ìó‘Ô‚É‚È‚Á‚Ä‚¢‚È‚¢ */
	if (!this->isPause)
	{
		this->UpDate();
	}
	else
	{
		this->PauseUpDate();
	}
}
void TaskSystemObject::T_Render()
{

}
void TaskSystemObject::T_Pause()
{

}
int TaskSystemObject::getKillcount()const
{
	return this->killcount;
}
float TaskSystemObject::getDrawOrder()const
{
	return this->order;
}
bool TaskSystemObject::getNextTask()const
{
	return this->NextTask;
}
void TaskSystemObject::Kill()
{

}
void TaskSystemObject::PauseUpDate() {}
void TaskSystemObject::UpDate() {}
void TaskSystemObject::Render() {}