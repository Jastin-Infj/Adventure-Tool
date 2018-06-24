#pragma once
#include <Siv3D.hpp>
class GameObject
{
protected:
	Vec2  position;							//座標位置
	Point Drawsize;							//描画サイズ
	Point scale;							//拡大率
protected:
	virtual void UpDate() = 0;				//更新処理
	virtual void Render() = 0;				//描画処理
	virtual bool Finalize() = 0;			//解放処理
public:
	//setter
	void setPos(const Vec2&);				//座標値を設定する
	void setSize(const Point&);				//サイズを設定する
	void setScale(const Point&);			//大きさを設定する
public:
	GameObject();
	virtual ~GameObject();

	//getter
	Vec2  getPos()const;
	Point getSize()const;
	Point getScale()const;

	//生成をする
	void CreateObject(const Vec2& pos, const Point& size ,const Point& scale = Point(1,1));
};