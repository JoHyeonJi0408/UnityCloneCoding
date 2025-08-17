#pragma once
#include "..\\JJRRDD_Source\jrdScene.h"

namespace jrd
{
	class PlayScene : public Scene
	{
	public:
		PlayScene();
		~PlayScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	private:
	};
}
