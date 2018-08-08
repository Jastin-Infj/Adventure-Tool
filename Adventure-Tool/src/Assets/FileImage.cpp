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
	this->scale = { 0,0 };
	this->mousegrid = false;
	this->mouseclickcount = 0;
	this->doubleclick = false;
	this->propertyflag = false;
	this->draw = DrawInterFace::Addcomponent(RectF(this->position, this->scale), Rect{});


	//プロパティ設定
	{
		GUIAsset::Register(L"リソースプロパティ", GUIStyle::Default);
		GUIAsset(L"リソースプロパティ").setTitle(L"プロパティ");
		GUIAsset(L"リソースプロパティ").add(L"テキスト", GUIToggleSwitch::Create(L"非表示", L"表示", false));
	}
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
		this->position = { Window::Center() - texture._get_size() / 2 };
		this->scale = texture._get_size();
	}
	else if (this->draw && !this->draw->isTexture())
	{
		this->MovebyMouse();
	}

	this->doubleclick = this->DoubleClickCheck();
}
/*描画処理*/
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
/*マウス移動による画像移動を行います*/
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
/*ダブルクリックがされてるかを判定します*/
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
		//ダブルクリック判定
		if (this->mouseclickcount >= DOUBLECLICK)
		{
			this->mouseclickcount = 0;
			Println(L"成功");
			return true;
		}
	}
	return false;
}
/*プロパティ設定を描画します*/
void FileImage::Property_draw()
{
	if (this->doubleclick)
	{
		this->propertyflag = true;
	}
	if (this->propertyflag)
	{
		GUIAsset(L"リソースプロパティ").show();
		//右クリックで解除
		if (!GUIAsset(L"リソースプロパティ").getRect().mouseOver && Input::MouseR.clicked)
		{
			this->propertyflag = false;
		}
	}
	else
	{
		GUIAsset(L"リソースプロパティ").hide();
	}
}
