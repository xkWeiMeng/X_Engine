#include <vector>
#include "KeyMouseMsg.h"
#include "Main/DirectX.h"
#include "Main/XE_Global.h"

vector<int> gameMsg;

KeyMouseMsg::KeyMouseMsg()
{
	//gameMsg.reserve(10);
	gameMsg.assign(10, 0);

}


KeyMouseMsg::~KeyMouseMsg()
{
}

char keys[256];
char keys_down[256]; 
//鼠标状态
DIMOUSESTATE mouseState;

bool Key_Down(int key)
{
	return (bool)(keys[key] & 0x80);
}

bool Key_Up(int key)
{
	//判断以往帧是否已经按下
	if ((bool)(keys_down[key] & 0x80))
	{
		//判断按键是否不处于按下状态
		if (!Key_Down(key))
		{
			keys_down[key] = 0;
		//	KeyMouseMsg_Ns::keyMsgVec
			return true;
		}
	}
	else if (Key_Down(key))
	{
		keys_down[key] = keys[key];
	}
	return false;
}
void KeyMouseMsg::ReadKeyState(HWND hWnd)
{
	//更新鼠标
	diMouse->Poll();

	if (!SUCCEEDED(diMouse->GetDeviceState(sizeof(DIMOUSESTATE), &mouseState)))
	{
		//mouse device lose, try to re-acquire
		diMouse->Acquire();
	}
	//ProcessInput(hWnd);

	//更新键盘
	diKeyboard->Poll();
	if (!SUCCEEDED(diKeyboard->GetDeviceState(256, (LPVOID)&keys)))
	{
		//keyboard device lost, try to re-acquire
		diKeyboard->Acquire();
	}

	////更新手柄
	//for (int i = 0; i < 4; i++)
	//{
	//    ZeroMemory(&controllers[i], sizeof(XINPUT_STATE));
	//    //get the state of the controller
	//    XINPUT_STATE state;
	//    DWORD result = XInputGetState(i, &state);
	//    //store state in global controllers array
	//    if (result == 0) controllers[i] = state.Gamepad;
	//}


}

void KeyMouseMsg::ProductionMsg()
{
	//在这里生成自己需要的消息，即gameMsg,然后在游戏循环中处理这些消息
	if (Key_Down(Global::KeyMouseMsg::playerOneDown))
	{
		gameMsg[0] = 1;
	}
	//类推

	////处理键盘按键状态，生成按键消息
	//for (int i = 0; i < 256; i++)
	//{
	//	//轮询键盘状态
	//	Key_Up(i);
	//}
}

