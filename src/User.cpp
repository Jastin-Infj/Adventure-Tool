#include "User.h"
User::User()
{
	#ifdef _DEBUG
	std::cout << "ユーザー　初期化処理" << std::endl;
	#endif // _DEBUG
}
User::~User()
{
	if (this->Finalize())
	{
		#ifdef _DEBUG
		std::cout << "ユーザー　解放処理" << std::endl;
		#endif // _DEBUG
	}
}
bool User::Initialize(const Vec2& position_ , const Point& Drawsize_, const Point& scale_)
{
	this->CreateObject(position_, Drawsize_, scale_);
	return true;
}
bool User::Finalize()
{
	return true;
}
void User::UpDate()
{

}
void User::Render()
{

}