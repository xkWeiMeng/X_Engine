#include "GameMainScene.h"
#include"Main\DirectX.h"
namespace GMS {
	D3DXVECTOR2* g_pLineArr;
};
using namespace GMS;

GameMainScene::GameMainScene()
{
}


GameMainScene::~GameMainScene()
{

}

bool GameMainScene::Init()
{
	g_pLineArr = new D3DXVECTOR2[2];
	g_pLineArr[0].x = 0;
	g_pLineArr[0].y = 0;
	g_pLineArr[1].x = 500;
	g_pLineArr[1].y = 500;

	return true;
}

void GameMainScene::End()
{

}

void GameMainScene::Render()
{
	g_pLine->SetWidth(30.f);
	g_pLine->SetAntialias(TRUE);
	g_pLine->Draw(g_pLineArr, 4, 0xffffffff);

}

void GameMainScene::Update()
{
}
