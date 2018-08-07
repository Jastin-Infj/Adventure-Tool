#pragma once
#include <Siv3D.hpp>
#include "../TaskSystem/TaskObject.h"

using TASKNAME = std::pair<std::string, std::string>;		//�^�X�N��

class Tool : public TaskObject
{
public:
	typedef std::shared_ptr<Tool>  SP;		//�V�F�A�|�C���^
	typedef std::weak_ptr<Tool>    WP;		//�E�B�[�N�|�C���^


	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	Tool();


	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~Tool();


	/// <summary>
	/// �������������s���܂�
	/// </summary>
	/// <param name="taskname_">
	/// �c�[����(�O���[�v���E�^�X�N��)
	/// </param>
	/// <returns>
	/// ���������� �I�� true 
	/// </returns>
	bool Init(const TASKNAME& taskname_);


	/// <summary>
	/// �c�[�����N�������܂�
	/// </summary>
	/// <param name="taskname_">
	/// �c�[����(�O���[�v���E�^�X�N��)
	/// </param>
	/// <param name="flag">
	/// �^�X�N�V�X�e���ɓo�^�����邩
	/// </param>
	/// <returns></returns>
	static TaskObject::SP Create(const TASKNAME& taskname_, bool flag = true);


	/// <summary>
	/// �X�V����
	/// </summary>
	void Update()override;


	/// <summary>
	/// �`�揈��
	/// </summary>
	void Render()override;


	/// <summary>
	/// �������
	/// </summary>
	/// <returns>
	/// ��� true
	/// </returns>
	bool Finalize()override;
};