#pragma once
#include <iostream>
#include <memory>
class GameMode
{
public:
	enum  Mode
	{
		Title,
		Game,
		Conflg,
		Option,
		Ending
	};
private:
	Mode mode;
public:
	typedef std::shared_ptr<GameMode> SP;
	typedef std::weak_ptr<GameMode>   WP;
//===============================================================
private:
	
public:
	GameMode();
	~GameMode();
	bool Initialize(GameMode::Mode);
	bool Finalize();
	void UpDate();
	void Render();
	static GameMode::SP Create(GameMode::Mode, bool = true);
	
	/// <summary>
	/// ゲームモードの切り替えを行います
	/// </summary>
	void ChengeMode(GameMode::Mode);
	//getter
	GameMode::Mode getMode();
};