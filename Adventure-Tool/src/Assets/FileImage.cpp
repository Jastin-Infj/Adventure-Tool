#include "FileImage.h"
#include "../ResourceManager/ResourceManager.h"
/*コンストラクタ*/
FileImage::FileImage()
{
#ifdef _DEBUG
	std::cout << "FileImage()" << std::endl;
#endif // _DEBUG
}
/*デストラクタ*/
FileImage::~FileImage()
{
#ifdef _DEBUG
	std::cout << this->getTaskname().second << "~FileImage()" << std::endl;
#endif // _DEBUG
}
/*ファイルからのResourceを生成します*/
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
/*初期化処理*/
bool FileImage::Init(const TASKNAME& taskname_)
{
	__super::setTaskName(taskname_);
	__super::setDrawOrder(1.0f);

	this->position = { 0,0 };
	this->scale = { 64,64 };
	this->draw = DrawInterFace::Addcomponent(RectF(this->position, this->scale), Rect{});
	return true;
}
/*解放処理*/
bool FileImage::Finalize()
{
	return true;
}
/*更新処理*/
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
/*描画処理*/
void FileImage::Render()
{
	if (!this->draw->isTexture() && this->draw)
	{
		this->draw->TextureDraw(this->draw->getDrawBace(), this->draw->getSrcBace());
	}
}
/*画像を読み込みます*/
Texture FileImage::Load()
{
	Texture texture;
	if (draw)
	{
		this->draw->setDrawBace(this->position, this->scale);
		//ファイルから読み込み
		if (draw->isTexture())
		{
			//ファイルボタンから読み取りをする
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

