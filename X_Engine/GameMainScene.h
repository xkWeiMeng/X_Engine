#pragma once
#include "Scene.h"
class GameMainScene :public Scene
{
public:
	GameMainScene();
	~GameMainScene();
	bool Init();
	//�����Ĺرպ��������л�����ʱ�ᱻִ��һ��
	void End();
	//��������Ⱦ����
	void Render();
	//�������߼����º���
	void Update();
};

