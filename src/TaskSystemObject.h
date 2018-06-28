#pragma once
#include <Siv3D.hpp>
#include <memory>
class TaskSystemObject
{
private:
	bool NextTask;			//�I�����Ɏ��̃^�X�N�𐶐��ł��邩
	int killcount;			//kill�J�E���^
	bool isPause;			//�|�[�Y����
	float order;			//�`�揇
	std::string taskName;	//�^�X�N��
public:
	typedef std::shared_ptr<TaskSystemObject> SP;
private:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	TaskSystemObject();


	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~TaskSystemObject();


	/// <summary>
	/// �X�V����
	/// </summary>
	/// <returns>
	/// �Ȃ�
	/// </returns>
	virtual void UpDate();


	/// <summary>
	/// �|�[�Y�������̍X�V����
	/// </summary>
	/// <returns>
	/// �Ȃ�
	/// </returns>
	virtual void PauseUpDate();


	/// <summary>
	/// �`�揈��
	/// </summary>
	/// <returns>
	/// �Ȃ�
	/// </returns>
	virtual void Render();
public:
	/// <summary>
	/// ���g�����ł����܂�
	/// </summary>
	/// <returns>
	/// �Ȃ�
	/// </returns>
	void Kill();


	/// <summary>
	/// �E����Ă���̎��Ԃ�Ԃ��܂�
	/// </summary>
	int getKillcount()const;


	/// <summary>
	/// �`��̗D�揇�ʂ�Ԃ��܂�
	/// </summary>
	float getDrawOrder()const;


	/// <summary>
	/// �^�X�N����Ԃ��܂�
	/// </summary>
	std::string getTaskName()const;


	/// <summary>
	/// ���ɐ��������^�X�N�����݂��邩�𔻒肵�܂�
	/// </summary>
	/// <returns>
	/// ���݂��� true ���݂��Ȃ� false
	/// </returns>
	bool getNextTask()const;


	/// <summary>
	/// �^�X�N�̍X�V����
	/// </summary>
	/// <returns>
	/// �Ȃ�
	/// </returns>
	void T_UpDate();


	/// <summary>
	/// �^�X�N�̃|�[�Y����
	/// </summary>
	/// <returns>
	/// �Ȃ�
	/// </returns>
	void T_Pause();


	/// <summary>
	/// �^�X�N�̕`�揈��
	/// </summary>
	/// <returns>
	/// �Ȃ�
	/// </returns>
	void T_Render();
	
};