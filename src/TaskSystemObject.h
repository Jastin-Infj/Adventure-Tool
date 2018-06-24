#pragma once
#include <Siv3D.hpp>
#include <memory>
class TaskSystemObject
{
private:
	bool NextTask;			//終了時に次のタスクを生成できるか
	int killcount;			
	bool isPause;			//ポーズ処理
	float order;			//描画順
public:
	typedef std::shared_ptr<TaskSystemObject> SP;
private:
	TaskSystemObject();
	~TaskSystemObject();

	virtual void UpDate();
	virtual void PauseUpDate();
	virtual void Render();
public:
	void Kill();
	int getKillcount()const;
	float getDrawOrder()const;
	bool getNextTask()const;

	void T_UpDate();
	void T_Pause();
	void T_Render();
	
};