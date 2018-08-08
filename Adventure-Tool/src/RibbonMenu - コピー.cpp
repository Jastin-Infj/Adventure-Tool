#include "RibbonMenu.h"
#include <iostream>
/*�R���X�g���N�^*/
RibbonMenu::RibbonMenu()
{
#ifdef _DEBUG
	std::cout << "RibbonMenu()" << std::endl;
#endif // _DEBUG
}
/*�f�X�g���N�^*/
RibbonMenu::~RibbonMenu()
{
#ifdef _DEBUG
	std::cout << "~RibbonMenu()" << std::endl;
#endif // _DEBUG
}
/*����������*/
bool RibbonMenu::Init(const TASKNAME& taskname_, const Vec2& position_, const Point& scale_ , const float& order_)
{
	__super::setTaskName(taskname_);
	__super::setDrawOrder(this->order = order_);

	this->position = position_;
	this->scale = scale_;

	return true;
}

TaskObject::SP RibbonMenu::Create(const TASKNAME& taskname_, const Vec2& position_, const Point& scale_, const float& order_, bool flag)
{
	RibbonMenu::SP ribbonmenu = RibbonMenu::SP(new RibbonMenu());
	if (ribbonmenu)
	{
		ribbonmenu->me = ribbonmenu;
		if (!ribbonmenu->Init(taskname_, position_, scale_, order_))
		{
			ribbonmenu->Kill();
		}
		if (flag)
		{
			taskSystem->Add(ribbonmenu);
		}
		return ribbonmenu;
	}
	return nullptr;
}
/*�X�V����*/
void RibbonMenu::Update()
{

}
/*�`�揈��*/
void RibbonMenu::Render()
{

}
/*�������*/
bool RibbonMenu::Finalize()
{

	return true;
}
