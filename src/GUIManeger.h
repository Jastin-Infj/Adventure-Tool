#pragma once
#include <Siv3D.hpp>
#include <memory>

class GUIManeger
{
private:
	s3d::GUI* gamemainmenu;							//�Q�[���V�[��GUI�𐧌䂷��
	s3d::GUI* config;								//�R���t�B�O�𐧌䂷��
	s3d::GUI* option;								//�I�v�V�����𐧌䂷��
public:
	typedef std::shared_ptr<GUIManeger> SP;
	typedef std::weak_ptr<GUIManeger>   WP;
private:
	void MenuCreate();
public:
	GUIManeger();
	~GUIManeger();

	bool Initialize();				//����������
	bool Finalize();				//�������
	void UpDate();					//�X�V����
	void Render();					//�`�揈��

	static GUIManeger::SP Create(bool = true);
};