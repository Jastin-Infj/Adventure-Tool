#pragma once
#include "GameObject.h"

class FileImage : public GameObject
{
public:
	typedef std::shared_ptr<FileImage> SP;		//�V�F�A�|�C���^
	typedef std::weak_ptr<FileImage>   WP;		//�E�B�[�N�|�C���^


	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	FileImage();


	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~FileImage();


	/// <summary>
	/// �h���b�v����Resource��ǂݍ��݂܂�
	/// </summary>
	/// <param name="taskname_">
	/// �I�u�W�F�N�g��(�O���[�v���E�^�X�N��)
	/// </param>
	/// <param name="flag">
	/// �^�X�N�V�X�e���ɓo�^���邩 true false
	/// </param>
	/// <returns></returns>
	static TaskObject::SP Create(const TASKNAME& taskname_, bool flag = true);


	/// <summary>
	/// ����������
	/// </summary>
	/// <param name="taskname_">
	/// �I�u�W�F�N�g��(�O���[�v���E�^�X�N��)
	/// </param>
	/// <returns>
	/// �������������� true 
	/// </returns>
	bool Init(const TASKNAME& taskname_);


	/// <summary>
	/// �������
	/// </summary>
	/// <returns>
	/// ��� true / false
	/// </returns>
	bool Finalize()override;


	/// <summary>
	/// �X�V����
	/// </summary>
	void Update()override;


	/// <summary>
	/// �`�揈��
	/// </summary>
	void Render()override;


	/// <summary>
	/// �摜�̓ǂݍ��݂��s���܂�
	/// </summary>
	/// <returns>
	/// true �ǂݍ��ݐ��� false �ǂ݂��ݎ��s
	/// </returns>
	Texture Load();
};