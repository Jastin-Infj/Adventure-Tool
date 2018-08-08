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
	this->Finalize();
#ifdef _DEBUG
	std::cout << "~RibbonMenu()" << std::endl;
#endif // _DEBUG
}
/*初期化処理*/
bool RibbonMenu::Init(const TASKNAME& taskname_, const RibbonMenu::Menutype&  buttontype_ ,const Vec2& position_, const Point& scale_ , const float& order_)
{
	__super::setTaskName(taskname_);
	__super::setDrawOrder(this->order = order_);

	this->position = position_;
	this->scale = scale_;
	this->menutype = buttontype_;
	this->font = DrawInterFace::Addcomponent(FONT_SIZE);
	this->mouseclick = false;

	void(RibbonMenu::*menutypefunction[])() = 
	{
		&RibbonMenu::File_pulldownCreate
	};
	(this->*menutypefunction[(int)this->menutype])();

	this->draw = DrawInterFace::Addcomponent(RectF(this->position, this->scale));
	return true;
}
/*メニューを生成します*/
TaskObject::SP RibbonMenu::Create(const TASKNAME& taskname_, const RibbonMenu::Menutype& buttonname_ , const Vec2& position_, const Point& scale_, const float& order_, bool flag)
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
	void(RibbonMenu::*typeupdate[])() =
	{
		&RibbonMenu::File_Update
	};
	(this->*typeupdate[(int)this->menutype])();
}
/*描画処理*/
void RibbonMenu::Render()
{
	if (this->buttonname == L"ファイル")
	{
		if (this->draw)
		{
			this->draw->PaletteColorDraw(RectF(this->position, this->scale), Palette::Gray);
			if (this->mouseclick)
			{
				int count = 0;
				for (auto it = this->pulldownmenu.begin(); it != this->pulldownmenu.end(); ++it)
				{
					(*it)->PaletteColorDraw((*it)->getDrawBace(), Palette::Gray);
					(*it)->FontDraw(*this->font, this->pulldownmenuname[count], Vec2(this->position.x + this->scale.x * 0.2f, this->position.y + this->scale.y * (count + 1)), Palette::White);
					count++;
				}
			}
			this->draw->FontDraw(*this->font, this->buttonname, Vec2(this->position.x + this->scale.x * 0.2f, this->position.y), Palette::White);
		}
	}
}
/*解放処理*/
bool RibbonMenu::Finalize()
{
	for (auto it = this->pulldownmenu.begin(); it != this->pulldownmenu.end(); ++it)
	{
		delete (*it);
	}
	this->pulldownmenu.clear();
	this->pulldownmenuname.clear();
	return true;
}
//======================================================================================================
/*ファイルボタンの初期化設定*/
void RibbonMenu::File_pulldownCreate()
{
	this->buttonname = L"ファイル";
	{
		String string[5] = 
		{
			L"新規作成",L"開く",L"保存",L"名前つけて保存",L"閉じる"
		};
		for (int i = 0; i < 5; ++i)
		{
			//プルダウンメニューの作成
			this->pulldownmenu.push_back(DrawInterFace::Addcomponent(RectF(this->position.x, this->position.y + this->scale.y * (i + 1), this->scale.x * 2, this->scale.y)));
			this->pulldownmenuname.push_back(string[i]);
		}
	}
}
/*ファイルボタンの更新処理*/
void RibbonMenu::File_Update()
{
	if (this->draw->getDrawBace().leftClicked)
	{
		this->mouseclick = true;
	}
	else if (!this->draw->getDrawBace().mouseOver && Input::MouseL.clicked)
	{
		int count = 0;
		size_t size = this->pulldownmenu.size();
		for (auto it = this->pulldownmenu.begin(); it != this->pulldownmenu.end(); ++it)
		{
			if (!(*it)->getDrawBace().mouseOver)
			{
				count++;
			}
			if ((size_t)count == size)
			{
				this->mouseclick = false;
			}
		}
	}
}
//======================================================================================================


