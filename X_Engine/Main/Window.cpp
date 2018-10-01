#include <Windows.h>
#include <String>
#include "XE_Global.h"
using namespace std;

HWND window;
HDC device;
bool Gameover = false;

// Window callback function
LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static RECT rect;
	LONG_PTR Style;
	switch (message)
	{
	case WM_DESTROY:
		Gameover = true;
		PostQuitMessage(0);
		break;
	case WM_PAINT:
		//获取窗口在屏幕的坐标
		if (!Global::Window::FullScreen)
		{
			GetClientRect(hWnd, &rect);
			Global::Window::x = rect.left;
			Global::Window::y = rect.top;

		}
		break;
		/*
		case WM_SIZE://不绘制标题栏
			Style = ::GetWindowLongPtr(hWnd, GWL_STYLE);
			Style = Style &~WS_CAPTION &~WS_SYSMENU &~WS_SIZEBOX;
			::SetWindowLongPtr(hWnd, GWL_STYLE, Style);
		break;
		*/
	case WM_ACTIVATE:
		Global::Window::isActity = !(wParam == WA_INACTIVE);
		break;
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}

// MyRegiserClass function sets program window properties
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	//create the window class structure
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);

	//fill the struct with info
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = (WNDPROC)WinProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = NULL;
	wc.hCursor = NULL;
	wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = Global::Window::GameTitle.c_str();
	wc.hIconSm = NULL;

	//set up the window with the class info
	return RegisterClassEx(&wc);
}

// Helper function to create the window and refresh it
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	//create a new window
	long MetricsX = ::GetSystemMetrics(SM_CXSCREEN);//获取显示器分辨率用于让窗口居中
	long MetricsY = ::GetSystemMetrics(SM_CYSCREEN);
	//create a new window
	//根据用户屏幕分辨率分配游戏窗口大小
	const float GameY_Screen_rate = 0.8888889;
	const float GameY_GameX_rate = 0.9375;

	float GameScreenHeight = MetricsY * GameY_Screen_rate;
	float GameScreenWidth = GameScreenHeight / GameY_GameX_rate;
	Global::Window::ScreenHeight = GameScreenHeight;
	Global::Window::ScreenWidth = GameScreenWidth;

	window = CreateWindow(
		Global::Window::GameTitle.c_str(),              //window class
		Global::Window::GameTitle.c_str(),              //title bar
		WS_OVERLAPPEDWINDOW,   //window style
		MetricsX / 2 - GameScreenWidth / 2,         //x position of window
		MetricsY / 2 - GameScreenHeight / 2,         //y position of window
		GameScreenWidth,                   //width of the window
		GameScreenHeight,                   //height of the window
		NULL,                  //parent window
		NULL,                  //menu
		hInstance,             //application instance
		NULL);                 //window parameters
							   //was there an error creating the window?
	if (window == 0) return 0;

	//display the window
	ShowWindow(window, nCmdShow);
	UpdateWindow(window);

	//get device context for drawing
	device = GetDC(window);

	return 1;
}
DWORD currentTime = 0;
DWORD lastCurrentTime = 0;
int currentCount = 0;
int refreshTime = 0;
// Entry point function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MSG msg;

	//create window
	MyRegisterClass(hInstance);
	if (!InitInstance(hInstance, nCmdShow)) return -1;


	while (!Gameover)
	{
		//如果有Windows消息则优先处理
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {

		}
	}
	//释放资源

	return msg.wParam;
}

//结束游戏
void EndApplication()
{
	PostMessage(window, WM_DESTROY, 0, 0);
}
