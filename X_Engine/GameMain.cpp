#include"Scene.h"
#include"Main\Window.h"
#include"Main\DirectX.h"
#include"Main\XE_Global.h"
#include"Main\DirectSound.h"
#include<Windows.h>

//当前游戏的场景
Scene *scene = NULL;

bool Game_Init(HWND window)
{
	if (!Direct3D_Init(window, Global::Window::ScreenWidth, Global::Window::ScreenHeight, Global::Window::FullScreen))
	{
		ShowMessage("Direct3D初始化失败");
		return false;
	}
	if (!DirectInput_Init(window))
	{
		ShowMessage("Direct Input 初始化失败");
		return false;
	}
	if (!DirectSound_Init(window)) {
		ShowMessage("Direct Sound 初始化失败");
		return false;
	}
	
	return true;
}

/*
	逻辑处理函数
*/
void Game_Update(HWND window)
{
	//获取最新的鼠标键盘输入
	DirectInput_Update(window);

	//执行当前场景的Update逻辑处理函数
	if (scene != NULL)
		scene->Update();

}

/*
	渲染处理函数
*/
void Game_Render(HWND window, HDC device)
{
	//确认DX已经生效
	if (!d3dDev) return;

	//清屏
	d3dDev->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_ARGB(0, 65, 105, 225), 1.0f, 0);

	//开始渲染
	if (d3dDev->BeginScene())
	{
		spriteObj->Begin(D3DXSPRITE_ALPHABLEND);

		//调用当前场景的渲染函数
		if (scene != NULL)
			scene->Render();

		spriteObj->End();
		d3dDev->EndScene();
		//把后台缓存刷到前台显示
		d3dDev->Present(NULL, NULL, NULL, NULL);
	}
}
//切换游戏场景
void Game_ChangeScene(int to)
{

}

// 只允许在消息处理函数WinProc中调用此函数，要想关闭游戏，调用WinMain里的EndApplication
void Game_Free(HWND window, HDC device)
{
	//调用场景的关闭函数并释放场景
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
////读取游戏设置
//bool ReadPlayerSettingInHD()
//{
//	char buf;
//	ifstream in("GameSet.set", ios::in | ios::binary);
//	if (!in.is_open())
//	{
//		ShowMessage("无法打开游戏的设置文件");
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
