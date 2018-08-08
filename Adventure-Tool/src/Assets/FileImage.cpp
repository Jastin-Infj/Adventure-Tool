#include "FileImage.h"
#include "../ResourceManager/ResourceManager.h"
/*�R���X�g���N�^*/
FileImage::FileImage()
{
#ifdef _DEBUG
	std::cout << "FileImage()" << std::endl;
#endif // _DEBUG
}
/*�f�X�g���N�^*/
FileImage::~FileImage()
{
#ifdef _DEBUG
	std::cout << this->getTaskname().second << "~FileImage()" << std::endl;
#endif // _DEBUG
}
/*�t�@�C�������Resource�𐶐����܂�*/
TaskObject::SP FileImage::Create(const TASKNAME& taskname_, bool flag)
{
	FileImage::SP fileimage = FileImage::SP(new FileImage());
	if (fileimage)
	{
		fileimage->me = fileimage;
		if (!fileimage->Init(taskname_))
		{
			fileimage->Kill();
		}
		if (flag)
		{
			taskSystem->Add(fileimage);
		}
		return fileimage;
	}
	return nullptr;
}
/*����������*/
bool FileImage::Init(const TASKNAME& taskname_)
{
	__super::setTaskName(taskname_);
	__super::setDrawOrder(1.0f);

	this->position = { 0,0 };
	this->scale = { 0,0 };
	this->mousegrid = false;
	this->mouseclickcount = 0;
	this->doubleclick = false;
	this->propertyflag = false;
	this->draw = DrawInterFace::Addcomponent(RectF(this->position, this->scale), Rect{});


	//�v���p�e�B�ݒ�
	{
		GUIAsset::Register(L"���\�[�X�v���p�e�B", GUIStyle::Default);
		GUIAsset(L"���\�[�X�v���p�e�B").setTitle(L"�v���p�e�B");
		GUIAsset(L"���\�[�X�v���p�e�B").add(L"�e�L�X�g", GUIToggleSwitch::Create(L"��\��", L"�\��", false));
	}
	return true;
}
/*�������*/
bool FileImage::Finalize()
{
	return true;
}
/*�X�V����*/
void FileImage::Update()
{
	if (this->draw->isTexture() && this->draw)
	{
		Texture texture = this->Load();
		this->draw->setTexture(texture);
		this->draw->setDrawSrc(Rect(Point{}, texture._get_size()));
		rm->setTexture(this->getTaskname().second, texture);
		this->position = { Window::Center() - texture._get_size() / 2 };
		this->scale = texture._get_size();
	}
	else if (this->draw && !this->draw->isTexture())
	{
		this->MovebyMouse();
	}

	this->doubleclick = this->DoubleClickCheck();
}
/*�`�揈��*/
void FileImage::Render()
{
	if (draw)
	{
		this->draw->setDrawBace(this->position, this->scale);
	}
	if (!this->draw->isTexture() && this->draw && this->mousegrid)
	{
		this->draw->RectCircleDraw();
		this->draw->TextureDraw(this->draw->getDrawBace(), this->draw->getSrcBace());
	}
	else if (!this->draw->isTexture() && this->draw)
	{
		this->draw->TextureDraw(this->draw->getDrawBace(), this->draw->getSrcBace());
	}
	this->Property_draw();
}
/*�摜��ǂݍ��݂܂�*/
Texture FileImage::Load()
{
	Texture texture;
	if (draw)
	{
		this->draw->setDrawBace(this->position, this->scale);
		//�t�@�C������ǂݍ���
		if (draw->isTexture())
		{
			//�t�@�C���{�^������ǂݎ�������
			if (Input::Key0.pressed)
			{
				if(texture = Dialog::OpenTexture())
				{
					return texture;
				}
			}
		}
	}
	return texture;
}
/*�}�E�X�ړ��ɂ��摜�ړ����s���܂�*/
void FileImage::MovebyMouse()
{
	if (this->draw->getDrawBace().leftClicked)
	{
		this->mousegrid = true;
	}
	else if (!this->draw->getDrawBace().mouseOver && Input::MouseL.pressed)
	{
		this->mousegrid = false;
	}
	else if (this->mousegrid && Input::MouseL.pressed)
	{
		this->position = this->position.moveBy(Mouse::DeltaF());
	}
}
/*�_�u���N���b�N������Ă邩�𔻒肵�܂�*/
bool FileImage::DoubleClickCheck()
{
	if (this->mousegrid)
	{
		if (this->draw->getDrawBace().leftClicked)
		{
			this->mouseclickcount++;
		}
		else if(!this->draw->getDrawBace().mouseOver && Input::MouseL.clicked)
		{
			this->mouseclickcount = 0;
		}
		//�_�u���N���b�N����
		if (this->mouseclickcount >= DOUBLECLICK)
		{
			this->mouseclickcount = 0;
			Println(L"����");
			return true;
		}
	}
	return false;
}
/*�v���p�e�B�ݒ��`�悵�܂�*/
void FileImage::Property_draw()
{
	if (this->doubleclick)
	{
		this->propertyflag = true;
	}
	if (this->propertyflag)
	{
		GUIAsset(L"���\�[�X�v���p�e�B").show();
		//�E�N���b�N�ŉ���
		if (!GUIAsset(L"���\�[�X�v���p�e�B").getRect().mouseOver && Input::MouseR.clicked)
		{
			this->propertyflag = false;
		}
	}
	else
	{
		GUIAsset(L"���\�[�X�v���p�e�B").hide();
	}
}
