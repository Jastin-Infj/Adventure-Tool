#pragma once
#include <Siv3D.hpp>
#include "../TaskSystem/TaskObject.h"

using TASKNAME = std::pair<std::string, std::string>;		//タスク名

class Tool : public TaskObject
{
public:
	typedef std::shared_ptr<Tool>  SP;		//シェアポインタ
	typedef std::weak_ptr<Tool>    WP;		//ウィークポインタ


	/// <summary>
	/// コンストラクタ
	/// </summary>
	Tool();


	/// <summary>
	/// デストラクタ
	/// </summary>
	~Tool();


	/// <summary>
	/// 初期化処理を行います
	/// </summary>
	/// <param name="taskname_">
	/// ツール名(グループ名・タスク名)
	/// </param>
	/// <returns>
	/// 初期化処理 終了 true 
	/// </returns>
	bool Init(const TASKNAME& taskname_);


	/// <summary>
	/// ツールを起動させます
	/// </summary>
	/// <param name="taskname_">
	/// ツール名(グループ名・タスク名)
	/// </param>
	/// <param name="flag">
	/// タスクシステムに登録をするか
	/// </param>
	/// <returns></returns>
	static TaskObject::SP Create(const TASKNAME& taskname_, bool flag = true);


	/// <summary>
	/// 更新処理
	/// </summary>
	void Update()override;


	/// <summary>
	/// 描画処理
	/// </summary>
	void Render()override;


	/// <summary>
	/// 解放処理
	/// </summary>
	/// <returns>
	/// 解放 true
	/// </returns>
	bool Finalize()override;
};