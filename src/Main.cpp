#include <Siv3D.hpp>
//void Main()
//{
//	/* �R���\�[����ʂ�\�����܂��i�����������������܂��j */
//	Console.open();
//	while (System::Update())
//	{
//		/* �G�X�P�[�v�������ƃA�v���P�[�V�������I�����܂� */
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
	gui.setTitle(U"�^�C�g��");
	gui.add(U"bt1", GUIButton::Create(U"OK"));
	gui.add(U"bt2", GUIButton::Create(U"�L�����Z��"));
	gui.setCenter(Window::Center());

	while (System::Update())
	{
		ClearPrint();
		Println(gui.getPos());
		Println(gui.getRect());
	}
}
