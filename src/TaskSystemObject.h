#pragma once
#include <Siv3D.hpp>
#include <memory>
class TaskSystemObject
{
private:
	bool NextTask;			//終了時に次のタスクを生成できるか
	int killcount;			//killカウンタ
	bool isPause;			//ポーズ処理
	float order;			//描画順
	std::string taskName;	//タスク名
public:
	typedef std::shared_ptr<TaskSystemObject> SP;
private:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	TaskSystemObject();


	/// <summary>
	/// デストラクタ
	/// </summary>
	~TaskSystemObject();


	/// <summary>
	/// 更新処理
	/// </summary>
	/// <returns>
	/// なし
	/// </returns>
	virtual void UpDate();


	/// <summary>
	/// ポーズ処理時の更新処理
	/// </summary>
	/// <returns>
	/// なし
	/// </returns>
	virtual void PauseUpDate();


	/// <summary>
	/// 描画処理
	/// </summary>
	/// <returns>
	/// なし
	/// </returns>
	virtual void Render();
public:
	/// <summary>
	/// 自身を消滅させます
	/// </summary>
	/// <returns>
	/// なし
	/// </returns>
	void Kill();


	/// <summary>
	/// 殺されてからの時間を返します
	/// </summary>
	int getKillcount()const;


	/// <summary>
	/// 描画の優先順位を返します
	/// </summary>
	float getDrawOrder()const;


	/// <summary>
	/// タスク名を返します
	/// </summary>
	std::string getTaskName()const;


	/// <summary>
	/// 次に生成されるタスクが存在するかを判定します
	/// </summary>
	/// <returns>
	/// 存在する true 存在しない false
	/// </returns>
	bool getNextTask()const;


	/// <summary>
	/// タスクの更新処理
	/// </summary>
	/// <returns>
	/// なし
	/// </returns>
	void T_UpDate();


	/// <summary>
	/// タスクのポーズ処理
	/// </summary>
	/// <returns>
	/// なし
	/// </returns>
	void T_Pause();


	/// <summary>
	/// タスクの描画処理
	/// </summary>
	/// <returns>
	/// なし
	/// </returns>
	void T_Render();
	
};