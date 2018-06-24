#include <Siv3D.hpp>
//void Main()
//{
//	/* コンソール画面を表示します（自動解放処理がされます） */
//	Console.open();
//	while (System::Update())
//	{
//		/* エスケープを押すとアプリケーションを終了します */
//		if (KeyEscape.down())
//		{
//			System::Exit();
//		}
//	}
//	return;
//}

void Main()
{
	Graphics::SetBackground(Color(160, 200, 100));

	GUI gui(GUIStyle::Default);
	gui.setTitle(U"タイトル");
	gui.add(U"bt1", GUIButton::Create(U"OK"));
	gui.add(U"bt2", GUIButton::Create(U"キャンセル"));
	gui.setCenter(Window::Center());

	while (System::Update())
	{
		ClearPrint();
		Println(gui.getPos());
		Println(gui.getRect());
	}
}
