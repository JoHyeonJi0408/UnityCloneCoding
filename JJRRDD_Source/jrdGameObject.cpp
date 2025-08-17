#include "jrdGameObject.h"
#include "jrdInput.h"
#include "jrdTime.h"

namespace jrd {
	GameObject::GameObject()
		: mX(0),
		mY(0)
	{
	}

	GameObject::~GameObject()
	{
	}

	void GameObject::Update()
	{
		const int speed = 100.0f;
		if (Input::GetKey(eKeyCode::A))
		{
			mX -= speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::D))
		{
			mX += speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::W))
		{
			mY -= speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::S))
		{
			mY += speed * Time::DeltaTime();
		}
	}

	void GameObject::LateUpdate()
	{
		// Late update logic here
	}

	void GameObject::Render(HDC hdc)
	{
		// 파란 브러쉬 생성
		HBRUSH blueBrush = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255));

		// 파란 브러쉬 DC에 선택 그리고 흰색 브러쉬 반환값 반환
		HBRUSH whiteBrush = (HBRUSH)SelectObject(hdc, blueBrush);

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN blackPen = (HPEN)SelectObject(hdc, redPen);
		SelectObject(hdc, blackPen);

		Ellipse(hdc, mX, mY, 100 + mX, 100 + mY);

		SelectObject(hdc, whiteBrush);
		DeleteObject(blueBrush);
		DeleteObject(redPen);
	}
}
