#include "EngineSystem.h"

OrderCheck::OrderCheck()
{
	///-1 �ݒ肳��Ă��Ȃ�
	this->id = -1;
	this->order_s = -1.f;
}


EngineSystem::EngineSystem()
{
#ifdef _DEBUG
	std::cout << "�^�X�N�G���W���@����";
#endif // _DEBUG
}
EngineSystem::~EngineSystem()
{
#ifdef _DEBUG
	std::cout << "�^�X�N�G���W���@�������" << std::endl;
#endif // _DEBUG
}
bool EngineSystem::Initalize()
{
	//�e�t���O�̏�����
	this->isPause = false;
	this->end = false;
	this->DebugFunction = false;

#ifdef _DEBUG
	std::cout << "�^�X�N�G���W���@����������" << std::endl;
#endif // _DEBUG
	return true;
}
/* �o�^�^�X�N�̍X�V���� */
void EngineSystem::Task_UpDate()
{
	for (int id = 0; id < taskobjects.size(); ++id)
	{
		/* Kill()���Ă΂�Ă��Ȃ� */
		if (this->taskobjects[id].second->getKillcount() == 0)
		{
			/* �|�[�Y����������Ă��Ȃ��� */
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
/* ���g�̍X�V���������܂� */
void EngineSystem::TaskGameUpDate()
{
	this->Task_UpDate();
	this->Task_Render();
}
void EngineSystem::ConfigDrawOrder()
{
	/* �`�揇�̐ݒ� */
	this->Orders.resize(this->taskobjects.size());
	/* �o�^�^�X�N���̕`�揇�����Ă���class������Ă��� */
	for (int i = 0; i < this->taskobjects.size(); ++i)
	{
		this->Orders[i].id = i;
		this->Orders[i].order_s = this->taskobjects[i].second->getDrawOrder();
	}
	/* �`�揇�ɍ��킹��id��order����ёւ��� */
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
	/* �|�[�Y�ݒ�����܂� */
	this->isPause = ispause_;
}
bool EngineSystem::getPause()const
{
	return this->isPause;
}
void EngineSystem::GameEnd()
{
	/* �A�v���P�[�V�����̏I���\��ݒ� */
	this->end = true;
}
bool EngineSystem::getEnd()const
{
	/* �A�v���P�[�V�������I���̗L����Ԃ� */
	return this->end;
}
void EngineSystem::setTaskObject(const TaskSystemObject::SP& To)
{
	/* �o�^�\��I�u�W�F�N�g��o�^���� */
	this->addTaskObjects.push_back(To);
}
/* �^�X�N��ύX����ۂɖ߂����� */
void EngineSystem::ChengeTask()
{
	this->setPause(false);
}
void EngineSystem::AllTaskDelete()
{
	/* �S�폜������ */
	auto id = this->taskobjects.begin();
	while (id != this->taskobjects.end())
	{
		/* vector�̐擪�A�h���X���폜 */
		this->taskobjects.erase(id);
		/* �폜�ŋl�߂Ă���擪��vector�A�h���X*/
		id = this->taskobjects.begin();
	}
}
void EngineSystem::TaskApplication()
{
	/* �o�^�\��̂��̂�o�^���� */
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
			/* kill���ꂽ */
			if (id->second->getKillcount() > 0)
			{
				/* ����폜���� */
				this->taskobjects.erase(id);
				/* �o�^�\��̂��̂�o�^���� */
				this->TaskApplication();
				/* vector�̐擪�A�h���X�w�� */
				id = this->taskobjects.begin();
			}
			/* kill����Ă��Ȃ��I�u�W�F�N�g�͔�΂��ĉ��Z���� */
			else
			{
				++id;
			}
		}
		/* nullptr�͔�΂��ĉ��Z������ */
		else
		{
			++id;
		}
	}
}
/* �o�^�\��I�u�W�F�N�g�̗L����Ԃ��܂� */
bool EngineSystem::CheckAddTask()
{
	return this->addTaskObjects.size() > 0;
}
/* �o�^�^�X�N��kill����Ă��邩�𔻒肵�܂� */
bool EngineSystem::CheckKillTask()
{
	for (int i = 0; i < this->taskobjects.size(); ++i)
	{
		/* �o�^�^�X�N�̃I�u�W�F�N�g��kill����Ă��� */
		if (taskobjects[i].second->getKillcount() > 0)
		{
			return true;
		}
	}
	return false;
}
/* �G���W���̏I����o�^���܂� */
void EngineSystem::setDeleteEngine(const bool flag)
{
	this->DeleteEngine = flag;
}
/* �G���W���I����Ԃ��܂� */
bool EngineSystem::getDeleteEngine()
{
	return this->DeleteEngine;
}
/* �^�X�N�̌���(�擪�̓����̃^�X�N��Ԃ��܂�)*/
template<class T>
std::shared_ptr<T> EngineSystem::GetTask(const std::string& taskname)
{
	/* �o�^����Ă���^�X�N����taskname�ƈ�v���Ă��邩 */
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
	/* �o�^�\��̃^�X�N����taskname�ƈ�v���Ă��邩 */
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
/* vector�Ŋi�[����Ă���I�u�W�F�N�g��Ԃ��܂� */
template <class T>
std::shared_ptr<std::vector<std::shared_ptr<T>>> EngineSystem::GetTasks(const std::string& taskname)
{
	/* ����vector::SP�𐶐����� */
	std::shared_ptr<std::vector<std::shared_ptr<T>>> find = std::shared_ptr<std::vector<std::shared_ptr<T>>>(new std::vector<std::shared_ptr<T>>());
	for (auto id = this->taskobjects.begin(); id != this->taskobjects.end(); ++id)
	{
		if ((*id).second->getTaskName() == taskname)
		{
			/* <unknown> <unnamed>�ɂ��push_back */
			/* ����vector�Ɍ����ǉ����� */
			find->push_back(std::static_pointer_cast<)
		}
	}
}
EngineSystem* TaskSystem;
