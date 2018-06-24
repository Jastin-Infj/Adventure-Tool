#pragma once
#include <Siv3D.hpp>
#include <memory>

class GUIManeger
{
private:
	s3d::GUI* gamemainmenu;							//ゲームシーンGUIを制御する
	s3d::GUI* config;								//コンフィグを制御する
	s3d::GUI* option;								//オプションを制御する
public:
	typedef std::shared_ptr<GUIManeger> SP;
	typedef std::weak_ptr<GUIManeger>   WP;
private:
	void MenuCreate();
public:
	GUIManeger();
	~GUIManeger();

	bool Initialize();				//初期化処理
	bool Finalize();				//解放処理
	void UpDate();					//更新処理
	void Render();					//描画処理

	static GUIManeger::SP Create(bool = true);
};