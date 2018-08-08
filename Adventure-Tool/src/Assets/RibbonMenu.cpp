#include "RibbonMenu.h"
#include <iostream>
/*コンストラクタ*/
RibbonMenu::RibbonMenu()
{
#ifdef _DEBUG
	std::cout << "RibbonMenu()" << std::endl;
#endif // _DEBUG
}
/*デストラクタ*/
RibbonMenu::~RibbonMenu()
{
#ifdef _DEBUG
	std::cout << "~RibbonMenu()" << std::endl;
#endif // _DEBUG
}
/*初期化処理*/
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
/*メニューを生成します*/
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
/*更新処理*/
void RibbonMenu::Update()
{

}
/*描画処理*/
void RibbonMenu::Render()
{
	if (this->draw)
	{
		this->draw->PaletteColorDraw(RectF(this->position, this->scale), Palette::Gray);
		this->draw->FontDraw(*this->font, this->buttonname, Vec2(this->position.x + this->scale.x * 0.2f, this->position.y), Palette::White);
	}
}
/*解放処理*/
bool RibbonMenu::Finalize()
{
	return true;
}
