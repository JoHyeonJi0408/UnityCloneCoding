#pragma once
#include "jrdEntity.h"
#include "jrdGameObject.h"

namespace jrd 
{
	class Scene : public Entity
	{
	public:
		Scene();
		~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void AddGameObject(GameObject* gameObject);
	private:
		std::vector<GameObject*> mGameObjects;
	};
}
