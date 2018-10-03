#pragma once
#include "Scene.h"
class GameMainScene :public Scene
{
public:
	GameMainScene();
	~GameMainScene();
	bool Init();
	//场景的关闭函数，在切换场景时会被执行一次
	void End();
	//场景的渲染函数
	void Render();
	//场景的逻辑更新函数
	void Update();
};

