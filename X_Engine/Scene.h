#pragma once
class Scene
{
public:
	Scene();
	virtual ~Scene();

	virtual bool Init() { return true; };
	//�����Ĺرպ��������л�����ʱ�ᱻִ��һ��
	virtual void End() {};
	//��������Ⱦ����
	virtual void Render() {};
	//�������߼����º���
	virtual void Update() {};
};

