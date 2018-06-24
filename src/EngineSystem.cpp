#include "EngineSystem.h"

EngineSystem::EngineSystem()
{
	
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
EngineSystem::~EngineSystem()
{
	/* 登録しているタスクをすべてを破棄する */
	this->AllTaskDelete();
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

void EngineSystem::AllTaskDelete()
{
	/* 全削除をする */
	auto id = this->taskobjects.begin();
	while (id != this->taskobjects.end())
	{
		/* vectorの先頭アドレスを削除 */
		this->taskobjects.erase(id);
		/* 削除で詰めてある先頭のvectorアドレス */
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
				this->taskobjects.erase(id);
				this->TaskApplication();
			}
		}
	}
}
