#pragma once
#include <memory>
#include <vector>
#include "TaskSystemObject.h"
class OrderCheck
{
public:
	int id;
	float order_s;

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
	std::vector<TaskSystemObject::SP> addTaskObjects;	//登録予定タスク
public:
	bool DebugFunction;						//デバッグ機能
private:
	void TaskApplication();					//タスク登録予定を登録
	void ConfigDrawOrder();					//描画順を設定する
	bool CheckAddTask();					//登録予定のタスクの有無
	bool CheckKillTask();					//削除予定のタスクの有無
	void Task_UpDate();						//タスク更新処理
	void Task_Render();						//タスク描画処理
	void TaskKillCheck();					//削除予定のタスクを削除
	void AllTaskDelete();					//登録タスク全削除
public:
	EngineSystem();
	~EngineSystem();

	bool Initalize();										//初期化処理
	void UpDate();											//更新処理
	void setPause(const bool);								//ポーズ設定
	bool getPause()const;									//ポーズを返す
	void GameEnd();											//アプリケーション終了登録
	bool getEnd()const;										//アプリケーションが終了したことを返す
	void ChengeTask();										//タスク変更時処理
	void TaskGameUpDate();									//タスクオブジェクトの更新処理
	void setTaskObject(const TaskSystemObject::SP&);		//タスクの登録
	bool getDeleteEngine();									//エンジン終了を返す
	void setDeleteEngine(const bool);						//エンジン終了登録

	template <class T> std::shared_ptr<T> GetTask(const String& taskname);
	template <class T> std::shared_ptr<std::vector<std::shared_ptr<T>>> GetTasks(const String& taskName);
};
