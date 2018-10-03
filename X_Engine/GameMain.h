#pragma once
#include<Windows.h>
bool Game_Init(HWND window);
void Game_Update(HWND window);
void Game_Free(HWND window, HDC device);
void Game_Render(HWND window, HDC device);
void Game_ChangeScene(int to);