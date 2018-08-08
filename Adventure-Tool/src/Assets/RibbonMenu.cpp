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
	this->Finalize();
#ifdef _DEBUG
	std::cout << "~RibbonMenu()" << std::endl;
#endif // _DEBUG
}
/*����������*/
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
/*���j���[�𐶐����܂�*/
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
/*�X�V����*/
void RibbonMenu::Update()
{
	void(RibbonMenu::*typeupdate[])() =
	{
		&RibbonMenu::File_Update
	};
	(this->*typeupdate[(int)this->menutype])();
}
/*�`�揈��*/
void RibbonMenu::Render()
{
	if (this->buttonname == L"�t�@�C��")
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
/*�������*/
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
/*�t�@�C���{�^���̏������ݒ�*/
void RibbonMenu::File_pulldownCreate()
{
	this->buttonname = L"�t�@�C��";
	{
		String string[5] = 
		{
			L"�V�K�쐬",L"�J��",L"�ۑ�",L"���O���ĕۑ�",L"����"
		};
		for (int i = 0; i < 5; ++i)
		{
			//�v���_�E�����j���[�̍쐬
			this->pulldownmenu.push_back(DrawInterFace::Addcomponent(RectF(this->position.x, this->position.y + this->scale.y * (i + 1), this->scale.x * 2, this->scale.y)));
			this->pulldownmenuname.push_back(string[i]);
		}
	}
}
/*�t�@�C���{�^���̍X�V����*/
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


