#pragma once
#include<vector>
#include<Windows.h>
extern std::vector<int> gameMsg;
class KeyMouseMsg
{
public:
	KeyMouseMsg();
	~KeyMouseMsg();
	void ReadKeyState(HWND);
	void ProductionMsg();
};

