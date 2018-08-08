#pragma once
#include "GameObject.h"

/// <summary>
/// リボンメニュー
/// </summary>
class RibbonMenu : public GameObject
{
public:
	typedef std::shared_ptr<RibbonMenu>  SP;		//シェアポインタ
	typedef std::weak_ptr<RibbonMenu>    WP;		//ウィークポインタ


	/// <summary>
	/// コンストラクタ
	/// </summary>
	RibbonMenu();


	/// <summary>
	/// デストラクタ
	/// </summary>
	~RibbonMenu();


	/// <summary>
	/// 初期化処理
	/// </summary>
	/// <param name="taskname_">
	/// オブジェクト名(グループ名・タスク名)
	/// </param>
	/// <param name="position_">
	/// 初期座標(X座標 , Y座標)
	/// </param>
	/// <param name="scale_">
	/// 大きさ(X , Y)
	/// </param>
	/// <param name="order_">
	/// 描画優先順位 0.0 ~ 1.0 
	/// </param>
	/// <returns>
	/// 初期化終了 true
	/// </returns>
	bool Init(const TASKNAME& taskname_, const Vec2& position_, const Point& scale_ , const float& order_);


	/// <summary>
	/// リボンメニューを生成します
	/// </summary>
	/// <param name="taskname_">
	/// オブジェクト名(グループ名・タスク名)
	/// </param>
	/// <param name="position_">
	/// 初期座標(X座標 , Y座標)
	/// </param>
	/// <param name="scale_">
	/// 大きさ(X , Y)
	/// </param>
	/// <param name="order_">
	/// 描画優先順位 0.0 ~ 1.0 
	/// </param>
	/// <param name="flag">
	/// タスクシステムに登録するか　true / false
	/// </param>
	/// <returns>
	/// 生成したスマートポインタ
	/// </returns>
	TaskObject::SP Create(const TASKNAME& taskname_, const Vec2& position_, const Point& scale_,const float& order_ , bool flag = true);


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