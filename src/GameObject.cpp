#include "GameObject.h"

GameObject::GameObject() {}
GameObject::~GameObject() {}

void GameObject::setPos(const Vec2& pos)
{
	this->position = pos;
}
Vec2 GameObject::getPos()const
{
	return this->position;
}
Point GameObject::getSize()const
{
	return this->Drawsize;
}
void GameObject::setSize(const Point& Drawsize_)
{
	this->Drawsize = Drawsize_;
}
void GameObject::setScale(const Point& scale_)
{
	this->scale = scale_;
}
Point GameObject::getScale()const
{
	return this->scale;
}
void GameObject::CreateObject(const Vec2& position_, const Point& Drawsize_,const Point& scale_)
{
	this->position = position_;
	this->Drawsize = Drawsize_;
	this->scale = scale_;
}