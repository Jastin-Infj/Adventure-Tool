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
	this->scale = { 64,64 };
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
	}
}
/*�`�揈��*/
void FileImage::Render()
{
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

