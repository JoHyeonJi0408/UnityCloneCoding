#include "jrdApplication.h"

namespace jrd
{
	Application::Application() 
		: mHwnd(nullptr),
		mHdc(nullptr),
		mSpeed(0.0f),
		mX(0.0f),
		mY(0.0f)
	{

	}

	Application::~Application() 
	{
		
	}

	void Application::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);
	}

	void Application::Run() 
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update() 
	{
		mSpeed += 0.01f;

		if(GetAsyncKeyState(VK_LEFT) & 0x8000)
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

	void Application::LateUpdate() 
	{
		// Late update logic here
	}

	void Application::Render() 
	{
		// 파란 브러쉬 생성
		HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));

		// 파란 브러쉬 DC에 선택 그리고 흰색 브러쉬 반환값 반환
		HBRUSH whiteBrush = (HBRUSH)SelectObject(mHdc, blueBrush);

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN blackPen = (HPEN)SelectObject(mHdc, redPen);
		SelectObject(mHdc, blackPen);

		Rectangle(mHdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);

		SelectObject(mHdc, whiteBrush);
		DeleteObject(blueBrush);
		DeleteObject(redPen);
	}
} 