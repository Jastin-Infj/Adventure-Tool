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
	///�R���X�g���N�^
	/// </summary>
	/// <returns>
	/// �Ȃ�
	/// </returns>
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
	std::vector<TaskSystemObject::SP> addTaskObjects;						//�o�^�\��^�X�N
public:
	bool DebugFunction;						//�f�o�b�O�@�\
private:
	/// <summary>
	///�^�X�N�o�^�\���o�^
	/// </summary>
	/// <returns>
	/// �Ȃ�
	/// </returns>
	void TaskApplication();


	/// <summary>
	/// �`�揇��ݒ肷��
	/// </summary>
	/// <returns>
	/// �Ȃ�
	/// </returns>
	void ConfigDrawOrder();


	/// <summary>
	/// �o�^�\��̃^�X�N�̗L��
	/// </summary>
	/// <returns>
	/// �^�X�N����@true �^�X�N�Ȃ� false
	/// </returns>
	bool CheckAddTask();


	/// <summary>
	///�폜�\��̃^�X�N�̗L��
	/// </summary>
	/// <returns>
	/// �^�X�N����@true �^�X�N�Ȃ� false
	/// </returns>
	bool CheckKillTask();


	/// <summary>
	///�^�X�N�X�V����
	/// </summary>
	/// <returns>
	/// �Ȃ�
	/// </returns>
	void Task_UpDate();


	/// <summary>
	///�^�X�N�`�揈��
	/// </summary>
	/// <returns>
	/// �Ȃ�
	/// </returns>
	void Task_Render();


	/// <summary>
	///�폜�\��̃^�X�N���폜
	/// </summary>
	/// <returns>
	/// �Ȃ�
	/// </returns>
	void TaskKillCheck();


	/// <summary>
	///�o�^�^�X�N�S�폜
	/// </summary>
	/// <returns>
	/// �Ȃ�
	/// </returns>
	void AllTaskDelete();


public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	EngineSystem();


	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~EngineSystem();


	/// <summary>
	/// ����������
	/// </summary>
	/// <returns>
	/// ���������o���� true ���������o���Ȃ� false
	/// </returns>
	bool Initalize();


	/// <summary>
	/// �|�[�Y�ݒ�
	/// </summary>
	/// <returns>
	/// �Ȃ�
	/// </returns>
	void setPause(const bool);


	/// <summary>
	/// �|�[�Y��Ԃ�
	/// </summary>
	/// <returns>
	/// �|�[�Y�� true �|�[�Y���ł͂Ȃ� false
	/// </returns>
	bool getPause()const;


	/// <summary>
	/// �A�v���P�[�V�����I���o�^
	/// </summary>
	/// <returns>
	/// �Ȃ�
	/// </returns>
	void GameEnd();


	/// <summary>
	/// �A�v���P�[�V�������I���������Ƃ�Ԃ�
	/// </summary>
	/// <returns>
	/// �I���@true �I�����Ă��Ȃ� false
	/// </returns>
	bool getEnd()const;


	/// <summary>
	/// �^�X�N�ύX������
	/// </summary>
	/// <returns>
	/// �Ȃ�
	/// </returns>
	void ChengeTask();


	/// <summary>
	/// �^�X�N�I�u�W�F�N�g�̍X�V����
	/// </summary>
	/// <returns>
	/// �Ȃ�
	/// </returns>
	void TaskGameUpDate();


	/// <summary>
	/// �^�X�N�̓o�^
	/// </summary>
	/// <returns>
	/// �Ȃ�
	/// </returns>
	void setTaskObject(const TaskSystemObject::SP&);


	/// <summary>
	/// �G���W���I����Ԃ�
	/// </summary>
	/// <returns>
	/// �I�� true �I�����Ă��Ȃ� false
	/// </returns>
	bool getDeleteEngine();	


	/// <summary>
	/// �G���W���I���o�^
	/// </summary>
	/// <returns>
	/// �Ȃ�
	/// </returns>
	void setDeleteEngine(const bool);


	/// <summary>
	/// �^�X�N�V�X�e�����ɓo�^�����I�u�W�F�N�g��Ԃ��܂�
	/// </summary>
	/// <returns>
	/// �o�^�����^�X�N���̃X�}�[�g�|�C���^
	/// </returns>
	template <class T> std::shared_ptr<T> GetTask(const std::string& taskname);


	/// <summary>
	/// �^�X�N�V�X�e���ɓo�^����std::vector��Ԃ��܂�
	/// </summary>
	/// <returns>
	/// �o�^�����^�X�N����vector
	/// </returns>
	template <class T> std::shared_ptr<std::vector<std::shared_ptr<T>>> GetTasks(const std::string& taskName);
};
