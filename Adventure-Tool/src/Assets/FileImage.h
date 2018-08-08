#pragma once
#include "GameObject.h"

#define DOUBLECLICK 2

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


	/// <summary>
	/// �}�E�X�ɂ��ړ����s���܂�
	/// </summary>
	void MovebyMouse();


	/// <summary>
	/// �_�u���N���b�N�𔻒肵�܂�
	/// </summary>
	/// <returns>
	/// �_�u���N���b�N���� true / false
	/// </returns>
	bool DoubleClickCheck();


	/// <summary>
	/// �v���p�e�B��`�悵�܂�
	/// </summary>
	void Property_draw();


	/// <summary>
	/// �p�x��ݒ�E�ύX���܂�
	/// </summary>
	/// <param name="angle_">
	/// �p�x(�ʓx)
	/// </param>
	void setAngle(const float& angle_);
private:
	float angle;			//�p�x
	bool mousegrid;			//�}�E�X�O���b�h�t���O
	bool doubleclick;		//�_�u���N���b�N�t���O
	bool propertyflag;		//�v���p�e�B�ݒ�t���O
	int  mouseclickcount;	//�}�E�X�J�E���g		 
};