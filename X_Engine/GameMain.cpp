#include"Scene.h"
#include"Main\Window.h"
#include"Main\DirectX.h"
#include"Main\XE_Global.h"
#include"Main\DirectSound.h"
#include<Windows.h>

//��ǰ��Ϸ�ĳ���
Scene *scene = NULL;

bool Game_Init(HWND window)
{
	if (!Direct3D_Init(window, Global::Window::ScreenWidth, Global::Window::ScreenHeight, Global::Window::FullScreen))
	{
		ShowMessage("Direct3D��ʼ��ʧ��");
		return false;
	}
	if (!DirectInput_Init(window))
	{
		ShowMessage("Direct Input ��ʼ��ʧ��");
		return false;
	}
	if (!DirectSound_Init(window)) {
		ShowMessage("Direct Sound ��ʼ��ʧ��");
		return false;
	}
	
	return true;
}

/*
	�߼�������
*/
void Game_Update(HWND window)
{
	//��ȡ���µ�����������
	DirectInput_Update(window);

	//ִ�е�ǰ������Update�߼�������
	if (scene != NULL)
		scene->Update();

}

/*
	��Ⱦ������
*/
void Game_Render(HWND window, HDC device)
{
	//ȷ��DX�Ѿ���Ч
	if (!d3dDev) return;

	//����
	d3dDev->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_ARGB(0, 65, 105, 225), 1.0f, 0);

	//��ʼ��Ⱦ
	if (d3dDev->BeginScene())
	{
		spriteObj->Begin(D3DXSPRITE_ALPHABLEND);

		//���õ�ǰ��������Ⱦ����
		if (scene != NULL)
			scene->Render();

		spriteObj->End();
		d3dDev->EndScene();
		//�Ѻ�̨����ˢ��ǰ̨��ʾ
		d3dDev->Present(NULL, NULL, NULL, NULL);
	}
}
//�л���Ϸ����
void Game_ChangeScene(int to)
{

}

// ֻ��������Ϣ������WinProc�е��ô˺�����Ҫ��ر���Ϸ������WinMain���EndApplication
void Game_Free(HWND window, HDC device)
{
	//���ó����Ĺرպ������ͷų���
	if (scene != NULL)
	{
		scene->End();
		delete scene;
	}
	DirectInput_Shutdown();
	DirectSound_Shutdown();
	Direct3D_Shutdown();
	ReleaseDC(window, device);
}
////��ȡ��Ϸ����
//bool ReadPlayerSettingInHD()
//{
//	char buf;
//	ifstream in("GameSet.set", ios::in | ios::binary);
//	if (!in.is_open())
//	{
//		ShowMessage("�޷�����Ϸ�������ļ�");
//		return false;
//	}
//	for (int i = 0; i < 5; i++)
//	{
//		in.read(&buf, 1);
//		Global::PlayerControl::Player1[i] = buf;
//	}
//	for (int i = 0; i < 5; i++)
//	{
//		in.read(&buf, 1);
//		Global::PlayerControl::Player2[i] = buf;
//	}
//	in.read(&buf, 1);
//	Global::Sound::SoundSwicth = buf;
//	in.close();
//	return true;
//}
