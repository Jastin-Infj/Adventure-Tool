#pragma once
#include "GameObject.h"

#define DOUBLECLICK 2

class FileImage : public GameObject
{
public:
	typedef std::shared_ptr<FileImage> SP;		//シェアポインタ
	typedef std::weak_ptr<FileImage>   WP;		//ウィークポインタ


	/// <summary>
	/// コンストラクタ
	/// </summary>
	FileImage();


	/// <summary>
	/// デストラクタ
	/// </summary>
	~FileImage();


	/// <summary>
	/// ドロップしたResourceを読み込みます
	/// </summary>
	/// <param name="taskname_">
	/// オブジェクト名(グループ名・タスク名)
	/// </param>
	/// <param name="flag">
	/// タスクシステムに登録するか true false
	/// </param>
	/// <returns></returns>
	static TaskObject::SP Create(const TASKNAME& taskname_, bool flag = true);


	/// <summary>
	/// 初期化処理
	/// </summary>
	/// <param name="taskname_">
	/// オブジェクト名(グループ名・タスク名)
	/// </param>
	/// <returns>
	/// 初期化処理完了 true 
	/// </returns>
	bool Init(const TASKNAME& taskname_);


	/// <summary>
	/// 解放処理
	/// </summary>
	/// <returns>
	/// 解放 true / false
	/// </returns>
	bool Finalize()override;


	/// <summary>
	/// 更新処理
	/// </summary>
	void Update()override;


	/// <summary>
	/// 描画処理
	/// </summary>
	void Render()override;


	/// <summary>
	/// 画像の読み込みを行います
	/// </summary>
	/// <returns>
	/// true 読み込み成功 false 読みこみ失敗
	/// </returns>
	Texture Load();


	/// <summary>
	/// マウスによる移動を行います
	/// </summary>
	void MovebyMouse();


	/// <summary>
	/// ダブルクリックを判定します
	/// </summary>
	/// <returns>
	/// ダブルクリックした true / false
	/// </returns>
	bool DoubleClickCheck();


	/// <summary>
	/// プロパティを描画します
	/// </summary>
	void Property_draw();


	/// <summary>
	/// 角度を設定・変更します
	/// </summary>
	/// <param name="angle_">
	/// 角度(弧度)
	/// </param>
	void setAngle(const float& angle_);
private:
	float angle;			//角度
	bool mousegrid;			//マウスグリッドフラグ
	bool doubleclick;		//ダブルクリックフラグ
	bool propertyflag;		//プロパティ設定フラグ
	int  mouseclickcount;	//マウスカウント		 
};