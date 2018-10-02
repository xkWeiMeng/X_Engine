#pragma once
#include<iostream>
namespace Global {
	namespace Window {
		const std::string GameTitle = "X_E";
		extern int ScreenWidth;
		extern int ScreenHeight;
		//窗口的坐标
		extern int x, y;
		extern bool isActity;
		const bool FullScreen = false;

	}
	namespace KeyMouseMsg {
		//待定，预计从玩家设置中设置这些按键信息

		char playerOneUp = 0xaa;
		char playerOneDown = 0xaa;
		char playerOneLeft = 0xaa;
		char playerOneRight = 0xaa;

	}
}
