#include "EngineSystem.h"

OrderCheck::OrderCheck()
{
	///-1 設定されていない
	this->id = -1;
	this->order_s = -1.f;
}


EngineSystem::EngineSystem()
{
#ifdef _DEBUG
	std::cout << "タスクエンジン　生成";
#endif // _DEBUG
}
EngineSystem::~EngineSystem()
{
#ifdef _DEBUG
	std::cout << "タスクエンジン　解放処理" << std::endl;
#endif // _DEBUG
}
bool EngineSystem::Initalize()
{
	//各フラグの初期化
	this->isPause = false;
	this->end = false;
	this->DebugFunction = false;

#ifdef _DEBUG
	std::cout << "タスクエンジン　初期化処理" << std::endl;
#endif // _DEBUG
	return true;
}
/* 登録タスクの更新処理 */
void EngineSystem::Task_UpDate()
{
	for (int id = 0; id < taskobjects.size(); ++id)
	{
		/* Kill()が呼ばれていない */
		if (this->taskobjects[id].second->getKillcount() == 0)
		{
			/* ポーズ処理がされていないか */
			if (!this->getPause())
			{
				this->taskobjects[id].second->T_UpDate();
			}
			else
			{
				this->taskobjects[id].second->T_Pause();
			}
		}
	}
}
void EngineSystem::Task_Render()
{
	for (int i = 0; i < this->taskobjects.size(); ++i)
	{
		/* Kill */
		if (this->taskobjects[this->Orders[i].id].second->getKillcount() == 0)
		{
			this->taskobjects[this->Orders[i].id].second->T_Render();
		}
	}
}
/* 自身の更新処理をします */
void EngineSystem::TaskGameUpDate()
{
	this->Task_UpDate();
	this->Task_Render();
}
void EngineSystem::ConfigDrawOrder()
{
	/* 描画順の設定 */
	this->Orders.resize(this->taskobjects.size());
	/* 登録タスク分の描画順を入れておくclassを作っておく */
	for (int i = 0; i < this->taskobjects.size(); ++i)
	{
		this->Orders[i].id = i;
		this->Orders[i].order_s = this->taskobjects[i].second->getDrawOrder();
	}
	/* 描画順に合わせてidとorderを並び替える */
	for (int i = 0; i < this->taskobjects.size(); ++i)
	{
		for (int j = i; j < this->taskobjects.size(); ++j)
		{
			if (this->Orders[i].order_s > this->Orders[j].order_s)
			{
				OrderCheck temp = this->Orders[i];
				this->Orders[i] = this->Orders[j];
				this->Orders[j] = temp;
			}
		}
	}
}
void EngineSystem::setPause(const bool ispause_)
{
	/* ポーズ設定をします */
	this->isPause = ispause_;
}
bool EngineSystem::getPause()const
{
	return this->isPause;
}
void EngineSystem::GameEnd()
{
	/* アプリケーションの終了予定設定 */
	this->end = true;
}
bool EngineSystem::getEnd()const
{
	/* アプリケーションを終了の有無を返す */
	return this->end;
}
void EngineSystem::setTaskObject(const TaskSystemObject::SP& To)
{
	/* 登録予定オブジェクトを登録する */
	this->addTaskObjects.push_back(To);
}
/* タスクを変更する際に戻す処理 */
void EngineSystem::ChengeTask()
{
	this->setPause(false);
}
void EngineSystem::AllTaskDelete()
{
	/* 全削除をする */
	auto id = this->taskobjects.begin();
	while (id != this->taskobjects.end())
	{
		/* vectorの先頭アドレスを削除 */
		this->taskobjects.erase(id);
		/* 削除で詰めてある先頭のvectorアドレス*/
		id = this->taskobjects.begin();
	}
}
void EngineSystem::TaskApplication()
{
	/* 登録予定のものを登録する */
	for (int i = 0; i < this->addTaskObjects.size(); ++i)
	{
		std::pair<DWORD, TaskSystemObject::SP> delete_;
		delete_.second = this->addTaskObjects[i];
		if (delete_.second->getNextTask())
		{
			this->taskobjects.push_back(delete_);
		}
	}
}
void EngineSystem::TaskKillCheck()
{
	auto id = this->taskobjects.begin();
	while (id != this->taskobjects.end())
	{
		if (id->second != nullptr)
		{
			/* killされた */
			if (id->second->getKillcount() > 0)
			{
				/* 一つずつ削除する */
				this->taskobjects.erase(id);
				/* 登録予定のものを登録する */
				this->TaskApplication();
				/* vectorの先頭アドレス指す */
				id = this->taskobjects.begin();
			}
			/* killされていないオブジェクトは飛ばして加算する */
			else
			{
				++id;
			}
		}
		/* nullptrは飛ばして加算をする */
		else
		{
			++id;
		}
	}
}
/* 登録予定オブジェクトの有無を返します */
bool EngineSystem::CheckAddTask()
{
	return this->addTaskObjects.size() > 0;
}
/* 登録タスクがkillされているかを判定します */
bool EngineSystem::CheckKillTask()
{
	for (int i = 0; i < this->taskobjects.size(); ++i)
	{
		/* 登録タスクのオブジェクトがkillされている */
		if (taskobjects[i].second->getKillcount() > 0)
		{
			return true;
		}
	}
	return false;
}
/* エンジンの終了を登録します */
void EngineSystem::setDeleteEngine(const bool flag)
{
	this->DeleteEngine = flag;
}
/* エンジン終了を返します */
bool EngineSystem::getDeleteEngine()
{
	return this->DeleteEngine;
}
/* タスクの検索(先頭の同名のタスクを返します)*/
template<class T>
std::shared_ptr<T> EngineSystem::GetTask(const std::string& taskname)
{
	/* 登録されているタスク名がtasknameと一致しているか */
	for (auto id = this->taskobjects.begin(); id != this->taskobjects.end(); ++id)
	{
		if ((*id).second != nullptr)
		{
			if ((*id).second->getTaskName() == taskname)
			{
				return std::static_pointer_cast<T>((*id).second);
			}
		}
	}
	/* 登録予定のタスク名がtasknameと一致しているか */
	for (auto id = this->addTaskObjects.begin(); id != this->addTaskObjects.end(); ++id)
	{
		if ((*id) != nullptr)
		{
			if ((*id)->getTaskName() == taskname)
			{
				return std::static_pointer_cast<T>((*id));
			}
		}
	}
	return nullptr;
}
/* vectorで格納されているオブジェクトを返します */
template <class T>
std::shared_ptr<std::vector<std::shared_ptr<T>>> EngineSystem::GetTasks(const std::string& taskname)
{
	/* 仮のvector::SPを生成する */
	std::shared_ptr<std::vector<std::shared_ptr<T>>> find = std::shared_ptr<std::vector<std::shared_ptr<T>>>(new std::vector<std::shared_ptr<T>>());
	for (auto id = this->taskobjects.begin(); id != this->taskobjects.end(); ++id)
	{
		if ((*id).second->getTaskName() == taskname)
		{
			/* <unknown> <unnamed>によりpush_back */
			/* 仮のvectorに件数追加する */
			find->push_back(std::static_pointer_cast<)
		}
	}
}
EngineSystem* TaskSystem;
