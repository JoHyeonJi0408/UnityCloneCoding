#include "jrdGameObject.h"

namespace jrd {
	GameObject::GameObject()
	{
	}

	GameObject::~GameObject()
	{
	}

	void GameObject::Update()
	{
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			mX -= 0.01f;
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			mX += 0.01f;
		}

		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			mY -= 0.01f;
		}

		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			mY += 0.01f;
		}
	}

	void GameObject::LateUpdate()
	{
		// Late update logic here
	}

	void GameObject::Render(HDC hdc)
	{
		// �Ķ� �귯�� ����
		HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));

		// �Ķ� �귯�� DC�� ���� �׸��� ��� �귯�� ��ȯ�� ��ȯ
		HBRUSH whiteBrush = (HBRUSH)SelectObject(hdc, blueBrush);

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN blackPen = (HPEN)SelectObject(hdc, redPen);
		SelectObject(hdc, blackPen);

		Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);

		SelectObject(hdc, whiteBrush);
		DeleteObject(blueBrush);
		DeleteObject(redPen);
	}
}
