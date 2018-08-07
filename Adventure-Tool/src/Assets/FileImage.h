#pragma once
#include "GameObject.h"

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
};