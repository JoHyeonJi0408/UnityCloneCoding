#pragma once
#include "..\\JJRRDD_Source\\jrdSceneManager.h"
#include "jrdPlayScene.h"

namespace jrd
{
	void LoadScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");

		SceneManager::LoadScene(L"PlayScene");
	}
}
