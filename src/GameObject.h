#pragma once
#include <Siv3D.hpp>
class GameObject
{
protected:
	Vec2  position;							//���W�ʒu
	Point Drawsize;							//�`��T�C�Y
	Point scale;							//�g�嗦
protected:
	virtual void UpDate() = 0;				//�X�V����
	virtual void Render() = 0;				//�`�揈��
	virtual bool Finalize() = 0;			//�������
public:
	//setter
	void setPos(const Vec2&);				//���W�l��ݒ肷��
	void setSize(const Point&);				//�T�C�Y��ݒ肷��
	void setScale(const Point&);			//�傫����ݒ肷��
public:
	GameObject();
	virtual ~GameObject();

	//getter
	Vec2  getPos()const;
	Point getSize()const;
	Point getScale()const;

	//����������
	void CreateObject(const Vec2& pos, const Point& size ,const Point& scale = Point(1,1));
};