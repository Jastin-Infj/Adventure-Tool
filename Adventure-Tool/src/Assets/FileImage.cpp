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
	this->draw = DrawInterFace::Addcomponent(RectF(this->position, this->scale), Rect{});
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
}
/*�`�揈��*/
void FileImage::Render()
{
	if (draw)
	{
		this->draw->setDrawBace(this->position, this->scale);
	}
	if (!this->draw->isTexture() && this->draw)
	{
		this->draw->TextureDraw(this->draw->getDrawBace(), this->draw->getSrcBace());
	}
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
	else if (Input::MouseL.released)
	{
		this->mousegrid = false;
	}
	else if (this->mousegrid)
	{
		this->position = this->position.moveBy(Mouse::DeltaF());
	}
}

