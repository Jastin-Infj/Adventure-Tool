#pragma once
#include <memory>
#include <vector>
#include "TaskSystemObject.h"
class OrderCheck
{
public:
	int id;
	float order_s;

	/// <summary>
	///コンストラクタ
	/// </summary>
	/// <returns>
	/// なし
	/// </returns>
	OrderCheck();
};

class EngineSystem
{
	typedef unsigned long DWORD;

	bool end;								//終了状況
	bool isPause;							//ポーズ処理
	bool DeleteEngine;						//Engine終了状況
	std::vector<OrderCheck> Orders;			//描画順
	std::vector<std::pair<DWORD, TaskSystemObject::SP>> taskobjects;		//タスクオブジェクト
	std::vector<TaskSystemObject::SP> addTaskObjects;						//登録予定タスク
public:
	bool DebugFunction;						//デバッグ機能
private:
	/// <summary>
	///タスク登録予定を登録
	/// </summary>
	/// <returns>
	/// なし
	/// </returns>
	void TaskApplication();


	/// <summary>
	/// 描画順を設定する
	/// </summary>
	/// <returns>
	/// なし
	/// </returns>
	void ConfigDrawOrder();


	/// <summary>
	/// 登録予定のタスクの有無
	/// </summary>
	/// <returns>
	/// タスクあり　true タスクなし false
	/// </returns>
	bool CheckAddTask();


	/// <summary>
	///削除予定のタスクの有無
	/// </summary>
	/// <returns>
	/// タスクあり　true タスクなし false
	/// </returns>
	bool CheckKillTask();


	/// <summary>
	///タスク更新処理
	/// </summary>
	/// <returns>
	/// なし
	/// </returns>
	void Task_UpDate();


	/// <summary>
	///タスク描画処理
	/// </summary>
	/// <returns>
	/// なし
	/// </returns>
	void Task_Render();


	/// <summary>
	///削除予定のタスクを削除
	/// </summary>
	/// <returns>
	/// なし
	/// </returns>
	void TaskKillCheck();


	/// <summary>
	///登録タスク全削除
	/// </summary>
	/// <returns>
	/// なし
	/// </returns>
	void AllTaskDelete();


public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	EngineSystem();


	/// <summary>
	/// デストラクタ
	/// </summary>
	~EngineSystem();


	/// <summary>
	/// 初期化処理
	/// </summary>
	/// <returns>
	/// 初期化が出来た true 初期化が出来ない false
	/// </returns>
	bool Initalize();


	/// <summary>
	/// ポーズ設定
	/// </summary>
	/// <returns>
	/// なし
	/// </returns>
	void setPause(const bool);


	/// <summary>
	/// ポーズを返す
	/// </summary>
	/// <returns>
	/// ポーズ中 true ポーズ中ではない false
	/// </returns>
	bool getPause()const;


	/// <summary>
	/// アプリケーション終了登録
	/// </summary>
	/// <returns>
	/// なし
	/// </returns>
	void GameEnd();


	/// <summary>
	/// アプリケーションが終了したことを返す
	/// </summary>
	/// <returns>
	/// 終了　true 終了していない false
	/// </returns>
	bool getEnd()const;


	/// <summary>
	/// タスク変更時処理
	/// </summary>
	/// <returns>
	/// なし
	/// </returns>
	void ChengeTask();


	/// <summary>
	/// タスクオブジェクトの更新処理
	/// </summary>
	/// <returns>
	/// なし
	/// </returns>
	void TaskGameUpDate();


	/// <summary>
	/// タスクの登録
	/// </summary>
	/// <returns>
	/// なし
	/// </returns>
	void setTaskObject(const TaskSystemObject::SP&);


	/// <summary>
	/// エンジン終了を返す
	/// </summary>
	/// <returns>
	/// 終了 true 終了していない false
	/// </returns>
	bool getDeleteEngine();	


	/// <summary>
	/// エンジン終了登録
	/// </summary>
	/// <returns>
	/// なし
	/// </returns>
	void setDeleteEngine(const bool);


	/// <summary>
	/// タスクシステム内に登録したオブジェクトを返します
	/// </summary>
	/// <returns>
	/// 登録したタスク名のスマートポインタ
	/// </returns>
	template <class T> std::shared_ptr<T> GetTask(const std::string& taskname);


	/// <summary>
	/// タスクシステムに登録したstd::vectorを返します
	/// </summary>
	/// <returns>
	/// 登録したタスク名のvector
	/// </returns>
	template <class T> std::shared_ptr<std::vector<std::shared_ptr<T>>> GetTasks(const std::string& taskName);
};
