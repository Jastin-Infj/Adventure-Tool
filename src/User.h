#pragma once
#include "GameObject.h"
class User : public GameObject
{
private:

public:

private:

public:
	User();
	~User();
	bool Initialize(const Vec2& , const Point& , const Point& = Point(1,1));
	bool Finalize()override;
	void UpDate()override;
	void Render()override;
};