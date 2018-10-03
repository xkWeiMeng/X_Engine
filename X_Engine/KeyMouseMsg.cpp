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
//���״̬
DIMOUSESTATE mouseState;

bool Key_Down(int key)
{
	return (bool)(keys[key] & 0x80);
}

bool Key_Up(int key)
{
	//�ж�����֡�Ƿ��Ѿ�����
	if ((bool)(keys_down[key] & 0x80))
	{
		//�жϰ����Ƿ񲻴��ڰ���״̬
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
	//�������
	diMouse->Poll();

	if (!SUCCEEDED(diMouse->GetDeviceState(sizeof(DIMOUSESTATE), &mouseState)))
	{
		//mouse device lose, try to re-acquire
		diMouse->Acquire();
	}
	//ProcessInput(hWnd);

	//���¼���
	diKeyboard->Poll();
	if (!SUCCEEDED(diKeyboard->GetDeviceState(256, (LPVOID)&keys)))
	{
		//keyboard device lost, try to re-acquire
		diKeyboard->Acquire();
	}

	////�����ֱ�
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
	//�����������Լ���Ҫ����Ϣ����gameMsg,Ȼ������Ϸѭ���д�����Щ��Ϣ
	if (Key_Down(Global::KeyMouseMsg::playerOneDown))
	{
		gameMsg[0] = 1;
	}
	//����

	////������̰���״̬�����ɰ�����Ϣ
	//for (int i = 0; i < 256; i++)
	//{
	//	//��ѯ����״̬
	//	Key_Up(i);
	//}
}

