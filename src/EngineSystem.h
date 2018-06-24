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

	bool end;								//�I����
	bool isPause;							//�|�[�Y����
	bool DeleteEngine;						//Engine�I����
	std::vector<OrderCheck> Orders;			//�`�揇
	std::vector<std::pair<DWORD, TaskSystemObject::SP>> taskobjects;		//�^�X�N�I�u�W�F�N�g
	std::vector<TaskSystemObject::SP> addTaskObjects;	//�o�^�\��^�X�N
public:
	bool DebugFunction;						//�f�o�b�O�@�\
private:
	void TaskApplication();					//�^�X�N�o�^�\���o�^
	void ConfigDrawOrder();					//�`�揇��ݒ肷��
	bool CheckAddTask();					//�o�^�\��̃^�X�N�̗L��
	bool CheckKillTask();					//�폜�\��̃^�X�N�̗L��
	void Task_UpDate();						//�^�X�N�X�V����
	void Task_Render();						//�^�X�N�`�揈��
	void TaskKillCheck();					//�폜�\��̃^�X�N���폜
	void AllTaskDelete();					//�o�^�^�X�N�S�폜
public:
	EngineSystem();
	~EngineSystem();

	bool Initalize();										//����������
	void UpDate();											//�X�V����
	void setPause(const bool);								//�|�[�Y�ݒ�
	bool getPause()const;									//�|�[�Y��Ԃ�
	void GameEnd();											//�A�v���P�[�V�����I���o�^
	bool getEnd()const;										//�A�v���P�[�V�������I���������Ƃ�Ԃ�
	void ChengeTask();										//�^�X�N�ύX������
	void TaskGameUpDate();									//�^�X�N�I�u�W�F�N�g�̍X�V����
	void setTaskObject(const TaskSystemObject::SP&);		//�^�X�N�̓o�^
	bool getDeleteEngine();									//�G���W���I����Ԃ�
	void setDeleteEngine(const bool);						//�G���W���I���o�^

	template <class T> std::shared_ptr<T> GetTask(const String& taskname);
	template <class T> std::shared_ptr<std::vector<std::shared_ptr<T>>> GetTasks(const String& taskName);
};
