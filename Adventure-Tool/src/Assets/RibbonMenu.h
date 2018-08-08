#pragma once
#include "GameObject.h"

#define FONT_SIZE 10


/// <summary>
/// ���{�����j���[
/// </summary>
class RibbonMenu : public GameObject
{
public:
	typedef std::shared_ptr<RibbonMenu>  SP;		//�V�F�A�|�C���^
	typedef std::weak_ptr<RibbonMenu>    WP;		//�E�B�[�N�|�C���^


	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	RibbonMenu();


	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~RibbonMenu();


	/// <summary>
	/// ����������
	/// </summary>
	/// <param name="taskname_">
	/// �I�u�W�F�N�g��(�O���[�v���E�^�X�N��)
	/// </param>
	/// <param name="buttonname_">
	/// �{�^����
	/// </param>
	/// <param name="position_">
	/// �������W(X���W , Y���W)
	/// </param>
	/// <param name="scale_">
	/// �傫��(X , Y)
	/// </param>
	/// <param name="order_">
	/// �`��D�揇�� 0.0 ~ 1.0 
	/// </param>
	/// <returns>
	/// �������I�� true
	/// </returns>
	bool Init(
		const TASKNAME& taskname_, 
		const String& buttonname_,
		const Vec2& position_, 
		const Point& scale_ ,
		const float& order_
		);


	/// <summary>
	/// ���{�����j���[�𐶐����܂�
	/// </summary>
	/// <param name="taskname_">
	/// �I�u�W�F�N�g��(�O���[�v���E�^�X�N��)
	/// </param>
	/// <param name="buttonname_">
	/// �{�^����
	/// </param>
	/// <param name="position_">
	/// �������W(X���W , Y���W)
	/// </param>
	/// <param name="scale_">
	/// �傫��(X , Y)
	/// </param>
	/// <param name="order_">
	/// �`��D�揇�� 0.0 ~ 1.0 
	/// </param>
	/// <param name="flag">
	/// �^�X�N�V�X�e���ɓo�^���邩�@true / false
	/// </param>
	/// <returns>
	/// ���������X�}�[�g�|�C���^
	/// </returns>
	static TaskObject::SP Create(
		const TASKNAME& taskname_, 
		const String& buttonname_,
		const Vec2& position_, 
		const Point& scale_,
		const float& order_ = 1.0f , 
		bool flag = true
		);


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

private:
	String buttonname;		//�{�^���̖��O
};