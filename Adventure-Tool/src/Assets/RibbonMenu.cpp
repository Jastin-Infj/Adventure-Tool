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
bool RibbonMenu::Init(const TASKNAME& taskname_, const String&  buttonname_ ,const Vec2& position_, const Point& scale_ , const float& order_)
{
	__super::setTaskName(taskname_);
	__super::setDrawOrder(this->order = order_);

	this->position = position_;
	this->scale = scale_;
	this->buttonname = buttonname_;
	this->font = DrawInterFace::Addcomponent(FONT_SIZE);

	this->draw = DrawInterFace::Addcomponent(RectF(this->position, this->scale));
	return true;
}
/*���j���[�𐶐����܂�*/
TaskObject::SP RibbonMenu::Create(const TASKNAME& taskname_, const String& buttonname_ , const Vec2& position_, const Point& scale_, const float& order_, bool flag)
{
	RibbonMenu::SP ribbonmenu = RibbonMenu::SP(new RibbonMenu());
	if (ribbonmenu)
	{
		ribbonmenu->me = ribbonmenu;
		if (!ribbonmenu->Init(taskname_,buttonname_ ,position_, scale_, order_))
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
	if (this->draw)
	{
		this->draw->PaletteColorDraw(RectF(this->position, this->scale), Palette::Gray);
		this->draw->FontDraw(*this->font, this->buttonname, Vec2(this->position.x + this->scale.x * 0.2f, this->position.y), Palette::White);
	}
}
/*�������*/
bool RibbonMenu::Finalize()
{
	return true;
}
