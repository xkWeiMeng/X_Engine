#pragma once
#include<iostream>
namespace Global {
	namespace Window {
		const std::string GameTitle = "X_E";
		extern int ScreenWidth;
		extern int ScreenHeight;
		//���ڵ�����
		extern int x, y;
		extern bool isActity;
		const bool FullScreen = false;

	}
	namespace KeyMouseMsg {
		//������Ԥ�ƴ����������������Щ������Ϣ

		char playerOneUp = 0xaa;
		char playerOneDown = 0xaa;
		char playerOneLeft = 0xaa;
		char playerOneRight = 0xaa;

	}
}
